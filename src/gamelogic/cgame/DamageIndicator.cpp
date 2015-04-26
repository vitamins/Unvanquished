/*
===========================================================================

Copyright 2015 Unvanquished Developers

This file is part of Unvanquished.

Unvanquished is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Unvanquished is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Unvanquished. If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#include "cg_local.h"

namespace DamageIndicator
{
	#define DIF_TEAM        0x0001 // belongs to a teammate
	#define DIF_INDIRECT    0x0002
	#define DIF_PLAYER      0x0004
	#define DIF_FRIENDLY    0x0008
	#define DIF_PERSISTENT  0x0010

	typedef struct
	{
		int spawnTime;
		int value;
		int flags;

		int target;
		int attacker;

		vec3_t origin;
		vec3_t velocity;

		float dist;
	} damage_indicator_t;

	std::list<damage_indicator_t> list;

	void MergeSimilar( damage_indicator_t& parent )
	{
		for( auto i = list.begin( ); i != list.end( ); )
		{
			damage_indicator_t& di = *i;
			float dist;

			if( parent.target != di.target )
				goto next_di;

			if( parent.flags != di.flags )
				goto next_di;

			dist = Distance( parent.origin, di.origin );

			if( dist > 80 )
				goto next_di;

			parent.value += di.value;

			i = list.erase( i );
			continue;

		next_di:
			i++;
		}
	}

	void Spawn( entityState_t *es )
	{
		damage_indicator_t di;
		entityState_t *target = NULL;

		switch( es->event )
		{
			case EV_WEAPON_HIT_ENTITY:
			case EV_MISSILE_HIT_ENTITY:
				break;

			default:
				return;
		}

		di.spawnTime = cg.time;
		di.value = es->groundEntityNum;
		di.target = es->otherEntityNum;
		di.attacker = es->otherEntityNum2;

		if( di.attacker < 0 || di.attacker >= MAX_CLIENTS )
			return;

		if( cg_entities[ di.target ].currentValid )
			target = &cg_entities[ di.target ].currentState;

		di.flags = 0;

		if( di.attacker != cg.predictedPlayerState.clientNum )
			di.flags |= DIF_TEAM;

		if( di.target < MAX_CLIENTS )
			di.flags |= DIF_PLAYER;
		else if( target && target->eType == ET_BUILDABLE )
		{
			if( ( target->eFlags & EF_DEAD ) ||
			    target->generic1 <= 0 )
				return;
			
			if( BG_Buildable( target->modelindex )->team ==
			    cg.predictedPlayerState.persistant[ PERS_TEAM ] )
				di.flags |= DIF_FRIENDLY;
		}

		VectorCopy( es->origin, di.origin );
		VectorSet( di.velocity, crandom( ) * 30, crandom( ) * 30, 30 );

		MergeSimilar( di );

		list.push_front( di );
	}

	bool IsTooOld( damage_indicator_t& di )
	{
		return ( cg.time - di.spawnTime >= 1000 );
	}

	bool Compare( const damage_indicator_t& a, const damage_indicator_t& b )
	{
		return ( a.dist > b.dist );
	}

	void Draw( damage_indicator_t& di )
	{
		float x, y, w, h, fade;
		int index, len;
		char str[ 20 ], *p;
		vec4_t color;

		if( !CG_WorldToScreen( di.origin, &x, &y ) )
			return;

		x *= cgs.glconfig.vidWidth / 640.0;
		y *= cgs.glconfig.vidHeight / 480.0;
		h = 0.4f * MIN( cgs.glconfig.vidWidth, cgs.glconfig.vidHeight ) / sqrt( di.dist );
		snprintf( str, sizeof( str ), "%d", di.value );
		len = strlen( str );
		w = h;
		y -= h / 2;
		x -= len * w / 2;

		fade = ( cg.time - di.spawnTime ) / 1000.0f;

		if( di.flags & DIF_FRIENDLY )
			VectorSet( color, 1, 0, 0 );
		else if( di.flags & DIF_PERSISTENT )
			VectorSet( color, 0, 1, 0 );
		else
		{
			if( di.flags & DIF_PLAYER )
			{
				if( di.flags & DIF_INDIRECT )
					VectorSet( color, 1, 1, 0 );
				else
					VectorSet( color, 1, 1, 1 );
			}
			else
			{
				if( di.flags & DIF_INDIRECT )
					VectorSet( color, 1, 0.5, 0 );
				else
					VectorSet( color, 0.7, 0.7, 0.7 );
			}
		}

		color[ 3 ] = 1.0f - fade;
		trap_R_SetColor( color );

		for( p = str; *p; p++ )
		{
			if( *p >= '0' && *p <= '9' )
				index = *p - '0';
			else if( *p == '.' )
				index = 10;
			else
				index = 11;

			if( *p != ' ' )
				trap_R_DrawStretchPic(
					x, y, w, h,
					0, 0, 1, 1,
					cgs.media.numberShaders[ index ] );

			x += w;
		}

		di.velocity[ 2 ] += -400.0f * cg.frametime * 0.001f;
		VectorMA( di.origin, 0.001f * cg.frametime, di.velocity,  di.origin );
	}

	void DrawAll( )
	{
		list.remove_if( IsTooOld );

		for( damage_indicator_t &di : list )
		{
			vec3_t delta;

			VectorSubtract( di.origin, cg.refdef.vieworg, delta );
			di.dist = DotProduct( delta, cg.refdef.viewaxis[ 0 ] );
		}

		list.sort( Compare );

		for( damage_indicator_t &di : list )
			Draw( di );
	}
}

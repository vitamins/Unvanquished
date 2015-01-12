/*
===========================================================================
Copyright (C) 2006-2008 Robert Beckebans <trebor_7@users.sourceforge.net>

This file is part of XreaL source code.

XreaL source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

XreaL source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with XreaL source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

/* blurY_vp.glsl */

attribute vec2 attr_TexCoord0;

uniform float u_DeformMagnitude;
uniform vec2  u_TexScale;

varying vec2 var_Tex0;
varying vec2 var_Tex1;
varying vec2 var_Tex2;
varying vec2 var_Tex3;

void	main()
{
	// transform vertex position into homogenous clip-space
	gl_Position = vec4( attr_TexCoord0.x * 2.0 - 1.0,
			    1.0 - attr_TexCoord0.y * 2.0,
			    0.0, 1.0);

	// precompute texture coords to avoid dependent texture reads
	vec2 stScale = u_TexScale * u_DeformMagnitude;
	var_Tex0 = attr_TexCoord0 + stScale * vec2( 0.0, -2.14 );
	var_Tex1 = attr_TexCoord0 + stScale * vec2( 0.0, -0.4  );
	var_Tex2 = attr_TexCoord0 + stScale * vec2( 0.0,  0.4  );
	var_Tex3 = attr_TexCoord0 + stScale * vec2( 0.0,  2.14 );
}

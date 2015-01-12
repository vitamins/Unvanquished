/*
===========================================================================
Copyright (C) 2006-2011 Robert Beckebans <trebor_7@users.sourceforge.net>

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

/* blurX_fp.glsl */

uniform sampler2D u_ColorMap;

varying vec2 var_Tex0;
varying vec2 var_Tex1;
varying vec2 var_Tex2;
varying vec2 var_Tex3;

void	main()
{
	// do a full gaussian blur
	vec4 sumColors = vec4(0.0);
	
	sumColors += texture2D(u_ColorMap, var_Tex0) * ( 7.0/64.0);
	sumColors += texture2D(u_ColorMap, var_Tex1) * (25.0/64.0);
	sumColors += texture2D(u_ColorMap, var_Tex2) * (25.0/64.0);
	sumColors += texture2D(u_ColorMap, var_Tex3) * ( 7.0/64.0);

	gl_FragColor = sumColors;
}

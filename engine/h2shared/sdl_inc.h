/*
 * sdl_inc.h -- common SDL header.
 * $Id: sdl_inc.h 5033 2013-01-07 10:00:49Z sezero $
 *
 * Copyright (C) 2005-2012  O.Sezer <sezero@users.sourceforge.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __HX2_SDL_INC
#define __HX2_SDL_INC

#include <SDL2/SDL.h>

/* =================================================================
Minimum required SDL versions:
Although the 1.1.x series might work fine, we require at least 1.2.0
=================================================================== */

/* =================================================================
if we are compiling against SDL-1.3.x, then require version 1.3.0 or
newer at runtime, too.

2010-01-27:
SDL-1.3 is still in active development and its API hasn't solidified
yet.  As of this writing, SDL-1.2 and 1.3 has some api differences:
see, for example, SDL_GetMouseState() which is not binary compatible
between SDL-1.2 / 1.3: http://forums.libsdl.org/viewtopic.php?t=5458
For now, I am limiting our own requirement to the compiled version,
hence the SDL_NEW_VERSION_REJECT macro below.
=================================================================== */

#define SDL_MIN_X	2
#define SDL_MIN_Y	0
#define SDL_MIN_Z	0

#define SDL_REQUIREDVERSION	(SDL_VERSIONNUM(SDL_MIN_X,SDL_MIN_Y,SDL_MIN_Z))

#if !(SDL_VERSION_ATLEAST(SDL_MIN_X,SDL_MIN_Y,SDL_MIN_Z))
#error SDL version found is too old
#endif


/* the defines below are actually part of SDL_GLattr enums in SDL
   versions supporting that relevant feature. */

/* gl stereo attribute was added to SDL beginning from v1.2.5 */
#define SDL_VER_WITH_STEREO		(SDL_VERSIONNUM(1,2,5))
#if SDL_COMPILEDVERSION < SDL_VER_WITH_STEREO
#define SDL_GL_STEREO			(SDL_GL_ACCUM_ALPHA_SIZE+1)
#endif	/* SDL_VER_WITH_STEREO */

/* multisampling was added to SDL beginning from v1.2.6 */
#define SDL_VER_WITH_MULTISAMPLING	(SDL_VERSIONNUM(1,2,6))
#if SDL_COMPILEDVERSION < SDL_VER_WITH_MULTISAMPLING
#define SDL_GL_MULTISAMPLEBUFFERS	(SDL_GL_ACCUM_ALPHA_SIZE+2)
#define SDL_GL_MULTISAMPLESAMPLES	(SDL_GL_ACCUM_ALPHA_SIZE+3)
#endif	/* SDL_VER_WITH_MULTISAMPLING */

/* swapinterval was added to SDL beginning from v1.2.10 */
#define SDL_VER_WITH_SWAPINTERVAL	(SDL_VERSIONNUM(1,2,10))
#if SDL_COMPILEDVERSION < SDL_VER_WITH_SWAPINTERVAL
#define SDL_GL_ACCELERATED_VISUAL	(SDL_GL_MULTISAMPLESAMPLES+1)
#define SDL_GL_SWAP_CONTROL		(SDL_GL_MULTISAMPLESAMPLES+2)
#endif	/* SDL_VER_WITH_SWAPINTERVAL */

#endif	/* __HX2_SDL_INC */


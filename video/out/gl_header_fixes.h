/*
 * This file is part of MPlayer.
 *
 * MPlayer is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * MPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with MPlayer; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * You can alternatively redistribute this file and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#ifdef MP_GET_GL_WORKAROUNDS

// workaround for some gl.h headers
#ifndef GLAPIENTRY
#ifdef APIENTRY
#define GLAPIENTRY APIENTRY
#elif HAVE_GL_WIN32
#define GLAPIENTRY __stdcall
#else
#define GLAPIENTRY
#endif
#endif

#ifndef GL_TEXTURE_RECTANGLE
#define GL_TEXTURE_RECTANGLE 0x84F5
#endif
#ifndef GL_UNSIGNED_SHORT_8_8
#define GL_UNSIGNED_SHORT_8_8 0x85BA
#endif
#ifndef GL_UNSIGNED_SHORT_8_8_REV
#define GL_UNSIGNED_SHORT_8_8_REV 0x85BB
#endif

#if HAVE_GL_WIN32 && !defined(WGL_CONTEXT_MAJOR_VERSION_ARB)
/* these are supposed to be defined in wingdi.h but mingw's is too old */
/* only the bits actually used by mplayer are defined */
/* reference: http://www.opengl.org/registry/specs/ARB/wgl_create_context.txt */

#define WGL_CONTEXT_MAJOR_VERSION_ARB          0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB          0x2092
#define WGL_CONTEXT_FLAGS_ARB                  0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB           0x9126
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB   0x00000001
#endif

// Define just enough constants to make the OpenGL 3 code compile against
// older SDKs. Values are taken straight from OpenGL/gl3.h
#if defined __APPLE__ && !(defined GL_VERSION_3_0)
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D

#ifndef GL_ARB_framebuffer_sRGB
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#endif
#endif

#ifndef GL_RGB_422_APPLE
#define GL_RGB_422_APPLE 0x8A1F
#endif

#ifndef UNSIGNED_SHORT_8_8_APPLE
#define UNSIGNED_SHORT_8_8_APPLE 0x85BA
#endif

#ifndef UNSIGNED_SHORT_8_8_APPLE
#define UNSIGNED_SHORT_8_8_APPLE 0x85BB
#endif

#ifndef GL_NV_vdpau_interop
#define GLvdpauSurfaceNV GLintptr
#endif

// OSX
#ifndef GL_RED_INTEGER
#define GL_RED_INTEGER                    0x8D94
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#endif
#ifndef GL_DEBUG_SEVERITY_HIGH
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#endif

#undef MP_GET_GL_WORKAROUNDS

#endif

#ifdef MP_GET_GLX_WORKAROUNDS

// FreeBSD 10.0-CURRENT lacks the GLX_ARB_create_context extension completely
#ifndef GLX_CONTEXT_MAJOR_VERSION_ARB
#define GLX_CONTEXT_MAJOR_VERSION_ARB           0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB           0x2092
#define GLX_CONTEXT_FLAGS_ARB                   0x2094
#define GLX_CONTEXT_PROFILE_MASK_ARB            0x9126
#ifndef __APPLE__
// These are respectively 0x00000001 and 0x00000002 on OSX
#define GLX_CONTEXT_DEBUG_BIT_ARB               0x0001
#define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB  0x0002
#endif
#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB        0x00000001
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#endif
// GLX_EXT_create_context_es2_profile
#ifndef GLX_CONTEXT_ES2_PROFILE_BIT_EXT
#define GLX_CONTEXT_ES2_PROFILE_BIT_EXT         0x00000004
#endif

#undef MP_GET_GLX_WORKAROUNDS

#endif

/*
 * Copyright (c) 2010 Alexander Strange <astrange@ithinksw.com>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVUTIL_X86_INTREADWRITE_H
#define AVUTIL_X86_INTREADWRITE_H

#include <stdint.h>
#include "config.h"
#if HAVE_INTRINSICS_SSE && defined(__SSE__)
#include <immintrin.h>
#endif
#if HAVE_INTRINSICS_SSE2 && defined(__SSE2__)
#include <emmintrin.h>
#endif
#include "libavutil/attributes.h"

#if HAVE_INTRINSICS_SSE && defined(__SSE__)

#define AV_COPY128 AV_COPY128
static av_always_inline void AV_COPY128(void *d, const void *s)
{
    __m128 tmp = _mm_load_ps(s);
    _mm_store_ps(d, tmp);
}

#endif /* HAVE_INTRINSICS_SSE && defined(__SSE__) */

#if HAVE_INTRINSICS_SSE2 && defined(__SSE2__)

#define AV_ZERO128 AV_ZERO128
static av_always_inline void AV_ZERO128(void *d)
{
    __m128i zero = _mm_setzero_si128();
    _mm_store_si128(d, zero);
}

#endif /* HAVE_INTRINSICS_SSE2 && defined(__SSE2__) */

#endif /* AVUTIL_X86_INTREADWRITE_H */

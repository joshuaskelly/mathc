/*
Copyright © 2018 Felipe Ferreira da Silva
Copyright (c) 2025 Joshua Skelton

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
     that you wrote the original software. If you use this software in a
     product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef MATHC_H
#define MATHC_H

#include <stdbool.h>
#include <math.h>

#define MATHC_VERSION_YYYY 2019
#define MATHC_VERSION_MM 02
#define MATHC_VERSION_DD 16
#define MATHC_VERSION_MICRO 0

#if !defined(MATHC_NO_INT)
#define MATHC_USE_INT
#endif
#if !defined(MATHC_NO_FLOATING_POINT)
#define MATHC_USE_FLOATING_POINT
#endif

#if !defined(MATHC_NO_EASING_FUNCTIONS)
#define MATHC_USE_EASING_FUNCTIONS
#endif

#if defined(MATHC_USE_INT)
#include <stdint.h>
#endif
#if defined(MATHC_USE_FLOATING_POINT)
#include <float.h>
#endif

#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4
#define QUAT_SIZE 4
#define MAT2_SIZE 4
#define MAT3_SIZE 9
#define MAT4_SIZE 16

#if defined(MATHC_USE_INT)
#if defined(MATHC_INT_TYPE)
typedef MATHC_INT_TYPE mint_t;
#endif
#if !defined(MATHC_USE_INT8) && !defined(MATHC_USE_INT16) && !defined(MATHC_USE_INT32) && !defined(MATHC_USE_INT64)
#define MATHC_USE_INT32
#endif
#if defined(MATHC_USE_INT8)
#if !defined(MATHC_INT_TYPE)
typedef int8_t mint_t;
#endif
#define MINT_MAX INT8_MAX
#define MINT_MIN INT8_MIN
#endif
#if defined(MATHC_USE_INT16)
#if !defined(MATHC_INT_TYPE)
typedef int16_t mint_t;
#endif
#define MINT_MAX INT16_MAX
#define MINT_MIN INT16_MIN
#endif
#if defined(MATHC_USE_INT32)
#if !defined(MATHC_INT_TYPE)
typedef int32_t mint_t;
#endif
#define MINT_MAX INT32_MAX
#define MINT_MIN INT32_MIN
#endif
#if defined(MATHC_USE_INT64)
#if !defined(MATHC_INT_TYPE)
typedef int64_t mint_t;
#endif
#define MINT_MAX INT64_MAX
#define MINT_MIN INT64_MIN
#endif
#endif

#if defined(MATHC_USE_FLOATING_POINT)
#if defined(MATHC_FLOATING_POINT_TYPE)
typedef MATHC_FLOATING_POINT_TYPE mfloat_t;
#endif
#if !defined(MATHC_USE_SINGLE_FLOATING_POINT) && !defined(MATHC_USE_DOUBLE_FLOATING_POINT)
#define MATHC_USE_SINGLE_FLOATING_POINT
#endif
#if defined(MATHC_USE_SINGLE_FLOATING_POINT)
#if !defined(MATHC_FLOATING_POINT_TYPE)
typedef float mfloat_t;
#endif
#define MPI 3.1415926536f
#define MPI_2 1.5707963268f
#define MPI_4 0.7853981634f
#define MFLT_EPSILON FLT_EPSILON
#define MFABS fabsf
#define MFMIN fminf
#define MFMAX fmaxf
#define MSQRT sqrtf
#define MSIN sinf
#define MCOS cosf
#define MACOS acosf
#define MASIN asinf
#define MTAN tanf
#define MATAN2 atan2f
#define MPOW powf
#define MFLOOR floorf
#define MCEIL ceilf
#define MROUND roundf
#define MFLOAT_C(c) c ## f
#endif
#if defined(MATHC_USE_DOUBLE_FLOATING_POINT)
#if !defined(MATHC_FLOATING_POINT_TYPE)
typedef double mfloat_t;
#endif
#define MPI 3.14159265358979323846
#define MPI_2 1.57079632679489661923
#define MPI_4 0.78539816339744830962
#define MFLT_EPSILON DBL_EPSILON
#define MFABS fabs
#define MFMIN fmin
#define MFMAX fmax
#define MSQRT sqrt
#define MSIN sin
#define MCOS cos
#define MACOS acos
#define MASIN asin
#define MTAN tan
#define MATAN2 atan2
#define MPOW pow
#define MFLOOR floor
#define MCEIL ceil
#define MROUND round
#define MFLOAT_C(c) c
#endif
#endif

#if defined(MATHC_USE_INT)
mint_t clampi(mint_t value, mint_t min, mint_t max);
#endif

#if defined(MATHC_USE_FLOATING_POINT)
#define MRADIANS(degrees) (degrees * MPI / MFLOAT_C(180.0))
#define MDEGREES(radians) (radians * MFLOAT_C(180.0) / MPI)
bool nearly_equal(mfloat_t a, mfloat_t b, mfloat_t epsilon);
mfloat_t to_radians(mfloat_t degrees);
mfloat_t to_degrees(mfloat_t radians);
mfloat_t clampf(mfloat_t value, mfloat_t min, mfloat_t max);
#endif

#if defined(MATHC_USE_INT)
bool vec2i_is_zero(mint_t *v0);
bool vec2i_is_equal(mint_t *v0, mint_t *v1);
mint_t *vec2i(mint_t *result, mint_t x, mint_t y);
mint_t *vec2i_assign(mint_t *result, mint_t *v0);
#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec2i_assign_vec2(mint_t *result, mfloat_t *v0);
#endif
mint_t *vec2i_zero(mint_t *result);
mint_t *vec2i_one(mint_t *result);
mint_t *vec2i_sign(mint_t *result, mint_t *v0);
mint_t *vec2i_add(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_add_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec2i_subtract(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_subtract_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec2i_multiply(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_multiply_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec2i_divide(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_divide_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec2i_snap(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_snap_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec2i_negative(mint_t *result, mint_t *v0);
mint_t *vec2i_abs(mint_t *result, mint_t *v0);
mint_t *vec2i_max(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_min(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec2i_clamp(mint_t *result, mint_t *v0, mint_t *v1, mint_t *v2);
mint_t *vec2i_tangent(mint_t *result, mint_t *v0);
bool vec3i_is_zero(mint_t *v0);
bool vec3i_is_equal(mint_t *v0, mint_t *v1);
mint_t *vec3i(mint_t *result, mint_t x, mint_t y, mint_t z);
mint_t *vec3i_assign(mint_t *result, mint_t *v0);
#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec3i_assign_vec3(mint_t *result, mfloat_t *v0);
#endif
mint_t *vec3i_zero(mint_t *result);
mint_t *vec3i_one(mint_t *result);
mint_t *vec3i_sign(mint_t *result, mint_t *v0);
mint_t *vec3i_add(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_add_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec3i_subtract(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_subtract_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec3i_multiply(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_multiply_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec3i_divide(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_divide_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec3i_snap(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_snap_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec3i_cross(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_negative(mint_t *result, mint_t *v0);
mint_t *vec3i_abs(mint_t *result, mint_t *v0);
mint_t *vec3i_max(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_min(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec3i_clamp(mint_t *result, mint_t *v0, mint_t *v1, mint_t *v2);
bool vec4i_is_zero(mint_t *v0);
bool vec4i_is_equal(mint_t *v0, mint_t *v1);
mint_t *vec4i(mint_t *result, mint_t x, mint_t y, mint_t z, mint_t w);
mint_t *vec4i_assign(mint_t *result, mint_t *v0);
#if defined(MATHC_USE_FLOATING_POINT)
mint_t *vec4i_assign_vec4(mint_t *result, mfloat_t *v0);
#endif
mint_t *vec4i_zero(mint_t *result);
mint_t *vec4i_one(mint_t *result);
mint_t *vec4i_sign(mint_t *result, mint_t *v0);
mint_t *vec4i_add(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_add_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec4i_subtract(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_subtract_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec4i_multiply(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_multiply_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec4i_divide(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_divide_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec4i_snap(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_snap_i(mint_t *result, mint_t *v0, mint_t i);
mint_t *vec4i_negative(mint_t *result, mint_t *v0);
mint_t *vec4i_abs(mint_t *result, mint_t *v0);
mint_t *vec4i_max(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_min(mint_t *result, mint_t *v0, mint_t *v1);
mint_t *vec4i_clamp(mint_t *result, mint_t *v0, mint_t *v1, mint_t *v2);
#endif
#if defined(MATHC_USE_FLOATING_POINT)
bool vec2_is_zero(mfloat_t *v0);
bool vec2_is_equal(mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2(mfloat_t *result, mfloat_t x, mfloat_t y);
mfloat_t *vec2_assign(mfloat_t *result, mfloat_t *v0);
#if defined(MATHC_USE_INT)
mfloat_t *vec2_assign_vec2i(mfloat_t *result, mint_t *v0);
#endif
mfloat_t *vec2_zero(mfloat_t *result);
mfloat_t *vec2_one(mfloat_t *result);
mfloat_t *vec2_sign(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_add(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_add_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec2_subtract(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_subtract_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec2_multiply(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_multiply_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec2_multiply_mat2(mfloat_t *result, mfloat_t *v0, mfloat_t *m0);
mfloat_t *vec2_divide(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_divide_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec2_snap(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_snap_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec2_negative(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_abs(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_floor(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_ceil(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_round(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_max(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_min(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_clamp(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2);
mfloat_t *vec2_normalize(mfloat_t *result, mfloat_t *v0);
mfloat_t vec2_dot(mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_project(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec2_slide(mfloat_t *result, mfloat_t *v0, mfloat_t *normal);
mfloat_t *vec2_reflect(mfloat_t *result, mfloat_t *v0, mfloat_t *normal);
mfloat_t *vec2_tangent(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec2_rotate(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec2_lerp(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t f);
mfloat_t *vec2_bezier3(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2, mfloat_t f);
mfloat_t *vec2_bezier4(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2, mfloat_t *v3, mfloat_t f);
mfloat_t vec2_angle(mfloat_t *v0);
mfloat_t vec2_length(mfloat_t *v0);
mfloat_t vec2_length_squared(mfloat_t *v0);
mfloat_t vec2_distance(mfloat_t *v0, mfloat_t *v1);
mfloat_t vec2_distance_squared(mfloat_t *v0, mfloat_t *v1);
bool vec2_linear_independent(mfloat_t *v0, mfloat_t *v1);
mfloat_t** vec2_orthonormalization(mfloat_t result[2][2], mfloat_t basis[2][2]);
bool vec3_is_zero(mfloat_t *v0);
bool vec3_is_equal(mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z);
mfloat_t *vec3_assign(mfloat_t *result, mfloat_t *v0);
#if defined(MATHC_USE_INT)
mfloat_t *vec3_assign_vec3i(mfloat_t *result, mint_t *v0);
#endif
mfloat_t *vec3_zero(mfloat_t *result);
mfloat_t *vec3_one(mfloat_t *result);
mfloat_t *vec3_sign(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec3_add(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_add_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec3_subtract(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_subtract_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec3_multiply(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_multiply_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec3_multiply_mat3(mfloat_t *result, mfloat_t *v0, mfloat_t *m0);
mfloat_t *vec3_divide(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_divide_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec3_snap(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_snap_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec3_negative(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec3_abs(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec3_floor(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec3_ceil(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec3_round(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec3_max(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_min(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_clamp(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2);
mfloat_t *vec3_cross(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_normalize(mfloat_t *result, mfloat_t *v0);
mfloat_t vec3_dot(mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_project(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec3_slide(mfloat_t *result, mfloat_t *v0, mfloat_t *normal);
mfloat_t *vec3_reflect(mfloat_t *result, mfloat_t *v0, mfloat_t *normal);
mfloat_t *vec3_rotate(mfloat_t *result, mfloat_t *v0, mfloat_t *ra, mfloat_t f);
mfloat_t *vec3_lerp(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t f);
mfloat_t *vec3_bezier3(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2, mfloat_t f);
mfloat_t *vec3_bezier4(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2, mfloat_t *v3, mfloat_t f);
mfloat_t vec3_length(mfloat_t *v0);
mfloat_t vec3_length_squared(mfloat_t *v0);
mfloat_t vec3_distance(mfloat_t *v0, mfloat_t *v1);
mfloat_t vec3_distance_squared(mfloat_t *v0, mfloat_t *v1);
bool vec3_linear_independent(mfloat_t *v0, mfloat_t *v1, mfloat_t *v2);
mfloat_t** vec3_orthonormalization(mfloat_t result[3][3], mfloat_t basis[3][3]);
bool vec4_is_zero(mfloat_t *v0);
bool vec4_is_equal(mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w);
mfloat_t *vec4_assign(mfloat_t *result, mfloat_t *v0);
#if defined(MATHC_USE_INT)
mfloat_t *vec4_assign_vec4i(mfloat_t *result, mint_t *v0);
#endif
mfloat_t *vec4_zero(mfloat_t *result);
mfloat_t *vec4_one(mfloat_t *result);
mfloat_t *vec4_sign(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_add(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_add_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec4_subtract(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_subtract_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec4_multiply(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_multiply_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec4_multiply_mat4(mfloat_t *result, mfloat_t *v0, mfloat_t *m0);
mfloat_t *vec4_divide(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_divide_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec4_snap(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_snap_f(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *vec4_negative(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_abs(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_floor(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_ceil(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_round(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_max(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_min(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *vec4_clamp(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t *v2);
mfloat_t *vec4_normalize(mfloat_t *result, mfloat_t *v0);
mfloat_t *vec4_lerp(mfloat_t *result, mfloat_t *v0, mfloat_t *v1, mfloat_t f);
bool quat_is_zero(mfloat_t *q0);
bool quat_is_equal(mfloat_t *q0, mfloat_t *q1);
mfloat_t *quat(mfloat_t *result, mfloat_t x, mfloat_t y, mfloat_t z, mfloat_t w);
mfloat_t *quat_assign(mfloat_t *result, mfloat_t *q0);
mfloat_t *quat_zero(mfloat_t *result);
mfloat_t *quat_null(mfloat_t *result);
mfloat_t *quat_multiply(mfloat_t *result, mfloat_t *q0, mfloat_t *q1);
mfloat_t *quat_multiply_f(mfloat_t *result, mfloat_t *q0, mfloat_t f);
mfloat_t *quat_divide(mfloat_t *result, mfloat_t *q0, mfloat_t *q1);
mfloat_t *quat_divide_f(mfloat_t *result, mfloat_t *q0, mfloat_t f);
mfloat_t *quat_negative(mfloat_t *result, mfloat_t *q0);
mfloat_t *quat_conjugate(mfloat_t *result, mfloat_t *q0);
mfloat_t *quat_inverse(mfloat_t *result, mfloat_t *q0);
mfloat_t *quat_normalize(mfloat_t *result, mfloat_t *q0);
mfloat_t quat_dot(mfloat_t *q0, mfloat_t *q1);
mfloat_t *quat_power(mfloat_t *result, mfloat_t *q0, mfloat_t exponent);
mfloat_t *quat_from_axis_angle(mfloat_t *result, mfloat_t *v0, mfloat_t angle);
mfloat_t *quat_from_vec3(mfloat_t *result, mfloat_t *v0, mfloat_t *v1);
mfloat_t *quat_from_mat4(mfloat_t *result, mfloat_t *m0);
mfloat_t *quat_lerp(mfloat_t *result, mfloat_t *q0, mfloat_t *q1, mfloat_t f);
mfloat_t *quat_slerp(mfloat_t *result, mfloat_t *q0, mfloat_t *q1, mfloat_t f);
mfloat_t quat_length(mfloat_t *q0);
mfloat_t quat_length_squared(mfloat_t *q0);
mfloat_t quat_angle(mfloat_t *q0, mfloat_t *q1);
mfloat_t *mat2(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m21, mfloat_t m22);
mfloat_t *mat2_zero(mfloat_t *result);
mfloat_t *mat2_identity(mfloat_t *result);
mfloat_t mat2_determinant(mfloat_t *m0);
mfloat_t *mat2_assign(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat2_negative(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat2_transpose(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat2_cofactor(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat2_adjugate(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat2_multiply(mfloat_t *result, mfloat_t *m0, mfloat_t *m1);
mfloat_t *mat2_multiply_f(mfloat_t *result, mfloat_t *m0, mfloat_t f);
mfloat_t *mat2_inverse(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat2_scaling(mfloat_t *result, mfloat_t *v0);
mfloat_t *mat2_scale(mfloat_t *result, mfloat_t *m0, mfloat_t *v0);
mfloat_t *mat2_rotation_z(mfloat_t *result, mfloat_t f);
mfloat_t *mat2_lerp(mfloat_t *result, mfloat_t *m0, mfloat_t *m1, mfloat_t f);
mfloat_t *mat3(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m31, mfloat_t m32, mfloat_t m33);
mfloat_t *mat3_zero(mfloat_t *result);
mfloat_t *mat3_identity(mfloat_t *result);
mfloat_t mat3_determinant(mfloat_t *m0);
mfloat_t *mat3_assign(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat3_negative(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat3_transpose(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat3_cofactor(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat3_multiply(mfloat_t *result, mfloat_t *m0, mfloat_t *m1);
mfloat_t *mat3_multiply_f(mfloat_t *result, mfloat_t *m0, mfloat_t f);
mfloat_t *mat3_inverse(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat3_scaling(mfloat_t *result, mfloat_t *v0);
mfloat_t *mat3_scale(mfloat_t *result, mfloat_t *m0, mfloat_t *v0);
mfloat_t *mat3_rotation_x(mfloat_t *result, mfloat_t f);
mfloat_t *mat3_rotation_y(mfloat_t *result, mfloat_t f);
mfloat_t *mat3_rotation_z(mfloat_t *result, mfloat_t f);
mfloat_t *mat3_rotation_axis(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *mat3_rotation_quat(mfloat_t *result, mfloat_t *q0);
mfloat_t *mat3_lerp(mfloat_t *result, mfloat_t *m0, mfloat_t *m1, mfloat_t f);
mfloat_t *mat4(mfloat_t *result, mfloat_t m11, mfloat_t m12, mfloat_t m13, mfloat_t m14, mfloat_t m21, mfloat_t m22, mfloat_t m23, mfloat_t m24, mfloat_t m31, mfloat_t m32, mfloat_t m33, mfloat_t m34, mfloat_t m41, mfloat_t m42, mfloat_t m43, mfloat_t m44);
mfloat_t *mat4_zero(mfloat_t *result);
mfloat_t *mat4_identity(mfloat_t *result);
mfloat_t mat4_determinant(mfloat_t *m0);
mfloat_t *mat4_assign(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat4_negative(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat4_transpose(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat4_cofactor(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat4_rotation_x(mfloat_t *result, mfloat_t f);
mfloat_t *mat4_rotation_y(mfloat_t *result, mfloat_t f);
mfloat_t *mat4_rotation_z(mfloat_t *result, mfloat_t f);
mfloat_t *mat4_rotation_axis(mfloat_t *result, mfloat_t *v0, mfloat_t f);
mfloat_t *mat4_rotation_quat(mfloat_t *result, mfloat_t *q0);
mfloat_t *mat4_translation(mfloat_t *result, mfloat_t *m0, mfloat_t *v0);
mfloat_t *mat4_translate(mfloat_t *result, mfloat_t *m0, mfloat_t *v0);
mfloat_t *mat4_scaling(mfloat_t *result, mfloat_t *m0, mfloat_t *v0);
mfloat_t *mat4_scale(mfloat_t *result, mfloat_t *m0, mfloat_t *v0);
mfloat_t *mat4_multiply(mfloat_t *result, mfloat_t *m0, mfloat_t *m1);
mfloat_t *mat4_multiply_f(mfloat_t *result, mfloat_t *m0, mfloat_t f);
mfloat_t *mat4_inverse(mfloat_t *result, mfloat_t *m0);
mfloat_t *mat4_lerp(mfloat_t *result, mfloat_t *m0, mfloat_t *m1, mfloat_t f);
mfloat_t *mat4_look_at(mfloat_t *result, mfloat_t *position, mfloat_t *target, mfloat_t *up);
mfloat_t *mat4_ortho(mfloat_t *result, mfloat_t l, mfloat_t r, mfloat_t b, mfloat_t t, mfloat_t n, mfloat_t f);
mfloat_t *mat4_perspective(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n, mfloat_t f);
mfloat_t *mat4_perspective_fov(mfloat_t *result, mfloat_t fov, mfloat_t w, mfloat_t h, mfloat_t n, mfloat_t f);
mfloat_t *mat4_perspective_infinite(mfloat_t *result, mfloat_t fov_y, mfloat_t aspect, mfloat_t n);
#endif

#if defined(MATHC_USE_FLOATING_POINT) && defined(MATHC_USE_EASING_FUNCTIONS)
mfloat_t quadratic_ease_out(mfloat_t f);
mfloat_t quadratic_ease_in(mfloat_t f);
mfloat_t quadratic_ease_in_out(mfloat_t f);
mfloat_t cubic_ease_out(mfloat_t f);
mfloat_t cubic_ease_in(mfloat_t f);
mfloat_t cubic_ease_in_out(mfloat_t f);
mfloat_t quartic_ease_out(mfloat_t f);
mfloat_t quartic_ease_in(mfloat_t f);
mfloat_t quartic_ease_in_out(mfloat_t f);
mfloat_t quintic_ease_out(mfloat_t f);
mfloat_t quintic_ease_in(mfloat_t f);
mfloat_t quintic_ease_in_out(mfloat_t f);
mfloat_t sine_ease_out(mfloat_t f);
mfloat_t sine_ease_in(mfloat_t f);
mfloat_t sine_ease_in_out(mfloat_t f);
mfloat_t circular_ease_out(mfloat_t f);
mfloat_t circular_ease_in(mfloat_t f);
mfloat_t circular_ease_in_out(mfloat_t f);
mfloat_t exponential_ease_out(mfloat_t f);
mfloat_t exponential_ease_in(mfloat_t f);
mfloat_t exponential_ease_in_out(mfloat_t f);
mfloat_t elastic_ease_out(mfloat_t f);
mfloat_t elastic_ease_in(mfloat_t f);
mfloat_t elastic_ease_in_out(mfloat_t f);
mfloat_t back_ease_out(mfloat_t f);
mfloat_t back_ease_in(mfloat_t f);
mfloat_t back_ease_in_out(mfloat_t f);
mfloat_t bounce_ease_out(mfloat_t f);
mfloat_t bounce_ease_in(mfloat_t f);
mfloat_t bounce_ease_in_out(mfloat_t f);
#endif

#endif

#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdio.h>

typedef struct {
	double e[3];
} vec3;

typedef vec3 point3;

// constuctors functions
vec3 vec3_create(double e0, double e1, double e2);
vec3 vec3_create_zero();

// accessor's functions
double vec3_x(const vec3* v);
double vec3_y(const vec3* v);
double vec3_z(const vec3* v);

// negation functions
vec3 vec3_negate(const vec3* v);

// indexing functions
double vec3_get(const vec3* v, int i);
void vec3_set(vec3* v, int i, double value);

// compound assignment operations functions
void vec3_add_assign(vec3* u, const vec3* v);
void vec3_mul_assign(vec3* v, double t);
void vec3_div_assign(vec3* v, double t);

// length functions
double vec3_length(const vec3* v);
double vec3_length_squared(const vec3* v);

// vector utility functions
void vec3_print(const vec3* v);

vec3 vec3_add(const vec3* u, const vec3* v);
vec3 vec3_sub(const vec3* u, const vec3* v);
vec3 vec3_mul_vec(const vec3* u, const vec3* v);

vec3 vec3_mul_scalar(double t, const vec3* v);
vec3 vec3_div_scalar(const vec3* v, double t);

double vec3_dot(const vec3* u, const vec3* v);
vec3 vec3_cross(const vec3* u, const vec3* v);
vec3 vec3_unit_vector(const vec3* v);


#endif

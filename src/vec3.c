#include <vec3.h>

// constuctors functions
vec3 vec3_create(double e0, double e1, double e2) {
	vec3 v;
	v.e[0] = e0;
	v.e[1] = e1;
	v.e[2] = e2;
	return v;
}
vec3 vec3_create_zero() {
	return vec3_create(0, 0, 0);
}

// accessor's functions
double vec3_x(const vec3* v) {
	return v->e[0];
}
double vec3_y(const vec3* v) {
	return v->e[1];
}
double vec3_z(const vec3* v) {
	return v->e[2];
}

// negation functions
vec3 vec3_negate(const vec3* v) {
	return vec3_create(-v->e[0], -v->e[1], -v->e[2]);
}

// indexing functions
double vec3_get(const vec3* v, int i) {
	return v->e[i];
}
void vec3_set(vec3* v, int i, double value) {
	v->e[i] = value;
}

// compound assignment operations functions
void vec3_add_assign(vec3* u, const vec3* v) {
	u->e[0] += v->e[0];
	u->e[1] += v->e[1];
	u->e[2] += v->e[2];
}
void vec3_mul_assign(vec3* v, double t) {
	v->e[0] *= t;
	v->e[1] *= t;
	v->e[2] *= t;
}
void vec3_div_assign(vec3* v, double t) {
	vec3_mul_assign(v, 1.0 / t);
}

// length functions
double vec3_length(const vec3* v) {
	return sqrt(vec3_length_squared(v));
}
double vec3_length_squared(const vec3* v) {
	return v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[1];
}

// vector utility functions
void vec3_print(const vec3* v) {
	printf("%f %f %f\n", v->e[0], v->e[1], v->e[2]);
}

vec3 vec3_add(const vec3* u, const vec3* v) {
	return vec3_create(u->e[0] + v->e[0], u->e[1] + v->e[1], u->e[2] + v->e[2]);
};
vec3 vec3_sub(const vec3* u, const vec3* v) {
	return vec3_create(u->e[0] - v->e[0], u->e[1] - v->e[1], u->e[2] - v->e[2]);
}
vec3 vec3_mul_vec(const vec3* u, const vec3* v) {
	return vec3_create(u->e[0] * v->e[0], u->e[1] * v->e[1], u->e[2] * v->e[2]);
}

vec3 vec3_mul_scaler(double t, const vec3* v) {
	return vec3_create(t * v->e[0],t * v->e[0], t * v->e[0]);
}
vec3 vec3_div_scaler(double t, const vec3* v) {
	return vec3_mul_scaler(1.0 / t, v);
}

double vec3_dot(const vec3* u, const vec3* v) {
	return u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2];
}
vec3 vec3_cross(const vec3* u, const vec3* v) {
	return vec3_create(
		u->e[1] * v->e[2] - u->e[2] * v->e[1],
		u->e[2] * v->e[0] - u->e[0] * v->e[2],
		u->e[0] * v->e[1] - u->e[1] * v->e[0]
	);
}
vec3 vec3_unit_vector(const vec3* v) {
	return vec3_div_scaler(vec3_length(v), v);
}

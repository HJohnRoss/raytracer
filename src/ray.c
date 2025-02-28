#include <ray.h>

// constuctor functions
ray ray_create(const point3* orig, const vec3* direction) {
	ray r;
	r.origin = *orig;
	r.direction = *direction;
	return r;
}

// assessor
point3 ray_origin(const ray* r) {
	return r->origin;
}
point3 ray_direction(const ray* r) {
	return r->direction;
}

// function to compute the point at parameter t along the ray
point3 ray_at(const ray* r, double t) {
	vec3 temp = vec3_mul_scalar(t, &r->direction);
	return vec3_add(&r->origin, &temp);
}

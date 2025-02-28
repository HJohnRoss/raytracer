#ifndef RAY_H
#define RAY_H

#include <vec3.h>


typedef struct {
	point3 origin;
	vec3 direction;
} ray;

// constuctor functions
ray ray_create(const point3* origin, const vec3* direction);

// assessor
point3 ray_origin(const ray* r);
point3 ray_direction(const ray* r);

// function to compute the point at parameter t along the ray
point3 ray_at(const ray* r, double t);


#endif

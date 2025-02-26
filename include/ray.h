#ifndef RAY_H
#define RAY_H

#include <vec3.h>

typedef vec3 point3;

typedef struct {
	point3 orig;
	vec3 dir;
} ray;

#endif

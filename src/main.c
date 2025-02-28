#include <stdio.h>

#include <vec3.h>
#include <color.h>
#include <ray.h>

color ray_color(const ray* r) {
	// Compute the unit direction vector of the ray
	vec3 unit_direction = vec3_unit_vector(&r->direction);

	// Compute the blending factor 'a' based on the y-component of the unit direction
	double a = 0.5 * (vec3_y(&unit_direction) + 1.0);

	// Define two colors for blending
	color white = vec3_create(1.0, 1.0, 1.0); // White color
	color blue = vec3_create(0.5, 0.7, 1.0);  // Light blue color

	// Blend the colors based on the factor 'a'
	vec3 temp1 = vec3_mul_scalar(1.0 - a, &white);
	vec3 temp2 = vec3_mul_scalar(a, &blue);
	return vec3_add(&temp1, &temp2);
}

int main() {
	// Image
	double aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// Calculate the image height, and ensure that it's at least 1.
	int image_height = (int)(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1: image_height;

	// Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / image_height);
    point3 camera_center = vec3_create(0, 0, 0);
	
	// Calculate the vectors across the horizontal and down the vertical viewport edges.
    vec3 viewport_u = vec3_create(viewport_width, 0, 0);
    vec3 viewport_v = vec3_create(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    vec3 pixel_delta_u = vec3_div_scalar(&viewport_u, image_width);
    vec3 pixel_delta_v = vec3_div_scalar(&viewport_v, image_height);

	// Calculate the location of the upper left pixel.
	vec3 temp1 = vec3_create(0, 0, focal_length);
	vec3 temp2 = vec3_sub(&camera_center, &temp1);
	vec3 temp3 = vec3_div_scalar(&viewport_u, 2.0);
	vec3 temp4 = vec3_sub(&temp2, &temp3);
	vec3 temp5 = vec3_div_scalar(&viewport_v, 2.0);
	vec3 viewport_upper_left = vec3_sub(&temp4, &temp5);

	vec3 temp6 = vec3_add(&pixel_delta_u, &pixel_delta_v);
	vec3 temp7 = vec3_mul_scalar(0.5, &temp6);
	vec3 pixel00_loc = vec3_add(&viewport_upper_left, &temp7);

	printf("P3\n%d %d\n255\n", image_height, image_width);

	for(int i = 0; i < image_height; i++) {
		char buff[BUFSIZ];

		setvbuf(stderr, buff, _IOFBF, BUFSIZ);
		fprintf(stderr, "\rScanlines remaining: %d\n", image_height - i);
		fflush(stderr);
		

		for(int j = 0; j < image_width; j++) {
			vec3 temp8 = vec3_mul_scalar(i, &pixel_delta_u);
            vec3 temp9 = vec3_mul_scalar(j, &pixel_delta_v);
            vec3 temp10 = vec3_add(&temp8, &temp9);
            vec3 pixel_center = vec3_add(&pixel00_loc, &temp10);

            vec3 ray_direction = vec3_sub(&pixel_center, &camera_center);
            ray r = ray_create(&camera_center, &ray_direction);

            color pixel_color = ray_color(&r);
            write_color(stdout, &pixel_color);
		}
	}
	char buff[BUFSIZ];

	setvbuf(stderr, buff, _IOFBF, BUFSIZ);
	fprintf(stderr, "\rDone.                   \n");
	fflush(stderr);

	return 0;
}

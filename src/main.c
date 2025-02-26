#include <stdio.h>

#include <vec3.h>
#include <color.h>

int main() {
	int imgHeight = 256;
	int imgWidth = 256;

	printf("P3\n%d %d\n255\n", imgHeight, imgWidth);

	for(int i = 0; i < imgWidth; i++) {
		char buff[BUFSIZ];

		setvbuf(stderr, buff, _IOFBF, BUFSIZ);
		fprintf(stderr, "\rScanlines remaining: %d\n", imgHeight - i);
		fflush(stderr);
		

		for(int j = 0; j < imgHeight; j++) {
			color pixel_color = vec3_create((double)j / (imgHeight - 1), (double)i / (imgWidth - 1), 0);
			write_color(stdout, &pixel_color);
	
		}
	}
	char buff[BUFSIZ];

	setvbuf(stderr, buff, _IOFBF, BUFSIZ);
	fprintf(stderr, "\rDone.                   \n");
	fflush(stderr);

	return 0;
}

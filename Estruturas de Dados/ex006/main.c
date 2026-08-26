// Leitor de imagens PPM (coautoria do professor)

#include <stdio.h>
#include <stdlib.h>

struct image {
	unsigned char*** data;
	int width;
	int height;
};

typedef struct image Image;

static int read_int_ppm(FILE* file, int* value) {
	char token[32];
	if (fscanf(file, "%31s", token) != 1) { return 0; }

	char* end;
	long result = strtol(token, &end, 10);
	if (end == token || *end != '\0') { return 0; }

	*value = (int)result;
	return 1;
}

void load_image_ppm(const char* filename, Image* image) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		printf("Error opening file for reading: %s\n", filename);
		return;
	}

	char magic[3];
	if (fscanf(file, "%2s", magic) != 1 || magic[0] != 'P' || magic[1] != '3') {
		printf("Invalid file format: %s (magic number must be P3)\n", filename);
		fclose(file);
		return;
	}

	if (!read_int_ppm(file, &image->width) || !read_int_ppm(file, &image->height)) {
		printf("Invalid file format: %s (could not read dimensions)\n", filename);
		fclose(file);
		return;
	}

	int max_value;
	if (!read_int_ppm(file, &max_value) || max_value != 255) {
		printf("Invalid file format: %s (maximum pixel value must be 255)\n", filename);
		fclose(file);
		return;
	}

	image->data = (unsigned char***)malloc(image->height * sizeof(unsigned char**));
	for (int i = 0; i < image->height; i++) {
		image->data[i] = (unsigned char**)malloc(image->width * sizeof(unsigned char*));
		for (int j = 0; j < image->width; j++) {
			image->data[i][j] = (unsigned char*)malloc(3 * sizeof(unsigned char));
		}
	}

	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			for (int k = 0; k < 3; k++) {
				int value;
				if (!read_int_ppm(file, &value)) {
					printf("Invalid file format: %s (could not read pixel data)\n", filename);
					fclose(file);
					return;
				}
				image->data[i][j][k] = (unsigned char)value;
			}
		}
	}
	fclose(file);
}


void write_image_to_ppm(const char* filename, const Image* image) {
	FILE* file = fopen(filename, "w");
	if (!file) {
		printf("Error opening file for writing: %s\n", filename);
		return;
	}

	fprintf(file, "P3\n");
	fprintf(file, "%d %d\n", image->width, image->height);
	fprintf(file, "255\n");

	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			fprintf(file, "%d %d %d", image->data[i][j][0], image->data[i][j][1], image->data[i][j][2]);
			if (j < image->width - 1) { fprintf(file, " "); }
			else { fprintf(file, "\n"); }
		}
	}

	fclose(file);
}

int main() {
	Image image;

	load_image_ppm("input.ppm", &image);
	write_image_to_ppm("output.ppm", &image);

	return 0;
}

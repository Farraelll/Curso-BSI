// For more information on PPM (P3) format, see https://paulbourke.net/dataformats/ppm/.
#include <stdio.h>
#include <stdlib.h>

// Struct to represent an image
struct image {
	unsigned char*** data; // 3D matrix of unsigned char representing the image (height x width x 3 for RGB)
	int width; // Width of the image
	int height; // Height of the image
};

// Typedef the struct image to Image
typedef struct image Image;

/**
 * Reads a single whitespace-delimited integer token from the file.
 *
 * @param file  The file to read from.
 * @param value Pointer where the parsed integer is stored on success.
 * @return 1 on success, 0 on read or conversion error.
 */
static int read_int_ppm(FILE* file, int* value) {
	char token[32];
	if (fscanf(file, "%31s", token) != 1) { return 0; }

	char* end;
	long result = strtol(token, &end, 10);
	if (end == token || *end != '\0') { return 0; }

	*value = (int)result;
	return 1;
}

/**
 * Loads an image from a (RGB+P3) PPM file.
 *
 * @param filename The path to the PPM file.
 * @param image    A pointer to the Image structure where the loaded image will be stored.
 */
void load_image_ppm(const char* filename, Image* image) {
	// Open the file for reading
	FILE* file = fopen(filename, "r");
	// Print error message is the file not opened
	if (!file) {
		printf("Error opening file for reading: %s\n", filename);
		return;
	}

	// Read the PPM header
	// * Read the magic number (it must be P3): print error message if the file format is invalid
	char magic[3];
	if (fscanf(file, "%2s", magic) != 1 || magic[0] != 'P' || magic[1] != '3') {
		printf("Invalid file format: %s (magic number must be P3)\n", filename);
		fclose(file);
		return;
	}

	// * Read the width and height of the image
	if (!read_int_ppm(file, &image->width) || !read_int_ppm(file, &image->height)) {
		printf("Invalid file format: %s (could not read dimensions)\n", filename);
		fclose(file);
		return;
	}

	// * Read the maximum pixel value (it must be 255): print error message if the file format is invalid
	int max_value;
	if (!read_int_ppm(file, &max_value) || max_value != 255) {
		printf("Invalid file format: %s (maximum pixel value must be 255)\n", filename);
		fclose(file);
		return;
	}

	// Allocate memory for the image data
	image->data = (unsigned char***)malloc(image->height * sizeof(unsigned char**));
	for (int i = 0; i < image->height; i++) {
		image->data[i] = (unsigned char**)malloc(image->width * sizeof(unsigned char*));
		for (int j = 0; j < image->width; j++) {
			image->data[i][j] = (unsigned char*)malloc(3 * sizeof(unsigned char));
		}
	}

	// Read the image data
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

	// Close the file
	fclose(file);
}

/**
 * Writes the given image to a (RGB+P3) PPM file.
 *
 * @param filename The name of the PPM file to write.
 * @param image The image to write.
 */

void write_image_to_ppm(const char* filename, const Image* image) {
	FILE* file = fopen(filename, "w");
	if (!file) {
		printf("Error opening file for writing: %s\n", filename);
		return;
	}

	// Write the PPM header
	fprintf(file, "P3\n");
	fprintf(file, "%d %d\n", image->width, image->height); // Write the width and height of the image
	fprintf(file, "255\n"); // Write the maximum pixel value

	// Write the image data
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			fprintf(file, "%d %d %d", image->data[i][j][0], image->data[i][j][1], image->data[i][j][2]);
			if (j < image->width - 1) { fprintf(file, " "); }
			else { fprintf(file, "\n"); }
		}
	}

	// Close the file
	fclose(file);
}

int main() {
	// Declare an image structure
	Image image;

	// Load the image from the file "input.ppm"
	load_image_ppm("input.ppm", &image);

	// Write the image to the file "output.ppm"
	write_image_to_ppm("output.ppm", &image);

	return 0;
}

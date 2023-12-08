#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief One pixel data in-place
 */
typedef uint8_t pixel_data;

/**
 * @brief Coordinate of a pixel and dimension of an image
 */
typedef unsigned int pixel_coord;

/**
 * @brief Image for application
 */
typedef struct image {
  pixel_coord width, height;
  pixel_data *data;
} image_t;

/**
 * @brief Image pointer
 */
typedef struct image *image_p;

/**
 * @brief Create image of given width and height
 * @param width,height Dimensions of an image
 * @returns an image
 */
image_p create_image(pixel_coord width, pixel_coord height);

/**
 * @brief Fill all pixels of image with white
 * @param picture picture to fill
 */
void fill_white(image_p picture);

/**
 * @brief Deallocate memory for image
 * @param picture picture
 */
void free_image(image_p picture);

/**
 * @brief Save image in PGM format
 * @param picture picture
 * @param filename name of the file where picture will be saved
 */
int save_pgm(image_p picture, const char *filename);

/**
 * @brief Set the pixel of an image to given color
 *
 * @param picture Image
 * @param x,y Pixel coordinates
 * @param color Color value
 */
void set_pixel(image_p picture, pixel_coord x, pixel_coord y, pixel_data color);

#endif  // _IMAGE_H_

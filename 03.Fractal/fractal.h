#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"

/**
 * @brief Draws sierpinski carpet on the given image (gaps are filled with black)
 *
 * @param picture 
 */
void draw_sierpinski_carpet(image_p picture);

/**
 * @brief Draws mandelbrot set on the given image (gaps are filled with black)
 *
 * @param picture 
 */
void draw_mandelbrot_set(image_p picture);

#endif // _FRACTAL_H_

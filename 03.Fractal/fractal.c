#include <assert.h>
#include <complex.h>

#include "image.h"
#include "fractal.h"


void draw_sc(image_p pic, int x, int y, int size)
{
    if (size < 1)
        return;
    
    size /= 3;

    for (int sector_row = 0; sector_row < 3; sector_row++) {
        for (int sector_col = 0; sector_col < 3; sector_col++) {
            if (sector_row == 1 && sector_col == 1) {
                for (int r = y + size; r < y + 2 * size; r++) {
                    for (int c = x + size; c < x + 2 * size; c++) {
                        set_pixel(pic, c, r, 0);
                    }
                }
            } else {
                draw_sc(pic, x + sector_row * size, y + sector_col * size, size);
            }
        }
    }
}

void draw_sierpinski_carpet(image_p picture)
{
    assert(("Picture is not square", picture->width == picture->height));
    draw_sc(picture, 0, 0, picture->width);
}


void draw_mandelbrot_set(image_p picture)
{
  int max_iter = 1000;
  double scale = 4.0 / picture->width;

  for( pixel_coord y = 0; y < picture->height; y++ ) {
    for( pixel_coord x = 0; x < picture->width; x++ ) {
      double real = (x - picture->width / 2.0) * scale;
      double imag = (y - picture->height / 2.0) * scale;

      complex double c = real + imag * I;
      complex double z = 0;
      int iter;

      for( iter = 0; iter < max_iter && cabs(z) <= 2.0; iter++ ) {
        z = z * z + c;
      }

      set_pixel(picture, x, y, iter % 256);
    }
  }
}

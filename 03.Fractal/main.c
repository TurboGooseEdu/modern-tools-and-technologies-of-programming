#include <stdio.h>

#include "fractal.h"
#include "image.h"

int main() {
  image_p img = create_image(300, 300);

  fill_white(img);
  draw_sierpinski_carpet(img);
  save_pgm(img, "sierpinski.pgm");

  fill_white(img);
  draw_mandelbrot_set(img);
  save_pgm(img, "mandelbrot.pgm");

  free_image(img);

  return 0;
}

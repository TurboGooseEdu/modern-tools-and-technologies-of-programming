#include "image.h"

#include <assert.h>
#include <stdlib.h>

image_p create_image(pixel_coord width, pixel_coord height) {
  image_t *v = malloc(sizeof(image_t));
  v->width = width;
  v->height = height;
  v->data = malloc(sizeof(pixel_data) * width * height);

  return v;
}

void fill_white(image_p picture) {
  pixel_data *p = picture->data;
  for (pixel_coord z = 0; z < picture->height * picture->width; ++z, ++p)
    *p = 255;
}

void free_image(image_p picture) {
  free(picture->data);
  free(picture);
}

int save_pgm(image_p picture, const char *filename) {
  FILE *to = fopen(filename, "w");
  fprintf(to, "P2\n%u %u\n255\n", picture->width, picture->height);

  pixel_data *p = picture->data;
  for (pixel_coord y = 0; y < picture->height; ++y)
    for (pixel_coord x = 0; x < picture->width; ++x)
      fprintf(to, "%u%c", *(p++), x == picture->width - 1 ? '\n' : ' ');

  fclose(to);
  return 0;
}

void set_pixel(image_p picture, pixel_coord x, pixel_coord y,
               pixel_data color) {
  assert(("Out of dimension",
          x >= 0 && y >= 0 && x < picture->width && y < picture->height));
  picture->data[picture->width * y + x] = color;
}

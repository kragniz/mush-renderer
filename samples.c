#include <stdlib.h>

#include "samples.h"


struct color *color_new(const float red, const float green, const float blue) {
    struct color *color = malloc(sizeof(*color));
    color->r = red;
    color->g = green;
    color->b = blue;
    return color;
}

struct samples *samples_new() {
    struct samples *samples = malloc(sizeof(*samples));
    return samples;
}

struct image *image_new(const int w, const int h) {
    struct image *image = malloc(sizeof(*image));

    image->w = w;
    image->h = h;
    image->samples = calloc(w*h, sizeof(image->samples));

    return image;
}

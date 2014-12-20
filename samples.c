#include <stdlib.h>

#include "samples.h"


struct color *color_new(const float red, const float green, const float blue) {
    struct color *color = malloc(sizeof(*color));
    color->r = red;
    color->g = green;
    color->b = blue;
    return color;
}

struct samples *samples_new(const float red, const float green, const float blue) {
    struct samples *samples = malloc(sizeof(*samples));
    samples->color.r = red;
    samples->color.g = green;
    samples->color.b = blue;
    return samples;
}


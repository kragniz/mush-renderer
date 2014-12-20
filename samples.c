#include <stdlib.h>

#include "samples.h"


struct color *color_new(const float r, const float g, const float b) {
    struct color *color = malloc(sizeof(*color));
    color->r = r;
    color->g = g;
    color->b = b;
    return color;
}

struct samples *samples_new(const float r, const float g, const float b) {
    struct samples *samples = malloc(sizeof(*samples));
    samples->color.r = r;
    samples->color.g = g;
    samples->color.b = b;
    return samples;
}


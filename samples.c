#include <stdlib.h>

#include "samples.h"


struct color *new_color(float red, float green, float blue) {
    struct color *color = malloc(sizeof(*color));
    color->r = red;
    color->g = green;
    color->b = blue;
    return color;
}


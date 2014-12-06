#include <stdlib.h>

#include "samples.h"


struct color *color_new(float red, float green, float blue) {
    struct color *color = malloc(sizeof(*color));
    color->r = red;
    color->g = green;
    color->b = blue;
    return color;
}

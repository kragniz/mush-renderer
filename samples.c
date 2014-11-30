#include "samples.h"

struct color {
    float r;
    float g;
    float b;
};

struct sample {
    struct color color;
    struct sample *next;
};

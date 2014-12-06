#ifndef SAMPLES_H
#define SAMPLES_H

struct color {
    float r;
    float g;
    float b;
};

struct samples {
    struct color color;
    struct samples *next;
};

struct color *color_new(float red, float green, float blue);

#endif

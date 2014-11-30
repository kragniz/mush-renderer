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

struct color *new_color(float red, float green, float blue);

#endif

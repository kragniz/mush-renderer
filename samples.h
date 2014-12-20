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

struct color *color_new(const float red, const float green, const float blue);

struct samples *samples_new(const float red, const float green, const float blue);

#endif

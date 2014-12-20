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

struct color *color_new(const float r, const float g, const float b);

struct samples *samples_new(const float r, const float g, const float b);

#endif

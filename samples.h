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

struct image {
    int w;
    int h;
    struct samples *samples;
};

struct color *color_new(const float red, const float green, const float blue);

struct samples *samples_new();

struct image *image_new(const int w, const int h);

#endif

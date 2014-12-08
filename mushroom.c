#include <assert.h>
#include <stdlib.h>

#include "samples.h"

void test_color_new() {
    struct color *color = color_new(24, 32, 64);
    assert(color->r == 24);
    assert(color->g == 32);
    assert(color->b == 64);
}

void test_samples_new() {
    struct samples *samples = samples_new();
    struct color *color = color_new(255, 128, 255);
    samples->color = *color;

    assert(samples->color.r == 255);
    assert(samples->color.g == 128);
}

void test_image_new() {
    struct image *image = image_new(40, 15);
    assert(image->w == 40);
    assert(image->h == 15);
}

int main() {
    test_color_new();
    test_samples_new();
    test_image_new();
    return 0;
}

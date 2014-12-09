#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "samples.h"

void test_color_new() {
    struct color *color = color_new(24, 32, 64);
    assert(color->r == 24);
    assert(color->g == 32);
    assert(color->b == 64);

    free(color);
}

void test_samples_new() {
    struct samples *samples = samples_new(255, 128, 255);

    assert(samples->color.r == 255);
    assert(samples->color.g == 128);

    free(samples);
}

void test_image_new() {
    struct image *image = image_new(40, 15);
    assert(image->w == 40);
    assert(image->h == 15);

    free(image->samples);
    free(image);
}

void test_image_sample() {
    struct image *image = image_new(40, 15);

    assert(image->samples != NULL);

    free(image->samples);
    free(image);
}

int main() {
    puts("running tests...");

    test_color_new();
    test_samples_new();
    test_image_new();
    test_image_sample();

    puts("tests succeeded!");
    return 0;
}

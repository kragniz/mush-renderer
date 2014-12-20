#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "samples.h"
#include "image.h"

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

void test_image_samples() {
    struct image *image = image_new(40, 15);

    struct samples *samples = samples_new(10, 20, 30);
    image->samples[0] = *samples;

    assert(image->samples[0].color.r == 10);

    free(samples);
    free(image->samples);
    free(image);
}

void test_image_to_ppm() {
    struct image *image = image_new(10, 10);

    struct samples *samples = samples_new(10, 20, 30);
    image->samples[0] = *samples;

    FILE *fp = fopen("/tmp/out.ppm", "r");
    image_to_ppm(image, fp);

    fclose(fp);
    free(samples);
    free(image->samples);
    free(image);
}

int main() {
    puts("running tests...");

    test_color_new();
    test_samples_new();
    test_image_new();
    test_image_samples();

    puts("tests succeeded!");
    return 0;
}

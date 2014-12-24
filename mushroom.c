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

void test_image_get_samples() {
    struct image *image = image_new(40, 15);

    struct samples *samples = samples_new(10, 20, 30);
    image->samples[0] = *samples;

    struct samples *s = image_get_samples(image, 0, 0);

    assert(s->color.r == 10);
    assert(s->color.g == 20);
    assert(s->color.b == 30);

    free(s);
    free(samples);
    free(image->samples);
    free(image);
}

void test_image_to_ppm() {
    struct image *image = image_new(5, 5);
    struct samples *samples;
    int x, y;
    for (y=0; y < image->h; y++) {
        for (x=0; x < image->w; x++) {
            samples = samples_new(0, 10, 20);
            image->samples[0] = *samples;
        }
    }

    FILE *fp = fopen("/tmp/out.ppm", "w");

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
    test_image_to_ppm();

    puts("tests succeeded!");
    return 0;
}

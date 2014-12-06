#include <assert.h>

#include "samples.h"

void test_color_new() {
    struct color *color = color_new(24, 32, 64);
    assert(color->r == 24);
    assert(color->g == 32);
    assert(color->b == 64);
}

int main() {
    test_color_new();
    return 0;
}

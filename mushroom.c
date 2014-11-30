#include <assert.h>

#include "samples.h"

void test_new_color() {
    struct color *color = new_color(24, 32, 64);
    assert(color->r == 24);
    assert(color->g == 32);
    assert(color->b == 64);
}

int main() {
    test_new_color();
    return 0;
}

#include "rec.h"
#include <stdio.h>

void Rectangle::setwidth(int w) {
    if (w <= 0) {
        printf("Width cannot be negative or zero. Setting width to 1.\n");
        width = 1;
    } else {
        width = w;
    }
}

void Rectangle::setheight(int h) {
    if (h <= 0) {
        printf("Height cannot be negative or zero. Setting height to 1.\n");
        height = 1;
    } else {
        height = h;
    }
}

Rectangle::Rectangle(int w, int h) {
    setwidth(w);
    setheight(h);
}

Rectangle::Rectangle(int w) {
    setwidth(w);
    setheight(w);
}

Rectangle::Rectangle() {
    setwidth(1);
    setheight(1);
}

int Rectangle::area() {
    return width * height;
}

int Rectangle::perimeter() {
    return 2 * (width + height);
}

void Rectangle::print() {
    printf("Width: %d, Height: %d, Area: %d, Perimeter: %d\n", width, height, area(), perimeter());
}
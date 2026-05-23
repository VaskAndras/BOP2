#include "circ.h"
#include <stdio.h>

void Circle::setRadius(int r) {
    if (r <= 0) {
        printf("Radius cannot be negative or zero. Setting radius to 1.\n");
        radius = 1;
    } else {
        radius = r;
    }
}
Circle::Circle(int r) {
    setRadius(r);
}
Circle::Circle() {
    setRadius(1);
}
int Circle::getRadius() {
    return radius;
}
double Circle::area() {
    return 3.14159 * radius * radius;
}
double Circle::circumference() {
    return 2 * 3.14159 * radius;
}
void Circle::print() {
    printf("Radius: %d, Area: %.2f, Circumference: %.2f\n", radius, area(), circumference());
}   


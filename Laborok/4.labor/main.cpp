#include "rec.h"
#include <stdio.h>
#include "circ.h"

int main() {
    Rectangle r1(5, 3);
    r1.print();
    Rectangle r2(4);
    r2.print();
    Rectangle r3;
    r3.print();
    Circle c1(2);
    c1.print();
    Circle c2;
    c2.print();
    return 0;
}

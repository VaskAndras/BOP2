#ifndef CIRC_H
#define CIRC_H

class Circle{
    int radius;
    
    public:
    Circle(int r);
    Circle();
    void setRadius(int r);
    int getRadius();
    double area();
    double circumference();
    void print();
};
#endif
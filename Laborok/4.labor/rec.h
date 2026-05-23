#ifndef REC_H
#define REC_H

class Rectangle {
    int width;
    int height;

public:
    Rectangle(int w, int h);
    Rectangle(int w);
    Rectangle();

    void setwidth(int w);
    void setheight(int h);
    int area();
    int perimeter();
    void print();
};

#endif
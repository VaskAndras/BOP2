#include <iostream>

class shape{
protected:
float a, b;

public:
shape(float c, float d);
virtual ~shape(){}
virtual float area();

};

float shape::area(){
    return 0.0;
}


shape::shape(float c, float d){
    a=c;
    b=d;
}


class rechtangle : public shape{
public:
float area() override;
rechtangle(float a, float b): shape(a, b){}
};

float rechtangle::area(){
    return a*b;
}

class triangle: public shape{
    public:
    float area()override;
    triangle(float a, float b): shape(a, b){}
};

float triangle::area(){
    return a*b/2;
}

int main() {
    rechtangle r(10, 5);
    triangle t(10, 5);
    
    std::cout << "Teglalap: " << r.area() << std::endl;
    std::cout << "Haromszog: " << t.area() << std::endl;
    
    return 0;
}

#include <iostream>

class vector{
private:
float x,y;
public:
vector();
vector(float a, float b );
~vector(){}
vector operator+(vector b);
vector operator*(float a);

friend vector operator*(float a, vector v);

};

vector::vector(){
    x=0;
    y=0;
}

vector::vector(float a, float b){
    this->x = a;
    this->y = b;
}

vector vector::operator+(vector b){
    vector c;
    c.x= this->x + b.x;
    c.y= this->y + b.y; 
    return c;
}
vector vector::operator*(float a){
    vector d;
    d.x = this->x*a;
    d.y = this->y*a;

}

vector operator*(float a, vector v) {
    vector d;
    d.x = v.x * a;
    d.y = v.y * a;
    return d; // Itt is kell a return!
}


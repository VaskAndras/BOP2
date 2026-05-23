#include "Vector.h"
#include <iostream>
#include <stdexcept>

Vector::Vector(const Vector& theOther)
{
    elementNum = theOther.elementNum;
    pData = new int[elementNum];
    for (unsigned int i = 0; i < elementNum; ++i)
        pData[i] = theOther.pData[i];
}

std::ostream & operator << (std::ostream& os, const Vector& v)
{
    os << "[";
    for (unsigned int i = 0; i < v.elementNum; ++i)
    {
        os << v.pData[i];
        if (i < v.elementNum - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

void Vector::clear()
{
    delete[] pData;
    elementNum = 0;
}

void Vector::erase(unsigned int position){
if (position >= elementNum) return;
for (int i = position; i < elementNum - 1; ++i) {
        pData[i] = pData[i + 1]; 
    }
elementNum--;
}

int& Vector::at(unsigned int position){
if (position >= elementNum) throw std::out_of_range("Index out of range");
return pData[position];
}

const int& Vector::at(unsigned int position)const{
if (position >= elementNum) throw std::out_of_range("Index out of range");
return pData[position];
}


bool Vector::insert(unsigned int position, int element){
    if (position > elementNum) {
        unsigned int newSize = position + 1;
        int* newData = new int[newSize];
        for (unsigned int i = 0; i < elementNum; ++i) {
            newData[i] = pData[i];
        }
        for (unsigned int i = elementNum; i < newSize; ++i) {
            newData[i] = 0; // Fill empty places with 0
        }
        delete[] pData;
        pData = newData;
        elementNum = newSize;
    }
    pData[position] = element;
    return true;
}

const Vector& Vector::operator= (const Vector & theOther){
if (this != &theOther) {
        delete[] pData;
        elementNum = theOther.elementNum;
        pData = new int[elementNum];
        for (unsigned int i = 0; i < elementNum; ++i)
            pData[i] = theOther.pData[i];
    }
    return *this;
}
int & Vector::operator [](unsigned int position){
    if (position >= elementNum) throw std::out_of_range("Index out of range");
    return pData[position];
}

const int & Vector::operator [](unsigned int position)const{
    if (position >= elementNum) throw std::out_of_range("Index out of range");
    return pData[position];
}

void Vector::bubbleSort() {
    for (unsigned int i = 0; i < elementNum - 1; ++i) {
        for (unsigned int j = 0; j < elementNum - i - 1; ++j) {
            if (pData[j] > pData[j + 1]) {
                std::swap(pData[j], pData[j + 1]);
            }
        }
    }
    return;
}



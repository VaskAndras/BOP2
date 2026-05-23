#include "display.h"
#include "equipment.h"
#include <iostream>



Display::Display(int id, double price, int year) : Equipment(id, "Display", price), year(year) {}


Display::Display(int id, int year) : Equipment(id, "Display"), year(year) {}





void Display::print() const{
    std::cout << "Display ID: " << id << ", Price: " << price << ", Year: " << year << std::endl;
}


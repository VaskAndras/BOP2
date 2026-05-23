#include "printer.h"
#include "equipment.h"
#include <iostream>

Printer::Printer(int id, int speed) : Equipment(id, "Printer"), speed(speed) {}



void Printer::print() const {
    std::cout << "Printer ID: " << id << ", Speed: " << speed << " pages per minute" << std::endl;
}   
#include <iostream>
#include "equipment.h"

Equipment::Equipment() : id(0), name("Unknown") {
}
Equipment::Equipment(int id, const std::string& name) : id(id), name(name) {
}
Equipment::Equipment(int id, int price) : id(id), name("Unknown"), price(price
) {}

Equipment::Equipment(int id, const std::string& name, int price) : id(id), name(name), price(price) { }



void Equipment::print() const {
    std::cout << "Equipment ID: " << id << ", Name: " << name << std::endl;
}



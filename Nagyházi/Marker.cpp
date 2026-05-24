#include "Marker.h"
#include <string>
#include <vector>
#include <iostream>


#include "Marker.h"

int Marker::getPosition() const { return position; }
int Marker::getLength() const { return length; }
std::string Marker::getType() const { return type; } 

// Add this at the bottom of Marker.cpp
std::ostream& operator<<(std::ostream& os, const Marker& m) {
    os << "[Marker Type: " << m.getType() << " | HTML: " << m.html_tag << " | Pos: " << m.getPosition() << "]";
    return os;
}
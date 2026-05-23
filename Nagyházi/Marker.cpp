#include "Marker.h"
#include <string>
#include <vector>
#include <iostream>


// Getter methods to access the marker's attributes
int Marker::getPosition() const { return position; }
int Marker::getLength() const { return length; }
std::string Marker::getLength() const { return type; }


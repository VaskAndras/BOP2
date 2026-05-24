#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <iostream>
#include "Marker.h"
#include "converter.h"

class engine {
public:
    std::vector<Marker*> map;
    
    ~engine();
    
    void addMarker(Marker* marker);
    void createmap(std::string text, std::vector<Converter*> converters);
    void checkmap(); 
    
    // Updated: Supports ostream for file writing (defaults to std::cout)
    void print(std::string text, std::ostream& os = std::cout);
};

#endif
#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <iostream>
#include "Marker.h"
#include "converter.h"

/*
This section implements the core functionality of the Markdown engine, which is responsible for processing the input text, identifying markers using the provided converters, and generating the final HTML output.
The engine class maintains a vector of Marker pointers, which represent the identified formatting markers in the text
The createmap function iterates through the input text and uses the converters to identify markers, which are then added to the map vector.
The checkmap function ensures that all markers are properly matched (e.g., every opening tag has a corresponding closing tag) and removes any unmatched markers from the map.
The print function generates the final HTML output by iterating through the map of markers and inserting the appropriate HTML tags into the output string based on the positions of the markers in the original text.
*/

class engine {
public:
    std::vector<Marker*> map;
    
    ~engine();
    
    void addMarker(Marker* marker);
    void createmap(std::string text, std::vector<Converter*> converters);
    void checkmap(); 
    
    void print(std::string text, std::ostream& os = std::cout);
};

#endif
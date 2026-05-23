
#include <string>
#include <vector>
#include <iostream> 
#include <engine.h>

engine::~engine(){
    for(Marker* m: map){
        delete m;
    }
}

void engine::addMarker(Marker* marker) {map.push_back(marker);}

void engine::createmap(std::string text, std::vector<Converter*> converters) {
        // This method will go through the text and use the converters to create markers for any special characters it finds
        for (int i = 0; i < text.size(); i++) {
            for (Converter* converter : converters) {
                // this uses the createMarker method of the converter to check if there is a marker at the current position in the text
                Marker* marker = converter->createMarker(text, i);
                //This is for the nullpointer, because createMarker will return nullptr if there is no marker.
                if (marker != nullptr) {
                    addMarker(marker);
                    // Move the index forward by the length of the marker to avoid checking the same characters again
                    i += marker->getLength() - 1; 
                    break; // If a marker is created, we can stop checking other converters for this position
                }
            }
        }
    }

    void engine::checkmap(std::vector<Converter*> converters) {
        // This method will check the map for any markers that are not properly closed 
        for  (int i = 0; i < map.size(); i++) {
            for (int j = i + 1; j < map.size(); j++) {
                if (map[i]->getType() == converters[j]->type) {
                    converters[j]->form = !converters[j]->form; // Toggle the form to indicate whether we are inside a marker or not
                }
            }
        }
    }

    void engine::print(std::string text) {
        // This method will print the text with the appropriate HTML tags based on the markers in the map
        int currentIndex = 0; // Keep track of the current index in the text
        for (Marker* marker : map) {
            // Print the text before the marker
            std::cout << text.substr(currentIndex, marker->getPosition() - currentIndex);
            // Print the HTML tag for the marker
            std::cout << marker->html_tag;
            // Update the current index to be after the marker
            currentIndex = marker->getPosition() + marker->getLength();
        }
        // Print any remaining text after the last marker
        std::cout << text.substr(currentIndex);
    }
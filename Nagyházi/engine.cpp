#include "engine.h"
#include <algorithm>
#include <map>
#include <iostream>



// Destructor to clean up dynamically allocated markers
engine::~engine(){
    for(Marker* m: map){
        delete m;
    }
}
// Function to add a marker to the map
void engine::addMarker(Marker* marker) {
    map.push_back(marker);
}

// Function to create the map of markers from the input text using the provided converters
void engine::createmap(std::string text, std::vector<Converter*> converters) {
    // Iterate through each character in the input text and use the converters to identify markers
    for (int i = 0; i < text.size(); i++) {
        for (Converter* converter : converters) {
            Marker* marker = converter->createMarker(text, i);
            // If a marker is identified, add it to the map and skip ahead in the text by the length of the marker to avoid reprocessing the same characters.
            if (marker != nullptr) {
                addMarker(marker);
                i += marker->getLength() - 1; 
                break; 
            }
        }
    }
}
// Function to check the map of markers for unmatched tags and remove them
void engine::checkmap() {
    // We use a map to keep track of open tags and a vector to keep track of indices of markers that need to be deleted.
    std::map<std::string, std::vector<int>> open_tags;
    std::vector<int> to_delete;
    // Iterate through the map of markers and check for matching opening and closing tags.
    for (int i = 0; i < map.size(); i++) {
        std::string type = map[i]->getType();
        // If the marker is an ending tag (indicated by "_end"), we check if there is a corresponding opening tag in the open_tags map. If there is, we pop it from the stack; if not, we mark this marker for deletion.
        if (type.length() >= 4 && type.substr(type.length() - 4) == "_end") {
            std::string base_type = type.substr(0, type.length() - 4);

            if (!open_tags[base_type].empty()) {
                open_tags[base_type].pop_back();
            } else {
                to_delete.push_back(i);
            }
        } else {
            open_tags[type].push_back(i);
        }
    }

    // After processing all markers, any remaining open tags in the open_tags map are unmatched and their indices are added to the to_delete vector.
    for (auto const& pair : open_tags) {
        for (int index : pair.second) {
            to_delete.push_back(index);
        }
    }
    // We sort the to_delete vector in reverse order to ensure that we delete markers from the end of the map first, which prevents invalidating the indices of markers that have not yet been deleted.
    std::sort(to_delete.rbegin(), to_delete.rend());
    // Finally, we iterate through the to_delete vector and delete the corresponding markers from the map.
    for (int index : to_delete) {
        delete map[index];
        map.erase(map.begin() + index);
    }
}
// Function to generate the final HTML output by iterating through the map of markers and inserting the appropriate HTML tags into the output string based on the positions of the markers in the original text.
void engine::print(std::string text, std::ostream& os) {
    int currentIndex = 0;
    for (Marker* marker : map) {
        os << text.substr(currentIndex, marker->getPosition() - currentIndex);
        os << marker->html_tag;
        currentIndex = marker->getPosition() + marker->getLength();
    }
    os << text.substr(currentIndex);
}
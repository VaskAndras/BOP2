#include "engine.h"
#include <algorithm>
#include <map>
#include <iostream>

engine::~engine(){
    for(Marker* m: map){
        delete m;
    }
}

void engine::addMarker(Marker* marker) {
    map.push_back(marker);
}

void engine::createmap(std::string text, std::vector<Converter*> converters) {
    for (int i = 0; i < text.size(); i++) {
        for (Converter* converter : converters) {
            Marker* marker = converter->createMarker(text, i);
            if (marker != nullptr) {
                addMarker(marker);
                i += marker->getLength() - 1; 
                break; 
            }
        }
    }
}

void engine::checkmap() {
    std::map<std::string, std::vector<int>> open_tags;
    std::vector<int> to_delete;

    for (int i = 0; i < map.size(); i++) {
        std::string type = map[i]->getType();
        
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

    // C++14 compatible loop (Warning fixed)
    for (auto const& pair : open_tags) {
        for (int index : pair.second) {
            to_delete.push_back(index);
        }
    }

    std::sort(to_delete.rbegin(), to_delete.rend());

    for (int index : to_delete) {
        delete map[index];
        map.erase(map.begin() + index);
    }
}

void engine::print(std::string text, std::ostream& os) {
    int currentIndex = 0;
    for (Marker* marker : map) {
        os << text.substr(currentIndex, marker->getPosition() - currentIndex);
        os << marker->html_tag;
        currentIndex = marker->getPosition() + marker->getLength();
    }
    os << text.substr(currentIndex);
}
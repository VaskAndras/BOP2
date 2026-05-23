#ifndef ENGINE_H
#define ENGINE_H

class engine {
public:
    std::vector<Marker*> map; // A vector to store pointers to Marker objects
    
    ~engine();
    
    // Method to add a marker to the map
    void addMarker(Marker* marker);

    // Method 
    void createmap(std::string text, std::vector<Converter*> converters);

    void checkmap(std::vector<Converter*> converters);

    void print(std::string text);
    

}

#endif
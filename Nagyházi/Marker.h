#ifndef MARKER_H
#define MARKER_H
class Marker {
public:
    // basic attributes of a marker: its position in the text, its length, and its type (e.g., "italic", "bold")
    int position;
    int length;
    std::string type;
    std::string html_tag;

    virtual ~Marker() = default;
    
    // Constructor to initialize the marker with its position, length, and type
    Marker(int pos, int len, std::string t, std::string html) : position(pos), length(len), type(t), html_tag(html) {}

    // Getter methods to access the marker's attributes
    int getPosition() const;
    int getLength() const;
    std::string getType() const;

};

class Italic : public Marker {
public:
    // Constructor to initialize an italic marker with its position and length, and set the type to "italic"
    Italic(int pos, int len) : Marker(pos, len, "italic", "<i>") {}
}; 

class italic_end : public Marker {
public:
    // Constructor to initialize an italic end marker with its position and length, and set the type
    // to "italic_end"
    italic_end(int pos, int len) : Marker(pos, len, "italic_end", "</i>"){}
};
#endif
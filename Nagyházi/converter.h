#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include "Marker.h"

/*
The goal of the Converter class and its derived classes is to define a common interface for creating markers based on the input text. 
Each specific converter (e.g., for bold, italic, headers) will implement the createMarker function to identify the appropriate markers in the text and return them as Marker objects. 
This design allows for easy extensibility and separation of concerns, as each converter is responsible for recognizing its specific syntax in the Markdown text.
*/

class Converter {
public: 
// The 'form' attribute indicates whether this converter is for a starting marker (false) or an ending marker (true).
    std::string type; 
    bool form;
protected:
// Constructor to initialize the converter with its type and form
    Converter(bool f, std::string t);
    bool isstart(std::string test, int pos);
    bool isend(std::string test, int pos);
public:
// Pure virtual function to create a marker based on the input text and position.
// Each derived converter will implement this function to return the appropriate Marker object when it recognizes its syntax in the text.
    virtual Marker* createMarker(std::string text, int pos) = 0;
    virtual ~Converter() = default;
};
class Italic_beg_conv : public Converter {
public:
    Italic_beg_conv();
    Marker* createMarker(std::string text, int pos) override;
};

class Italic_end_conv : public Converter {
public:
    Italic_end_conv();
    Marker* createMarker(std::string text, int pos) override;
};
class Bold_beg_conv : public Converter {
public: Bold_beg_conv(); Marker* createMarker(std::string text, int pos) override;
};
class Bold_end_conv : public Converter {
public: Bold_end_conv(); Marker* createMarker(std::string text, int pos) override;
};

class Strike_beg_conv : public Converter {
public: Strike_beg_conv(); Marker* createMarker(std::string text, int pos) override;
};
class Strike_end_conv : public Converter {
public: Strike_end_conv(); Marker* createMarker(std::string text, int pos) override;
};

class H1_beg_conv : public Converter {
public: H1_beg_conv(); Marker* createMarker(std::string text, int pos) override;
};
class H1_end_conv : public Converter {
public: H1_end_conv(); Marker* createMarker(std::string text, int pos) override;
};

class H2_beg_conv : public Converter {
public: H2_beg_conv(); Marker* createMarker(std::string text, int pos) override;
};
class H2_end_conv : public Converter {
public: H2_end_conv(); Marker* createMarker(std::string text, int pos) override;
};

class H3_beg_conv : public Converter {
public: H3_beg_conv(); Marker* createMarker(std::string text, int pos) override;
};
class H3_end_conv : public Converter {
public: H3_end_conv(); Marker* createMarker(std::string text, int pos) override;
};

#endif 


#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include "Marker.h"

class Converter {
public: 
    std::string type; 
    bool form;
protected:
    Converter(bool f, std::string t);
    bool isstart(std::string test, int pos);
    bool isend(std::string test, int pos);
public:
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
#endif 


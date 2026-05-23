#include "converter.h"

Converter::Converter(bool f, std::string t) : form(f), type(t) {}

bool Converter::isstart(std::string test, int pos){
    return (pos == 0 || test[pos - 1] == ' ' || test[pos - 1] == '\n');
}
bool Converter::isend(std::string test, int pos){
    return (pos == test.size() - 1 || test[pos + 1] == ' ' || test[pos + 1] == '\n');
}

Italic_beg_conv::Italic_beg_conv() : Converter(false, "Italic_start") {}
Marker* Italic_beg_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '*' && isstart(text, pos)) {
        return new ItalicStartMarker(pos); 
    }
    return nullptr;
}

Italic_end_conv::Italic_end_conv() : Converter(false, "Italic_end") {}
Marker* Italic_end_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '*' && isend(text, pos)) {
        return new ItalicEndMarker(pos);
    }
    return nullptr;
}
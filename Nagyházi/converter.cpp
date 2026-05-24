#include "converter.h"
#include <cctype> // For recognizing punctuation marks!

Converter::Converter(bool f, std::string t) : form(f), type(t) {}

bool Converter::isstart(std::string test, int pos){
    return (pos == 0 || test[pos - 1] == ' ' || test[pos - 1] == '\n');
}

bool Converter::isend(std::string test, int pos){
    // Updated: Now recognizes punctuation marks (e.g., comma, period) at the end of words!
    return (pos == test.size() - 1 || test[pos + 1] == ' ' || test[pos + 1] == '\n' || std::ispunct(test[pos + 1]));
}

Bold_beg_conv::Bold_beg_conv() : Converter(false, "Bold_start") {}
Marker* Bold_beg_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 1 && text[pos] == '*' && text[pos+1] == '*' && isstart(text, pos)) {
        return new Bold(pos, 2); 
    }
    return nullptr;
}

Bold_end_conv::Bold_end_conv() : Converter(false, "Bold_end") {}
Marker* Bold_end_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 1 && text[pos] == '*' && text[pos+1] == '*' && isend(text, pos + 1)) {
        return new bold_end(pos, 2);
    }
    return nullptr;
}

Strike_beg_conv::Strike_beg_conv() : Converter(false, "Strike_start") {}
Marker* Strike_beg_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 1 && text[pos] == '~' && text[pos+1] == '~' && isstart(text, pos)) {
        return new Strike(pos, 2); 
    }
    return nullptr;
}

Strike_end_conv::Strike_end_conv() : Converter(false, "Strike_end") {}
Marker* Strike_end_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 1 && text[pos] == '~' && text[pos+1] == '~' && isend(text, pos + 1)) {
        return new strike_end(pos, 2);
    }
    return nullptr;
}

H1_beg_conv::H1_beg_conv() : Converter(false, "H1_start") {}
Marker* H1_beg_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 1 && text[pos] == '#' && text[pos+1] == ' ' && (pos == 0 || text[pos-1] == '\n')) {
        return new H1(pos, 2); 
    }
    return nullptr;
}

H1_end_conv::H1_end_conv() : Converter(false, "H1_end") {}
Marker* H1_end_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '\n') {
        return new h1_end(pos, 1);
    }
    return nullptr;
}

Italic_beg_conv::Italic_beg_conv() : Converter(false, "Italic_start") {}
Marker* Italic_beg_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '*' && isstart(text, pos)) {
        return new Italic(pos, 1); 
    }
    return nullptr;
}

Italic_end_conv::Italic_end_conv() : Converter(false, "Italic_end") {}
Marker* Italic_end_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '*' && isend(text, pos)) {
        return new italic_end(pos, 1);
    }
    return nullptr;
}
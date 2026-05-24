#include "converter.h"
#include <cctype> // For recognizing punctuation marks!

Converter::Converter(bool f, std::string t) : form(f), type(t) {}
// Helper function to check if the marker is at the start of a word or line

bool Converter::isstart(std::string test, int pos){
    // A marker is considered to be at the start if it's at the beginning of the text, or if it's preceded by a space or a newline character.
    return (pos == 0 || test[pos - 1] == ' ' || test[pos - 1] == '\n');
}

bool Converter::isend(std::string test, int pos){
    // A marker is considered to be at the end if it's at the end of the text, or if it's followed by a space, a newline character, or a punctuation mark.
    return (pos == test.size() - 1 || test[pos + 1] == ' ' || test[pos + 1] == '\n' || std::ispunct(test[pos + 1]));
}

Bold_beg_conv::Bold_beg_conv() : Converter(false, "Bold_start") {}
Marker* Bold_beg_conv::createMarker(std::string text, int pos) {
    // Check if the current position and the next character form a bold marker (i.e., "**") and if it's at the start of a word or line.
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

H1_beg_conv::H1_beg_conv() : Converter(false, "H1_start") {}
Marker* H1_beg_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 1 && text[pos] == '#' && text[pos+1] == ' ' && (pos == 0 || text[pos-1] == '\n')) {
        return new H1(pos, 2); 
    }
    return nullptr;
}

H2_beg_conv::H2_beg_conv() : Converter(false, "H2_start") {}
Marker* H2_beg_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 2 && text[pos] == '#' && text[pos+1] == '#' && text[pos+2] == ' ' && (pos == 0 || text[pos-1] == '\n')) {
        return new H2(pos, 3); 
    }
    return nullptr;
}

H3_beg_conv::H3_beg_conv() : Converter(false, "H3_start") {}
Marker* H3_beg_conv::createMarker(std::string text, int pos) {
    if (pos < text.size() - 3 && text[pos] == '#' && text[pos+1] == '#' && text[pos+2] == '#' && text[pos+3] == ' ' && (pos == 0 || text[pos-1] == '\n')) {
        return new H3(pos, 4); 
    }
    return nullptr;
}
H1_end_conv::H1_end_conv() : Converter(false, "H1_end") {}
Marker* H1_end_conv::createMarker(std::string text, int pos) {
    // To identify the end of an H1 header, we look for a newline character. 
    //We then check if the line that just ended started with "# " to confirm it's an H1 header.
    if (text[pos] == '\n') {
        int start = pos - 1;
        while (start >= 0 && text[start] != '\n') start--;
        start++; 
        // Only close H1 if the line actually started with "# "
        if (start < text.size() - 1 && text[start] == '#' && text[start+1] == ' ') 
            return new h1_end(pos, 1);
    }
    return nullptr;
}

H2_end_conv::H2_end_conv() : Converter(false, "H2_end") {}
Marker* H2_end_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '\n') {
        int start = pos - 1;
        while (start >= 0 && text[start] != '\n') start--;
        start++; 
        // Only close H2 if the line actually started with "## "
        if (start < text.size() - 2 && text[start] == '#' && text[start+1] == '#' && text[start+2] == ' ') 
            return new h2_end(pos, 1);
    }
    return nullptr;
}
H3_end_conv::H3_end_conv() : Converter(false, "H3_end") {}
Marker* H3_end_conv::createMarker(std::string text, int pos) {
    if (text[pos] == '\n') {
        int start = pos - 1;
        while (start >= 0 && text[start] != '\n') start--;
        start++; 
        // Only close H3 if the line actually started with "### "
        if (start < text.size() - 3 && text[start] == '#' && text[start+1] == '#' && text[start+2] == '#' && text[start+3] == ' ') 
            return new h3_end(pos, 1);
    }
    return nullptr;
}
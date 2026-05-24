#ifndef MARKER_H
#define MARKER_H

#include <string>

/*
The goal of this class is to represent a "marker" in the Markdown text, which can be either a starting or ending marker for a formatting element (like bold, italic, headers, etc.). 
Each marker will have a position in the text, a length (to know how many characters it spans), a type (to identify what kind of marker it is), and an HTML tag that corresponds to it.
For example, a bold marker might have type "bold" and HTML tag "<b>" for the starting marker, and type "bold_end" with HTML tag "</b>" for the ending marker.
*/ 

// Base Marker class
class Marker {
public:
// Common attributes for all markers
    int position;
    int length;
    std::string type;
    std::string html_tag;
// Virtual destructor for proper cleanup of derived classes
    virtual ~Marker() = default;
// Constructor to initialize all attributes 
    Marker(int pos, int len, std::string t, std::string html) : position(pos), length(len), type(t), html_tag(html) {}
// Getters for the attributes
    int getPosition() const;
    int getLength() const;
    std::string getType() const;
    // Overload the << operator for easy debugging and visualization of markers
    friend std::ostream& operator<<(std::ostream& os, const Marker& m);
};
class Italic : public Marker {
public:
    Italic(int pos, int len) : Marker(pos, len, "italic", "<i>") {}
}; 

class italic_end : public Marker {
public:
    italic_end(int pos, int len) : Marker(pos, len, "italic_end", "</i>"){}
};

class Bold : public Marker {
public:
    Bold(int pos, int len) : Marker(pos, len, "bold", "<b>") {}
}; 
class bold_end : public Marker {
public:
    bold_end(int pos, int len) : Marker(pos, len, "bold_end", "</b>") {}
};

class Strike : public Marker {
public:
    Strike(int pos, int len) : Marker(pos, len, "strike", "<s>") {}
}; 
class strike_end : public Marker {
public:
    strike_end(int pos, int len) : Marker(pos, len, "strike_end", "</s>") {}
};

class H1 : public Marker {
public:
    H1(int pos, int len) : Marker(pos, len, "h1", "<h1>") {}
}; 
class h1_end : public Marker {
public:
    h1_end(int pos, int len) : Marker(pos, len, "h1_end", "</h1>\n") {}
};

class H2 : public Marker {
public:
    H2(int pos, int len) : Marker(pos, len, "h2", "<h2>") {}
}; 
class h2_end : public Marker {
public:
    h2_end(int pos, int len) : Marker(pos, len, "h2_end", "</h2>\n") {}
};

class H3 : public Marker {
public:
    H3(int pos, int len) : Marker(pos, len, "h3", "<h3>") {}
}; 
class h3_end : public Marker {
public:
    h3_end(int pos, int len) : Marker(pos, len, "h3_end", "</h3>\n") {}
};


// Custom exception class for Markdown-related errors
// This allows us to throw specific exceptions with informative messages when something goes wrong during file handling or processing
class MarkdownException : public std::exception {
private:
    std::string message;
public:
    MarkdownException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
#ifndef MARKER_H
#define MARKER_H

#include <string>

class Marker {
public:
    int position;
    int length;
    std::string type;
    std::string html_tag;

    virtual ~Marker() = default;
    
    Marker(int pos, int len, std::string t, std::string html) : position(pos), length(len), type(t), html_tag(html) {}

    int getPosition() const;
    int getLength() const;
    std::string getType() const;
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

// --- Félkövér ---
class Bold : public Marker {
public:
    Bold(int pos, int len) : Marker(pos, len, "bold", "<b>") {}
}; 
class bold_end : public Marker {
public:
    bold_end(int pos, int len) : Marker(pos, len, "bold_end", "</b>") {}
};

// --- Áthúzott ---
class Strike : public Marker {
public:
    Strike(int pos, int len) : Marker(pos, len, "strike", "<s>") {}
}; 
class strike_end : public Marker {
public:
    strike_end(int pos, int len) : Marker(pos, len, "strike_end", "</s>") {}
};

// --- Címsor 1 ---
class H1 : public Marker {
public:
    H1(int pos, int len) : Marker(pos, len, "h1", "<h1>") {}
}; 
class h1_end : public Marker {
public:
    h1_end(int pos, int len) : Marker(pos, len, "h1_end", "</h1>\n") {}
};

// --- Header 2 ---
class H2 : public Marker {
public:
    H2(int pos, int len) : Marker(pos, len, "h2", "<h2>") {}
}; 
class h2_end : public Marker {
public:
    h2_end(int pos, int len) : Marker(pos, len, "h2_end", "</h2>\n") {}
};

// --- Header 3 ---
class H3 : public Marker {
public:
    H3(int pos, int len) : Marker(pos, len, "h3", "<h3>") {}
}; 
class h3_end : public Marker {
public:
    h3_end(int pos, int len) : Marker(pos, len, "h3_end", "</h3>\n") {}
};

#endif
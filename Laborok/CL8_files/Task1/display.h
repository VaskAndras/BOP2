#ifndef DISPLAY_H
#define DISPLAY_H
#include "equipment.h"
class Display : public Equipment {
public:
    Display(int id, double price, int year); 

    // Constructor
    Display(int id, int year);

    ~Display();

    void print() const;
private:
    int year;
};  
#endif /* DISPLAY_H */

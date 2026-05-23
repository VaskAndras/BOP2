#ifndef PRINTER_H
#define PRINTER_H
#include "equipment.h"
class Printer : public Equipment {
public:
    // Constructor
    Printer(int id, int speed);

    ~Printer();
    // Method to display printer information
    void print() const override;
private:
    int speed; 
};
#endif // PRINTER_H
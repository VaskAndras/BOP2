#ifndef EQUIPMENT_H
#define EQUIPMENT_H 

#include <string>

class Equipment {
public:
    // Constructor
    Equipment();

    Equipment(int id, const std::string& name, int price);
    Equipment(int id, const std::string& name);
    Equipment(int id, int price);

    // Destructor
    virtual ~Equipment() {}

    virtual void print() const = 0; 
    
protected:
    int id;
    std::string name;
    int price; 

};


#endif /* EQUIPMENT_H */

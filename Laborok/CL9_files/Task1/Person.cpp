#include "Person.h"
#include <iostream>
#include <fstream>
using namespace std;

  // Implementation of ISerializable::Save
  void Person::Save(std::ostream& os)
  {
    os << (int)age << ';' << height << ';' << weight << endl;
  }

  // Implementation of ISerializable::Load 
  void Person::Load(std::istream& is)
  {
    double height; double weight; int age; char c;
    is >> age;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> height;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> weight;
    if(is)
    {
      this->age = age;
      this->height = height;
      this->weight = weight;
    }
    else
    {
      cerr << "Error in input format." << endl;
    }


	// Write implementation for other member functions
  }
  void Person::SetHeight(double height) { this->height = height; }
  double Person::GetHeight() { return height; }
  void Person::SetWeight(double weight) { this->weight = weight; }
  double Person::GetWeight() { return weight; }
  bool Person::operator ==(const IComparable& theOther)
  {
    const Person* otherPerson = dynamic_cast<const Person*>(&theOther);
    if (otherPerson)
    {
      return this->age == otherPerson->age &&
             this->height == otherPerson->height &&
             this->weight == otherPerson->weight;
    }
    return false; // Not comparable

  }
  bool Person::operator >(const IComparable& theOther)
  {
    const Person* otherPerson = dynamic_cast<const Person*>(&theOther);
    if (otherPerson)
    {
      if (this->age > otherPerson->age) return true;
      if (this->age < otherPerson->age) return false;
      if (this->height > otherPerson->height) return true;
      if (this->height < otherPerson->height) return false;
      return this->weight > otherPerson->weight;
    }
    return false; // Not comparable
  }
  void Person::Save(std::ostream& os)
  {
    os << (int)age << ';' << height << ';' << weight << endl;
  }
  void Person::Load(std::istream& is)
  {
    double height; double weight; int age; char c;
    is >> age;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> height;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> weight;
    if(is)
    {
      this->age = age;
      this->height = height;
      this->weight = weight;
    }
    else
    {
      cerr << "Error in input format." << endl;
    }
  }

  

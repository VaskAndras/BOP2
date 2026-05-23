#include<iostream>
#include "equipment.h"
#include "display.h"
#include "printer.h"

using namespace std;

int main()
{
	const unsigned maxEquipment=4;
	Equipment* equipments[maxEquipment];

	equipments[1]=new Printer(2,8);	 // Parameters: unique ID, printing speed (pages per minute)
	equipments[2]=new Display(3,20000,1996); // Parameters: unique ID, price, year of appropriation
	equipments[3]=new Printer(4,15);   // Parameters: unique ID, printing speed
	
	for(int i=0;i<maxEquipment;i++)
	{
		equipments[i]->print();
		delete equipments[i];
		cout<<endl;
	}
	return 0;
	
}


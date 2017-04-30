#include "CustomAttribute.h"
#include "CustomClass.h"
#include <iostream>
#include <conio.h>
#include "CCList.h"

void printInfo();

int main()
{
	int input;
	CCList CustomList;
	printInfo();
	while(true)
	{	
		std::cout << "Please enter what you want to do\n";
		std::cin >> input;
		std::cout << "\n";
		try {
			switch (input)
			{
			case 1: CustomList.newNode();
				break;
			case 2: CustomList.addAttributeToNode(CustomList.selectNode());
				break;
			case 3: CustomList.printList();
				break;
			case 4: CustomList.selectNode()->Entity.printAttributes();
				break;
			case 5: CustomList.removeNode(CustomList.selectNode());
				break;
			case 6: CustomList.selectNode()->Entity.removeAttribute();
				break;
			case 7: printInfo();
				break;
			case 8: exit(1);
			default: std::cout << "Invalid Input!\n";
			}
			std::cout << "\n";
		}
		catch(const char* msg)
		{
			std::cout << msg;
		}
	}
	
}

void printInfo()
{
	std::cout << "1 - Add a new Class\n";
	std::cout << "2 - Add a new Attribute to an existing Class\n";
	std::cout << "3 - Print all Classes\n";
	std::cout << "4 - Print all Attributes from a given Class\n";
	std::cout << "5 - Remove a Class\n";
	std::cout << "6 - Remove an Attribute from a given Class\n";
	std::cout << "7 - Show the menu again\n";
	std::cout << "8 - Exit the program\n";
	std::cout << "\n";
}
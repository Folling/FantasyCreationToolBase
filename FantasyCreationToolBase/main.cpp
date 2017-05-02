#include "Entity.h"

void printInfo();

int main()
{
	Entity List;
	int input;
	printInfo();
	while (true)
	{
		std::cout << "Please enter what you want to do\n";
		std::cin >> input;
		std::cout << "\n";
		try {
			switch (input)
			{
			case 1: List.newEntity();
				break;
			case 2: List.selectEntity()->addAttribute();
				break;
			case 3: List.printEntityList();
				break;
			case 4: List.selectEntity()->printAttributes();
				break;
			case 5: List.removeEntity();
				break;
			case 6: List.selectEntity()->removeAttribute();
				break;
			case 7: printInfo();
				break;
			case 8: exit(1);

			default: std::cout << "Invalid Input!\n";
			}
			std::cout << "\n";
		}
		catch (const char* msg)
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
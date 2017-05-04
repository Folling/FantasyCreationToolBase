#include "Entity.h"
#include "EntityInstances.h"

void printInfo();
int menu = 0;

int main()
{	
	Entity List;
	EntityInstances Instances;
	std::string input;
	printInfo();
	while (true)
	{
		std::cout << "Please enter what you want to do\n";
		std::cin >> input;
		while(true){
			if ( input.size() > 1 || input.at(0) > '8' || input.at(0) < '1') {
				List.validateInput("Invalid input. Please enter a valid index.");
				std::cin >> input;
			}
			else break;
		}
		std::cout << "\n";
		try {
			if (menu == 0)
			{
				switch (input.at(0))
				{
				case '1': List.newEntity();
					break;
				case '2': List.selectEntity()->addAttribute();
					break;
				case '3': List.printEntityList();
					break;
				case '4': List.selectEntity()->printAttributes();
					break;
				case '5': List.removeEntity();
					break;
				case '6': List.selectEntity()->removeAttribute();
					break;
				case '7': printInfo();
					break;
				case '8': menu++;
					printInfo();
					break;
				case '9': exit(1);

				default: std::cout << "Invalid Input!\n";
				}
				std::cout << "\n";
			}
			else
			{
				switch (input.at(0))
				{
				case '1': Instances.createNewInstace();
					break;
				case '2': Instances.printInstancesOfEntity(List.selectEntity());
					break;
				case '3': //renameInstance
					break;
				case '4': List.printEntityList();
					break;
				case '5': List.selectEntity()->printAttributes();
					break;
				case '6': printInfo();
					break;
				case '7': menu--;
					printInfo();
					break;
				case '8': exit(1);

				default: std::cout << "Invalid Input!\n";
				}
				std::cout << "\n";
			}
		}
		catch (const char* msg)
		{
			std::cout << msg;
		}
		List.clearInput();
	}

}

void printInfo()
{
	if (menu == 0) {
		std::cout << "1 - Add a new entities\n";
		std::cout << "2 - Add a new attribute to an existing entity\n";
		std::cout << "3 - Print all entities\n";
		std::cout << "4 - Print all attributes from a given entity\n";
		std::cout << "5 - Remove an entity\n";
		std::cout << "6 - Remove an attribute from a given entity\n";
		std::cout << "7 - Show the menu again\n";
		std::cout << "8 - Switch the menu to add instances\n";
		std::cout << "9 - Exit the program\n";
		std::cout << "\n";
	}
	else
	{
		std::cout << "1 - Add an instance to an entity\n";
		std::cout << "2 - Print all instances from an entity\n";
		std::cout << "3 - Rename an instance from an entity\n";
		std::cout << "4 - Print all entities\n";
		std::cout << "5 - Print all attributes from a given entity\n";
		std::cout << "6 - Show the menu again\n";
		std::cout << "7 - Switch the menu to add entities and attributes\n";
		std::cout << "8 - Exit the program\n";
	}
}
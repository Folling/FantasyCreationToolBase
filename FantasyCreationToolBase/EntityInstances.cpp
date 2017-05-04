#include "EntityInstances.h"

Entity List;

void EntityInstances::createNewInstace()
{
	eItr selection = List.selectEntity();
	std::cout << "Okay you selected " << selection->getName() << std::endl;
	defineAttributes(selection->getAttributes());
	this->setInstanceValues(selection);	
	std::pair<std::string, std::list<characteristic>> toAdd;
	toAdd.first = selection->getName();
	toAdd.second = characteristics;
	listedInstances.insert(toAdd);	
}

void EntityInstances::setInstanceValues(const eItr& selection)
{
	for (cItr i = characteristics.begin(); i != characteristics.end(); i++)
	{
		setAttributeValue(i, selection);
	}
}

void EntityInstances::setAttributeValue(const cItr& i, const eItr& selection) const
{
	std::cout << "Please enter the " << selection->getName() << "'s " << i->atName.name << std::endl;
	std::cin >> i->name;
	if (i->atName.type == Bool)
	{
		while (true)
		{
			if (inputIsBool(i->name)) break;
			List.validateInput("Please enter a boolean value!\n");
			std::cin >> i->name;
		}
	}
	if (i->atName.type == Range)
	{
		std::string startValue;
		std::string endValue;
		std::cout << "Please enter the start value of the range:  ";
		std::cin >> startValue;
		while (true)
		{
			if (!inputIsNumber(startValue))
			{
				List.validateInput("Please enter a numeric value!\n");
				std::cin >> startValue;
			}
			else break;
		}
		std::cout << "Please enter the end value of the range:  ";
		std::cin >> endValue;
		while (true)
		{
			if (!inputIsNumber(endValue))
			{
				List.validateInput("Please enter a numeric value!\n");
				std::cin >> endValue;
			}
			else break;
		}
		i->name.append(startValue);
		i->name.append(" - ");
		i->name.append(endValue);
	}
	if (i->atName.type == Number)
	{
		while (true)
		{
			if (inputIsNumber(i->name)) break;
			List.validateInput("Please enter a numeric value!\n");
			std::cin >> i->name;
		}
	}
	if (i->atName.type == Word)
	{
		while (true)
		{
			if (inputIsWord(i->name)) break;
			List.validateInput("Please use alphabetical values only!\n");
			std::cin >> i->name;
		}
	}
}

void EntityInstances::printInstancesOfEntity(eItr selection)
{
	if (listedInstances.at(selection->getName()).size() == 0) throw "Entity contains no instances yet!\n";
	std::cout << "Entity : " << selection->getName() << std::endl;
	for (cItr i = listedInstances.at(selection->getName()).begin(); i != listedInstances.at(selection->getName()).end(); i++)
	{
		std::cout << i->atName.index << ". :" <<  i->atName.name << ": " << i->name << std::endl;
	}
}

void EntityInstances::defineAttributes(std::list<attribute>& attributes)
{
	characteristics.resize(attributes.size());
	cItr i = characteristics.begin();
	for (aItr j = attributes.begin(); i != characteristics.end(); i++ , j++)
	{
		i->atName = *j;
	}
}

bool EntityInstances::inputIsBool(std::string input) const
{
	if (input == "0" || input == "1" || input == "true" || input == "false") return true;
	return false;
}

bool EntityInstances::inputIsNumber(std::string input) const
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) < 48 || input.at(i) > 57) return false;
	}
	return true;
}

bool EntityInstances::inputIsWord(std::string input) const
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) < 65 || (input.at(i) > 90 && input.at(i) < 97) || input.at(i) > 122) return false;
	}
	return true;
}

void EntityInstances::renameInstance()
{
	std::cout << "Of which entity do you want to rename an instance do you want to rename?\n";
	eItr entitySelection = List.selectEntity();
	printInstancesOfEntity(entitySelection);
	std::cout << "Which instance do you want to rename?\n";
	cItr selection = selectInstance(entitySelection);
	std::cout << "Please enter the new value.\n";
	setAttributeValue(selection, entitySelection);
}

bool EntityInstances::characteristicsListIsEmpty() const
{
	if (characteristics.size() == 0) return true;
	return false;
}

cItr EntityInstances::selectInstance(eItr selection)
{
	if (characteristicsListIsEmpty()) throw "Entity contains no instances yet!\n";
	printInstancesOfEntity(selection);
	std::cout << "Please select the index of the instace.\n";
	uint input;
	std::cin >> input;
	while (true)
	{
		if (std::cin.fail() || input < 1 || input >= listedInstances.at(selection->getName()).size()) {
			List.validateInput("Please enter a valid index!\n");
			std::cin >> input;
		}
		else break;
	}
	cItr iterator = listedInstances.at(selection->getName()).begin();
	for (int i = 0; i < input; i++) iterator++;
	std::cout << "Selected instance: " << iterator->name << std::endl;
	return iterator;
}
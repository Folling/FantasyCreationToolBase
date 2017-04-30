#include "CustomClass.h"

CustomClass::CustomClass()
{
	std::cout << "Enter Entity Name : ";
	std::cin >> this->name;
}

CustomClass::~CustomClass()
{
}

void CustomClass::addAttribute()
{
	CustomAttribute newAttribute;
	this->attributes.push_back(newAttribute);
}

void CustomClass::printAttributes() const
{
	if (attributes.size() == 0) throw "Class contains no Attributes yet!\n";
	for (unsigned int i = 0; i < attributes.size(); i++)
		std::cout << i + 1 << ": Type : " << attributes.at(i).resolveType() << "  Name : " << attributes.at(i).getName() << std::endl;
}

void CustomClass::removeAttribute()
{
	unsigned int selection;
	std::cout << "Please select the index of the attribute you want to attribute you want to remove\n";
	std::cout << "The available attributes are: \n\n";
	printAttributes();
	std::cin >> selection;
	while (true)
	{
		if (std::cin.fail()) std::cin >> selection;
		else if (selection > attributes.size());
		else break;
	}
	attributes.erase(attributes.begin() + (selection - 1));
}

void CustomClass::setAttributes(std::vector<CustomAttribute> input)
{
	this->attributes = input;
}

std::string CustomClass::getName() const
{
	return name;
}

std::vector<CustomAttribute> CustomClass::getAttributes() const
{
	return attributes;
}
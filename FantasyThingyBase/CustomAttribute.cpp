#include "CustomClass.h"
#include "CustomAttribute.h"

enum Type
{
	Bool = 0,
	Char = 1,
	Short = 2,
	Int = 3,
	Long = 4,
	LongLong = 5,
	Float = 6,
	Double = 7,
	LongDouble = 8,
	String = 9,
	ClassMember = 10
};

CustomAttribute::CustomAttribute()
{
	std::string typeSelection;
	std::cout << "Enter the attributes name: ";
	std::cin >> name;
	std::cout << "Enter the attributes type: ";
	std::cin >> typeSelection;
	this->determineType(typeSelection);
}


CustomAttribute::~CustomAttribute()
{
}

void CustomAttribute::determineType(std::string selection)
{
	for (unsigned int i = 0; i < selection.size(); i++)
	{
		if (selection.at(i) == 32)selection.erase(selection.begin() + i);
		else tolower(selection.at(i));
	}
	std::cout << selection << std::endl;
	if (selection.find("bool") != std::string::npos) this->type = Bool;
	else if (selection.find("char") != std::string::npos) this->type = Char;
	else if (selection.find("short") != std::string::npos) this->type = Short;
	else if (selection.find("int") != std::string::npos) this->type = Int;
	else if (selection.find("longdouble") != std::string::npos) this->type = LongDouble;
	else if (selection.find("longlong") != std::string::npos) this->type = LongLong;
	else if (selection.find("long") != std::string::npos) this->type = Long;
	else if (selection.find("float") != std::string::npos) this->type = Float;
	else if (selection.find("double") != std::string::npos) this->type = Double;
	else if (selection.find("string") != std::string::npos) this->type = String;
	else if (selection.find("class") != std::string::npos) {
		std::pair <std::string, std::string> toSet = recieveDifferentClassMember();
		this->type = ClassMember;
		this->name = toSet.first;
		this->name.append(".");
		this->name.append(toSet.second);
	}
}

std::pair <std::string, std::string> CustomAttribute::recieveDifferentClassMember() const
{
	std::pair <std::string, std::string> result;
	std::cout << "Please select the Entity of which you want to extract the attribute\n";
	CCList::Class* temporary = MainList.selectNode();
	unsigned int index;
	std::cout << "Which attribute do you want to use?\n";
	temporary->Entity.printAttributes();
	std::cin >> index;
	while(true)
	{
		if (std::cin.fail() || index > temporary->Entity.getAttributes().size()) std::cout << "Invalid input!\n";
		else break;
	}
	result.first  = temporary->Entity.getName();
	result.second = temporary->Entity.getAttributes().at(index - 1).getName();
	return result;
}

std::string CustomAttribute::resolveType() const
{
	std::string rType;
	switch (this->type)
	{
	case 0: rType = "bool";
		break;
	case 1: rType = "char";
		break;
	case 2: rType = "short";
		break;
	case 3: rType = "int";
		break;
	case 4: rType = "long";
		break;
	case 5: rType = "long long";
		break;
	case 6: rType = "float";
		break;
	case 7: rType = "double";
		break;
	case 8: rType = "long double";
		break;
	case 9: rType = "string";
		break;
	case 10:rType = this->name;
		break;
	default: throw "Error resolving type!\n";
	}
	return rType;
}

int CustomAttribute::getType() const
{
	return this->type;
}

std::string CustomAttribute::getName() const
{
	return this->name;
}
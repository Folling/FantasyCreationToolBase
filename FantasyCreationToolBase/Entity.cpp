#include "Entity.h"


std::list<Entity> EntityList;

void Entity::newEntity() const
{
	Entity toAdd;
	std::cout << "Enter Entity Name : ";
	std::cin >> toAdd.name;
	if (entityListIsEmpty()) toAdd.index = 1;
	else toAdd.index = EntityList.back().index + 1;
	EntityList.push_back(toAdd);
}

void Entity::printEntityList() const
{
	if  (entityListIsEmpty()) throw "List is Empty!\n";
	for (eItr i = EntityList.begin(); i != EntityList.end(); ++i) std::cout << i->index << ": " << i->name << std::endl;
}

void Entity::removeEntity() const
{
	if (entityListIsEmpty()) throw "List is Empty!\n";
	eItr selection = selectEntity();
	eItr temp = selection;
	EntityList.erase(selection);
	updateListIndices();
}

eItr Entity::selectEntity() const
{
	if (entityListIsEmpty()) throw "List is Empty!\n";
	std::cout << "Please select the index of the entity you want to select\n";
	std::cout << "The availabe entities are :\n";
	printEntityList();
	uint selIndex;
	std::cin >> selIndex;

	//gets user input until the input is valid
	while(true)
	{
		if (std::cin.fail()) {
			validateInput("Invalid input. Please enter an integer.");			
			std::cin >> selIndex;
		}
		else if (selIndex > EntityList.back().index || selIndex <= 0) {
			validateInput("Index is out of range. Please enter a valid index.");			
			std::cin >> selIndex;
		}
		else break;
	}

	//returns the iterator if the index is = to the selected index
	for (eItr i = EntityList.begin(); i != EntityList.end(); i++) if (i->index == selIndex) return i; 
	throw "No idea how but you fucked it up\nselIndex is :" + selIndex;
}

bool Entity::entityListIsEmpty() const
{
	if (EntityList.size() == 0) return true;
	return false;
}

void Entity::printAttributes()
{
	if (this->attributes.size() == 0) throw "Entity contains no attributes yet!\n";
	for(aItr i = attributes.begin(); i != attributes.end(); i++)
	{
		std::cout << i->index << ". attribute : " << i->name << " Type: " << resolveAttributeType(*i) << std::endl;
	}
}

void Entity::addAttribute()
{
	attribute toAdd;
	std::cout << "Please enter the attributes type: \n";
	std::string typeSel;
	std::cin >> typeSel;
	while (true)
	{
		if (determineAttributeType(typeSel, &toAdd) == -1) {
			validateInput("Invalid type. Please try again.");			
			std::cin >> typeSel;
		}
		else break;
	}
	std::cout << "Please enter the attributes name: \n";
	if (toAdd.type != ClassMember) {
		std::cin >> toAdd.name;
		while (true)
		{
			if (std::cin.fail()) {
				validateInput("Invalid input. Please try again.");
				std::cin >> toAdd.name;
			}
			else break;
		}
	}
	if (attributes.size() == 0) toAdd.index = 1;
	else toAdd.index = attributes.back().index + 1;
	this->attributes.push_back(toAdd);
}

void Entity::removeAttribute()
{
	if(this->attributes.size() == 0) throw "Entity doesn't contain any attributes yet!\n";
	uint selIndex;
	std::cout << "Which attribute do you want to remove?";
	this->printAttributes();
	std::cin >> selIndex;
	while (true) {
		if (std::cin.fail() || index > this->attributes.size()) {			
			validateInput("Invalid input. Please enter a valid index.");
			std::cin >> index;
		}
		else break;
	}
	aItr selAttr;
	for (aItr i = this->attributes.begin(); i != this->attributes.end(); i++) if (i->index == selIndex) selAttr = i;
	this->attributes.erase(selAttr);
	this->updateAttributesIndices();
}

int Entity::determineAttributeType(std::string type, attribute* selection) const
{
	for (unsigned int i = 0; i < type.size(); i++)
	{
		if (type.at(i) == 32)type.erase(type.begin() + i);
		else tolower(type.at(i));
	}
	if		(type.find("bool"	   ) != std::string::npos) selection->type = Bool;
	else if (type.find("range"	   ) != std::string::npos) selection->type = Range;
	else if (type.find("number"    ) != std::string::npos) selection->type = Number;
	else if (type.find("word"	   ) != std::string::npos) selection->type = Word;
	else if (type.find("class"     ) != std::string::npos) {
		std::pair <std::string, std::string> toSet = receiveDifferentEntityMember();
		selection->type = ClassMember;
		selection->name = toSet.first;
		selection->name.append(".");
		selection->name.append(toSet.second);
	}
	else return -1;	
	return 1;
}

std::pair<std::string, std::string> Entity::receiveDifferentEntityMember() const
{
	std::pair <std::string, std::string> result;
	eItr selection = selectEntity();
	uint selIndex;
	std::cout << "Which attribute do you want to use?\n";
	selection->printAttributes();
	std::cin >> selIndex;
	while (true)
	{
		if (std::cin.fail() || index > selection->attributes.size()) {
		    validateInput("Invalid input. Please enter a valid index.");
			std::cin >> selIndex;
		}
		else break;
	}
	c_aItr selAttr;
	for (c_aItr i = this->attributes.begin(); i != this->attributes.end(); i++) if (i->index == selIndex)selAttr = i;
	result.first = selection->name;
	result.second = selAttr->name;
	return result;
}

std::string Entity::resolveAttributeType(attribute& selection) const
{
	std::string rType;
	switch (selection.type)
	{
	case 0: rType = "bool";
		break;
	case 1: rType = "range";
		break;
	case 2: rType = "number";
		break;
	case 3: rType = "word";
		break;
	case 4: rType = selection.name;
		break;
	default: throw "Unknown type!\n";
	}
	return rType;
}

void Entity::validateInput(std::string errorMsg) const
{
	std::cout << errorMsg << std::endl;
	clearInput();
}

void Entity::clearInput() const
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Entity::updateListIndices() const
{
	int count = 1;
	for(eItr i = EntityList.begin(); i != EntityList.end(); i++)
	{
		i->index = count;
		count++;
	}
}

void Entity::updateAttributesIndices()
{
	int count = 1;
	for(aItr i = attributes.begin(); i != attributes.end(); i++)
	{
		i->index = count;
		count++;
	}
}

std::string Entity::getName() const
{
	return name;
}

std::list<attribute> Entity::getAttributes() const
{
	return attributes;
}

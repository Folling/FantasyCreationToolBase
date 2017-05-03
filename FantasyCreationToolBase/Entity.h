#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>
#include <conio.h>
#include <typeinfo>

typedef unsigned int uint;

struct attribute
{
	std::string name;
	uint type;
	uint index;
};

typedef std::list<attribute>::const_iterator c_aItr;
typedef std::list<attribute>::iterator aItr;

class Entity
{
public:
	void newEntity() const;
	void printEntityList() const;
	void removeEntity() const;
	std::list<Entity>::iterator selectEntity() const;
	bool entityListIsEmpty() const;
public:
	void printAttributes() const;
	void addAttribute();
	void removeAttribute();
public:
	int determineAttributeType(std::string type, attribute* selection) const;
	std::pair<std::string, std::string> receiveDifferentEntityMember() const;
	std::string resolveAttributeType(c_aItr selection) const;
public:
	void validateInput(std::string errorMsg) const;
	void clearInput() const;
	void updateListIndices() const;
	void updateAttributesIndices();
public:
	uint index = 0;
	std::pair<std::string, std::string> classNameSyntax;
private:
	std::string name;
	std::list<attribute> attributes;
public :
	std::string getName() const;
	std::list<attribute> getAttributes() const;
};

typedef std::list<Entity>::iterator eItr;
typedef std::list<Entity>::const_iterator c_eItr;

enum Type
{
	Bool		  = 0,
	Range         = 1,
	Number		  = 2,
	Word	      = 3,
	ClassMember   = 4
};

#endif
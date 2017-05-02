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
	Entity();
	~Entity();
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
	uint index = 0;
	std::pair<std::string, std::string> classNameSyntax;
private:
	std::string name;
	std::list<attribute> attributes;	
};

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

#endif
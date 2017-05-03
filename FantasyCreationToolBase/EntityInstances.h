#ifndef ENTITY_INST_H
#define ENTITY_INST_H

#include "Entity.h"
#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <map>
struct characteristic
{
	attribute atName;
	std::string name;
};

class EntityInstances
{
public:
	void createNewInstace();
	void printInstancesOfEntity(eItr selection);
	void defineAttributes(std::list<attribute>& attributes);
	bool inputIsBool(std::string input) const;
	bool inputIsNumber(std::string input) const;
	bool inputIsWord(std::string input) const;
	//void removeInstance();
private:
	std::list<characteristic> characteristics;
public:
	std::map <std::string, std::list<characteristic>> listedInstances;
};

typedef std::list<characteristic>::iterator cItr;
typedef std::list<characteristic>::const_iterator c_cItr;
typedef std::map <std::string, std::list<characteristic>>::iterator miItr;
typedef std::map <std::string, std::list<characteristic>>::const_iterator c_miItr;
#endif

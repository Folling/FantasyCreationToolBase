#ifndef ENTITY_INST_H
#define ENTITY_INST_H

#include "Entity.h"
#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <map>
#include <algorithm>

struct characteristic
{
	attribute atName;
	std::string name;
};

typedef std::list<characteristic>::iterator cItr;
typedef std::list<characteristic>::const_iterator c_cItr;
typedef std::map <std::string, std::list<characteristic>>::iterator miItr;
typedef std::map <std::string, std::list<characteristic>>::const_iterator c_miItr;

class EntityInstances
{
public:
	void setInstanceValues(const eItr& entity);
	void setAttributeValue(const cItr& i, const eItr& selection) const;
	void createNewInstace();
	cItr selectInstance(eItr selection);
	void printInstancesOfEntity(eItr selection);
	void defineAttributes(std::list<attribute>& attributes);
	bool inputIsBool(std::string input) const;
	bool inputIsNumber(std::string input) const;
	bool inputIsWord(std::string input) const;
	void renameInstance();
	bool characteristicsListIsEmpty() const;
private:
	std::list<characteristic> characteristics;
public:
	std::map <std::string, std::list<characteristic>> listedInstances;
};
#endif

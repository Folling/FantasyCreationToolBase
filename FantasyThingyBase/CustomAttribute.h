#ifndef CUSTOM_ATT_H
#define CUSTOM_ATT_H

#include "CCList.h"
#include <iostream>
#include <string>

class CustomAttribute
{
public:
	CustomAttribute();
	~CustomAttribute();
public:
	void determineType(std::string selection);
	std::pair<std::string, std::string> recieveDifferentClassMember() const;
	std::string resolveType() const;
public: 
	int getType() const;
	std::string getName() const;
private:
	int type;
	std::string name;
};

#endif
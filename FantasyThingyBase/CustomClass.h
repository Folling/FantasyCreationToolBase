#ifndef CUS_CLASS_H
#define CUS_CLASS_H

#include <string>
#include <vector>
#include "CustomAttribute.h"

class CustomClass
{
public:
	CustomClass();
	~CustomClass();
public:
	void addAttribute();
	std::string getName() const;
	std::vector<CustomAttribute> getAttributes() const;
	void printAttributes() const;
	void removeAttribute();
private:
	std::string name;
	std::vector <CustomAttribute> attributes;
};
#endif
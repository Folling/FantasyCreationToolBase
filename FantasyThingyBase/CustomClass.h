#ifndef CUST_CLASS_H
#define CUST_CLASS_H

#include "CustomAttribute.h"
#include "CCList.h"
#include <string>
#include <vector>

class CustomClass
{
public:
	CustomClass();
	~CustomClass();
public:
	void addAttribute();
	void printAttributes() const;
	void removeAttribute();
public:
	std::string getName() const;
	std::vector<CustomAttribute> getAttributes() const;
public:
	void setAttributes(std::vector <CustomAttribute> input);
private:
	std::string name;
	std::vector <CustomAttribute> attributes;
};

#endif
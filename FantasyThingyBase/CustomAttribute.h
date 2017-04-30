#ifndef CUSTOM_ATT_H
#define CUSTOM_ATT_H

#include <iostream>
#include <string>

class CustomAttribute
{
public:
	CustomAttribute();
	~CustomAttribute();
public:
	void determineType(std::string selection);
	std::string resolveType() const;
public: 
	int getType() const;
	std::string getName() const;
private:
	int type;
	std::string name;
};
#endif

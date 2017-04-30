#ifndef CCLIST_H
#define CCLIST_H

#include "CustomAttribute.h"
#include "CustomClass.h"

class CCList
{
public:
	CCList();
	~CCList();
public:
	struct Class
	{
		int index;
		Class* prev;
		CustomClass Entity;
		Class* next;
	};
	Class* begin;
	Class* end;
public:
	void newNode();
	void printList() const;
	Class* selectNode() const;
	void removeNode(Class* selection);
	bool isEmpty() const;
	void addAttributeToNode(Class* selection) const;
};

CCList MainList;
#endif
#include "CCList.h"
#include <conio.h>

CCList::CCList()
{
	begin = nullptr;
	end = nullptr;
}

CCList::~CCList()
{
}

void CCList::newNode()
{
	if (this->begin == nullptr)
	{
		Class* node = new Class;
		node->index = 1;
		node->prev = nullptr;
		node->next = nullptr;
		begin = node;
		end = node;
	}
	else
	{
		Class* node = new Class;
		node->prev = end;
		end->next = node;
		node->index = end->index + 1; //increases index by one for each node
		node->next = nullptr;
		end = node;
	}
}

void CCList::printList() const
{
	if (isEmpty()) throw "List is Empty!\n";
	Class* iterator = begin;
	while (iterator != nullptr)
	{
		std::cout << iterator->index << " : " << iterator->Entity.getName() << std::endl;
		iterator = iterator->next;
	}
}

CCList::Class* CCList::selectNode() const
{
	if (isEmpty()) throw "List is empty!\n";
	Class* selection = begin;
	int index;

	std::cout << "The available Classes are: \n";
	printList();

	while (true)
	{
		std::cout << "Please enter the Index of the Class you want to select\n";
		while (true)
		{
			std::cin >> index;
			if (std::cin.fail())
			{
				std::cout << "Invalid Input!\n";
				std::cout << "Pleas re-enter the index!\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
		while (selection != nullptr)
		{
			if (selection->index == index) return selection;
			selection = selection->next;
		}
		std::cout << "Index out of range, please re-enter the index!\n";
		selection = begin;
	}
}

void CCList::removeNode(Class* selection)
{
	if (isEmpty()) throw "List doesn't contain any Entities yet!\n";
	if (selection == begin)
	{
		Class* del = begin;
		begin->prev = nullptr;
		begin = begin->next;
		delete del;
		return;
	}
	if (selection == end)
	{
		Class* del = end;
		end->next = nullptr;
		end = end->prev;
		delete del;
		return;
	}
	for (Class* iterator = begin; iterator != nullptr; iterator = iterator->next)
	{
		if (iterator == selection)
		{
			Class* del = selection;
			selection = selection->next;
			selection->prev = selection->prev->prev;
			delete del;
			return;
		}
	}
	throw "List doesn't contain the Entity you selected!\n";
}

bool CCList::isEmpty() const
{
	if (begin == nullptr)return true;
	return false;
}

void CCList::addAttributeToNode(Class* selection) const
{
	selection->Entity.addAttribute();
}
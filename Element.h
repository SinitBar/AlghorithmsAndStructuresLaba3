#pragma once
#include "Node.h"
class Element
{
	Element* next;
	Node* data;
	void set_next(Element*);
	void set_data(Node*);

public:
	Element();
	Element* get_next();
	Node* get_data();
	~Element();
	friend class Queue;
	friend class Stack;
};
#pragma once
#include "Node.h"
class Iterator
{
public:
	virtual Node* next() = 0; // return current element and goes to the next
	virtual bool has_next() = 0; // return true if next exists
};
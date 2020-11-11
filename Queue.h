#pragma once
#include "Element.h"
class Queue
{
private:
	Element* head; // the first in queue, leaves first
	Element* tail; // the last, new in queue
	void set_head(Element*);
	void set_tail(Element*);
public:
	Queue();
	int size(); // return a number of elements in queue
	bool is_empty(); // returns true if queue is empty
	Element* top(); // to know who will leave first
	Element* pop(); // to delete first in queue and return it to user
	Element* push(Node*); // to add in the end of the queue the element with key-data and return it to user
	//Element* back(); // to know who is the last in queue and return it to user
	~Queue();
};
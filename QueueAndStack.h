#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class element
{
	element* next;
	int data;
	void set_next(element*);
	void set_data(int);

public:
	element();
	friend class Queue;
	friend class
	element* get_next();
	int get_data();
	~element();
};

class Queue
{
private:
	element* head; // the first in queue, leaves first
	element* tail; // the last, new in queue
	void set_head(element*);
	void set_tail(element*);
public:
	Queue();
	int size(); // return a number of elements in queue
	bool is_empty(); // returns true if queue is empty
	element* top(); // to know who will leave first
	element* pop(); // to delete first in queue and return it to user
	element* push(int); // to add in the end of the queue the element with key-data and return it to user
	element* back(); // to know who is the last in queue and return it to user
	~Queue();
};

class Stack
{
private:
	element* top;
	void set_top(element*);
public:
	Stack();
	bool is_empty();
	int size();
	element* peek(); // to show who's on the top
	element* pop(); // to delte top and show it
	element* push(int); // to push on top and show it
	~Stack();
};
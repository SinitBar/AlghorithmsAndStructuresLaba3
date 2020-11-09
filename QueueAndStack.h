#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Node
{
private:
	int key;
	Node* left_child;
	Node* right_child;
	Node* set_left_child(int);
	Node* set_right_child(int);
	void set_key(int);
public:
	Node();
	Node(int);
	friend class BinarySearchTree;
	friend class Element;
	friend class Queue;
	friend class Stack;
	Node* get_left_child();
	Node* get_right_child();
	int get_key();
	~Node();
};

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
	Element* back(); // to know who is the last in queue and return it to user
	~Queue();
};

class Stack
{
private:
	Element* top;
	void set_top(Element*);
public:
	Stack();
	bool is_empty();
	int size();
	Element* peek(); // to show who's on the top
	Element* pop(); // to delte top and show it
	Element* push(Node*); // to push on top and show it
	~Stack();
};

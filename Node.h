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
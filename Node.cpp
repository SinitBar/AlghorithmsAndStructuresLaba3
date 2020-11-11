#include "Node.h"

Node::Node()
{
	key = 0;
	left_child = nullptr;
	right_child = nullptr;
}

Node::Node(int key_number)
{
	key = key_number;
	left_child = nullptr;
	right_child = nullptr;
}

Node* Node::set_left_child(int child_key)
{
	Node* new_node = new Node(child_key);
	left_child = new_node;
	return left_child;
}

Node* Node::set_right_child(int child_key)
{
	Node* new_node = new Node(child_key);
	right_child = new_node;
	return right_child;
}

void Node::set_key(int key_number) { key = key_number; }

Node* Node::get_left_child() { return left_child; }

Node* Node::get_right_child() { return right_child; }

int Node::get_key() { return key; }

Node::~Node()
{
	delete left_child;
	delete right_child;
	left_child = right_child = nullptr;
}
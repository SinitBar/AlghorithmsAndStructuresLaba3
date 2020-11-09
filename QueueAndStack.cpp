#include "QueueAndStack.h"

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

Element::Element()
{
	data = 0;
	next = nullptr;
}

Element* Element::get_next() { return next; }
Node* Element::get_data() { return data; }
void Element::set_next(Element* new_element) { next = new_element; }
void Element::set_data(Node* information) { data = information; }
Element::~Element() { delete next; next = nullptr; }

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}
void Queue::set_head(Element* key) { head = key; }
void Queue::set_tail(Element* key) { tail = key; }

bool Queue::is_empty() // returns true if queue is empty
{
	if (tail == nullptr)
		return true;
	return false;
}

int Queue::size() // return a number of elements in queue
{
	if (is_empty())
		return 0;
	int size = 1;
	for (Element* now = tail; now->get_next() != nullptr; now = now->get_next())
		size++;
	return size;
}

Element* Queue::top() // to know who will leave first
{ return head; }

Element* Queue::push(Node* data_key) // to add in the end of the queue the element with key-data
{
	Element* new_element = new Element;
	new_element->set_data(data_key);
	if (is_empty())
		head = tail = new_element;
	else
	{
		new_element->set_next(tail);
		tail = new_element;
	}
	return new_element;
}

Element* Queue::pop() // to delete first in queue and return it's key-data
{
	Element* to_delete;
	if (is_empty())
		throw out_of_range("the queue is empty");
	else if (size() == 1)
	{
		to_delete = head;
		head = tail = nullptr;
	}
	else
	{
		to_delete = head;
		for (Element* now = tail; now->get_next() != nullptr; now = now->get_next())
			head = now;
		head->next = nullptr;
	}
	return to_delete;
}

Element* Queue::back() // to know who is the last in queue
{ return tail; }

Queue::~Queue()
{
	while (!is_empty())
		pop();
}

void Stack::set_top(Element* top_element) { top = top_element; }
Stack::Stack()
{
	top = nullptr;
}
bool Stack::is_empty()
{
	if (top == nullptr)
		return true;
	return false;
}
int Stack::size()
{
	int size = 1;
	if (is_empty())
		return 0;
	for (Element* now = top; now->get_next() != nullptr; now = now->get_next())
		size++;
	return size;
}

Element* Stack::peek() // to show who's on the top
{
	return top;
}

Element* Stack::pop() // to delte top and show it
{
	Element* to_delete = top;
	if (is_empty())
		throw out_of_range("the stack is empty");
	else
		top = top->get_next();
	return to_delete;
}

Element* Stack::push(Node* data) // to push on top and show it
{
	Element* new_element = new Element;
	new_element->set_data(data);
	if (is_empty())
		top = new_element;
	else
	{
		new_element->set_next(top);
		top = new_element;
	}
	return new_element;
}

Stack::~Stack()
{
	while (!is_empty())
		pop();
}

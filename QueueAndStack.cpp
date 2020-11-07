#include "QueueAndStack.h"
element::element()
{
	data = 0;
	next = nullptr;
}
element* element::get_next() { return next; }
int element::get_data() { return data; }
void element::set_next(element* new_element) { next = new_element; }
void element::set_data(int information) { data = information; }
element::~element() { delete next; next = nullptr; }

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}
void Queue::set_head(element* key) { head = key; }
void Queue::set_tail(element* key) { tail = key; }

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
	for (element* now = tail; now->get_next() != nullptr; now = now->get_next())
		size++;
	return size;
}

element* Queue::top() // to know who will leave first
{ return head; }

element* Queue::push(int data_key) // to add in the end of the queue the element with key-data
{
	element* new_element = new element;
	new_element->data = data_key;
	if (is_empty())
		head = tail = new_element;
	else
	{
		new_element->set_next(tail);
		tail = new_element;
	}
	return new_element;
}

element* Queue::pop() // to delete first in queue and return it's key-data
{
	element* to_delete;
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
		for (element* now = tail; now->get_next() != nullptr; now = now->get_next())
			head = now;
		head->next = nullptr;
	}
	return to_delete;
}

element* Queue::back() // to know who is the last in queue
{ return tail; }

Queue::~Queue()
{
	while (!is_empty())
		pop();
}

void Stack::set_top(element* top_element) { top = top_element; }
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
	for (element* now = top; now->get_next() != nullptr; now = now->get_next())
		size++;
	return size;
}

element* Stack::peek() // to show who's on the top
{
	return top;
}

element* Stack::pop() // to delte top and show it
{
	element* to_delete = top;
	if (is_empty())
		throw out_of_range("the stack is empty");
	else
		top = top->get_next();
	return to_delete;
}

element* Stack::push(int data) // to push on top and show it
{
	element* new_element = new element;
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
#include "Element.h"

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
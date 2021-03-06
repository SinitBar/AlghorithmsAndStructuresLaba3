#pragma once
#include "Queue.h"
#include "Stack.h"
#include "Iterator.h"
using namespace std;

class BinarySearchTree // BST
{
private:
	Node* root;
	Node* set_root(int);
	Node* get_root();
public:
	BinarySearchTree();
	BinarySearchTree(int);
	bool is_empty();
	void insert(int); // add element with given key
	bool contains(int); // search element with given key
	void remove(int); // delete element with given key

	Iterator* create_breadth_first_traverse_iterator(); // to realise this method of passing through elements

	class BreadthFirstTraverse_Iterator : public Iterator
	{
	private:
		Node* current;
		Queue queue;
	public:
		BreadthFirstTraverse_Iterator(Node* start);
		Node* next() override;
		bool has_next() override;
	};

	Iterator* create_pre_ordered_depth_first_traverse_iterator(); // to realise this method of passing through elements

	class PreOrderedDepthFirstTraverse_Iterator : public Iterator
	{
	private:
		Node* current;
		Stack stack;
	public:
		PreOrderedDepthFirstTraverse_Iterator(Node* start);
		Node* next() override;
		bool has_next() override;
	};

	Iterator* create_in_ordered_depth_first_traverse_iterator(); // to realise this method of passing through elements

	class InOrderedDepthFirstTraverse_Iterator : public Iterator
	{
	private:
		Node* current;
		Stack stack;
	public:
		InOrderedDepthFirstTraverse_Iterator(Node* start);
		Node* next() override;
		bool has_next() override;
	};

	Iterator* create_post_ordered_depth_first_traverse_iterator(); // to realise this method of passing through elements

	class PostOrderedDepthFirstTraverse_Iterator : public Iterator
	{
	private:
		Node* current;
		Stack stack;
	public:
		PostOrderedDepthFirstTraverse_Iterator(Node* start);
		Node* next() override;
		bool has_next() override;
	};

	~BinarySearchTree();
};
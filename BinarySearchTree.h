#pragma once
#include "QueueAndStack.h"
using namespace std;

class Node;

class Iterator
{
public:
	virtual Node* next() = 0;
	virtual bool has_next() = 0;
};

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
	Node* get_left_child();
	Node* get_right_child();
	int get_key();
	~Node();
};

class BinarySearchTree // BST
{
private:
	Node* root;
	Node* set_root(int);
public:
	BinarySearchTree();
	BinarySearchTree(int);
	bool is_empty();
	Node* get_root();
	void insert(int); // ���������� �������� � ������ �� �����. ������ �������� �� O(logN)
	Node* contains(int); // ����� �������� � ������ �� �����
	void remove(int); // �������� �������� ������ �� �����

	Iterator* create_bft_iterator(); // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)

	class BFT_Iterator : public Iterator
	{
	private:
		Node* current;
		// queue
	public:
		BFT_Iterator(Node* start);
		Node* next() override;
		bool has_next() override;
	};
	//Iterator create_dft_iterator(); // �������� ���������, ������������ ���� �� ������� ������ � ������� (depth-first traverse)
	//Iterator create_bft_iterator() 
	~BinarySearchTree();
};


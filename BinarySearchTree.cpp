#include "/Users/varka/source/repos/BinarySearchTree/BinarySearchTree.h"
#include "/Users/varka/source/repos/BinarySearchTree/QueueAndStack.h"

BinarySearchTree::BinarySearchTree()
{ root = nullptr; }
BinarySearchTree::BinarySearchTree(int key_number)
{
	Node* new_node = new Node;
	new_node->key = key_number;
	root = new_node;
}
bool BinarySearchTree::is_empty() { return (root == nullptr); }
Node* BinarySearchTree::set_root(int root_key) 
{
	Node* new_node = new Node(root_key);
	new_node->key = root_key;
	root = new_node;
	return root;
}
Node* BinarySearchTree::get_root() { return root; }
void BinarySearchTree::insert(int vertex_key) 
{
	if (is_empty())
		set_root(vertex_key);
	else
	{
		Node* now = root;
		while (true) // while did not set element
		{
			if (vertex_key <= now->get_key())
			{ // search for the place in the left branch
				if (now->get_left_child() == nullptr)
				{
					now->set_left_child(vertex_key);
					break;
				}
				now = now->get_left_child();
			}
			else
			{ // search for the place in the right branch
				if (now->get_right_child() == nullptr)
				{
					now->set_right_child(vertex_key);
					break;
				}
				now = now->get_right_child();
			}
		}
	}
}
bool BinarySearchTree::contains(int vertex_key) 
{
	if (is_empty())
		throw out_of_range("search in the empty tree");
	Node* now = root;
	while (vertex_key != now->get_key())
	{
		if (vertex_key < now->get_key())
		{ // search in the left branch
			if (now->get_left_child() == nullptr)
				return false; // false case, element doesn't exist
			now = now->get_left_child();
		}
		else
		{ // search in the right branch
			if (now->get_right_child() == nullptr)
				return false; // false case, element doesn't exist	
			now = now->get_right_child();
		}
	}
	return true;
}
void BinarySearchTree::remove(int vertex_key) 
{
	if (is_empty())
		throw out_of_range("remove from empty tree");
	// we should find this element
	Node* to_delete = root; 
	Node* parent_of_to_delete = root;
	while (vertex_key != to_delete->get_key())
	{
		if (vertex_key < to_delete->get_key())
		{ // search in the left branch
			if (to_delete->get_left_child() == nullptr)
			{
				to_delete = nullptr;
				break;
			}// false case, element doesn't exist
			parent_of_to_delete = to_delete;
			to_delete = to_delete->get_left_child();
		}
		else
		{ // search in the right branch
			if (to_delete->get_right_child() == nullptr)
			{
				to_delete = nullptr;
				break;
			}// false case, element doesn't exist	
			parent_of_to_delete = to_delete;
			to_delete = to_delete->get_right_child();
		}
	}
	if (to_delete == nullptr)
		throw out_of_range("remove not-existing element");
	if (to_delete->get_left_child() == nullptr)
	{
		if (to_delete->get_right_child() == nullptr)
		{//case 1: a leaf
			if (to_delete == root)
			{ // root is the only element in the tree
				delete root;
				root = nullptr;
				return;
			}
			if (parent_of_to_delete->left_child == to_delete)
			{
				delete parent_of_to_delete->left_child;
				parent_of_to_delete->left_child = nullptr;
				return;
			}
			if (parent_of_to_delete->right_child == to_delete)
			{
				delete parent_of_to_delete->right_child;
				parent_of_to_delete->right_child = nullptr;
				return;
			}
		}
		else
		{// case 2: to_delete has only right child
			if (to_delete == root)
				root = to_delete->right_child;
			else if (parent_of_to_delete->left_child == to_delete)
				parent_of_to_delete->left_child = to_delete->right_child;
			else if (parent_of_to_delete->right_child == to_delete)
				parent_of_to_delete->right_child = to_delete->right_child;
			to_delete = nullptr;
			return;
		}
	}
	else if (to_delete->get_right_child() == nullptr)
	{ // case 3: to_delete has only left child
		if (to_delete == root)
			root = to_delete->left_child;
		else if (parent_of_to_delete->left_child == to_delete)
			parent_of_to_delete->left_child = to_delete->left_child;
		else if (parent_of_to_delete->right_child == to_delete)
			parent_of_to_delete->right_child = to_delete->left_child;
		to_delete = nullptr;
		return;
	}
	else
	{// case 4: to_delete has both childs
		Node* change_leaf = to_delete->right_child;
		Node* change_leaf_parent = to_delete;
		while (change_leaf->left_child != nullptr)
		{ // go to the left leaf
			change_leaf_parent = change_leaf;
			change_leaf = change_leaf->left_child;
		}
		if (to_delete == root)
			root->key = change_leaf->key;
		else
			to_delete->key = change_leaf->key;
		if (change_leaf != to_delete->right_child)
		{
			delete change_leaf_parent->left_child;
			change_leaf_parent->left_child = nullptr;
		}
		else
		{
			delete change_leaf_parent->right_child;
			change_leaf_parent->right_child = nullptr;
		}
	}
}
BinarySearchTree::~BinarySearchTree()
{
	while (root != nullptr)
		remove(root->get_key());
}

Iterator* BinarySearchTree::create_breadth_first_traverse_iterator()
{ return new BreadthFirstTraverse_Iterator(root); }
BinarySearchTree::BreadthFirstTraverse_Iterator::BreadthFirstTraverse_Iterator(Node* start)
{
	current = start;
	queue.push(current);
}
bool BinarySearchTree::BreadthFirstTraverse_Iterator::has_next()
{ return (!queue.is_empty()); }
Node* BinarySearchTree::BreadthFirstTraverse_Iterator::next()
{
	if (queue.is_empty())
		return current = nullptr;
	current = queue.top()->get_data();
	if (current->get_left_child() != nullptr)
		queue.push(current->get_left_child());
	if (current->get_right_child() != nullptr)
		queue.push(current->get_right_child());
	return queue.pop()->get_data();
}

Iterator* BinarySearchTree::create_pre_ordered_depth_first_traverse_iterator()
{ return new PreOrderedDepthFirstTraverse_Iterator(root); }
BinarySearchTree::PreOrderedDepthFirstTraverse_Iterator::PreOrderedDepthFirstTraverse_Iterator(Node* start)
{
	current = start;
	stack.push(current);
}
bool BinarySearchTree::PreOrderedDepthFirstTraverse_Iterator::has_next()
{ return (!stack.is_empty()); }
Node* BinarySearchTree::PreOrderedDepthFirstTraverse_Iterator::next()
{
	if (stack.is_empty())
		return current = nullptr;
	Node* to_return = new Node;
	to_return = current;
	if (current->get_right_child() != nullptr)
		stack.push(current->get_right_child());
	if (current->get_left_child() != nullptr)
		current = current->get_left_child();
	else if (!stack.is_empty())
		current = stack.pop()->get_data();
	return to_return;
}

Iterator* BinarySearchTree::create_in_ordered_depth_first_traverse_iterator()
{ return new InOrderedDepthFirstTraverse_Iterator(root); }
BinarySearchTree::InOrderedDepthFirstTraverse_Iterator::InOrderedDepthFirstTraverse_Iterator(Node* start)
{ current = start; }
bool BinarySearchTree::InOrderedDepthFirstTraverse_Iterator::has_next()
{ return (current != nullptr); }
Node* BinarySearchTree::InOrderedDepthFirstTraverse_Iterator::next()
{
	Node* to_return = new Node;
	to_return = nullptr;
	if (!stack.is_empty())
	{
		if (stack.peek()->get_data() != current) // else we skip getting down procedure
		{
			stack.push(current);
			while (current->get_left_child() != nullptr)
			{
				current = current->get_left_child();
				stack.push(current);
			}
		}
		to_return = stack.pop()->get_data();
	}
	else if (current != nullptr) // when reach the root stack is empty but we have right branch
	{
		stack.push(current);
		while (current->get_left_child() != nullptr)
		{
			current = current->get_left_child();
			stack.push(current);
		}
		to_return = stack.pop()->get_data();
	}
	else
		return nullptr;
	if (current->get_right_child() != nullptr)
		current = current->get_right_child(); // the next is right-child node
	else if (!stack.is_empty())
		current = stack.peek()->get_data(); // the next is the top from the stack
	else
		current = nullptr;
	return to_return;
}

Iterator* BinarySearchTree::create_post_ordered_depth_first_traverse_iterator()
{ return new PostOrderedDepthFirstTraverse_Iterator(root); }
BinarySearchTree::PostOrderedDepthFirstTraverse_Iterator::PostOrderedDepthFirstTraverse_Iterator(Node* start)
{
	current = start;
	stack.push(current);
	while ((current->get_left_child() != nullptr) || (current->get_right_child() != nullptr))
	{
		if (current->get_left_child() != nullptr)
		{
			if (current->get_right_child() != nullptr)
			{
				stack.push(current->get_right_child());
				stack.push(current);
			}
			current = current->get_left_child();
			stack.push(current);
		}
		else if (current->get_right_child() != nullptr)
		{
			current = current->get_right_child();
			if (((current->get_left_child() != nullptr) && (current->get_right_child() == nullptr))|| ((current->get_right_child() != nullptr) && (current->get_left_child() == nullptr)))
				stack.push(current); // if has only one child
		}
	}
}
bool BinarySearchTree::PostOrderedDepthFirstTraverse_Iterator::has_next()
{ return (current != nullptr); }
Node* BinarySearchTree::PostOrderedDepthFirstTraverse_Iterator::next()
{
	Node* to_return = new Node;
	to_return = nullptr;
	if (!stack.is_empty())
	{
		if ((current->get_right_child() == stack.peek()->get_data()) || (current->get_left_child() == stack.peek()->get_data()))
		{ // if current has childs
			current = stack.peek()->get_data(); // take the one that wasn't considered
			while ((current->get_left_child() != nullptr)||(current->get_right_child() != nullptr))
			{
				if (current->get_left_child() != nullptr)
				{ // if left exists add right and go to left
					if (current->get_right_child() != nullptr)
					{
						stack.push(current->get_right_child());
						stack.push(current);
					}
					current = current->get_left_child();
					stack.push(current);
				} // if left doesn't exist, but right exist
				else if (current->get_right_child() != nullptr)
				{
					current = current->get_right_child();
					if (((current->get_left_child() != nullptr) && (current->get_right_child() == nullptr)) || ((current->get_right_child() != nullptr) && (current->get_left_child() == nullptr)))
						stack.push(current);
				}
			}
			to_return = stack.pop()->get_data();
		}
		else 
		{
			if (current == stack.peek()->get_data())
				to_return = stack.pop()->get_data();
			else
				to_return = current;
		}
	}
	else if (current != nullptr)
	{
		to_return = current;
		current = nullptr;
	}
	if (!stack.is_empty())
		current = stack.pop()->get_data(); // the next is the top from the stack
	return to_return;
}

int main()
{
	BinarySearchTree BST(8);
	BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
	BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
	Iterator* post_dft_iterator = BST.create_post_ordered_depth_first_traverse_iterator();
	Iterator* pre_dft_iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
	Iterator* in_dft_iterator = BST.create_in_ordered_depth_first_traverse_iterator();
	Iterator* bft_iterator = BST.create_breadth_first_traverse_iterator();
	cout << "Tree, passed by breadth-first iterator: " << endl;
	while (bft_iterator->has_next())
		cout << bft_iterator->next()->get_key() << " ";
	cout << endl << "Tree, passed by pre-ordered depth-first iterator: " << endl;
	while (pre_dft_iterator->has_next())
		cout << pre_dft_iterator->next()->get_key() << " ";
	cout << endl << "Tree, passed by in-ordered depth-first iterator: " << endl;
	while (in_dft_iterator->has_next())
		cout << in_dft_iterator->next()->get_key() << " ";
	cout << endl << "Tree, passed by post-ordered depth-first iterator: " << endl;
	while (post_dft_iterator->has_next())
		cout << post_dft_iterator->next()->get_key() << " ";
	cout << endl;
	return 0;
}

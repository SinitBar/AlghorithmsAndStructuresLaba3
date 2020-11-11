#include "/Users/varka/source/repos/BinarySearchTree/BinarySearchTree.h"

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
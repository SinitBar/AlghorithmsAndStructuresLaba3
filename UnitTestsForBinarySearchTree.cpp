#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/varka/source/repos/BinarySearchTree/BinarySearchTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsForBinarySearchTree
{
	TEST_CLASS(UnitTestsForBinarySearchTree)
	{
	public:
		TEST_METHOD(TestBinarySearchTreeEmpty)
		{
			BinarySearchTree BST;
			Assert::AreEqual(BST.is_empty(), true);
		}
		TEST_METHOD(TestBinarySearchTreeContainsError)
		{
			BinarySearchTree BST;
			try
			{
				BST.contains(2);
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "search in the empty tree");
			}
		}
		TEST_METHOD(TestBinarySearchTreeRemoveFromEmptyTree)
		{
			BinarySearchTree BST(2);
			BST.remove(2);
			try
			{
				BST.remove(2);
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "remove from empty tree");
			}
		}
		TEST_METHOD(TestBinarySearchTreeRemoveError)
		{
			BinarySearchTree BST(8);
			BST.insert(2), BST.insert(3);
			BST.remove(2);
			try
			{
				BST.contains(2);
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "remove not-existing element");
			}
		}
		TEST_METHOD(TestBinarySearchTreeNotEmpty)
		{
			BinarySearchTree BST(1);
			Assert::AreEqual(BST.is_empty(), false);
		}
		TEST_METHOD(TestBinarySearchTreeIntConstructor)
		{
			BinarySearchTree BST(1);
			Assert::AreEqual(BST.contains(1), true);
			BinarySearchTree BST1(1);
			BinarySearchTree BST2;
			BST2.insert(1);
			Assert::AreEqual(BST1.contains(1),  BST2.contains(1));
		}
		TEST_METHOD(TestBinarySearchForExistingElement)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10);
			Assert::AreEqual(BST.contains(8), true);
		}
		TEST_METHOD(TestBinarySearchForNotExistingElement)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10);
			Assert::AreEqual(BST.contains(4), false);
		}
		TEST_METHOD(TestBinarySearchBFTIteratorAndInsert)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
			BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 1);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchPreOrderDFTIteratorAndInsert)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
			BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 1);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchInOrderDFTIteratorAndInsert)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
			BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
			Iterator* iterator = BST.create_in_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 1);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchPostOrderDFTIteratorAndInsert)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
			BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 1);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchRemoveOneElement)
		{
			BinarySearchTree BST(8);
			BST.remove(8);
			Assert::AreEqual(BST.is_empty(), true);
		}
		TEST_METHOD(TestBinarySearchRemoveOneElementFromThreeBFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(14); BST.insert(13);
			BST.remove(14);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeBFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(4);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeBFTIteratorLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(14);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeBFTIteratorRight)
		{
			BinarySearchTree BST(8);
			BST.insert(6); BST.insert(3);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeBFTIteratorLeftRight)
		{
			BinarySearchTree BST(8);
			BST.insert(5); BST.insert(7);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 5);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeBFTIteratorRightLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(10); BST.insert(9);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 9);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePreOrderedDFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(4);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePreOrderedDFTIteratorLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(14);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePreOrderedDFTIteratorRight)
		{
			BinarySearchTree BST(8);
			BST.insert(6); BST.insert(3);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePreOrderedDFTIteratorLeftRight)
		{
			BinarySearchTree BST(8);
			BST.insert(5); BST.insert(7);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 5);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePreOrderedDFTIteratorRightLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(10); BST.insert(9);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 9);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeInOrderedDFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(4);
			Iterator* iterator = BST.create_in_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeInOrderedDFTIteratorLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(14);
			Iterator* iterator = BST.create_in_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeInOrderedDFTIteratorRight)
		{
			BinarySearchTree BST(8);
			BST.insert(6); BST.insert(3);
			Iterator* iterator = BST.create_in_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeInOrderedDFTIteratorLeftRight)
		{
			BinarySearchTree BST(8);
			BST.insert(5); BST.insert(7);
			Iterator* iterator = BST.create_in_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 5);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreeInOrderedDFTIteratorRightLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(10); BST.insert(9);
			Iterator* iterator = BST.create_in_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 9);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePostOrderedDFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(4);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePostOrderedDFTIteratorLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(13); BST.insert(14);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePostOrderedDFTIteratorRight)
		{
			BinarySearchTree BST(8);
			BST.insert(6); BST.insert(3);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 6);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePostOrderedDFTIteratorLeftRight)
		{
			BinarySearchTree BST(8);
			BST.insert(5); BST.insert(7);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 5);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchThreePostOrderedDFTIteratorRightLeft)
		{
			BinarySearchTree BST(8);
			BST.insert(10); BST.insert(9);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 9);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 10);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchTwoPostOrderedDFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(3);
			Iterator* iterator = BST.create_post_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchRemoveOneElementFromThreeDFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(14); BST.insert(13);
			BST.remove(14);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchRemoveAndInsertBFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
			BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
			BST.remove(6); BST.remove(10); BST.remove(1);
			Iterator* iterator = BST.create_breadth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			Assert::AreEqual(iterator->has_next(), false);
		}
		TEST_METHOD(TestBinarySearchRemoveAndInsertDFTIterator)
		{
			BinarySearchTree BST(8);
			BST.insert(3); BST.insert(10); BST.insert(14); BST.insert(13);
			BST.insert(6); BST.insert(1); BST.insert(7); BST.insert(4);
			BST.remove(6); BST.remove(10); BST.remove(1);
			Iterator* iterator = BST.create_pre_ordered_depth_first_traverse_iterator();
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 8);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 3);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 7);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 4);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 14);
			if (iterator->has_next())
				Assert::AreEqual(iterator->next()->get_key(), 13);
			Assert::AreEqual(iterator->has_next(), false);
		}
	};
}

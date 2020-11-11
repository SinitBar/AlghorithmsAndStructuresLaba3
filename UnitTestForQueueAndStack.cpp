#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/varka/source/repos/BinarySearchTree/Queue.h"
#include "/Users/varka/source/repos/BinarySearchTree/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForQueueAndStack
{
	TEST_CLASS(UnitTestForQueueAndStack)
	{
	public:
		TEST_METHOD(TestEmptyQueue)
		{
			Queue queue;
			Assert::AreEqual(queue.is_empty(), true);
		}
		TEST_METHOD(TestEmptyStack)
		{
			Stack stack;
			Assert::AreEqual(stack.is_empty(), true);
		}
		TEST_METHOD(TestEmptyQueuePop)
		{
			Queue queue;
			try
			{
				queue.pop();
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "the queue is empty");
			}
		}
		TEST_METHOD(TestEmptyStackPop)
		{
			Stack stack;
			try
			{
				stack.pop();
			}
			catch (const exception & message)
			{
				Assert::AreEqual(message.what(), "the stack is empty");
			}
		}
		TEST_METHOD(TestEmptyQueueSize)
		{
			Queue queue;
			Assert::AreEqual(queue.size(), 0);
		}
		TEST_METHOD(TestEmptyStackSize)
		{
			Stack stack;
			Assert::AreEqual(stack.size(), 0);
		}
		TEST_METHOD(TestOneElementQueueIsEmpty)
		{
			Queue queue;
			Node new_node(3);
			queue.push(&new_node);
			Assert::AreEqual(queue.is_empty(), false);
		}
		TEST_METHOD(TestOneElementStack)
		{
			Stack stack;
			Node new_node(3);
			stack.push(&new_node);
			Assert::AreEqual(stack.is_empty(), false);
		}
		TEST_METHOD(TestOneElementQueueSize)
		{
			Queue queue;
			Node new_node(3);
			queue.push(&new_node);
			Assert::AreEqual(queue.size(), 1);
		}
		TEST_METHOD(TestOneElementStackSize)
		{
			Stack stack;
			Node new_node(3);
			stack.push(&new_node);
			Assert::AreEqual(stack.size(), 1);
		}
		TEST_METHOD(TestOneElementQueuePop)
		{
			Queue queue;
			Node new_node(3);
			queue.push(&new_node);
			Assert::AreEqual(queue.pop()->get_data()->get_key(), 3);
		}
		TEST_METHOD(TestOneElementStackPop)
		{
			Stack stack;
			Node new_node(3);
			stack.push(&new_node);
			Assert::AreEqual(stack.pop()->get_data()->get_key(), 3);
		}
		TEST_METHOD(TestTwoElementQueuePop)
		{
			Queue queue;
			Node new_node(3);
			queue.push(&new_node);
			Node new_node2(4);
			queue.push(&new_node2);
			Assert::AreEqual(queue.pop()->get_data()->get_key(), 3);
			Assert::AreEqual(queue.pop()->get_data()->get_key(), 4);
		}
		TEST_METHOD(TestTwoElementStackPop)
		{
			Stack stack;
			Node new_node(3);
			stack.push(&new_node);
			Node new_node2(4);
			stack.push(&new_node2);
			Assert::AreEqual(stack.pop()->get_data()->get_key(), 4);
			Assert::AreEqual(stack.pop()->get_data()->get_key(), 3);
		}
		TEST_METHOD(TestTwoElementQueueSize)
		{
			Queue queue;
			Node new_node(3);
			queue.push(&new_node); 
			Node new_node2(1);
			queue.push(&new_node2);
			Assert::AreEqual(queue.size(), 2);
		}
		TEST_METHOD(TestTwoElementStackSize)
		{
			Stack stack;
			Node new_node(3);
			stack.push(&new_node);
			Node new_node2(1);
			stack.push(&new_node2);
			Assert::AreEqual(stack.size(), 2);
		}
		TEST_METHOD(TestOneElementStackPeek)
		{
			Stack stack;
			Node new_node(3);
			stack.push(&new_node);
			Node new_node2(5);
			stack.push(&new_node2); 
			Node new_node3(7);
			stack.push(&new_node3);
			Node new_node4(1);
			stack.push(&new_node4);
			Assert::AreEqual(stack.peek()->get_data()->get_key(), 1);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Dkvit\source\repos\АлгСтр_данных_лб3\АлгСтр_данных_лб3\Tree.h"
#include "C:\Users\Dkvit\source\repos\АлгСтр_данных_лб3\АлгСтр_данных_лб3\TreeNode.h"
#include "C:\Users\Dkvit\source\repos\АлгСтр_данных_лб3\АлгСтр_данных_лб3\Tree.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(InitTest1)
		{
			BinaryTree* Tree = new BinaryTree;
			Tree->insert(1);
			Iterator* iter = Tree->create_dft_iterator();
			Assert::IsTrue(iter->next() == 1);
		}

		TEST_METHOD(InitTest2)
		{
			BinaryTree* Tree = new BinaryTree;
			try
			{
				Tree->create_dft_iterator();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is empty");
			}
		}
		TEST_METHOD(InsertTest1)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			Iterator* iter = Tree->create_bft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}

		TEST_METHOD(InsertTest2)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7, 4, 1, 0, 3, 2, 6, 5, 9, 8 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			Iterator* iter = Tree->create_dft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}

		TEST_METHOD(ContainsTest1)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) {
				Tree->insert(arr[i]);
				Assert::IsTrue(Tree->contains(arr[i]));
			}
		}

		TEST_METHOD(ContainsTest2)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			Assert::IsFalse(Tree->contains(11));
		}

		TEST_METHOD(ContainsTest3)
		{
			BinaryTree* Tree = new BinaryTree;
			try
			{
				Tree->contains(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is empty");
			}
		}

		TEST_METHOD(RemoveTest1)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			Tree->remove(1);
			Assert::IsFalse(Tree->contains(1));
		}

		TEST_METHOD(RemoveTest2)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			try
			{
				Tree->remove(11);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "No such element exists");
			}
		}

		TEST_METHOD(RemoveTest3)
		{
			BinaryTree* Tree = new BinaryTree;
			try
			{
				Tree->remove(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "No such element exists");
			}
		}

	};
}
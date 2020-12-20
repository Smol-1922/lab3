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
		TEST_METHOD(BinarTree_Test1)
		{
			BinaryTree* Tree = new BinaryTree;
			Tree->insert(1);
			Iterator* iter = Tree->create_dft_iterator();
			Assert::IsTrue(iter->next() == 1);
		}

		TEST_METHOD(BinarTree_Test2)
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
		TEST_METHOD(BinarTree_Test3)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7,6,9,2,8,10,1,4,3,5 };
			for (int i = 0; i < 10; i++) {
				Tree->insert(arr[i]);
			};
			Iterator* iter = Tree->create_bft_iterator();
			for (int i = 0; i < 10; i++) {
				Assert::IsTrue(arr[i] == iter->next());
			}
		}

		TEST_METHOD(BinarTree_Test4)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = {7,6,2,1,4,3,5,9,8,10 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			Iterator* iter = Tree->create_dft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}

		TEST_METHOD(BinarTree_Test5)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7,6,9,8,10,2,1,4,3,5 };
			for (int i = 0; i < 10; i++) {
				Tree->insert(arr[i]);
				Assert::IsTrue(Tree->contains(arr[i]));
			}
		}

		TEST_METHOD(BinarTree_Test6)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7,6,9,8,10,2,1,4,3,5 };
			for (int i = 0; i < 10; i++) Tree->insert(arr[i]);
			Assert::IsFalse(Tree->contains(15));
		}

		TEST_METHOD(BinarTree_Test7)
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

		TEST_METHOD(BinarTree_Test8)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7,6,9,8,10,2,1,4,3,5 };
			for (int i = 0; i < 10; i++) { 
				Tree->insert(arr[i]);
			}
			Tree->remove(1);
			Assert::IsFalse(Tree->contains(1));
		}

		TEST_METHOD(BinarTree_Test9)
		{
			BinaryTree* Tree = new BinaryTree;
			int arr[10] = { 7,6,9,8,10,2,1,4,3,5 };
			for (int i = 0; i < 10; i++) {
				Tree->insert(arr[i]);
			}
			try
			{
				Tree->remove(16);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "No such element exists");
			}
		}

		TEST_METHOD(BinarTree_Test10)
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
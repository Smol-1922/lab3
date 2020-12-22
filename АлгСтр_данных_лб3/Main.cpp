#include "Tree.h"
#include<iostream>
int main()
{
	Iterator* Iter;
	BinaryTree* Tree = new BinaryTree;
	int array[9] = { 8,3,1,6,4,7,10,14,13 };
	for (int i = 0; i < 9; i++) {
		Tree->insert(array[i]);
	}
	Iter = Tree->create_bft_iterator();
	for (int i = 0; i < 9; i++) {
		std::cout << Iter->next() << " ";
	}
	std::cout << "\n";
	Iter = Tree->create_dft_iterator();
	for (int i = 0; i < 9; i++) {
		std::cout << Iter->next() << " ";
	}
	return 0;
}
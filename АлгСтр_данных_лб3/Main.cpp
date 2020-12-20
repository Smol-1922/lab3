#include "Tree.h"
#include<iostream>
int main()
{
	Iterator* gggg;
	BinaryTree* Tree = new BinaryTree;
	Tree->insert(8);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(6);
	Tree->insert(4);
	Tree->insert(7);
	Tree->insert(10);
	Tree->insert(14);
	Tree->insert(13);
	gggg = Tree->create_bft_iterator();
	for (int i = 0; i < 9; i++) {
		std::cout << gggg->next() << " ";
	}
	std::cout << "\n";
	gggg = Tree->create_dft_iterator();
	for (int i = 0; i < 9; i++) {
		std::cout << gggg->next() << " ";
	}
	return 0;
}
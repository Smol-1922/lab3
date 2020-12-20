#include"Tree.h"
#include"stack.h"
#include <stdexcept>
#include<iostream> 

BinaryTree::BinaryTree()
{
	Root = nullptr;
}
BinaryTree::~BinaryTree()
{
	preOrder(Root); 
}
void BinaryTree::insert(int key)
{
	if (Root == NULL) {
		Root = new Node(key,NULL,NULL);
	}
	else {
		Node* iter;
		iter = Root;
		for (;;) {
			if (key <= iter->key) {
				if (iter->Lnext == NULL) {
					iter->Lnext = new Node(key,iter);
					break;
				}
				iter = iter->Lnext;
			}
			else{
				if (iter->Rnext == NULL) {
					iter->Rnext = new Node(key, iter);
					break;
				}
				iter = iter->Rnext;
			}
		}
	}
}
bool BinaryTree::contains(int key) 
{
	if (Root == NULL) {
		return 0;
	}
	else {
		Node* iter;
		iter = Root;
		for (;;) {
			if (key <= iter->key) {
				if (iter->key == key) {
					return 1;
				}
				if (iter->Lnext == NULL) {
					return 0;
				}
				iter = iter->Lnext;
			}
			else {
				if (iter->key == key) {
					return 1;
				}
				if (iter->Rnext == NULL) {
					return 0;
				}
				iter = iter->Rnext;
			}
		}
	}
}
void BinaryTree::remove(int key)
{
	if (!contains(key)) {
		throw "No such element exists";
	}
	else {
		Node* iter;
		iter = Root;
		if (iter->key == key) {
			if (iter->Lnext == NULL && iter->Rnext == NULL) {
				delete iter;
				return;
			}
			if (iter->Lnext != NULL && iter->Rnext == NULL) {
				iter->Lnext->parent = iter->parent;
				Root = iter->Lnext;
				delete iter;
				return;
			}
			if (iter->Lnext == NULL && iter->Rnext != NULL) {
				iter->Rnext->parent = iter->parent;
				Root = iter->Rnext;
				delete iter;
				return;
			}
			else {
				Node* iter2;
				iter2 = iter->Rnext;
				if (iter2->Lnext != NULL) {
					while (iter2->Lnext != NULL) {
						iter2 = iter2->Lnext;
					}
					iter2->parent->Lnext = NULL;
				}
				else {
					iter2->parent->Rnext = iter2->Rnext;
				}
				iter->Lnext->parent = iter2;
				iter2->Lnext = iter->Lnext;
				iter2->parent = iter->parent;
				while (iter2->Rnext!=NULL)
				{
					iter2 = iter2->Rnext;
				}
				iter->Rnext->parent = iter2;
				iter2->Rnext = iter->Rnext;
				return;
			}
		}
		for (;;) {
			if (key <= iter->key) {
				iter = iter->Lnext;
				if (iter->parent->Lnext->key == key) {
					if (iter->Lnext == NULL && iter->Rnext == NULL) {
						iter->parent->Lnext = NULL;
						delete iter;
						break;
					}
					if (iter->Lnext != NULL && iter->Rnext == NULL) {
						iter->parent->Lnext = iter->Lnext;
						iter->Lnext->parent = iter->parent;
						delete iter;
						break;
					}
					if (iter->Lnext == NULL && iter->Rnext != NULL) {
						iter->parent->Lnext = iter->Rnext;
						iter->Rnext->parent = iter->parent;
						delete iter;
						break;
					}
					else {
						Node* iter2;
						iter2 = iter->Rnext;
						if (iter2->Lnext != NULL) {
							while (iter2->Lnext != NULL) {
								iter2 = iter2->Lnext;
							}
							iter2->parent->Lnext = NULL;
						}
						else {
							iter2->parent->Rnext = iter2->Rnext;
						}
						iter->parent->Lnext = iter2;
						iter->Lnext->parent = iter2;
						iter2->Lnext = iter->Lnext;
						iter2->parent = iter->parent;
						while (iter2->Rnext != NULL)
						{
							iter2 = iter2->Rnext;
						}
						iter->Rnext->parent = iter2;
						iter2->Rnext = iter->Rnext;
						delete iter;
						break;
					}
				}
			}
			else {
				iter = iter->Rnext;
				if (iter->parent->Rnext->key == key) {
					if (iter->Lnext == NULL && iter->Rnext == NULL) {
						iter->parent->Rnext = NULL;
						delete iter;
						break;
					}
					if (iter->Lnext != NULL && iter->Rnext == NULL) {
						iter->parent->Rnext = iter->Lnext;
						iter->Lnext->parent = iter->parent;
						delete iter;
						break;
					}
					if (iter->Lnext == NULL && iter->Rnext != NULL) {
						iter->parent->Rnext = iter->Rnext;
						iter->Rnext->parent = iter->parent;
						delete iter;
						break;
					}
					else {
						Node* iter2;
						iter2 = iter->Rnext;
						if (iter2->Lnext != NULL) {
							while (iter2->Lnext != NULL) {
								iter2 = iter2->Lnext;
							}
							iter2->parent->Lnext = NULL;
						}
						else {
							iter2->parent->Rnext = iter2->Rnext;
						}
						iter->parent->Rnext = iter2;
						iter->Lnext->parent = iter2;
						iter2->Lnext = iter->Lnext;
						iter2->parent = iter->parent;
						while (iter2->Rnext != NULL)
						{
							iter2 = iter2->Rnext;
						}
						iter2->Rnext = iter->Rnext;
						iter->Rnext->parent = iter2;
						delete iter;
						break;
					}
				}

			}
		}
	}

}
BinaryTree::dft_iterator::dft_iterator(Node* root) {
	cur = root;
	if (cur != nullptr) {
		Stack.push(cur);
	}
	else {
		throw "This tree is empty";
	}
}

BinaryTree::dft_iterator::~dft_iterator() {
}
int BinaryTree::dft_iterator::next(){
	int temp = cur->key;
	if (!has_next()) {
		throw "This tree is empty";
	}
	if (cur->Rnext != nullptr) {
		if (flag) {
			Stack.pop_front();
			flag = false;
		}
		Stack.push(cur->Rnext);
	}
	if (cur->Lnext != nullptr) {
		cur = cur->Lnext;
	}
	else
	{

		if (flag) {
			Stack.pop_front();
		}
		if (has_next()) {
			cur = Stack.head->date;
		}
		flag = true;
	}
	return temp;
}

bool BinaryTree::dft_iterator::has_next(){
	if (cur->Lnext == nullptr && cur->Rnext == nullptr && Stack.size == 0) return false;
	else return true;
}
BinaryTree::bft_iterator::bft_iterator(Node* root) {
	cur = root;
	if (cur != nullptr) {
		Queue.push(cur);
	}
	else {
		throw "This tree is empty";
	}

}

BinaryTree::bft_iterator::~bft_iterator() {
	delete cur;
	Queue.clear();
}

int BinaryTree::bft_iterator:: next() {

	if (!has_next()) {
		throw "This tree is empty";
	}
	cur = Queue.head->date;
	Queue.pop();

	if (cur->Lnext != nullptr) {
		Queue.push(cur->Lnext);
	}
	if (cur->Rnext != nullptr) {
		Queue.push(cur->Rnext);
	}
	return cur->key;
}

bool BinaryTree::bft_iterator::has_next() {
	if (cur->Lnext == nullptr && cur->Rnext == nullptr && Queue.size == 0) return false;
	else return true;
}
void BinaryTree::preOrder(Node* node) {
	if (node == nullptr) return;
	preOrder(node->Lnext);
	preOrder(node->Rnext);
	delete node;
}
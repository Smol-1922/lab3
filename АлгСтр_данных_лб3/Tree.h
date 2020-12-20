#ifndef Tree_H
#define Tree_H
#include "iterator.h"
#include"stack.h"
#include"TreeNode.h"
#include"queue.h"
#include <stdexcept>
using namespace std;
class BinaryTree
{
private:
	Node* Root;
public:
    BinaryTree();
	~BinaryTree();
    void preOrder(Node*);
	bool contains(int); // поиск элемента в дереве по ключу
	void insert(int); // добавление элемента в дерево по ключу. Должен работать за O(logN)
	void remove(int); // удаление элемента дерева по ключу

   Iterator* create_bft_iterator() {
        return new bft_iterator(Root);
    }
    Iterator* create_dft_iterator() {
        return new dft_iterator(Root);
    }

   class bft_iterator : public Iterator {
    private:
        Node* cur;
        queue Queue;
    public:
        bft_iterator(Node* root);

        ~bft_iterator();

        int next();

        bool has_next();
    };


    class dft_iterator : public Iterator {
    private:
        Node* cur;
       stack Stack;
        bool flag = true;
    public:
        dft_iterator(Node* root);

        ~dft_iterator();

        int next();

        bool has_next();

    };

};
#endif
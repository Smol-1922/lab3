#ifndef Tree_H
#define Tree_H
#include "iterator.h"
#include"stack.h"
#include"TreeNode.h"
#include"queue.h"
#include <stdexcept>
class BinaryTree
{
private:
	Node* Root;
public:
	BinaryTree();
	~BinaryTree();
	bool contains(int); // ����� �������� � ������ �� �����
	void insert(int); // ���������� �������� � ������ �� �����. ������ �������� �� O(logN)
	void remove(int); // �������� �������� ������ �� �����
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
        bft_iterator(Node* root) {
            cur = root;
            if (cur != nullptr) {
                Queue.push(cur);
            }
            else {
                throw "This tree is empty";
            }

        }

        ~bft_iterator() {
            delete cur;
            Queue.clear();
        }

        int next() override {
           
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

        bool has_next() override {
            if (cur->Lnext == nullptr && cur->Rnext == nullptr && Queue.size == 0) return false;
            else return true;
        }
    };


    class dft_iterator : public Iterator {
    private:
        Node* cur;
        stack Stack;
        bool flag = true;
    public:
        dft_iterator(Node* root) {
            cur = root;
            if (cur != nullptr) {
               Stack.push(cur);
            }
            else {
                throw "This tree is empty";
            }
        }

        ~dft_iterator() {
            delete cur;
            Stack.clear();
        }

        int next() override {
            int temp= cur->key;
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

        bool has_next() override {
            if (cur->Lnext == nullptr && cur->Rnext == nullptr&& Stack.size==0) return false;
            else return true;
        }

    };

};
#endif
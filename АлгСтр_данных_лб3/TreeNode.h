#ifndef TreeNode_H
#define TreeNode_H
class Node {
public:
	int key;
	Node* Lnext;
	Node* Rnext;
	Node* parent;
	Node(int key, Node* parent, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->parent = parent;
		this->key = key;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};
	~Node()
	{
		int key;
		Lnext = nullptr;
		Rnext = nullptr;
		parent = nullptr;

	}

};
#endif
#pragma once
#include "BTree.h"
#include <queue>

using namespace std;

class BinarySearchTree
{
private:
	node*	root;
	void Insert(node* &n, int val);
	void DestroyTree(node* &n);
	node* Search(node* &n, int val);
	node* Search(node* &n, queue<node*> &searchQueue, int val);
	void FlipTree(node* n);

public:
	BinarySearchTree();
	void Insert(int val);
	node* Search(int val);
	void DestroyTree();
	void PrintLevels();
	void FlipTree();
	node* FindCommonParent(int val1, int val2);
	~BinarySearchTree();
};


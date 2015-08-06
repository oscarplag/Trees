#pragma once
#include <stack>
#include <queue>

using namespace std;

struct node
{
	node* left_child;
	node* right_child;
	int key_val;
	node(int key)
	{
		key_val = key;
		left_child = NULL;
		right_child = NULL;
	}
	node(int key, node* left, node* right)
	{
		key_val = key;
		left_child = left;
		right_child = right;
	}
	node()
	{
		key_val = 0;
		left_child = NULL;
		right_child = NULL;
	}
};

class BST
{
public:
	BST(void);
	~BST(void);
	void destroy_tree();
	node* search_tree(int key);
	queue<node*> search_tree_queue(int key);
	void insert_node(int key);
	void printLevels();
	void flipTree();
	node* findCommonParent(int val1, int val2);

private:
	node* root;
	void destroy_tree(node* n);
	node* search_tree(node* n, int key);
	node* search_tree(node* n, queue<node*>& st, int key);
	void insert_node(node* n, int key);
	void printLevels(node* n);
	void flipTree(node* n);
};


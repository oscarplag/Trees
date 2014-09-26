#pragma once
#include <stack>
#include <queue>

using namespace std;

struct node
{
	node* parent;
	node* left_child;
	node* right_child;
	int key_val;
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
	node* findCommonParent_NoParent(int val1, int val2);

private:
	node* root;
	void destroy_tree(node* n);
	node* search_tree(node* n, int key);
	node* search_tree(node* n, queue<node*>& st, int key);
	void insert_node(node* n, int key);
	void printLevels(node* n);
	node* flipTree(node* n);
	node* findCommonParent(node* n1, node* n2);

	void buildAncestorStack(node* n, stack<node*>& stack);
};


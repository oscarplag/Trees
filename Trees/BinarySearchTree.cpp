#include "StdAfx.h"
#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}


BinarySearchTree::~BinarySearchTree()
{
	DestroyTree();
}

void BinarySearchTree::Insert(node* &n, int val)
{
	if (n == NULL)
	{
		n = new node(val);
	}
	else if (val < n->key_val)
		Insert(n->left_child, val);
	else
		Insert(n->right_child, val);

}

void BinarySearchTree::Insert(int val)
{
	Insert(root, val);
}

void BinarySearchTree::DestroyTree(node* &n)
{
	if (n->left_child)
		DestroyTree(n->left_child);
	if (n->right_child)
		DestroyTree(n->right_child);
	delete n;
	n = NULL;
}

void BinarySearchTree::DestroyTree()
{
	if (root == NULL)
		return;
	else
		DestroyTree(root);
}

node* BinarySearchTree::Search(node* &n, int val)
{
	if (n == NULL)
		return NULL;
	else if (val == n->key_val)
		return n;
	else if (val < n->key_val)
		return Search(n->left_child, val);
	else
		return Search(n->right_child, val);
}

node* BinarySearchTree::Search(int val)
{
	return Search(root, val);
}

void BinarySearchTree::PrintLevels()
{
	if (root == NULL)
		return;

	queue<node*> myQueue;
	
	myQueue.push(root);

	while (!myQueue.empty())
	{
		queue<node*> tempQueue;

		while (!myQueue.empty())
		{
			node* n = myQueue.front();
			myQueue.pop();

			if (n->left_child)
				tempQueue.push(n->left_child);
			if (n->right_child)
				tempQueue.push(n->right_child);

			cout << n->key_val << " ";
		}
		cout << endl;
		while (!tempQueue.empty())
		{
			myQueue.push(tempQueue.front());
			tempQueue.pop();
		}

	}
}

void BinarySearchTree::FlipTree(node* n)
{
	if (n == NULL)
		return;
	else if (n->left_child == NULL)
		root = n;
	else
	{
		FlipTree(n->left_child);

		n->left_child->left_child = n->right_child;
		n->left_child->right_child = n;
		n->left_child = NULL;
		n->right_child = NULL;
	}
}

void BinarySearchTree::FlipTree()
{
	FlipTree(root);
}

node* BinarySearchTree::Search(node* &n, queue<node*> &searchQueue, int val)
{
	if (n == NULL)
	{
		while (!searchQueue.empty())
			searchQueue.pop();
		return NULL;
	}
	searchQueue.push(n);
	
	if (val == n->key_val)
		return n;
	else if (val < n->key_val)
		return Search(n->left_child, searchQueue, val);
	else
		return Search(n->right_child, searchQueue, val);
}

node* BinarySearchTree::FindCommonParent(int val1, int val2)
{
	queue<node*> q1;
	queue<node*> q2;

	Search(root, q1, val1);
	Search(root, q2, val2);

	if (q1.empty() || q2.empty())
		return NULL;

	node* commonParent = NULL;

	while (!q1.empty() && !q2.empty() && q1.front() == q2.front())
	{
		commonParent = q1.front();
		q1.pop();
		q2.pop();
	}

	return commonParent;
}
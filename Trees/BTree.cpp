#include "StdAfx.h"
#include "BTree.h"
#include <queue>
#include <list>
#include <stack>


BST::BST(void)
{
	root = NULL;
}

BST::~BST(void)
{
	destroy_tree();
}

void BST::destroy_tree()
{
	destroy_tree(root);
}

void BST::destroy_tree(node* n)
{
	if(n!=NULL)
	{
		destroy_tree(n->left_child);
		destroy_tree(n->right_child);
		delete n;
	}
}

node* BST::search_tree(int key)
{
	return search_tree(root,key);
}

node* BST::search_tree(node* n, int key)
{
	if (n == NULL)
		return NULL;

	if(key<n->key_val)
	{
		return search_tree(n->left_child,key);
	}
	else if(key>n->key_val)
	{
		return search_tree(n->right_child,key);
	}
	else
		return n;
}

void BST::insert_node(int key)
{
	if(root == NULL)
	{
		root = new node();
		root->key_val = key;
		root->left_child = NULL;
		root->right_child = NULL;
	}
	else
		insert_node(root,key);
}

void BST::insert_node(node* n, int key)
{
	if(key<n->key_val)
	{
		if(n->left_child==NULL)
		{
			n->left_child = new node();
			n->left_child->key_val = key;
			n->left_child->left_child = NULL;
			n->left_child->right_child = NULL;
		}
		else
			insert_node(n->left_child,key);
	}
	else
	{
		if(n->right_child == NULL)
		{
			n->right_child = new node();
			n->right_child->key_val = key;
			n->right_child->left_child = NULL;
			n->right_child->right_child = NULL;
		}
		else
		{
			insert_node(n->right_child,key);
		}
	}

}

void BST::printLevels()
{
	printLevels(root);
}

void BST::printLevels(node* n)
{
	std::queue<node*,std::list<node*>> myQueue;

	myQueue.push(n);

	while(!myQueue.empty())
	{
		std::queue<node*, std::list<node*>> myList;

		while(!myQueue.empty())
		{
			node* myNode = myQueue.front();
			myQueue.pop();
			printf("%d ", myNode->key_val);
			if(myNode->left_child != NULL)
				myList.push(myNode->left_child);
			if(myNode->right_child != NULL)
				myList.push(myNode->right_child);
		}
		printf("\n");

		while(!myList.empty())
		{
			myQueue.push(myList.front());
			myList.pop();
		}
	}
}

void BST::flipTree()
{
	flipTree(root);
}

void BST::flipTree(node* n)
{
	if(n->left_child != NULL)
	{
		flipTree(n->left_child);
	}
	
	if(n->left_child==NULL)
	{	
		root = n;
		//return n;
	}
	else
	{
		n->left_child->left_child = n->right_child;
		n->left_child->right_child = n;
		n->left_child = NULL;
		n->right_child = NULL;
	}
	//return n;
}

node* BST::findCommonParent(int val1, int val2)
{
	queue<node*>q1 = search_tree_queue(val1);
	if(q1.empty())
		return NULL;
	queue<node*>q2 = search_tree_queue(val2);
	if(q2.empty())
		return NULL;

	node* commonParent = NULL;

	while(!q1.empty() && !q2.empty() && q1.front() == q2.front() )
	{
		commonParent = q1.front();
		q1.pop();
		q2.pop();
	}

	return commonParent;
}

queue<node*> BST::search_tree_queue(int key)
{
	queue<node*> q;
	node* n = search_tree(root,q,key);
	if(n==NULL)
	{
		queue<node*> emp;
		return emp;
	}
	return q;
}

node* BST::search_tree(node* n, queue<node*>& q, int key)
{
	q.push(n);
	if(key<n->key_val)
	{
		if(n->left_child == NULL)
			return NULL;
		else
			return search_tree(n->left_child,q,key);
	}
	else if(key>n->key_val)
	{
		if(n->right_child == NULL)
			return NULL;
		else
			return search_tree(n->right_child,q,key);
	}
	else
		return n;
}
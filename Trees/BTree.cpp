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
	if(key<n->key_val)
	{
		if(n->left_child == NULL)
			return NULL;
		else
			return search_tree(n->left_child,key);
	}
	else if(key>n->key_val)
	{
		if(n->right_child == NULL)
			return NULL;
		else
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
		root->parent = NULL;
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
			n->left_child->parent = n;
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
			n->right_child->parent = n;
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
	std::queue<node*> myQueue;

	myQueue.push(n);

	while(!myQueue.empty())
	{
		std::list<node*> myList;

		while(!myQueue.empty())
		{
			node* myNode = myQueue.front();
			myQueue.pop();
			printf("%d ", myNode->key_val);
			if(myNode->left_child != NULL)
				myList.push_back(myNode->left_child);
			if(myNode->right_child != NULL)
				myList.push_back(myNode->right_child);
		}
		printf("\n");

		while(!myList.empty())
		{
			myQueue.push(myList.front());
			myList.pop_front();
		}
	}
}

void BST::flipTree()
{
	flipTree(root);
}

node* BST::flipTree(node* n)
{
	if(n->left_child != NULL)
	{
		flipTree(n->left_child);
	}


	//if(n->left_child == NULL)
	//{
	//	root = n;
	//}
	//if(n->parent!=NULL)
	//{
	//	n->left_child = n->parent->right_child;
	//	n->right_child = n->parent;
	//}
	//else
	//{
	//	n->left_child = NULL;
	//	n->right_child = NULL;
	//}

	
	if(n->left_child==NULL)
	{	
		root = n;
		//n->parent = NULL;
		return n;
	}
	else
	{
		n->left_child->left_child = n->right_child;
		n->left_child->right_child = n;
		n->left_child = NULL;
		n->right_child = NULL;
		//n->parent = n->left_child;
	}
	return n;
}

node* BST::findCommonParent(int val1, int val2)
{
	node* n1 = BST::search_tree(val1);
	if(n1 == NULL)
		return NULL;
	node* n2 = BST::search_tree(val2);
	if(n2 == NULL)
		return NULL;

	return findCommonParent(n1,n2);

}

node* BST::findCommonParent(node* n1, node* n2)
{
	stack<node*> s1;
	stack<node*> s2;

	buildAncestorStack(n1,s1);
	buildAncestorStack(n2,s2);

	node* commonParent = NULL;

	while(!s1.empty() && !s2.empty() && s1.top() == s2.top() )
	{
		commonParent = s1.top();
		s1.pop();
		s2.pop();
	}

	return commonParent;
}

void BST::buildAncestorStack(node* n, stack<node*>& stack)
{
	if(n->parent!=NULL)
	{
		stack.push(n->parent);
		buildAncestorStack(n->parent, stack);
	}
}

node* BST::findCommonParent_NoParent(int val1, int val2)
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
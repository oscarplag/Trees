#include "StdAfx.h"
#include "LRU.h"


LRU::LRU(int capacity)
{
	_capacity = capacity;
	_nodeCount = 0;
	_head = NULL;
	_end = NULL;
}


LRU::~LRU()
{
}

void LRU::remove(LRUNode* n)
{
	if (n->prev != NULL)
		n->prev->next = n->next;
	else
		_head = n->next;

	if (n->next != NULL)
		n->next->prev = n->prev;
	else
		_end = n->prev;
}

void LRU::setHead(LRUNode* n)
{
	n->next = _head;
	n->prev = NULL;

	if (_head != NULL)
		_head->prev = n;

	_head = n;

	if (_end == NULL)
		_end = _head;
}

void LRU::Insert(int key, int value)
{
	if (myMap.count(key))
	{
		LRUNode* oldNode = myMap[key];
		oldNode->value = value;
		remove(oldNode);
		setHead(oldNode);
	}
	else
	{
		LRUNode* newNode = new LRUNode(key, value);
		if (_nodeCount < _capacity)
		{
			if (_head == NULL)
			{
				_head = newNode;
				_end = _head;
			}
			else
			{
				setHead(newNode);
			}
			_nodeCount++;
		}
		else
		{
			myMap.erase(_end->key);
			LRUNode* temp = _end;
			remove(_end);
			setHead(newNode);
			delete temp;			
		}
		myMap[key] = newNode;
	}
}

int LRU::Get(int key)
{
	if (myMap.count(key))
	{
		LRUNode* temp = myMap[key];
		remove(temp);
		setHead(temp);
		return temp->value;
	}
	return -1;
}
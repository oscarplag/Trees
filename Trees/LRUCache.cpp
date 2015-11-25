#include "StdAfx.h"
#include "LRUCache.h"


LRUCache::LRUCache(int cap)
{
	head = NULL;
	end = NULL;
	capacity = cap;
}


LRUCache::~LRUCache()
{
}


void LRUCache::remove(CacheNode* n)
{
	if (n->pre)
		n->pre->next = n->next;
	else
		head = n->next;

	if (n->next)
		n->next->pre = n->pre;
	else
		end = n->pre;
}
void LRUCache::setHead(CacheNode* n)
{
	n->next = head;
	n->pre = NULL;

	if (head)
		head->pre = n;
	head = n;

	if (!end)
		end = head;
}

int LRUCache::get(int key)
{
	myMux.lock();
	if (myMap.count(key))
	{
		CacheNode* n = myMap[key];
		remove(n);
		setHead(n);
		myMux.unlock();
		return n->value;
	}
	else
	{
		myMux.unlock();
		return -1;
	}
}
void LRUCache::set(int key, int value)
{
	myMux.lock();
	if (myMap.count(key))
	{
		CacheNode* old = myMap[key];
		old->value = value;
		remove(old);
		setHead(old);
	}
	else
	{
		CacheNode* newNode = new CacheNode(key, value);
		if (myMap.size() >= capacity)
		{
			myMap.erase(end->key);
			CacheNode* temp = end;
			remove(end);
			delete temp;
			setHead(newNode);
		}
		else
			setHead(newNode);
		myMap[key] = newNode;
	}
	myMux.unlock();
}
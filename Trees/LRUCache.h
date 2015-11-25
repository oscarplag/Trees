#include<map>
#include<mutex>

using namespace std;
struct CacheNode
{
	int key;
	int value;
	CacheNode* pre;
	CacheNode* next;
	CacheNode(int Key, int Val)
	{
		key = Key;
		value = Val;
		pre = NULL;
		next = NULL;
	}
};

#pragma once
class LRUCache
{
private:
	mutex myMux;
	CacheNode* head;
	CacheNode* end;
	int capacity;
	map<int, CacheNode*> myMap;
	void remove(CacheNode* n);
	void setHead(CacheNode* n);
public:
	LRUCache(int cap);
	~LRUCache();
	int get(int key);
	void set(int key, int value);
};


#pragma once
#include <map>

struct LRUNode
{
	int key;
	int value;
	LRUNode* next;
	LRUNode* prev;

	LRUNode(int Key, int Value)
	{
		key = Key;
		value = Value;
		next = NULL;
		prev = NULL;
	};
	LRUNode(int Key, int Value, LRUNode* Next, LRUNode* Prev)
	{
		key = Key;
		value = Value;
		next = Next;
		prev = Prev;
	}
	LRUNode()
	{
		key = 0;
		value = 0;
		next = NULL;
		prev = NULL;
	}
};

class LRU
{
private:
	std::map<int, LRUNode*> myMap;
	LRUNode* _head;
	LRUNode* _end;
	void remove(LRUNode* n);
	void setHead(LRUNode* n);
	int _capacity;
	int _nodeCount;

public:
	LRU(int capacity);
	~LRU();
	void Insert(int key, int value);
	int Get(int key);
};


#pragma once
#include <list>
#include <iterator>
#include <vector>

using namespace std;

class NestedList
{
private:
	vector<NestedList*> _nestedList;
	bool _isInt;
	int _val;
	int _getSum(NestedList* ni,int depth);
	void deleteList();
public:
	NestedList(int val);
	NestedList(void);
	~NestedList(void);
	void addInt(int val);
	void addList();

	std::vector<NestedList*>::iterator begin();
	std::vector<NestedList*>::iterator NestedList::end();

	NestedList* operator[](int index) const;

	bool isInteger();
	int getInteger();
	NestedList* getList();
	int getSum();

	NestedList* At(int index);
};


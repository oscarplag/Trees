#include "StdAfx.h"
#include "NestedList.h"

NestedList::NestedList(int val)
{
	_val = val;
	_isInt = true;
}

NestedList::NestedList(void)
{
	_isInt = false;
}

NestedList::~NestedList(void)
{
	while(!_nestedList.empty())
	{
		NestedList* temp = _nestedList.back();
		delete[] temp;
		_nestedList.pop_back();
	}
}

void NestedList::addInt(int val)
{
	_nestedList.push_back(new NestedList(val));
}

void NestedList::addList()
{
	_nestedList.push_back(new NestedList());
}

std::vector<NestedList*>::iterator NestedList::begin()
{
	return _nestedList.begin();
}

std::vector<NestedList*>::iterator NestedList::end()
{
	return _nestedList.end();
}

NestedList* NestedList::operator[](int index) const
{
	return _nestedList[index];
}

bool NestedList::isInteger()
{
	return _isInt;
}

int NestedList::getInteger()
{
	if(!_isInt)
		throw -1;
	else
		return _val;
}

NestedList NestedList::getList()
{
	if(_isInt)
		throw -2;
	else
		return *this;
}

int NestedList::getSum()
{
	if(_isInt)
		return _val;
	else
		return _getSum(*this,1);
}

int NestedList::_getSum(NestedList ni,int depth)
{
	int sum = 0;
	for(std::vector<NestedList*>::iterator it = ni.begin();it!=ni.end();++it)
	{
		NestedList* temp = *it;
		if(temp->isInteger())
			sum += temp->getInteger()*depth;
		else
			sum += _getSum(temp->getList(),depth+1);
	}
	return sum;
}
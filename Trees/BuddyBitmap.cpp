#include "StdAfx.h"
#include "BuddyBitmap.h"
#include <queue>


BuddyBitmap::BuddyBitmap(vector<int> arr)
{
	_arr = arr;
}


BuddyBitmap::~BuddyBitmap()
{
}

void BuddyBitmap::SetBits(int index, int length)
{
	if (_arr.empty() || index >= _arr.size() || length<=0 || index<0)
		return;
	if (_arr[index] == 1) //already set do nothing
		return;

	int upper_bound = _arr.size();
	if ((index + length) < upper_bound) // check to see if index+length is smaller than vector boundary
		upper_bound = index + length;
	if ((2 * index +1) < upper_bound) //check to see if we hit the child of node at index
		upper_bound = 2 * index+1;

	//Set bits down
	for (int i = index; i < upper_bound; i++)
	{
		if (_arr[i] == 1)
			continue;
		_arr[i] = 1;
		SetBitsDown(i);
		SetBitsUp(i);
	}
}

void BuddyBitmap::SetBitsDown(int index)
{
	int upper_bound = _arr.size();
	if (index >= upper_bound)
		return;
	int left_child = 2 * index+1;
	int right_child = left_child + 1;

	if (left_child < upper_bound && _arr[left_child] == 0)
	{
		_arr[left_child] = 1;
		SetBitsDown(left_child);
	}
	if (right_child < upper_bound && _arr[right_child] == 0)
	{
		_arr[right_child] = 1;
		SetBitsDown(right_child);
	}
}

void BuddyBitmap::SetBitsUp(int index)
{
	if (index <= 0)
		return;
	//check to see if current node's sibiling is 1 and if so set the parent
	if ((index % 2 == 1 && index < _arr.size() && _arr[index + 1] == 1) || (index % 2 == 0 && _arr[index - 1] == 1))
	{
		_arr[(index - 1) / 2] = 1;
		SetBitsUp((index-1)/2);
	}
}

void BuddyBitmap::ClearBits(int index, int length)
{
	if (_arr.empty() || index >= _arr.size() || length <= 0 || index<0)
		return;
	if (_arr[index] == 0)
		return;

	int upper_bound = _arr.size();
	if ((index + length) < upper_bound)
		upper_bound = index + length;
	for (int i = index; index < upper_bound; index++)
	{
		_arr[index] = 0;
		ClearBitsDown(index);
		ClearBitsUp(index);
	}
}

void BuddyBitmap::ClearBitsDown(int index)
{
	int left_child = 2 * index + 1;
	if (left_child >= _arr.size())
		return;
	_arr[left_child] = 0;
	ClearBitsDown(left_child);
}

void  BuddyBitmap::ClearBitsUp(int index)
{
	int parent = (index - 1) / 2;
	if (parent <= 0)
		return;	
	if (_arr[parent] == 0)
		return;
	_arr[parent] = 0;
	ClearBitsUp(parent);
}

void BuddyBitmap::PrintMap()
{
	queue<int> myQueue;
	myQueue.push(0);
	int upper_bound = _arr.size();

	float queueDepth = log((float)upper_bound) / log((float)2);

	int depthCounter = 0;

	while (!myQueue.empty())
	{
		queue<int> tempQueue;
		while (!myQueue.empty())
		{
			tempQueue.push(myQueue.front());
			myQueue.pop();
		}

		for (int i = depthCounter; i<queueDepth - 1; i++)
		{
			cout << " ";
		}
		cout << " ";

		while (!tempQueue.empty())
		{
			int temp = tempQueue.front();
			tempQueue.pop();
			cout << _arr[temp] << " ";

			int left_child = temp * 2 + 1;
			int right_child = left_child + 1;
			if (left_child < upper_bound)
			{
				myQueue.push(left_child);
				int right_child = left_child + 1;
				if (right_child < upper_bound)
					myQueue.push(right_child);
			}			
		}
		cout << endl;
		depthCounter++;
	}
}
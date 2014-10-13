#include "StdAfx.h"
#include "Heap.h"
#include <queue>
#include <iostream>
#include <math.h>

Heap::Heap(int minMax)
{
	if(minMax<0)
		arr.push_back(-1);
	else
		arr.push_back(1);
}


Heap::~Heap(void)
{
}

int Heap::top()
{
	return arr[1];
}

int Heap::pop()
{
	int top = arr[1];
	arr[1] = arr.back();
	arr.pop_back();
	if(arr[0]==-1)
		perc_down_min(arr[1],1);
	else
		perc_down_max(arr[1],1);

	return top;
}

void Heap::perc_down_min(int val, int pos)
{
	int size = arr.size();

	if(2*pos>=size)
		return;
	else if((2*pos)+1>=size)
	{
		int temp = arr[2*pos];
		if(val < temp)
			return;
		else
		{
			arr[pos] = temp;
			arr[2*pos] = val;
			return;
		}
	}
	else
	{
		int left = arr[2*pos];
		int right = arr[(2*pos)+1];

		if(left<right)
		{
			if(val>left)
			{
					arr[pos] = left;
					arr[2*pos] = val;
					perc_down_min(val,2*pos);
			}
			else
				return;
		}
		else if(val>right)
		{
				arr[pos] = right;
				arr[(2*pos)+1] = val;
				perc_down_min(val,(2*pos+1));
		}
		else
			return;
	}
}

void Heap::perc_down_max(int val, int pos)
{
	int size = arr.size();

	if(2*pos>=size)
		return;
	else if((2*pos)+1>=size)
	{
		int temp = arr[2*pos];
		if(val > temp)
			return;
		else
		{
			arr[pos] = temp;
			arr[2*pos] = val;
			return;
		}
	}
	else
	{
		int left = arr[2*pos];
		int right = arr[(2*pos)+1];

		if(left>right)
		{
			if(val<left)
			{
					arr[pos] = left;
					arr[2*pos] = val;
					perc_down_max(val,2*pos);
			}
			else
				return;
		}
		else if(val<right)
		{
				arr[pos] = right;
				arr[(2*pos)+1] = val;
				perc_down_min(val,(2*pos+1));
		}
		else
			return;
	}
}


void Heap::insert(int val)
{
	arr.push_back(val);

	int i = arr.size()-1;

	if(arr[0]== -1)
		perc_up_min(val,i);
	else
		perc_up_max(val,i);
}

void Heap::perc_up_min(int val, int pos)
{
	if(pos == 1)
		return;

	int parent = arr[pos/2];
	if(val<parent)
	{
		arr[pos/2] = val;
		arr[pos] = parent;
		perc_up_min(val,pos/2);
	}
	else
		return;
}

void Heap::perc_up_max(int val, int pos)
{
	if(pos == 1)
		return;

	int parent = arr[pos/2];
	if(val>parent)
	{
		arr[pos/2] = val;
		arr[pos] = parent;
		perc_up_max(val,pos/2);
	}
	else
		return;
}

void Heap::print_heap()
{
	int size = arr.size();
	queue<int> myQueue;

	float queueDepth = log((float)size)/log((float)2);
	//int maxDepth = (int)queueDepth;

	myQueue.push(1);

	int depthCounter = 0;

	while(!myQueue.empty())
	{
		queue<int> tempQueue;
		while(!myQueue.empty())
		{
			tempQueue.push(myQueue.front());
			myQueue.pop();
		}
		for(int i = depthCounter;i<queueDepth-1;i++)
		{
				cout << "   ";
		}
		cout << " ";

		depthCounter++;
		while(!tempQueue.empty())
		{			
			int temp = tempQueue.front();
			tempQueue.pop();

			printf("%2d ",arr[temp]);
			//cout << arr[temp] << " ";

			int pos = 2*temp;
			if(pos<size)
			{
				myQueue.push(pos);
				pos = 2*temp+1;
				if(pos<size)
				{
					myQueue.push(pos);
				}
			}	
		}
		cout << endl;
	}
}
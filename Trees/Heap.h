#pragma once
#include <vector>

using namespace std;

class Heap
{
private:
	vector<int> arr;
	void perc_up_min(int val, int pos);
	void perc_down_min(int val, int pos);
	void perc_up_max(int val, int pos);
	void perc_down_max(int val, int pos);

public:
	Heap(int minMax);
	~Heap(void);
	int top();
	int pop();
	void insert(int val);

	void print_heap();
};


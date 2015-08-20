#pragma once
#include<vector>
#include<iostream>

using namespace std;

class BuddyBitmap
{
private:
	vector<int> _arr;
	void SetBitsDown(int index);
	void SetBitsUp(int index);
	void ClearBitsDown(int index);
	void ClearBitsUp(int index);
public:
	BuddyBitmap(vector<int> arr);
	~BuddyBitmap();
	void SetBits(int index, int length);
	void ClearBits(int index, int length);
	void PrintMap();
};


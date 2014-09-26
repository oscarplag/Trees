#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class WordJustifier
{
private:
	vector<string> stringList;
	vector<string> justified;
	vector<int> costs;
	vector<int> lineStarts;
	void solveWordWrap (int l[], int n, int M);
	void solveWordWrapCustom(vector<int> lengths, int M);
	int printSolution (int p[], int n);
	void justifyStrings(int n);
public:
	WordJustifier(vector<string> list);
	~WordJustifier(void);

	void Justify(int M);
	void JustifyCustom(int M);
	void print();
};


#pragma once
#include <vector>

using namespace std;

static class pickNumber 
{ 
public:
	static bool canIWin (int maxNumber, int target);	
	static bool canIWin(int maxNumber, int target, vector<int> players, int times, vector<bool> visited); 
} ;
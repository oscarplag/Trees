#include "StdAfx.h"
#include "PickNumber.h"

bool pickNumber::canIWin (int maxNumber, int target)
{ 
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(0);
	vector<bool> temp2;
	for(int i = 0; i<maxNumber; i++)
	{
		temp2.push_back(false);
	}

	return canIWin(maxNumber, target, temp, 0, temp2); 
} 

bool pickNumber::canIWin(int maxNumber, int target, vector<int> players, int times, vector<bool> visited)
{ 
	int count = 0; 
	for(int i = 0; i<visited.size();i++)//bool b : visited) 
	{ 
		bool b = visited[i];
		if(!b) count++; 
	} 
	if(count == 0)
		return false; 
	if(times % 2 == 0) 
	{ 
		for(int i = 1; i <= maxNumber; i++) 
		{ 
			if(!visited[i - 1]) 
			{ 
				visited[i - 1] = true; 
				players[0] += i; 
				if(players[0] >= target || canIWin(maxNumber, target, players, times + 1, visited)) 
					return true; 
				visited[i - 1] = false; 
				players[0] -= i; 
			} 
		} 
	} 
	else 
	{ 
		for(int i = 1; i <= maxNumber; i++) 
		{ 
			bool b = false; 
			if(!visited[i - 1] && players[1] + i < target) 
			{ 
				b = true; 
				visited[i - 1] = true; 
				players[1] += i; 
				if(canIWin(maxNumber, target, players, times + 1, visited)) 
					return true; 
				visited[i - 1] = false; 
				players[1] -= i; 
			} 
			if(!b) 
				return false; 
		} 
	} 
	return false; 
} 
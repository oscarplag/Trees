#include "StdAfx.h"
#include "HundredGame.h"


HundredGame::HundredGame(int maxVal, int desiredTotal)
{
	_desiredTotal = desiredTotal;
	for(int i = 0; i<maxVal;i++)
	{
		_nums.push_back(i+1);
	}
}


HundredGame::~HundredGame(void)
{
}

bool HundredGame::canIWin(vector<int> vals, int total)
{
	if (total <= 0) 
	{
		return false;
	}
	for(int i = 0; i < vals.size(); ++i) 
	{
		int newTotal = total - vals[i];
		vector<int> tempList = remove(vals,vals[i]);
		if (!canIWin(tempList, newTotal)) 
		{
			return true;
		}
	}
	return false;
}
 
bool HundredGame::canIWinCustom(vector<int> vals, int total, bool myTurn)
{
	if (total <= 0 ) 
	{
		if(myTurn)
			return true;
		else
			return false;
	}
	for(int i = 0; i < vals.size(); ++i) 
	{
		int newTotal = total - vals[i];
		vector<int> tempList = remove(vals,vals[i]);
		return(canIWinCustom(tempList,newTotal,!myTurn));
		//if(!canIWinCustom(tempList,newTotal,!myTurn))
		//	return false;
	}
	return true;
}
bool HundredGame::canIWinCustom2()
{
	for(int i = 0; i<_nums.size();i++)
	{
		int newTotal = _desiredTotal - _nums[i];
		vector<int>tempList = remove(_nums,_nums[i]);

		if(canIWinCustom(tempList,newTotal,true))
			return true;
	}
	return false;
}

vector<int> HundredGame::remove(vector<int> temp, int tempVal)
{
	vector<int> tempList;

	for(int i = 0; i<temp.size();i++)
	{
		if(temp[i]!=tempVal)
		{
			tempList.push_back(temp[i]);
		}
	}
	return tempList;
}

bool HundredGame::canIWin()
{
	return canIWin(_nums,_desiredTotal);
}

bool HundredGame::canIWinCustom()
{
	return canIWinCustom(_nums,_desiredTotal,false);
}
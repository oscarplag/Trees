#pragma once
#include <vector>

using namespace std;

class HundredGame
{
private:
	vector<int> _nums;
	int _desiredTotal;
	bool canIWin(vector<int>vals, int total);
	vector<int> HundredGame::remove(vector<int> temp, int tempVal);
	bool canIWinCustom(vector<int> vals, int total, bool myTurn);
	bool canIWinCustom2(vector<int> vals, int total, bool myTurn);


public:
	HundredGame(int maxVal, int desiredTotal);
	~HundredGame(void);
	bool canIWin();
	bool canIWinCustom();
	bool canIWinCustom2();
	
};


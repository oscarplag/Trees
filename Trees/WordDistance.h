#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

class WordDistance
{
private:
	map<string,vector<int>*> indecies;
	multimap<string, int> indeceisMulti;
public:
	WordDistance(vector<string> words);
	~WordDistance(void);
	int getDistance(string &str1, string &str2);
	int getDistanceMulti(string &str1, string& str2);
};


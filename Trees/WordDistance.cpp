#include "StdAfx.h"
#include "WordDistance.h"


WordDistance::WordDistance(vector<string> words)
{
	for(std::vector<string>::iterator it = words.begin();it!=words.end();++it)
	{
		if(indecies.count(*it)!=0)
		{
			vector<int>* temp = indecies[*it];
			temp->push_back(it-words.begin());
		}
		else
		{
			vector<int>* temp = new vector<int>[1];
			temp->push_back(it-words.begin());
			indecies.emplace(pair<string,vector<int>*>(*it,temp));
		}
	}
}


WordDistance::~WordDistance(void)
{
}

int WordDistance::getDistance(string &str1, string &str2)
{
	if(indecies.count(str1)==0)
		return -1;
	if(indecies.count(str2)==0)
		return -1;

	int minDist = INT_MAX;

	vector<int>* indecies1 = indecies[str1];
	vector<int>* indecies2 = indecies[str2];
	std::vector<int>::iterator it1 = indecies1->begin();
	std::vector<int>::iterator it2 = indecies2->begin();

	for(it1,it2;it1!=indecies1->end()&&it2!=indecies2->end();)
	{
		int distance = abs(*it1-*it2);
		if(distance<minDist)
			minDist = distance;

		if(it2 != indecies2->end()-1)
		{
			int next = abs(*it1-*(++it2));
			if(next>distance)
			{
				it1++;
				it2--;
			}
		}
		else
			it1++;
	}
	

	/*
	for(std::vector<int>::iterator it = indecies[str1]->begin();it!=indecies[str1]->end();++it)
	{
		int index1 = *it;
		for(std::vector<int>::iterator it2 = indecies[str2]->begin();it2!=indecies[str2]->end();++it2)
		{
			int dist = abs(*it-*it2);
			if(dist<minDist)
				minDist = dist;
		}
	}*/
	return minDist;
}
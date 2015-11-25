#include "StdAfx.h"
#include "WordDistance.h"
#include <iostream>

WordDistance::WordDistance(vector<string> words)
{
	for(std::vector<string>::iterator it = words.begin();it!=words.end();++it)
	{
		indeceisMulti.insert(pair<string, int>(*it, it - words.begin()));
		if(indecies.count(*it)!=0)
		{
			vector<int>* temp = indecies[*it];
			temp->push_back(it-words.begin());
		}
		else
		{
			vector<int>* temp = new vector<int>();
			temp->push_back(it-words.begin());
			//indecies.emplace(pair<string,vector<int>*>(*it,temp));
			indecies.insert(pair<string, vector<int>*>(*it, temp));
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

	while(it1!=indecies1->end()&&it2!=indecies2->end())
	{
		int distance = abs(*it1-*it2);
		if(distance<minDist)
			minDist = distance;

		vector<int>::iterator temp = next(it2);
		if(temp != indecies2->end())
		{
			int next = abs(*it1-*(temp));
			if (next > distance)
			{
				it1++;
			}
			else
				it2++;

		}
		else
			it1++;
	}

	return minDist;
}

int WordDistance::getDistanceMulti(string &str1, string& str2)
{
	if (indecies.count(str1) == 0)
		return -1;
	if (indecies.count(str2) == 0)
		return -1;

	int minDist = INT_MAX;

	pair<std::multimap<string, int>::iterator, std::multimap<string, int>::iterator> mIts2 = indeceisMulti.equal_range(str2);
	pair<std::multimap<string, int>::iterator, std::multimap<string, int>::iterator> mIts1 = indeceisMulti.equal_range(str1);
	multimap<string, int>::iterator mIt1 = mIts1.first;
	multimap<string, int>::iterator mIt2 = mIts2.first;	

	while (mIt1 != mIts1.second && mIt2 != mIts2.second)
	{
		int distance = abs(mIt1->second - mIt2->second);
		if (distance < minDist)
			minDist = distance;

		std::multimap<string, int>::iterator temp = next(mIt2);

		if (temp != mIts2.second)
		{
			int next = abs(mIt1->second - temp->second);
			if (next > distance)
			{
				mIt1++;
			}
			else
				mIt2++;
		}
		else
			mIt1++;
	}

	return minDist;
}
// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BTree.h"
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <Windows.h>
#include <iostream>
#include <stack>
#include "Heap.h"
#include <set>
#include <algorithm>
#include <utility>
#include "WordJustifier.h"
#include "HundredGame.h"
#include "PickNumber.h"


//#define INDECIES
//#define COMMONPARENT
//#define PERMUTATIONS
//#define PERMUTATIONS_VECTOR
//#define HEAP
//#define GREY_CODE
//#define BST_TEST
//#define COMMON_LETTER
//#define MAX_SUMSUBARRAY
//#define MAX_PRODSUBARRAY
//#define TUPLE_RANGE
//#define WORD_JUSTIFIER
//#define HUNDRED_GAME
#define POWER

using namespace std;

int NumCommonCharsCustom(vector<string> words);
int NumberOfSetBits(int i);
int NumCommonCharsSet(vector<string> words);
vector<string> GetGreyCode(int n);
vector<string> GetGreyCodeRecurse(int n);
vector<string> GetGreyCodeRecurse(int n, vector<string> arr);
void findIndecies(int arr[], int& low, int& high, int val, int cap);
int findLowIndex(int arr[], int start, int stop, int val);
int findHighIndex(int arr[], int start, int stop, int val, int cap);
double _power(double x, int y);
double power(double x, int y);

#ifdef PERMUTATIONS_VECTOR
vector<string> GetPermutations(string str);
void GetPermutations(string str,int pos, vector<string>& strArr);
#else
set<string> GetPermutations(string str);
void GetPermutations(string str,int pos, set<string>& strArr);
#endif
void swap(string& str, int i, int j);

int maxSumSubArray(vector<int> &arr, int& start, int& end);
int maxProdSubArray(vector<int> &arr, int& start, int& end);

bool pairCompare(const pair<int,int> &a, const pair<int,int> &b);
int findRange(vector<pair<int,int>> &pairList);


int _tmain(int argc, _TCHAR* argv[])
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2, t3, t4;
	double elapsedTime;

#ifdef POWER
	double a = power(2,4);
	double b = power(12,-5);
	double c = power(3,4);
#endif

#ifdef HUNDRED_GAME

	HundredGame test(2,3);
	if(test.canIWinCustom2())
		printf("I can win!\n");
	else
		printf("I can't win :(\n");

	if(test.canIWin())
		printf("I can win!\n");
	else
		printf("I can't win :(\n");

	int bla = 0;
	bla++;
#endif HUNDRED_GAME

#ifdef WORD_JUSTIFIER
	vector<string> stringList;
	
	stringList.push_back("aaa");
	stringList.push_back("bb");
	stringList.push_back("cc");
	stringList.push_back("eee");
	stringList.push_back("f");
	stringList.push_back("ddddd");
	
	
	WordJustifier wj(stringList);

	//wj.Justify(10);
	wj.JustifyCustom(8);
	wj.print();
	int temp = 0;
	temp++;

#endif

#ifdef TUPLE_RANGE

	vector<pair<int,int>> pairList;
	pairList.push_back(pair<int,int>(8,9));
	pairList.push_back(pair<int,int>(1,3));
	pairList.push_back(pair<int,int>(2,5));
	

	int range = findRange(pairList);
	int temp = 0;
	temp++;

#endif

#ifdef MAX_SUMSUBARRAY

	vector<int> arr;
	//arr.push_back(-2);
	//arr.push_back(1);
	//arr.push_back(-3);
	//arr.push_back(1);
	//arr.push_back( 4);
	//arr.push_back(-1);
	//arr.push_back(2);
	//arr.push_back(1);
	//arr.push_back(-5);
	//arr.push_back(4);

	arr.push_back(5);
	arr.push_back(-4);
	arr.push_back(2);
	arr.push_back(-3);
	arr.push_back(3);
	arr.push_back(3);

	int start = 0;
	int end = 0;

	int max = maxSumSubArray(arr,start,end);
	int temp = 0;
	temp++;
#endif

#ifdef MAX_PRODSUBARRAY

	vector<int> arr;
	//arr.push_back(2);
	//arr.push_back(-3);
	//arr.push_back(-2);
	//arr.push_back(-2);
	//arr.push_back(-40);
	//arr.push_back(-5);
	arr.push_back(-9);
	arr.push_back(-8);
	arr.push_back(-1);
	arr.push_back(4);
	arr.push_back(9);
	arr.push_back(-9);
	arr.push_back(-2);

	int start = 0;
	int end = 0;

	int max = maxProdSubArray(arr,start,end);
	int temp = 0;
	temp++;
#endif

#ifdef INDECIES
	int arr[10];

	arr[0] = 2;
	arr[1] = 2;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 5;
	arr[5] = 5;
	arr[6] = 5;
	arr[7] = 7;
	arr[8] = 7;
	arr[9] = 10;

	int start = 0;
	int stop = 0;

	findIndecies(arr,start,stop,5,10);
#endif

#ifdef COMMONPARENT
	BST tree;
	tree.insert_node(20);
	tree.insert_node(30);
	tree.insert_node(10);
	tree.insert_node(35);
	tree.insert_node(25);
	tree.insert_node(15);
	tree.insert_node(5);
	tree.insert_node(3);
	tree.insert_node(7);
	tree.insert_node(12);
	tree.insert_node(17);
	tree.insert_node(24);
	tree.insert_node(28);
	tree.insert_node(34);
	tree.insert_node(40);

	tree.printLevels();

	node* test = tree.findCommonParent(7,15);

	if(test!=NULL)
		printf("Common Parent is: %d\n",test->key_val);
#endif

#ifdef PERMUTATIONS
	string temp = "ABCD";

#ifdef PERMUTATIONS_VECTOR
	vector<string> tempArr = GetPermutations(temp);
		for(int i = 0; i<tempArr.size();i++)
	{
		cout << tempArr[i] << endl;
	}
#else
	set<string> tempArr = GetPermutations(temp);

	std::set<string>::iterator it;
	for (it = tempArr.begin(); it != tempArr.end(); ++it)
	{
		cout << *it << endl;
	}
#endif
	
#endif

#ifdef HEAP
	Heap heap(-1);

	heap.insert(8);
	heap.insert(10);
	heap.insert(12);
	heap.insert(2);
	heap.insert(22);
	heap.insert(1);
	heap.insert(32);
	heap.insert(-5);

	heap.print_heap();

	int min = heap.pop();
	cout << endl;
	heap.print_heap();

	min = heap.pop();
	cout << endl;
	heap.print_heap();

	min = heap.pop();
	cout << endl;
	heap.print_heap();

	min = heap.pop();
	cout << endl;
	heap.print_heap();

	min = heap.pop();
	cout << endl;
	heap.print_heap();
#endif

#ifdef GREY_CODE
	::QueryPerformanceFrequency(&frequency);
	::QueryPerformanceCounter(&t1);
	vector<string> grey1 = GetGreyCodeRecurse(10);
	::QueryPerformanceCounter(&t2);
	::QueryPerformanceCounter(&t3);
	vector<string> grey2 = GetGreyCode(10);
	::QueryPerformanceCounter(&t4);

	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0/ frequency.QuadPart;
	printf("Elapsed Time for Recursive method: %f\n",elapsedTime);

	elapsedTime = (t4.QuadPart - t3.QuadPart) * 1000.0/ frequency.QuadPart;
	printf("Elapsed Time for non-Recursive method: %f\n",elapsedTime);


	cout<< "recursive: " <<endl;
    vector<string> greyTest2 = GetGreyCodeRecurse(4);
	for(int i = 0;i<greyTest2.size();i++)
	{
		cout << greyTest2[i] << endl;
	}
	cout<<endl<<"non-recursive:"<<endl;
	vector<string> greyTest = GetGreyCode(4);
	for(int i = 0;i<greyTest.size();i++)
	{
		cout << greyTest[i] << endl;
	}
#endif

#ifdef BST_TEST
	BST tree = BST();
	tree.insert_node(10);
	tree.insert_node(8);
	tree.insert_node(11);
	tree.insert_node(9);
	tree.insert_node(6);
	tree.insert_node(7);
	tree.insert_node(5);

	node* n = tree.search_tree(8);

	printf("n left child value: %d\n",n->left_child->key_val);
	printf("n right child value: %d\n",n->right_child->key_val);

	node* n2 = tree.search_tree(121);

	if(n2==NULL)
		printf("N2 not found!\n");
	else
		printf("N2 key value: %d\n",n2->key_val);

	printf("original Tree:\n");
	tree.printLevels();

	tree.flipTree();

	printf("\nFlipped Tree:\n");
	tree.printLevels();
#endif

#ifdef COMMON_LETTER
	char test = 'a';
	int test2 = (int)test;

	string temp1("aghkafgklt");
	string temp2("dfghako");
	string temp3("qwemnaarkf");

	vector<string>temp;
	temp.push_back(temp1);
	temp.push_back(temp2);
	temp.push_back(temp3);


	
	::QueryPerformanceFrequency(&frequency);
	::QueryPerformanceCounter(&t1);
	int answer = NumCommonCharsCustom(temp);
	::QueryPerformanceCounter(&t2);
	::QueryPerformanceCounter(&t3);
	int answer2 = NumCommonCharsSet(temp);
	::QueryPerformanceCounter(&t4);

	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0/ frequency.QuadPart;
	printf("Elapsed Time for Custom method: %f\n",elapsedTime);

	elapsedTime = (t4.QuadPart - t3.QuadPart) * 1000.0/ frequency.QuadPart;
	printf("Elapsed Time for Set method: %f\n",elapsedTime);
#endif

	return 0;
}

int NumCommonCharsSet(vector<string> words)
{
	int count = 0;
	int counts[256] = {0};

	for(int i = 0; i<words.size();i++)
	{
		set<char> uniqueChars;

		string str = words[i];
		for(int j = 0; j<str.size();j++)
		{
			if(!uniqueChars.count(str[j]))
			{
				uniqueChars.insert(str[j]);
				counts[str[j]]++;
			}
		}
	}

	for(int i = 0;i<256;i++)
	{
		if(counts[i] == words.size())
			count++;
	}
	return count;
}

int NumCommonCharsCustom(vector<string> words)
{
	int numWords = words.size();
	int* valArray = new int[numWords];

	int index = 0;

	while(!words.empty())
	{
		string s = words.back();

		int val = 0;
		while(!s.empty())
		{
			char temp = s.back();
			int tempVal = (int)temp-97;

			val |= (1<<tempVal);

			s.pop_back();
		}

		valArray[index] = val;
		index++;
		words.pop_back();
	}

	int val = 0xFFFF;
	for(int i = 0 ; i<numWords; i++)
	{
		val &= valArray[i];
	}

	delete valArray;

	return NumberOfSetBits(val);
}

int NumberOfSetBits(int val)
{
	unsigned int c;
	for(c=0;val;c++)
	{
		val &= val-1;
	}
	return c;
 }

vector<string> GetGreyCode(int n)
{
	vector<string> arr;
	arr.push_back("0");
	arr.push_back("1");
	
	for(int i = 2; i<(1<<n);i= (i<<1))
	{
		int curSize = arr.size();

		for(int j = curSize-1; j>=0;j--)
		{
			arr.push_back("1"+arr[j]);
			arr[j] = "0" + arr[j];
		}
	}
	return arr;
}

vector<string> GetGreyCodeRecurse(int n)
{
	vector<string> arr;

	arr = GetGreyCodeRecurse(n,arr);

	return arr;
}

vector<string> GetGreyCodeRecurse(int n, vector<string> arr)
{
	if(n == 1)
	{
		arr.push_back("0");
		arr.push_back("1");
	}
	else
	{
		arr = GetGreyCodeRecurse(n-1,arr);
		int curSize = arr.size();
		for(int i = curSize-1;i>=0;i--)
		{
			arr.push_back("1"+arr[i]);
			arr[i] = "0"+arr[i];
		}
	}
	return arr;
}

#ifdef PERMUTATIONS_VECTOR
vector<string> GetPermutations(string str)
{
	vector<string> strArr;
	GetPermutations(str,0,strArr);
	return strArr;
}

void GetPermutations(string str,int pos, vector<string>& strArr)
{
	if(pos == str.size()-1)
		strArr.push_back(str);
	else
	{
		for(int i =pos;i<str.size();i++)
		{
			swap(str,pos,i);
			GetPermutations(str,pos+1,strArr);
			swap(str,pos,i);
		}
	}
	return;
}
#else
set<string> GetPermutations(string str)
{
	set<string> strArr;
	GetPermutations(str,0,strArr);
	return strArr;
}

void GetPermutations(string str,int pos, set<string>& strArr)
{
	if(pos == str.size()-1)
	{	
		if(strArr.count(str)!=0)
		{
			cout<< "Duplicate string found: " << str <<endl;
		}
		else
			strArr.insert(str);
	}
	else
	{
		for(int i =pos;i<str.size();i++)
		{
			swap(str,pos,i);
			GetPermutations(str,pos+1,strArr);
			swap(str,pos,i);
		}
	}
	return;
}
#endif

void swap(string& str, int i, int j)
{
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void findIndecies(int arr[], int& low, int& high, int val, int cap)
{
	low = findLowIndex(arr,0,cap,val);
	high = findHighIndex(arr,low,cap,val,cap);
}

int findLowIndex(int arr[], int start, int stop, int val)
{
	if(start<0 || stop<start)
		return -1;

	int mid = (stop-start)/2 + start;

	if((arr[mid]==val)&&(mid == 0 || arr[mid-1]<val))
		return mid;
	else if(arr[mid]<val)
		return findLowIndex(arr,mid+1,stop,val);
	else 
		return findLowIndex(arr,start,mid-1,val);
}
int findHighIndex(int arr[], int start, int stop, int val, int cap)
{
	if(start>=cap || start>stop)
		return -1;

	int mid = (stop-start)/2 + start;

	if((arr[mid]==val)&&(mid == cap-1 || arr[mid+1]>val))
		return mid;
	else if(arr[mid]>val)
		return findHighIndex(arr,start,mid-1,val,cap);
	else 
		return findHighIndex(arr,mid+1,stop,val,cap);
}

int maxSumSubArray(vector<int> &arr, int& start, int& end)
{
	int max = arr[0];
	int cur_max = arr[0];
	int start_temp = 0;

	for(int i = 1; i<arr.size(); i++)
	{
		if(cur_max<=0)
		{
			cur_max = arr[i];
			start_temp = i;
		}
		else
		{
			cur_max += arr[i];
		}
		if(cur_max >= max)
		{
			max = cur_max;
			start = start_temp;
			end = i;
		}
	}

	return max;
}

int maxProdSubArray(vector<int> &arr, int& start, int& end)
{
	int max = 0;
	int curMax = 0;
	int startNeg = 0;
	int startPos = 0;
	
	vector<int> maxPos;
	vector<int> minNeg;

	maxPos.push_back(arr[0]);
	minNeg.push_back(arr[0]);

	for(int i = 1; i<arr.size();i++)
	{
		int val = arr[i];
		int valPos = val*maxPos[i-1];
		int valNeg = val*minNeg[i-1];	
		
		curMax = max(max(val,valPos),valNeg);
		if(curMax>max)
		{
			if(curMax == valPos)
				start = startPos;
			else
				start = startNeg;
			end = i;
			max = curMax;
		}

		int initStartPos = startPos;
		
		if(curMax == val)
			startPos = i;
		else if(curMax == valNeg)
			startPos = startNeg;

		int curMin = min(min(val,valPos),valNeg);

		if(curMin == val)
			startNeg = i;
		else if(curMin == valPos)
			startNeg = initStartPos;

		maxPos.push_back(curMax);
		minNeg.push_back(curMin);
	}
		
	return max;
}

bool pairCompare(const pair<int,int> &a, const pair<int,int> &b)
{
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
	{
		if(a.second<b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}

int findRange(vector<pair<int,int>> &pairList)
{
	std::sort(pairList.begin(),pairList.end(),pairCompare);

	int begin = pairList[0].first;
	int end = pairList[0].second;

	int range = 0;

	for(int i = 1; i<pairList.size(); i++)
	{
		pair<int,int> tempPair = pairList[i];

		if(tempPair.first > end)
		{
			range += end-begin;
			begin = tempPair.first;
			end = tempPair.second;
		}
		else
		{
			if(tempPair.second>end)
				end = tempPair.second;
		}
	}

	range += end-begin;

	return range;
}

double _power(double x, int y)
{
	if(y==0) return 1;

	double t = _power(x, y/2);
	t *= t;

	int val = ((y%2)?x:1);

	return t * ( (y%2)?x:1 );
}

double power(double x, int y)
{
	if(y<0) return (1/_power(x,y));
	else return _power(x,y);
}

/*
#include<stdio.h>
#include<cmath>
int max(int a,int b)
{
        return a>b?a:b;
}
int Knapsack(int items,int weight[],int value[],int maxWeight)
{
		int** dp = new int* [items+1];
		for(int i = 0; i<items+1;i++)
		{
			dp[i] = new int[maxWeight+1];
		}
        int iter,w;
        for(iter=0;iter<=maxWeight;iter++)
        {
                dp[0][iter]=0;
        }
        for(iter=0;iter<=items;iter++)
        {
                dp[iter][0]=0;
        }
        for(iter=1;iter<=items;iter++)
        {
                for(w=0;w<=maxWeight;w++)
                {
                        dp[iter][w] = dp[iter-1][w]; // If I do not take this item 
                        if(w-weight[iter] >=0)
                        {
								if(iter ==2 && w==2)
								{
									int a = 0;
									a++;
								}
                                // suppose if I take this item 
                                dp[iter][w] = max(dp[iter][w] , dp[iter-1][w-weight[iter]]+value[iter]);
								printf("i: %d, w: %d, max: %d\n",iter,w,dp[iter][w]);
                        }
                }

        }
        return dp[items][maxWeight];
}
int _tmain(int argc, _TCHAR* argv[])
{
        int items = 3;
        //scanf("%d",&items);
        int* weight = new int [items+1];
		int* value = new int [items+1];
        int iter;
        for(iter=1;iter<=items;iter++)
        {
			weight[iter] = iter;
			value[iter] = (int)pow((float)2,iter);
               // scanf("%d%d",&weight[iter],&value[iter]);
        }
        int maxWeight;
        scanf("%d",&maxWeight);
        printf("Max value attained can be %d\n",Knapsack(items,weight,value,maxWeight));
}
*/

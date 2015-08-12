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
#include <regex>
#include "Heap.h"
#include <set>
#include <algorithm>
#include <utility>
#include <map>
#include "WordJustifier.h"
#include "HundredGame.h"
#include "PickNumber.h"
#include "Plane.h"
#include "NestedList.h"
#include "WordDistance.h"
#include "boost/lexical_cast.hpp"
#include <boost/algorithm/string.hpp>
#include "BinarySearchTree.h"


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
//#define HUNDRED_GAME
//#define KNAPSACK
//#define POWER_TEST
//#define ROTATED_SEARCH
//#define SELF_EXCLUDING_PRODUCT
//#define PLANE_POINTS
//#define NESTED_LIST
//#define INFLUENCER
#define IS_NUM
//#define PALINDROME
//#define SPLIT_WORDS
//#define WORD_DIST
//#define WORD_JUSTIFIER


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
int maximum(int a,int b);
int Knapsack(int items,int weight[],int value[],int maxWeight);
double power(int x, int y);
double _power(int x, int y);
double powerNew(int x, int y);
double _powerNew(int x, int y);
vector<int> SelfExcludingProduct(vector<int> &input);

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
int maxProdSubArrayCustom(vector<int> &arr, int& start, int& end);

bool pairCompare(const pair<int,int> &a, const pair<int,int> &b);
int findRange(vector<pair<int,int>> &pairList);

int RotatedSearch(vector<int> &list, int key);
//int RotatedSearch(vector<int> &list, int key, int start, int stop);
int RotatedSearchForward(vector<int> &list, int key, int start, int stop);
int RotatedSearchBackward(vector<int> &list, int key, int start, int stop);

int FindInfluencer(vector<vector<int>> &users);
int FindInfluencer2(vector<vector<int>> &users);

void findRepeatSubStrings(string str,int length);
bool isNum(string &str);
bool isNumBoost(string &str);
bool isNumRegEx(string &str);

int maxPalindrome(string &str);
int _maxPalindrome(string &str, int** dp, int start, int end);

int wordDistance(string sentence, string str1, string str2); 

int _tmain(int argc, _TCHAR* argv[])
{
	LARGE_INTEGER frequency;
	::QueryPerformanceFrequency(&frequency);
	LARGE_INTEGER t1, t2, t3, t4;
	double elapsedTime;

#ifdef WORD_DIST
	vector<string> stringList = vector<string>();
	stringList.push_back("the");
	stringList.push_back("the");
	stringList.push_back("quick");
	stringList.push_back("brown");
	stringList.push_back("brown");
	stringList.push_back("fox");
	stringList.push_back("jumped");
	stringList.push_back("over");
	stringList.push_back("the");

	WordDistance wd(stringList);

	int dist1 = wd.getDistance(string("quick"),string("jumped"));
	int dist1Multi = wd.getDistanceMulti(string("quick"), string("jumped"));
	int dist2 = wd.getDistance(string("the"),string("brown"));
	int dist2Multi = wd.getDistanceMulti(string("the"), string("brown"));
	int a = 0;
	a++;

#endif

#ifdef SPLIT_WORDS
	string sent("The quick brown fox jumped over");
	int test = wordDistance(sent,string("QUICK"),string("jumped"));
	string sent2("The quick quick brown fox jumped over");
	int test2 = wordDistance(sent2,string("QuIcK"),string("brown"));
	int test3 = wordDistance(sent2,string("brown"),string("quick"));
	int test4 = wordDistance(sent2,string("brown"),string("brown"));
	int test5 = wordDistance(sent2,string("brown"),string("bla"));
	int a = 0;
	a++;
#endif

#ifdef REPEAT_SUBSTRING
	
	string str1 = "ABCACBABC";
	int length1 = 3;
	string str2 = "ABCABCABC";
	int length2 = 2;

	cout << "Substrings of length " << length1 <<" for string \"" << str1 << "\"  are: " << endl;
	findRepeatSubStrings(str1,3); 
	cout << endl << "Substrings of length " << length2 <<" for string \"" << str2 << "\"  are: " << endl;
	findRepeatSubStrings(str2,2);
#endif

#ifdef PALINDROME
	string str1("habobeh");

	int test = maxPalindrome(str1);
	cout << str1 << ": max palindrome length is " << test << "." <<endl;

	string str2("habobah");

	int test2 = maxPalindrome(str2);
	cout << str2 << ": max palindrome length is " << test2 << "." <<endl;

	string str3("habovbah");

	int test3 = maxPalindrome(str3);
	cout << str3 << ": max palindrome length is " << test3 << "." <<endl;
#endif

#ifdef IS_NUM

	bool test = std::regex_match("1234b", std::regex("\\d+"));

	isNumRegEx(string("80.4536"));
	isNumRegEx(string("-75.65"));
	isNumRegEx(string("69"));
	isNumRegEx(string("a123123"));
	isNumRegEx(string("1231."));
	isNumRegEx(string("0.9876.08"));
	isNumRegEx(string(".982324"));
	isNumRegEx(string(".982.324"));
	isNumRegEx(string("1.234asd"));
	isNumRegEx(string("-.123"));


#endif

#ifdef POWER
	double a = power(2,4);
	double b = power(12,-5);
	double c = power(3,4);
#endif

#ifdef INFLUENCER
	
	int numUsers=5;	
	vector<vector<int>> users;

	for(int i = 0; i<numUsers; i++)
	{
		vector<int> isFollowing;
		for(int j = 0;j<numUsers;j++)
		{
			if(i==j)
			{
				isFollowing.push_back(0);
			}
			else
				isFollowing.push_back(1);
		}
		users.push_back(isFollowing);
	}	 

	int isInfluencer = FindInfluencer(users);
	int isInfluencer2 = FindInfluencer2(users);

	if(isInfluencer == -1)
		printf("\nNo Influencer found!!\n");
	else
		printf("Influencer found in postion: %d\n",isInfluencer);

	int influencer = 3;

	for(int i = 0; i<numUsers;i++)
	{
		users[influencer][i] =0;
	}

	isInfluencer = FindInfluencer(users);
	isInfluencer2 = FindInfluencer2(users);

	if(isInfluencer == -1)
		printf("\nNo Influencer found!!\n");
	else
		printf("Influencer found in postion: %d\n",isInfluencer);

	influencer = 2;
	users.clear();
	for(int i = 0; i<numUsers; i++)
	{
		vector<int> isFollowing;
		for(int j = 0;j<numUsers;j++)
		{
			if(i==j)
			{
				isFollowing.push_back(0);
			}
			else if(j==influencer)
				isFollowing.push_back(1);
			else
				isFollowing.push_back(0);
		
		}
		users.push_back(isFollowing);
	}	

	isInfluencer = FindInfluencer(users);
	isInfluencer2 = FindInfluencer2(users);

	if(isInfluencer == -1)
		printf("\nNo Influencer found!!\n");
	else
		printf("Influencer found in postion: %d\n",isInfluencer);

#endif

#ifdef NESTED_LIST
	NestedList nl;

	nl.addInt(1);
	nl.addList();
	nl.At(1)->addInt(2);
	nl.At(1)->addList();
	nl.At(1)->addInt(3);
	nl.addInt(4);
	nl.At(1)->At(1)->addInt(6);
	nl.At(1)->At(1)->addInt(2);
	nl.At(1)->At(1)->addList();
	nl.At(1)->At(1)->At(2)->addInt(3);

	for(std::vector<NestedList*>::iterator it = nl.begin(); it!=nl.end(); ++it)
	{
		NestedList* temp = *it;
		if(temp->isInteger())
		{
			printf("%d ",temp->getInteger());
		}
	}

	int test = nl.getSum();
	int test2 = 0;
	test2++;


#endif

#ifdef PLANE_POINTS
	Plane plane;
	plane.addPoint(Point(1,1));
	plane.addPoint(Point(2,2));
	plane.addPoint(Point(3,3));
	plane.addPoint(Point(4,4));
	plane.addPoint(Point(0,5));

	vector<Point> nearestPoints = plane.findClosestPoints(Point(0,5),2);

	CustomPlane custPlane;
	custPlane.addPoint(Point(1,1));
	custPlane.addPoint(Point(2,2));
	custPlane.addPoint(Point(3,3));
	custPlane.addPoint(Point(4,4));
	custPlane.addPoint(Point(0,5));

	vector<Point> nearestPointsCust = custPlane.findClosestPoints(Point(0,5),2);

	int a = 0;
	a++;
#endif

#ifdef SELF_EXCLUDING_PRODUCT
	vector<int> testList;
	testList.push_back(3);
	testList.push_back(1);
	testList.push_back(4);
	testList.push_back(2);

	vector<int> outList1 = SelfExcludingProduct(testList);

	testList.push_back(0);

	vector<int> outList2 = SelfExcludingProduct(testList);

	testList.push_back(0);

	vector<int> outList3 = SelfExcludingProduct(testList);

	int a = 0;
	a++;

#endif 

#ifdef ROTATED_SEARCH
	vector<int> list1;
	list1.push_back(4);
	list1.push_back(8);
	list1.push_back(10);
	list1.push_back(48);
	list1.push_back(32);
	list1.push_back(25);
	list1.push_back(15);

	int test = RotatedSearch(list1,25);
	int test2 = RotatedSearch(list1,8);
	int test3 = RotatedSearch(list1,55);
	int test4 = RotatedSearch(list1,2);
	int test5 = RotatedSearch(list1,4);
	int test6 = RotatedSearch(list1,10);
	int test7 = RotatedSearch(list1,15);
	int test8 = RotatedSearch(list1,32);
	int test9 = RotatedSearch(list1,48);

	vector<int> list2;
	list2.push_back(15);
	list2.push_back(10);
	list2.push_back(8);
	list2.push_back(4);
	list2.push_back(25);
	list2.push_back(32);
	list2.push_back(48);

	int test10 = RotatedSearch(list2,25);
	int test11 = RotatedSearch(list2,8);
	int test12 = RotatedSearch(list2,55);
	int test13 = RotatedSearch(list2,2);
	int test14 = RotatedSearch(list2,4);
	int test15 = RotatedSearch(list2,10);
	int test16 = RotatedSearch(list2,15);
	int test17 = RotatedSearch(list2,32);
	int test18 = RotatedSearch(list2,48);

#endif

#ifdef POWER_TEST
	while(true)
	{
		int x;
		printf("Please enter x: ");
		scanf("%d",&x);
		int y;
		printf("Please enter y: ");
		scanf("%d",&y);
		double test = power(x,y);
		double test2 = powerNew(x, y);
		printf("Old: %d^%d=%f\n",x,y,test);
		printf("New: %d^%d=%f\n", x, y, test2);
	}
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
	WordJustifier wj2(stringList);
	

	::QueryPerformanceCounter(&t1);
	wj2.Justify(8);
	::QueryPerformanceCounter(&t2);
	double time = (t2.QuadPart - t1.QuadPart) * 1000.0/ frequency.QuadPart;
	wj2.print();
	
	::QueryPerformanceCounter(&t3);
	wj.JustifyCustom(8);
	::QueryPerformanceCounter(&t4);
	double timeCustom = (t4.QuadPart - t3.QuadPart) * 1000.0/ frequency.QuadPart;
	wj.print();

	printf("Standard justification takes: %fms\n",time);
	printf("Custom justification takes: %fms\n",timeCustom);


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
	arr.push_back(-1);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(0);
	//arr.push_back(-9);
	//arr.push_back(-2);

	int start = 0;
	int end = 0;

	int max = maxProdSubArray(arr,start,end);


	int customStart = 0;
	int customEnd = 0;
	int customMax = maxProdSubArrayCustom(arr, customStart, customEnd);

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


	int arr2[7];
	int start2 = 0;
	int stop2 = 0;

	arr2[0] = 1;
	arr2[1] = 1;
	arr2[2] = 2;
	arr2[3] = 3;
	arr2[4] = 4;
	arr2[5] = 4;
	arr2[6] = 5;

	findIndecies(arr2,start2,stop2,4,7);

#endif

#ifdef COMMONPARENT
	if (true)
	{
		BinarySearchTree bsTree;
		bsTree.Insert(20);
		bsTree.Insert(30);
		bsTree.Insert(10);
		bsTree.Insert(35);
		bsTree.Insert(25);
		bsTree.Insert(15);
		bsTree.Insert(5);
		bsTree.Insert(3);
		bsTree.Insert(7);
		bsTree.Insert(12);
		bsTree.Insert(17);
		bsTree.Insert(24);
		bsTree.Insert(28);
		bsTree.Insert(34);
		bsTree.Insert(40);

		bsTree.PrintLevels();

		int val1 = 34;
		int val2 = 401;

		node* test = bsTree.FindCommonParent(val1, val2);

		if (test != NULL)
			cout << "Common Parent to " << val1 << " and " << val2 << " is: " << test->key_val << endl << endl;
		else
			cout << "At least one of the values was not found in the Binary Search Tree!" << endl << endl;;
	}

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

	int val1 = 34;
	int val2 = 401;

	node* test = tree.findCommonParent(val1,val2);

	if(test!=NULL)
		printf("\nCommon Parent of %d and %d is: %d\n",val1,val2,test->key_val);
	else
		printf("\nOne of the values was not found in the BST!\n");
#endif

#ifdef PERMUTATIONS
	string temp = "ABCD";
	//string temp = "ABCC";

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
	if (true)
	{
		BinarySearchTree bTree;
		bTree.Insert(10);
		bTree.Insert(8);
		bTree.Insert(11);
		bTree.Insert(9);
		bTree.Insert(6);
		bTree.Insert(7);
		bTree.Insert(5);

		node* n = bTree.Search(8);
		cout << "n left child value: " << n->left_child->key_val << endl;
		cout << "n right child value: " << n->right_child->key_val << endl;

		node* n2 = bTree.Search(121);

		if (n2 == NULL)
			cout << "N2 not found!" << endl;
		else
			cout << "N2 key value: %d\n" << endl;

		cout << "Original Tree:" << endl;
		bTree.PrintLevels();

		bTree.FlipTree();
		cout << "Flipped Tree:" << endl;
		bTree.PrintLevels();
	}

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

double powerNew(int x, int y)
{
	if (y < 0)
		return 1 / _powerNew(x, -1 * y);
	else
		return _powerNew(x, y);
}

double _powerNew(int x, int y)
{
	if (y == 0)
		return 1;
	else if (y == 1)
		return x;
	else if (y % 2 != 0)
		return x * powerNew(x, y - 1);
	else
	{
		double temp = power(x, y / 2);
		return temp*temp;
	}
}

int wordDistance(string sentence, string str1, string str2)
{
	std::transform(str1.begin(),str1.end(),str1.begin(),tolower);
	std::transform(str2.begin(),str2.end(),str2.begin(),tolower);

	if(str1.compare(str2)==0)
		return 0;

	vector<string> splitStrings;
	//boost::split(splitStrings,sentence,boost::is_any_of("\t "));
	std::stringstream ss(sentence);
	std::string item;
	while(std::getline(ss,item,' '))
	{
		splitStrings.push_back(item);
	}


	int aIndex = -1;
	int bIndex = -1;

	int minDistance = INT_MAX;

	std::vector<string>::iterator start = splitStrings.begin();

	for(std::vector<string>::iterator it= splitStrings.begin(); it!= splitStrings.end();++it)
	{
		std::transform(it->begin(),it->end(),it->begin(),tolower);

		if(str1.compare(*it)==0)
		{
			aIndex = it-start;
		}
		else if(str2.compare(*it)==0)
		{
			bIndex = it-start;
		}
		if(aIndex>0 && bIndex>0)
		{
			int dist = bIndex-aIndex;
			if(dist<minDistance && dist>0)
			{
				minDistance = bIndex-aIndex;
			}
		}		
	}

	if(aIndex==-1 || bIndex == -1 || minDistance == 100000)
		return -1;
	else
		return minDistance;
}

int maxPalindrome(string &str)
{
	int size = str.length();
	int end = size-1;

	int** dp = new int*[size];
	for(int i = 0; i<size;i++)
	{
		dp[i] = new int[size];
		std::fill_n(dp[i],size,-1);
		dp[i][i] = 1;
	}

	int val = _maxPalindrome(str,dp,0,end);

	for(int i = 0; i<size;i++)
	{
		delete [] dp[i];
	}
	delete [] dp;

	return val;
}
int _maxPalindrome(string &str, int** dp, int start, int end)
{
	if(end<start)
		return 0;
	if(dp[start][end]!=-1)
		return dp[start][end];
	if(str[start] == str[end])
		dp[start][end]= 2+ _maxPalindrome(str,dp,start+1,end-1);
	else
		dp[start][end] = max(_maxPalindrome(str,dp,start+1,end),_maxPalindrome(str,dp,start,end-1));

	return dp[start][end];
}

bool isNum(string &str)
{
	std::string::iterator it = str.begin();
	int numDecimal = 0;

	if(*it == '.')
	{
		numDecimal++;
	}
	else if(*it!='-' && !isdigit(*it) )
	{
		cout << str << " is not a number" << endl;
		return false;
	}
	it++;	
	for(it; it!= str.end();++it)
	{
		if(*it == '.')
			numDecimal++;
		else if (!isdigit(*it))
		{
			cout << str << " is not a number" << endl;
			return false;
		}
		if(numDecimal >1)
		{
			cout << str << " is not a number" << endl;
			return false;
		}
	}
	cout << str << " is a number!" << endl;
	return true;
}

bool isNumBoost(string &str)
{
	try
	{
		double test = boost::lexical_cast<double,string>(str);
		cout << str << " is a number!!" << endl;
		return true;
	}
	catch (exception ex)
	{
		cout << str << " is not a number!" << endl;
		return false;
	}
}

bool isNumRegEx(string &str)
{
	if (std::regex_match(str, std::regex("(-)?\\d+(\\.\\d+)?")))
	//if (std::regex_search(str, std::regex("^(-\\d+|\\d+)(\\.\\d+)?$")))
	//if (std::regex_search(str, std::regex("^(((-\\d+|\\d+)(\\.\\d+)?)|\\.\\d+)$"))) // SEARCH VERSION WITH EVERYTHING IN ONE STEP
	//if (std::regex_match(str,std::regex("((-)?\\d+(\\.\\d+)?)|(\\.\\d+)"))) //MATCH VERSION WITH EVERYTHING IN ONE STEP
	{
		cout << str << " is a number!" << endl;
		return true;
	}
	else if(std::regex_match(str,std::regex("\\.\\d+")))
	//else if (std::regex_search(str, std::regex("^(\\.\\d+)$")))
	{
		cout << str << " is a number!" << endl;
		return true;
	}
	else
	{
		cout << str << " is not a number!" << endl;
		return false;
	}
}

int FindInfluencer(vector<vector<int>> &users)
{
	for(int i = 0;i<users.size();i++)
	{
		bool isInfluencer = true;
		for(int j= 0;j<users[i].size();j++)
		{
			if(i==j)
			{
				continue;
			}

			if(users[i][j] == 1 || users[j][i] == 0)
			{
				isInfluencer = false;
				break;
			}
		}
		if(isInfluencer)
			return i;
	}
	return -1;
}

int FindInfluencer2(vector<vector<int>> &users)
{
	int cand = 0;
	for(int i = 1; i<users.size(); i++)
	{
		if(users[cand][i] == 1 || users[i][cand]==0)
		{
			cand = i;
		}
	}
	for(int i = 0;i<users.size();i++)
	{
		if(i==cand)
			continue;
		if(users[cand][i]==1||users[i][cand]==0)
			return-1;
	}
	return cand;
}

vector<int> SelfExcludingProduct(vector<int> &input)
{
	int numZeros = 0;
	int product = 1;
	for(int i = 0; i<input.size();i++)
	{
		if(input[i] == 0)
			numZeros++;
		else
			product *= input[i];

		if(numZeros >= 2)
		{
			product = 0;
			break;
		}
	}

	vector<int> out;
	for(int i = 0;i<input.size();i++)
	{
		if(input[i] == 0)
			out.push_back(product);
		else if(numZeros ==1)
			out.push_back(0);
		else
			out.push_back(product/input[i]);
	}

	return out;
}

int RotatedSearch(vector<int> &list, int key)
{
	int start = 0;
	int stop = list.size()-1;

	int mid = (stop-start)/2;

	if(list[mid] == key)
		return mid;
	else
	{
		if(list[mid+1]<list[stop])
		{
			if(key>=list[mid+1])
				return RotatedSearchForward(list,key,mid+1,stop);
			else
				return RotatedSearchBackward(list,key,mid-1,start);
		}
		else
		{
			if(key<=list[mid-1])
				return RotatedSearchForward(list,key,start,mid-1);
			else
				return RotatedSearchBackward(list,key,stop,mid+1);
		}
	}
}

int RotatedSearchForward(vector<int> &list, int key, int start, int stop)
{
	if(start>stop)
		return -1;
	if(start<0)
		return -1;
	if(stop>list.size()-1)
		return -1;
	//if(start==stop && list[start]!=key)
	//	return -1;

	int mid;
	mid = (stop-start)/2+start;
	
	if(list[mid] == key)
		return mid;
	else
	{
		if(key>list[mid])
			return RotatedSearchForward(list,key,mid+1,stop);
		else
			return RotatedSearchForward(list,key,start,mid-1);
	}
}
int RotatedSearchBackward(vector<int> &list, int key, int start, int stop)
{
	if(stop>start)
		return -1;
	if(stop<0)
		return -1;
	if(start>list.size()-1)
		return -1;
	//if(start==stop && list[start]!=key)
	//	return -1;

	int mid;
	mid = start-((start-stop)/2);
	
	if(list[mid] == key)
		return mid;
	else
	{
		if(key>list[mid])
			return RotatedSearchBackward(list,key,mid-1,stop);
		else
			return RotatedSearchForward(list,key,start,mid+1);
	}
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
	arr.reserve(1<<n);
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
			//swap(str,pos,i);
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
	
	int maxPos = arr[0];
	int minNeg = arr[0];

	for(int i = 1; i<arr.size();i++)
	{
		int val = arr[i];
		int valPos = val*maxPos;
		int valNeg = val*minNeg;	
		
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

		maxPos = curMax;
		minNeg = curMin;
	}
		
	return max;
}

int maxProdSubArrayCustom(vector<int> &arr, int& start, int& end)
{
	int max = arr[0];
	int curMax = max;
	int curMin = max;
	int maxEndingHere = arr[0];
	int minEndingHere = arr[0];
	start = 0;
	end = 0;
	int startPos = 0;
	int startNeg = 0;
	std::vector<int>::iterator it = arr.begin();

	for (++it; it != arr.end(); ++it)
	{
		maxEndingHere *= *it;
		minEndingHere *= *it;
		curMax = max(max(*it, maxEndingHere), minEndingHere);
		if(curMax>max)
		{
			if (curMax == maxEndingHere)
				start = startPos;
			else if (curMax == minEndingHere)
				start = startNeg;
			else
				start = it - arr.begin();

			end = it - arr.begin();
			max = curMax;
		}

		int initStartPos = startPos;

		if (curMax == *it)
			startPos = it - arr.begin();
		else if (curMax == minEndingHere)
			startPos = startNeg;

		curMin = min(min(*it, minEndingHere), maxEndingHere);

		if (curMin == *it)
			startNeg = it - arr.begin();
		else if (curMin == maxEndingHere)
			startNeg = initStartPos;


		maxEndingHere = curMax;
		minEndingHere = curMin;
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
							// suppose if I take this item 
							dp[iter][w] = max(dp[iter][w] , dp[iter-1][w-weight[iter]]+value[iter]);								
                        }
						printf("i: %d, w: %d, max: %d\n",iter,w,dp[iter][w]);
                }

        }
        return dp[items][maxWeight];
}

double power(int x, int y)
{
	if(y<0)
		return (1/_power(x,-1*y));
	else
		return _power(x,y);
}
double _power(int x, int y)
{
	if(y==0)
		return 1;
	else if(y==1)
		return x;

	double ans = power(x,y/2);
	ans = ans*ans;

	if(y%2!=0)
		ans *=x;

	return ans;
}

void findRepeatSubStrings(string str,int length)
{
	set<string> repeatStrings;
	set<string> tempStrings;

	for(int i = 0; i<str.size()-2;i++)
	{
		string subStr = str.substr(i,length);
		if(tempStrings.count(subStr)!=0)
		{
			repeatStrings.insert(subStr);
		}
		else
			tempStrings.insert(subStr);
	}
	
	for(set<string>::iterator it = repeatStrings.begin(); it!=repeatStrings.end();it++)
	{
		cout << *it << endl;
	}
}

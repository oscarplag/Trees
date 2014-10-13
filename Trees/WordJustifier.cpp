#include "StdAfx.h"
#include "WordJustifier.h"


WordJustifier::WordJustifier(vector<string> list)
{
	stringList = list;
}


WordJustifier::~WordJustifier(void)
{
}

void WordJustifier::Justify(int M)
{
	int n = stringList.size();
	int* l = new int[stringList.size()];

	for(int i = 0; i<n;i++)
	{
		int stringSize = stringList[i].size();
		l[i] = stringList[i].size();
	}
	solveWordWrap(l,n,M);
}

void WordJustifier::JustifyCustom(int M)
{
	vector<int> l;

	for(int i = 0; i<stringList.size();i++)
	{
		l.push_back(stringList[i].size());
	}

	solveWordWrapCustom(l,M);
}

void WordJustifier::print()
{
	for(int i = 0; i<justified.size();i++)
	{
		cout << justified[i] << endl;
	}
}

void WordJustifier::solveWordWrapCustom(vector<int> lengths, int M)
{
	int n = lengths.size();
	vector<vector<int>> spaces;

	//figure out how many spaces will be left over for each a line starting with each word in the set
	for(int i = 0; i<n-1;i++)
	{
		vector<int>lineSizes;

		int itr = i;
		int size = lengths[i];

		while(size<=M) 
		{
			lineSizes.push_back(M-size);
			itr++;
			if(itr>=n)
				break;
			size += lengths[itr] + 1;
		}
		spaces.push_back(lineSizes);
	}
	vector<int>final;
	final.push_back(M-lengths[n-1]);
	spaces.push_back(final);

	//figure out the associated costs with the given spaces
	vector<vector<int>> lineCosts;
	for(int i = 0; i<spaces.size();i++)
	{
		vector<int> curCosts;
		for(int j = 0; j<spaces[i].size(); j++)
		{
			int val = spaces[i][j]*spaces[i][j]*spaces[i][j];
			curCosts.push_back(val);
		}
		lineCosts.push_back(curCosts);
	}

	costs.clear();
	lineStarts.clear();
	int cost = 0;
	costs.push_back(cost);
	
	//figure out the best solution for a set ending in each word
	for(int i = 1; i<=n;i++)
	{
		cost = INT_MAX;
		int costPrev = INT_MAX;
		int costLine = INT_MAX;
		int lineStart = INT_MAX;

		for(int j = i; j>0; j--)
		{
			costPrev = costs[j-1];
			if(lineCosts[j-1].size()>i-j)
			{
				costLine = lineCosts[j-1][i-j];
				if(costPrev+costLine<cost)
				{
					cost = costPrev+costLine;
					lineStart = j;
				}
			}
			else
				continue;
		}
		costs.push_back(cost);
		lineStarts.push_back(lineStart);
	}

	justifyStrings(lineStarts.size());
}

void WordJustifier::justifyStrings(int n)
{

	if(n<=0)
		return;
	else
	{
		int next = lineStarts[n-1]-1;
		justifyStrings(next);
	}

	int cur = lineStarts[n-1]-1;
	int end = 0;
	if(n==lineStarts.size())
		end = stringList.size();
	else
		end = n;

	string temp = "";
	for(int i = cur; i<end; i++)
	{
		temp += stringList[i] + " ";
	}
	justified.push_back(temp);	
	
}

void WordJustifier::solveWordWrap (int l[], int n, int M)
{
	 // For simplicity, 1 extra space is used in all below arrays 
 
    // extras[i][j] will have number of extra spaces if words from i 
    // to j are put in a single line
    int** extras = new int*[n+1];
	for(int i = 0; i<n+1; i++)
	{
		extras[i] = new int[n+1];
	}

    // lc[i][j] will have cost of a line which has words from 
    // i to j
	int** lc = new int*[n+1];
	for(int i = 0; i<n+1; i++)
	{
		lc[i] = new int[n+1];
	}
  
    // c[i] will have total cost of optimal arrangement of words 
    // from 1 to i
    int* c = new int[n+1];
 
    // p[] is used to print the solution.  
    int* p = new int[n+1];
 
    int i, j;
 
    // calculate extra spaces in a single line.  The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
		{
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
		}
    }
 
    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INT_MAX;
            //else if (j == n && extras[i][j] >= 0)
            //    lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j]*extras[i][j];
        }
    }
 
    // Calculate minimum cost and find minimum cost arrangement.
    //  The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INT_MAX;
        for (int i = 1; i <= j; i++)
        {
            if (c[i-1] != INT_MAX && lc[i][j] != INT_MAX && (c[i-1] + lc[i][j] < c[j]))
            {
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }

	for(int i = 0; i<n+1;i++)
	{
		delete[] extras[i];
		delete[] lc[i];
	}

	/*for(int i = 0; i< n+1; i++)
	{
		cout << p[i] << endl;
	}*/

	printSolution(p, n);

	delete[] extras;
	delete[] lc;
	delete[] c;
	delete[] p;
 
    
}

int WordJustifier::printSolution (int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    //printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
	string temp = "";
	for(int i = p[n]-1; i<= n-1; i++)
	{
		temp+= stringList[i] + " ";
	}
	justified.push_back(temp);
    return k;
}
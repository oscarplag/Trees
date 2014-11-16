#include "StdAfx.h"
#include "CustomHeap.h"


CustomHeap::CustomHeap(Point center)
{
	_center = center;
}


CustomHeap::~CustomHeap(void)
{
	while(!closestPoints.empty())
	{
		closestPoints.pop_back();
	}
}

bool CustomHeap::compare(Point p1, Point p2)
{
	float dist1 = sqrt(pow(float(_center.x-p1.x),2)+pow(float(_center.y-p1.y),2));
	float dist2 = sqrt(pow(float(_center.x-p2.x),2)+pow(float(_center.y-p2.y),2));

	return dist1<dist2;
}

Point CustomHeap::top()
{
	return closestPoints[0];
}
Point CustomHeap::pop()
{
	Point top = closestPoints[0];
	closestPoints[0] = closestPoints.back();
	closestPoints.pop_back();
	if(!empty())
		perc_down(closestPoints[0],0);	
	return top;
}
void CustomHeap::perc_down(Point val, int pos)
{
	int size = closestPoints.size();

	if(2*pos>=size)
		return;
	else if((2*pos)+1>=size)
	{
		Point left = closestPoints[2*pos];
		if(compare(val,left))
			return;
		else
		{
			closestPoints[pos] = left;
			closestPoints[2*pos] = val;
			return;
		}
	}
	else
	{
		Point left = closestPoints[2*pos];
		Point right = closestPoints[(2*pos)+1];

		if(compare(left,right))
		{
			if(compare(left,val))
			{
					closestPoints[pos] = left;
					closestPoints[2*pos] = val;
					perc_down(val,2*pos);
			}
			else
				return;
		}
		else if(compare(right,val))
		{
				closestPoints[pos] = right;
				closestPoints[(2*pos)+1] = val;
				perc_down(val,(2*pos+1));
		}
		else
			return;
	}
}
void CustomHeap::insert(Point val)
{
	closestPoints.push_back(val);

	int i = closestPoints.size()-1;

	perc_up(val,i);
}

void CustomHeap::perc_up(Point val, int pos)
{
	if(pos == 0)
		return;

	Point parent = closestPoints[pos/2];

	if(compare(val,parent))
	{
		closestPoints[pos/2] = val;
		closestPoints[pos] = parent;

		perc_up(val,pos/2);
	}
	else
		return;
}

bool CustomHeap::empty()
{
	return closestPoints.empty();
}
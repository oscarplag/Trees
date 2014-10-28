#include "StdAfx.h"
#include "Plane.h"


Plane::Plane(void)
{
}


Plane::~Plane(void)
{
}

void Plane::addPoint(Point p)
{
	_planePoints.push_back(p);
}

vector<Point> Plane::findClosestPoints(Point center, int numPoints)
{
	_center = center;

	while(!_centerDistances.empty())
	{
		_centerDistances.pop();
	}
	
	for(int i =0; i<_planePoints.size();i++)
	{
		PointCenter p(_planePoints[i],_center);
		_centerDistances.push(p);
	}

	vector<Point> closestPoints;

	for(int i = 0;i<numPoints && !_centerDistances.empty();)
	{
		Point p = _centerDistances.top().p;
		if(!(p==_center))
		{
			closestPoints.push_back(_centerDistances.top().p);
			i++;
		}
		_centerDistances.pop();
	}

	return closestPoints;
}
		
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
	priority_queue<Point, vector<Point>, Compare> _centerDistances(center);

	for(int i =0; i<_planePoints.size();i++)
	{
		_centerDistances.push(_planePoints[i]);
	}

	vector<Point> closestPoints;

	for(int i = 0;i<numPoints && !_centerDistances.empty();)
	{
		Point p = _centerDistances.top();
		if(!(p==center))
		{
			closestPoints.push_back(_centerDistances.top());
			i++;
		}
		_centerDistances.pop();
	}
	return closestPoints;
	return vector<Point>();
}
		
CustomPlane::CustomPlane(void)
{
	_centerDistances=NULL;
}


CustomPlane::~CustomPlane(void)
{
}

void CustomPlane::addPoint(Point p)
{
	_planePoints.push_back(p);
}

vector<Point> CustomPlane::findClosestPoints(Point center, int numPoints)
{
	_center = center;
	if(_centerDistances)
	{
		delete _centerDistances;
	}

	_centerDistances = new CustomHeap(center);

	for(int i =0; i<_planePoints.size();i++)
	{
		_centerDistances->insert(_planePoints[i]);
	}

	vector<Point> closestPoints;

	for(int i = 0;i<numPoints && !_centerDistances->empty();)
	{
		Point p = _centerDistances->top();
		if(!(p==_center))
		{
			closestPoints.push_back(p);
			i++;
		}
		_centerDistances->pop();
	}

	return closestPoints;
}
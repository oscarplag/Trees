#pragma once
#include <vector>
#include <queue>
#include "Point.h"
#include "CustomHeap.h"

using namespace std;

class Compare
{
private:
	Point _center;
public:
	Compare(Point center)
	{
		_center = center;
	}
	bool operator()(Point p1, Point p2)
	{
		float dist1 = sqrt(pow(float(_center.x-p1.x),2)+pow(float(_center.y-p1.y),2));
		float dist2 = sqrt(pow(float(_center.x-p2.x),2)+pow(float(_center.y-p2.y),2));
		return dist1>dist2;
	}
};

class Plane
{
private:
	vector<Point> _planePoints;
	
public:
	Plane(void);
	~Plane(void);
	void addPoint(Point p);

	vector<Point> findClosestPoints(Point center, int numPoints);
};

class CustomPlane
{
private:
	vector<Point> _planePoints;
	CustomHeap* _centerDistances;
	Point _center;

public:
	CustomPlane(void);
	~CustomPlane(void);
	void addPoint(Point p);

	vector<Point> findClosestPoints(Point center, int numPoints);
};
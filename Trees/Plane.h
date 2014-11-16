#pragma once
#include <vector>
#include <queue>
#include "Point.h"
#include "CustomHeap.h"

using namespace std;

struct PointCenter
{
	Point p;
	Point center;
	PointCenter(Point P, Point Center)
	{
		p = P;
		center = Center;
	}
};

class Compare
{
public:
	bool operator()(PointCenter p1, PointCenter p2)
	{
		float dist1 = sqrt(pow(float(p1.center.x-p1.p.x),2)+pow(float(p1.center.y-p1.p.y),2));
		float dist2 = sqrt(pow(float(p2.center.x-p2.p.x),2)+pow(float(p2.center.y-p2.p.y),2));
		return dist1>dist2;
	}
};

class Plane
{
private:
	Point _center;
	vector<Point> _planePoints;
	priority_queue<PointCenter, vector<PointCenter>,Compare> _centerDistances;	

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
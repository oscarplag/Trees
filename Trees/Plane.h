#pragma once
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int x;
	int y;
	Point(int X, int Y)
	{
		x = X;
		y = Y;
	}
	Point()
	{
		x = 0;
		y=0;
	}
};

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
	static int smallestDistance(Point p1, Point p2);
	priority_queue<PointCenter, vector<PointCenter>,Compare> _centerDistances;	

public:
	Plane(void);
	~Plane(void);
	void addPoint(Point p);

	vector<Point> findClosestPoints(Point center, int numPoints);
};


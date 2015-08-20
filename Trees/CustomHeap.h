#pragma once
#include <vector>
#include "Point.h"

using namespace std;

class CustomHeap
{
private:
	Point _center;
	vector<Point> closestPoints;
	void perc_up(Point val, int pos);
	void perc_down(Point val, int pos);
	bool compare(Point p1, Point p2);

public:
	CustomHeap(Point center);
	~CustomHeap(void);
	Point top();
	Point pop();
	void insert(Point val);
	bool empty();
};


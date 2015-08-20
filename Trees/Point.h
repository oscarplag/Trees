#pragma once

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
	bool operator==(Point p2)
	{
		if(p2.x == x && p2.y == y)
			return true;
		else
			return false;
	}
};
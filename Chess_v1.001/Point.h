#ifndef POINT_H
#define POINT_H

struct Point
{
	Point() { x = 0; y = 0; }
	Point(int x, int y) { this->x = x; this->y = y; }
	int x;
	int y;

	Point(const vec3 & v) { x = v.x+4; y = v.z+4; }

	bool operator ==(const Point & v)
	{
		if ((this->x == v.x) && (this->y == v.y))
			return true;
		else
			return false;
	}
};

#endif // !POINT_H

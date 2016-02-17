#include "point.h"

namespace main_savitch_2B
{

point::point(double initial_x, double initial_y)
{
	x = initial_x;
	y = initial_y;
}

void point::shift(double x_amount, double y_amount)
{
	x= x+x_amount;
	y+=y_amount;
	}

point operator -(const point& p1, const point& p2)
{
    double xDiff, yDiff;

    xDiff = (p1.get_x() - p2.get_x());
    yDiff = (p1.get_y() - p2.get_y());

    point difference(xDiff, yDiff);
    return difference;
}
}




#include <iostream>
#include "point.h"
#include "math.h"
#include "assert.h"
#include "string.h"

namespace main_wessels_1
{
    point::point(double initial_x, double initial_y, double initial_z)
    {
        x = initial_x;
        y = initial_y;
        z = initial_z;
    }


void point::shift(double x_amount, double y_amount, double z_amount)
{
    x += x_amount;
    y += y_amount;
    z += z_amount;
}

void point::rotate(char axis[], double ang)
{
    const double pi = 3.14159265;
    ang = ang * pi / 180.0;
    assert(strcmp(axis, "x") == 0 || strcmp(axis, "y") == 0 || strcmp(axis, "z") == 0);
    if(strcmp(axis, "x") == 0)
    {
        y = y * cos(ang) - z * sin(ang);
        z = y * sin(ang) + z * cos(ang);
    }
    else if(strcmp(axis, "y") == 0)
    {
        x = x * cos(ang) + z * sin(ang);
        z = -x * sin(ang) + z * cos(ang);
    }
    else
    {
        x = x * cos(ang) - y * sin(ang);
        y = x * sin(ang) + y * cos(ang);
    }
}

ostream& operator <<(ostream& outs, const point& source)
{
    outs << "x: " << source.get_x() << " y: " << source.get_y() << " z: "
    << source.get_z();
    return outs;
}
}


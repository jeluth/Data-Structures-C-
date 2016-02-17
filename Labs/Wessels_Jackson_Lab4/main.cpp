#include <iostream>
#include "throttle.h"
#include "point.h"
using namespace std;
using namespace main_savitch_2A;
using namespace main_savitch_2B;

int main()
{
    throttle throttleOne(6);
    throttle throttleTwo(6);

    throttleOne.shift(3);
    throttleTwo.shift(4);

    cout << (throttleOne.flow() < throttleTwo.flow()) << endl;

    point pointOne(0, 0);
    point pointTwo(0, 0);

    pointOne.shift(4.5, 4.5);
    pointTwo.shift(3.5, 3.5);

    point difference = pointOne - pointTwo;

    cout << difference.get_x() << difference.get_y() << endl;
    cout << "Hello world!" << endl;
    return 0;
}



#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "bag.h"
#include "time.h"


using namespace std;
using namespace main_wessels_5;

int main()
{
    bag b;

    srand(time(NULL));
    cout << b.getCapacity() << endl;

    for(int i = 1; i < 102; i++)
    {
        b.insert(rand() % 20);
        cout << left<< setw(6) << i
        << right << setw(6) <<  b.getCapacity() << endl;
    }
        cout << b.getCapacity() << endl;

    return 0;
}

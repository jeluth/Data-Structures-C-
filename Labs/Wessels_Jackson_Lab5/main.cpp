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
    int range = 20;

    srand(time(NULL));
    for(int i = 0; i < b.CAPACITY; i++)
        b.insert(rand() % 20);

    for(int i=0; i < range; i++)
        cout << left<< setw(6) << i
        << right << setw(6) <<  b.count(i) << endl;

    return 0;
}

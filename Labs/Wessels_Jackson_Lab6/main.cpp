#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    const int CAPACITY = 30;

    multiset<double> myContainer;
    multiset<double>::iterator it;

    srand(time(NULL));
    for (int i = 0; i < CAPACITY; i++)
    {
        double random = rand()/(double)RAND_MAX;
        myContainer.insert(random);
    }

    for (it = myContainer.begin(); it != myContainer.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

// FILE: str_demo.cxx
// This is a small demonstration program showing how the string class is used.
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "cstring" // Or use the Standard Library <string>
using namespace std;
// PROTOTYPES for functions used by this demonstration program:
// The two strings, mine and yours, are compared. If they are the same, then a
// message is printed saying they are the same; otherwise mine is printed
// in a message. In either case, the string variety is part of the message.

int strLength(char myChar[]);

int main( )
{
    char blank[20] = "";
    cout << "Enter a string with up to 20 characters:";
    cin.getline(blank, 20);
    strcat(blank, "!");
    cout << "Your string: " << blank << " length = " << strLength(blank);
    return EXIT_SUCCESS;
}

int strLength(char myChar[])
{
    int length = 0;
    int i = 0;
    while(myChar[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}



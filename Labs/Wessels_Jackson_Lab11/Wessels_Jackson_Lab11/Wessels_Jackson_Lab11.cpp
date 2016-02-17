// Wessels_Jackson_Lab11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
//template <class Item> 
//Item equalTest(item a, item b);

template <class Item> char const* equalTest(Item a, Item b)
{
	if (a == b)
		return "Those are the same.";
	else
		return "Those are different.";
}
int main()
{
	int a, b;
	a = 2;
	b = 2;
	cout << equalTest(a, b) << endl;
	b = 3;
	cout << equalTest(a, b) << endl;
	char const* c = "hi";
	char const* d = "hello";
	cout << equalTest(c, d) << endl;
	d = "hi";
	cout << equalTest(c, d) << endl;

    return 0;
}



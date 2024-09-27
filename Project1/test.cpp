#include<iostream>
#include"Vector.h"
using namespace std;

int test()
{
	Vector a(10);
	a.InputRand();
	a *= 10;
	a.Print();

	return 0;
}
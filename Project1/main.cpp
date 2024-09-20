#include<iostream>
#include"Vector.h"
using namespace std;

int main()
{
	srand(time(0));

	Vector obj1(5);
	obj1.InputRand();
	obj1.Print();

	Vector obj3 = obj1 - 2;
	obj3.Print();

	Vector obj2 = obj1 + 12;
	obj2.Print();

	Vector obj4(2);
	obj4.InputRand();
	obj4.Print();

	Vector obj5 = obj1 + obj4;
	obj5.Print();

	Vector obj6 = obj1 * 3;
	obj6.Print();
	


}
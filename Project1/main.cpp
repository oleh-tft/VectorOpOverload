#include<iostream>
#include"Vector.h"
using namespace std;

int main()
{
	srand(time(0));

	Vector obj(5);
	obj.InputRand();
	obj.Print();

	obj += 5;
	obj.Print();

	obj -= 4;
	obj.Print();

	obj *= 5;
	obj.Print();

	Vector c = 2 - obj;
	c.Print();
	obj.Print();

	Vector inp(4);
	cin >> inp;
	cout << inp;

}
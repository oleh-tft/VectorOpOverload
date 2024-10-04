#pragma once
#include<iostream>
using namespace std;

class Vector
{
	int* arr;
	int size;
	friend ostream& operator<<(ostream& os, Vector& obj);
	friend istream& operator>>(istream& is, Vector& obj);
public:
	Vector();
	Vector(int s);
	~Vector();
	Vector(const Vector & obj);
	Vector(initializer_list<int> a);

	void InputRand();
	void Print();

	void PushBack(int a);
	int PopBack();
	void AddFirst(int value);
	void AddElement(int index, int value);
	void Remove(int index);
	void RemoveFirst();
	void Concat(int* add, int size);

	Vector operator-(int a);
	Vector operator+(int a);
	Vector operator+(Vector & b);
	Vector operator*(int a);

	int GetSize()const;
	void SetSize(int Size);
	int* GetArr()const;
	void SetArr(int* Arr);
	int operator[] (int index);

	Vector& operator=(const Vector& obj);
};

Vector operator+=(Vector& obj, int a);
Vector operator-=(Vector& obj, int a);
Vector operator*=(Vector& obj, int a);
Vector operator-(int a, Vector& obj);
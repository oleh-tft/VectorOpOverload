#pragma once
class Vector
{
	int* arr;
	int size;
public:
	Vector();
	~Vector();
	Vector(const Vector & obj);


	Vector(int s);
	void InputRand(); // инициализация случ числами
	void Print();// вывод на консоль

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

	Vector& operator++();
	Vector operator++(int);
	Vector& operator--();
	Vector operator--(int);
	Vector& operator+=(int a);
	Vector& operator-=(int a);
	Vector& operator*=(int a);

	Vector& operator=(const Vector& obj);
};
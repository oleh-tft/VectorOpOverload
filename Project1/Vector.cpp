#include "Vector.h"
#include<iostream>
#include<Windows.h>
using namespace std;

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}
Vector::Vector(int s)
{
	size = s;
	arr = new int[size] {0};
}
Vector::~Vector()
{
	cout << "Destructor\n";
	delete[]arr;
	size = 0;
	
}
Vector::Vector(const Vector& obj)
{
	cout << "Copy constructor\n";
	this->size = obj.size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}
void Vector::InputRand()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%41 - 20; // [-20 +20]
	}
}
void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n---------------------------------------------------\n";
}

void Vector::PushBack(int a)
{
	int* temp = new int[size + 1];  // ������ ����� ������ (��� ������ +1)

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i]; // �������� ������� �������� ������� ������� � ����� ������
	}
	temp[size] = a; // ������������� ���������� �������� ���������� ������

	delete[] arr; // �������� ������� �������!

	arr = temp; // �������������� ��������� � ������� �� ����� ���. ������
	size++;

}

int Vector::PopBack()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	int el = arr[size - 1]; // ������� ��������� ������� ������� ������� �� ��������

	delete[] arr;
	arr = temp;
	size--;

	return el;
}

Vector Vector::operator-(int a)
{
	Vector rez(size - a);
	for (int i = 0; i < rez.size; i++)
	{
		rez.arr[i] = arr[i];
	}
	return rez;
}

Vector Vector::operator+(int a)
{
	Vector rez(size + a);

	for (int i = 0; i < rez.size; i++)
	{
		rez.arr[i] = i >= size ? 0 : arr[i];
	}

	return rez;
}

Vector Vector::operator+(Vector& b)
{
	Vector rez(size + b.size);

	for (int i = 0; i < size; i++)
	{
		rez.arr[i] = arr[i];
	}
	for (int i = 0; i < b.size; i++)
	{
		rez.arr[size+i] = b.arr[i];
	}

	return rez;
}

Vector Vector::operator*(int a)
{
	Vector rez(size);

	for (int i = 0; i < rez.size; i++)
	{
		rez.arr[i] = arr[i] * a;
	}

	return rez;
}

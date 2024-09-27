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
	int* temp = new int[size + 1];  // содаем новый массив (тек размер +1)

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i]; // копируем текущие значени€ старого массива в новый массив
	}
	temp[size] = a; // инициализаци€ последнего элемента параметром метода

	delete[] arr; // удаление старого массива!

	arr = temp; // перенаправл€ем указатель в объекте на новый дин. массив
	size++;

}

int Vector::PopBack()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	int el = arr[size - 1]; // достаем последний элемент старого массива ƒќ удалени€

	delete[] arr;
	arr = temp;
	size--;

	return el;
}

void Vector::AddFirst(int value)
{
	int* temp = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i + 1] = arr[i];
	}
	temp[0] = value;

	delete[] arr;
	arr = temp;
	size++;
}

void Vector::AddElement(int index, int value)
{
	int* temp = new int[size + 1];

	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = index; i < size; i++)
	{
		temp[i + 1] = arr[i];
	}

	temp[index] = value;

	delete[] arr;
	arr = temp;
	size++;
}

void Vector::Remove(int index)
{
	int* temp = new int[size - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = index; i < size; i++)
	{
		temp[i] = arr[i + 1];
	}

	delete[] arr;
	arr = temp;
	size--;
}

void Vector::RemoveFirst()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i + 1];
	}

	delete[] arr;
	arr = temp;
	size--;
}

void Vector::Concat(int* add, int AddSize)
{
	int* temp = new int[size + AddSize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < AddSize; i++)
	{
		temp[size + i] = add[i];
	}

	delete[] arr;
	arr = temp;
	size += AddSize;
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

int Vector::GetSize()const
{
	return size;
}

void Vector::SetSize(int Size)
{
	size = Size;
}

int* Vector::GetArr() const
{
	return arr;
}

void Vector::SetArr(int* Arr)
{
	delete[] arr;
	arr = Arr;
}

int Vector::operator[](int index)
{
	return arr[index];
}

Vector& Vector::operator=(const Vector& obj)
{

	if (this == &obj) return *this;
	if (arr != nullptr) delete[] arr;

	size = obj.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}

	return *this;
}

ostream& operator<<(ostream& os, Vector& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		os << obj.arr[i] << " ";
	}
	os << endl;
	return os;
}

istream& operator>>(istream& is, Vector& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		is >> obj.arr[i];
	}
	return is;
}

Vector operator+=(Vector& obj, int a)
{
	int* temp = new int[obj.GetSize() + a];

	for (int i = 0; i < obj.GetSize() + a; i++)
	{
		temp[i] = i >= obj.GetSize() ? 0 : obj[i];
	}

	obj.SetArr(temp);
	obj.SetSize(obj.GetSize() + a);

	return obj;
}

Vector operator-=(Vector& obj, int a)
{
	if (obj.GetSize() < a)
	{
		cout << "Input value must be lower than " << obj.GetSize() + 1 << endl;
		return obj;
	}

	int* temp = new int[obj.GetSize() - a];

	for (int i = 0; i < obj.GetSize() - a; i++)
	{
		temp[i] = obj[i];
	}

	obj.SetArr(temp);
	obj.SetSize(obj.GetSize() - a);

	return obj;
}

Vector operator*=(Vector& obj, int a)
{
	int* temp = new int[obj.GetSize()];

	for (int i = 0; i < obj.GetSize(); i++)
	{
		temp[i] = obj[i] * a;
	}

	obj.SetArr(temp);

	return obj;
}

Vector operator-(int a, Vector& obj)
{
	Vector t(obj.GetSize() - a);

	for (int i = 0; i < obj.GetSize() - a; i++)
	{
		t.GetArr()[i] = obj[i + a];
	}

	return t;
}

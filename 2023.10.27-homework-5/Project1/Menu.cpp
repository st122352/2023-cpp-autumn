#include <iostream>
#include<ctime>
#include<cstdlib>
#include "body2.h"

void mainMenu()
{
	std::cout << "Commands:" << std::endl;
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Eppend new element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - Sort the array" << std::endl;
	std::cout << "5 - Deploy the array" << std::endl;
	std::cout << "6 - Change firts max and last min elements" << std::endl;
	std::cout << "7 - Delete all duplicates from array" << std::endl;
	std::cout << "8 - Append randome elements to array" << std::endl;
	std::cout << "Array: ";

}

void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& a, int& len)
{
	int* newArray = new int[len + 1] {0};
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newArray[i] = a[i];
		}
		delete[] a;
	}
	a = newArray;
	++len;
}

void addElement(int*& a, int& len, int newElement)
{
	expandArray(a, len);
	a[len - 1] = newElement;
}

bool checkIndex(int index, int len)
{
	return (index >= 0 && index < len);
}

void reduceArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
		a = newA;
		--len;
	}
}

void deleteElement(int*& a, int& len, int index)
{
	if (checkIndex(index, len))
	{
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		reduceArray(a, len);
	}
}

void sortArray(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int b = 0; b < len - i; ++b)
		{
			if (a[i] > a[i + b])
			{
				int temp = a[i];
				a[i] = a[i + b];
				a[i + b] = temp;
			}
		}
	}
}

void flipArray(int* a, int len)
{
	for (int i = 0; i < len / 2; ++i)
	{
		int temp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = temp;
	}
}

void findMaxMin(int* a, int len, int& max, int& min)
{
	for (int i = 1; i < len; ++i)
	{
		if (a[max] < a[i])
		{
			max = i;
		}
		if (a[min] >= a[i])
		{
			min = i;
		}
	}
}

void swapMaxMin(int* a, int len, int& max, int& min, int& temp)
{
	temp = a[max];
	a[max] = a[min];
	a[min] = temp;
}

void deleteDuplicates(int*& a, int& len, int& index)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int b = i + 1; b < len; ++b)
		{
			if (a[i] == a[b])
			{
				index = b;
				deleteElement(a, len, index);
			}
		}
	}
}

void randArray(int*& a, int& len, int n, int newElement)
{
	int max = 1000;
	int min = -1000;

	srand(time(0));

	for (int i = 0; i < n; ++i)
	{
		newElement = rand() % (max - min + 1) + max;
		addElement(a, len, newElement);
	}
}

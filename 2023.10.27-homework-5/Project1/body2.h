#pragma once
#include <iostream>

void mainMenu();

void printArray(int* a, int len);

void expandArray(int*& a, int& len);

void addElement(int*& a, int& len, int newElement);

bool checkIndex(int index, int len);

void reduceArray(int*& a, int& len);

void deleteElement(int*& a, int& len, int index);

void sortArray(int* a, int len);

void flipArray(int* a, int len);

void findMaxMin(int* a, int len, int& max, int& min);

void swapMaxMin(int* a, int len, int& max, int& min, int& temp);

void deleteDuplicates(int*& a, int& len, int& index);

void randArray(int*& a, int& len, int n, int newElement);
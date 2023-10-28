#include <iostream>
#include "body2.h"

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;
	bool exit = false;

	while (!exit)
	{
		int max = 0;
		int min = 0;
		int temp = 0;
		int index = 0;
		{
			system("cls");
			mainMenu();
			printArray(a, len);
		}
		int key = 0;
		{
			std::cin >> key;
		}
		{
			switch (key)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int newElement = 0;
				std::cout << "Enter new element to add: ";
				std::cin >> newElement;
				addElement(a, len, newElement);
				break;
			}
			case 3:
			{
				std::cout << "Enter index to delete element: ";
				std::cin >> index;
				deleteElement(a, len, index);
				break;
			}
			case 4:
				sortArray(a, len);
				break;
			case 5:
				flipArray(a, len);
				break;
			case 6:
			{
				findMaxMin(a, len, max, min);
				swapMaxMin(a, len, max, min, temp);
				break;
			}
			case 7:
				deleteDuplicates(a, len, index);
				break;
			case 8:
			{
				int newElement = 0;
				std::cout << "Enter number of elements to append: ";
				int n = 0;
				std::cin >> n;
				randArray(a, len, n, newElement);
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}

	}

	return EXIT_SUCCESS;
}

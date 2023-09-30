#include<iostream>

int main(int argc, char* argv[])
{

	int x = 0;

	std::cin >> x;

	while (x) 
	{

		std::cout << x % 10;

		x = x / 10;
	}

	return EXIT_SUCCESS;

}
#include<iostream>

int main(int argc, char* argv[])
{

	int n = 0;
	int i = 1;
	int s = 0;

	std::cin >> n;

	while (i < n) 
	{

		i = i * 2;

		s = s + 1;

	}

	std::cout << s;

	return EXIT_SUCCESS;

}
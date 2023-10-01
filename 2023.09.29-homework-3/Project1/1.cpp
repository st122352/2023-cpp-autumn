#include<iostream>

int main(int argc, char* argv[])
{
    int n = 1;
	int a = 0;

	std::cin >> a;

	for (int i = 1; n <= a; i++)
		for (int j = 1; j <= i && n <= a; j++, ++n)
		{
			std::cout << i << ' ';

		}

	return EXIT_SUCCESS;

}
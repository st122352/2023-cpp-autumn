#include<iostream>

int main(int argc, char* argv[])
{

	int a = 0;
	int n = 0;

	std::cin >> a;

	for (int i = 1; i <= sqrt(a) - 1; ++i) 
	{

		if (a % i == 0)

			++n;
	}
	n = n * 2;

	if (sqrt(a) == int(sqrt(a)))

		++n;

	std::cout << n;

	
	return EXIT_SUCCESS;
}
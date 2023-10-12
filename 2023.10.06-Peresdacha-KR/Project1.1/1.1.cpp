#include<iostream>

int main(int argc, char* argv[])
{
	const int BIT = sizeof(unsigned int) * 8;

	unsigned int n = 0;

	std::cin >> n;

	int summ = 0;

	for (int i = 0; i < BIT; ++i)
	{
	   summ += (n >> i) & 1;
    }

	std::cout << summ << std::endl;
	
	return EXIT_SUCCESS;
}

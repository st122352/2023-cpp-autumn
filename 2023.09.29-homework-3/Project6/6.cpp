#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int i = 0;
	int f = 0;
	int f0 = 0;
	int f1 = 1;


	std::cin >> n;

	if (n == 0)
	{ 
	
		f = 0;

	}
	if (n == 1) 
	{

		f = 1;

	}

	while (++i < n) 
	{

		f = f1 + f0;

		f0 = f1;

		f1 = f;

	}
	
	std::cout << f;

	return EXIT_SUCCESS;

}

#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;


	std::cout << "a)" << std::endl;
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << j + 1;
			}

			std::cout << std::endl;
		}
	}

	std::cout << "b)" << std::endl;
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << i + 1;
			}

			std::cout << std::endl;
		}
	}

	std::cout << "c)" << std::endl;
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << (i + j) % n + 1;
			}

			std::cout << std::endl;
		}
	}

	std::cout << "d)" << std::endl;
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << 2 * n - i - j - 1;
			}

			std::cout << std::endl;
		}
	}

	std::cout << "e)" << std::endl;
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << std::max(std::min(n - j, j + 1), std::min(n - i, i + 1));
			}

			std::cout << std::endl;
		}
	}

	std::cout << "f)" << std::endl;
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << (i % 2 == 0 ? j + 1 : n - j);
			}

			std::cout << std::endl;
		}
	}

	return EXIT_SUCCESS;

}

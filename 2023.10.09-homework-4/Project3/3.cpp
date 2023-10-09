#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int c = 0;

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);

		if (i % 2 == 1)
		{
			std::cout << *(a + i) << " ";
		}

	}

	free(a);

	return EXIT_SUCCESS;

}

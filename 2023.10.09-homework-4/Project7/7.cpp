#include<iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	int c = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);

		if (*(a + i) > 0)
		{
			c++;
		}
		else 
		{
			*(a + i) = 0;

		}
	}

	int* b = (int*)malloc(sizeof(int) * c);

	int j = 0;

	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			*(b + j) = *(a + i);
			std::cout << *(b + j);
		}
	}
	free(a);
	free(b);

	return EXIT_SUCCESS;

}

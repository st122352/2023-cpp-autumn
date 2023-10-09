#include<iostream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	std::cin >> *(a);

	int max = *(a);
	int max_i = 0;
	int min = *(a);
	int min_i = 0;

	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);

		if (*(a + i) >= max)
		{
			max = *(a + i);
			max_i = i;

		}
		if (*(a + i) < min)
		{
			min = *(a + i);
			min_i = i;

		}
	}
	*(a + max_i) = min;
	*(a +min_i) = max;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);

	return EXIT_SUCCESS;

}

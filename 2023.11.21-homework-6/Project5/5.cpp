#include<iostream>

void hanoi(int n, int from, int to)
{
	if (n <= 0 || n > 10)
	{
		return;
	}

	int res = 6 - from - to;

	hanoi(n - 1, from, res);

	std::cout << n << " " << from << " " << to << std::endl;

	hanoi(n - 1, res, to);

}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int to = 0;
	if (n % 2 != 0)
	{
		to = 2;
	}
	else
	{
		to = 3;
	}

	hanoi(n, 1, to);

	int res = 5 - to;

	for (int i = n; i > 0; i--)
	{
		hanoi(i - 1, to, res);
		std::swap(to, res);
	}

	return EXIT_SUCCESS;
}
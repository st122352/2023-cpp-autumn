#include<iostream>

void hanoi(int count, int from, int to)
{
	if (count <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	if (count == 1)
	{
		std::cout << 1 << " " << from << " " << to << std::endl;
	}
	else
	{
		hanoi(count - 1, from, to);

		hanoi(count - 2, to, res);

		std::cout << 0 << " " << from << " " << to << std::endl;

		hanoi(count - 2, res, from);

		hanoi(count - 1, from, to);

	}
}


int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	hanoi(n, 1, 3);

	return EXIT_SUCCESS;
}
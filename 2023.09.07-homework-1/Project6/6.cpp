#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;

	std::cin >> a;
	std::cin >> b;

	c = ((((a / b) * a) + ((b / a) * b)) / ((a / b) + (b / a)));

	std::cout << c;

	return EXIT_SUCCESS;

}
#include <iostream>

int main(int argc, char* argv[])
{
	int a;
	int b;
	int c;

	std::cin >> a;
	std::cin >> b;

	c = ((((a / b) * a) + ((b / a) * b)) / ((a / b) + (b / a)));

	std::cout << c;

	return EXIT_SUCCESS;

}
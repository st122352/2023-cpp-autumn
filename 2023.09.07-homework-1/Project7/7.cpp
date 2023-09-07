#include <iostream>

int main(int argc, char* argv[])
{
	int a;
	int b;
	int c;

	std::cin >> a;

	b = a - 1;
	c = a + 1;

	std::cout << "The next number for the number " << a << " is " << c << "." << std::endl;
	std::cout << "The previous number for the number " << a << " is " << b << "." << std::endl;

	return EXIT_SUCCESS;

}
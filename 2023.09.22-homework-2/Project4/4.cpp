#include<iostream>

int main(int argc, char* argv[]) {

	int n;
	int b1;
	int b5;
	int b10;
	int b20;
	int b60;

	std::cin >> n;

	b60 = n / 60;
	n = n % 60;

	b20 = n / 20;
	n = n % 20;

	b10 = n / 10;
	n = n % 10;

	b5 = n / 5;

	b1 = n % 5;

	if (b1 * 15 >= 70)
	{
		b1 = 0;
		b5++;
	}
	if (b1 * 15 + b5 * 70 >= 125)
	{
		b1 = 0;
		b5 = 0;
		b10++;
	}
	if (b1 * 15 + b5 * 70 + b10 * 125 >= 230)
	{
		b1 = 0;
		b5 = 0;
		b10 = 0;
		b20++;
	}
	if (b1 * 15 + b5 * 70 + b10 * 125 + b20 * 230 >= 440)
	{
		b1 = 0;
		b5 = 0;
		b10 = 0;
		b20 = 0;
		b60++;
	}

	std::cout << b1 << " " << b5 << " " << b10 << " " << b20 << " " << b60;

	return EXIT_SUCCESS;
}
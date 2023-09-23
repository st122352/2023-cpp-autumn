#include<iostream>

int main(int argc, char* argv[]) {

	int n = 0;
	int c = 0;

	std::cin >> c;

	n = c % 10;

	if (n == 0 || (n >= 5 && n <= 9) || (c % 100 >= 11 && c % 100 <= 14)) {

		std::cout << c << " bochek";

	}
	else if (n == 1) {

		std::cout << c << " bochka";

	}
	else {

		std::cout << c << " bochki";

	}



	return EXIT_SUCCESS;

}




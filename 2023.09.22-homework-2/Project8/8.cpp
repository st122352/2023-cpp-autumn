#include<iostream>

int main(int argc, char* argv[]) {

	int a = 0;
	int b = 0;
	int c = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	if (a > b && a > c) {
		if (b > c) {
			std::cout << c << " " << b << " " << a;
		}
		else {
			std::cout << b << " " << c << " " << a;

		}
		
	}
	else if (b > a && b > c) {

			if (a > c) {
				std::cout << c << " " << a << " " << b;
			}
			else {
				std::cout << a << " " << c << " " << b;

			}
		
	}
	else if (c > a && c > b) {
		if (a > b) {
			std::cout << b << " " << a << " " << c;
		}
		else {
			std::cout << a << " " << b << " " << c;

		}
		

	}
	else {

		std::cout << a << b << c;

	}

	return EXIT_SUCCESS;

}
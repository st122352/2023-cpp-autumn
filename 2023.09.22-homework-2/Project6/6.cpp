#include<iostream>

int main(int argc, char* argv[]) {

	double k = 0;
	double m = 0;
	double n = 0;
	double a = 0;

	std::cin >> k;
	std::cin >> m;
	std::cin >> n;


	if (n == k) {

		std::cout << n * (2 * m);

	}
	else if (n > k) {

		a = ceil(n / k);

		std::cout << a * (2 * m);
	}
	else {

		std::cout << a * (2 * m);

	}



	return EXIT_SUCCESS;

}
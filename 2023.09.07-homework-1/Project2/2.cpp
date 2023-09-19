#include<iostream>;

int main(int argc, char* argv[])
{
	int a = 0;
	int S = 0;
	int N = 0;
	int d = 0;


	a = 1;
	d = 1;

	std::cin >> N;
	
	S = ((2 * a) + d * (N - 1)) * N / 2;
	
	std::cout << S;

	return EXIT_SUCCESS;
}
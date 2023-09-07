#include<iostream>;

int main(int argc, char* argv[])
{
	int a;
	int S;
	int N;
	int d;


	a = 1;
	d = 1;

	std::cin >> N;
	
	S = ((2 * a) + d * (N - 1)) * N / 2;
	
	std::cout << S;

	return EXIT_SUCCESS;
}
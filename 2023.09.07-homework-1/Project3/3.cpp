#include<iostream>;

int main(int argc, char* argv[])
{
    int long long a = 0;
    int long long b = 0;

    std::cin >> a;

    b = a / 10;

    a = 100 * b * (b + 1) + 25;

    std::cout << a;
   

	return EXIT_SUCCESS;

}
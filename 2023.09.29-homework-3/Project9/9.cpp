#include<iostream>

int main(int argc, char* argv[])
{
	int n1 = 0;
	int n2 = 0;

	std::cin >> n1;
	std::cin >> n2;

	while (n1 != n2)
	{

	    if ((n1 % 2) == 0 && n1 / 2 >= n2)
		{
			n1 = n1 / 2;

			std::cout << ":2" << std::endl;

		}
		else if ((n1 % 2) != 0)
		{
			n1 = n1 - 1;

			std::cout << "-1" << std::endl;

		}
		
	}

	std::cout << " " << std::endl;


		return EXIT_SUCCESS;
}
#include<iostream>

int main(int argc, char* argv[])
{
	const int BIT = sizeof(unsigned int) * 8;

	unsigned int n = 0;		
	std::cin >> n;

	std::cout << "0b ";
	for (int i = BIT - 1; i >= 0; --i)
	{
		std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
	}
	std::cout << std::endl;

	if (n == 0)
	{
		n = ~n;
	}
	else
	{
		int mx = BIT - 1;
		int mn = 0;
		while ((n >> mx & 1) == 0)
		{
			mx--;
		}
		while ((n >> mn & 1) == 0)
		{
			mn++;
		}

		mx--;
		mn++;
		unsigned int mask = 0;		
		mask = ~mask;		
		mask = (mask >> (mx - mn + 1));		
		mask = ~mask;		
		mask = (mask >> (BIT - mx - 1));		
		n = n ^ mask;

		std::cout << "0b ";
		for (int i = BIT - 1; i >= 0; --i)
		{
			std::cout << ((n >> i) & 1) << (i % 4 == 0 ? " " : "");
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;

}

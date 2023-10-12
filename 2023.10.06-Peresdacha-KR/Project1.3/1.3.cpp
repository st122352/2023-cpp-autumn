#include<iostream>

int main(int argc, char* argv[])
{
	const int BIT = sizeof(unsigned int) * 8;

	unsigned int a = 0; 
	unsigned int b = 0; 
	unsigned int c = 0;    
	
	std::cin >> a;
	std::cin >> b;

	bool up = 0;
	for (int i = 0; i < BIT; ++i)
	{
		bool bitA = ((a >> i) & 1);
		bool bitB = ((b >> i) & 1);
		bool current = bitA ^ bitB ^ up;
		
		up = (bitA & bitB) | (bitA & up) | (bitB & up);

		c = c | ((int)current << i);
	}
	std::cout << a << " + " << b << " = " << c << std::endl;


	return EXIT_SUCCESS;

}

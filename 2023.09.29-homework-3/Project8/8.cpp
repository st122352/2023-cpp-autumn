#include<iostream>


int main(int argc, char* argv[])
{
	int a; 
	int b;
	int n;
	int s1;
	int s2;
	int possible = 1;

	std::cin >> a;
	std::cin >> b;
	std::cin >> n;

	s1 = 0;
	s2 = 0;

	while (true) {
		if (s1 == 0)
		{
			s1 += a;
			if (s1 == n || s2 == n) break;
		}
		if (s1 < b - s2)
		{
			s2 += s1;
			s1 = 0;
		}
		else
		{
			s1 -= b - s2;
			s2 = b;
		}

		if (s1 == n || s2 == n) break;

		if (s2 == b)
		{
			s2 = 0;

			if (s1 == n || s2 == n) break;
		}
		if (s1 == 0 && s2 == 0)
		{
			possible = 0;

			break;
		}
	}


	if ((a < n && b < n) || (possible == 0))
	{
		std::cout << "Impossible" << std::endl;
	}
	else
	{
		s1 = 0;
		s2 = 0;

		while (true) {
			if (s1 == 0)
			{
				s1 += a;
				std::cout << ">A" << std::endl;

				if (s1 == n || s2 == n) return 0;
			}
			if (s1 < b - s2)
			{
				s2 += s1;

				s1 = 0;
			}
			else
			{
				s1 -= b - s2;

				s2 = b;
			}
			std::cout << "A>B" << std::endl;

			if (s1 == n || s2 == n) return 0;

			if (s2 == b)
			{
				s2 = 0;
				std::cout << "B>" << std::endl;

				if (s1 == n || s2 == n) return 0;
			}
			if (s1 == 0 && s2 == 0)
			{
				std::cout << "Impossible" << std::endl;

				return 0;
			}
		}
	}

	return EXIT_SUCCESS;

}

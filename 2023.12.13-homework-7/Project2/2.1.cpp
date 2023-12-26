#include<iostream>
#include<string>
#include<fstream>

std::string findmword(std::string& text) 
{
	std::string words[255];

	int counts[255] = { 0 };

	std::string word;

	int count = 0;

	size_t start = 0, end = text.find(' ');

	while (end != std::string::npos) 
	{
		word = text.substr(start, end - start);

		for (char& c : word) 
		{
			c = std::tolower(c);
		}

		int in = -1;
		for (int i = 0; i < count; ++i) 
		{
			if (words[i] == word)
			{
				in = i;

				break;
			}
		}

		if (in != -1) 
		{
			counts[in]++;
		}
		else 
		{
			words[count] = word;

			counts[count] = 1;

			count++;
		}

		start = end + 1;

		end = text.find(' ', start);
	}

	word = text.substr(start);

	for (char& c : word) 
	{
		c = std::tolower(c);
	}

	int in = -1;
	for (int i = 0; i < count; ++i)
	{
		if (words[i] == word)
		{
			in = i;
			break;
		}
	}

	if (in != -1) 
	{
		counts[in]++;
	}
	else 
	{
		words[count] = word;

		counts[count] = 1;

		count++;

		if (count >= 255)
		{
			std::cout << "Mnogo slov\n";
			return "";
		}
	}

	std::string maxword;

	int maxcount = 0;

	for (int i = 0; i < count; ++i) 
	{
		if (counts[i] > maxcount) 
		{
			maxword = words[i];

			maxcount = counts[i];
		}
	}

	return maxword;
}

int main() 
{
	std::ifstream fin("in.txt");

	std::string a = "";

	std::getline(fin, a);

	fin.close();

	std::ofstream fout("out.txt");

	fout << findmword(a) << std::endl;

	fout.close();


	return 0;
}
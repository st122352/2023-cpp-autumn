#include<iostream>
#include<cstring>
#include<fstream>

bool ispalindrome(const std::string& str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() 
{
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    std::string palindrome = ispalindrome(text) ? "eto polindrome" : "eto ne polindrome";

    outputFile << palindrome << std::endl;

    outputFile.close();

    std::cout << "SUCCESS" << std::endl;

    return 0;
}


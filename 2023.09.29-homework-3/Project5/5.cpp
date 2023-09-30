#include<iostream>

int main(int argc, char* argv[])
{

    int n = 0;
    int r = 0;
    
    std::cin >> n;

    for (int a = 1; a <= n; ++a)
    {
        int n1 = a;
        int n2 = 0;
        
        while (n1 > 0)
        {
            n2 = n2 * 10 + n1 % 10;
            n1 = n1 / 10;
        }

        if (a == n2) 
        {
            r++;
        }
    }

    std::cout << r << std::endl;

   
   return EXIT_SUCCESS;

}

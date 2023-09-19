#include <iostream>

int main(int argc, char* argv[])
{
    int v = 0;
    int t = 0;
    int d = 0;
    int s = 0;

    std::cin >> v >> t;

    s = v * t % 109;

    d = (s + 109) % 109 + 1;

    std::cout << d;

    return EXIT_SUCCESS;
}

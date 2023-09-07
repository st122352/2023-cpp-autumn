#include <iostream>

int main(int argc, char* argv[])
{
    int v;
    int t;
    int d;
    int s;

    std::cin >> v >> t;

    s = v * t % 109;

    d = (s + 109) % 109 + 1;

    std::cout << d;

    return EXIT_SUCCESS;
}

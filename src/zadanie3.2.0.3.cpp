#include <iostream>

auto swap(int &, int &) -> void;

auto main()-> int
{
    int a = 42;
    int b = 64;

    std::cout << "Przed zamiana\na = " << a << ", b = " << b << std::endl << std::endl;

    swap(a, b);

    std::cout << "Po zamianie\na = " << a << ", b = " << b << std::endl;


    return 0;
}


auto swap(int &x, int &y) -> void
{
    int temp = x;
    x = y;
    y = temp;
}

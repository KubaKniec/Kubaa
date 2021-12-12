#include <iostream>

auto print(std::string) -> void;

auto main() -> int
{

    print("Hello, World!");

    return 0;
}


auto print(std::string x) -> void
{
    std::cout << &x << " = " << x;
}

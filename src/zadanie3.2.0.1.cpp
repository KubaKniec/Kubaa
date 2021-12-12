#include <iostream>


auto main() -> int
{
    std::string hello = "Hello, World!";

    std::string *wsk = &hello;

    std::cout << wsk;

    return 0;
}

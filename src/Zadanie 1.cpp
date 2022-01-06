#include <iostream>
#include <string>
#include <vector>

auto main() -> int
{
    int x = 2;
    bool t;
    std::string str;

    while (x <= 20)
    {
        t = true;
        for (int i = 2; i < x; i++)
            if (x % i == 0)
            {
                t = false;
                break;
            }

        if (t)
        {
            str += std::to_string(x) + " ";
        }
        x++;
    }

    std::cout << str << std::endl;
    std::cout << str << std::endl;

    return 0;
}

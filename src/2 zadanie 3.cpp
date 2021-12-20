#include <iostream>
#include <vector>

auto dot_product(std::vector<int> a, std::vector<int> b) -> int
{
    int wynik;
    for (int i=0;i<a.size();i++)
    {
        wynik += a[i] * b[i];
    }
    return wynik;
}


auto main() -> int
{
    std::vector<int> vec = {1,2,3,4,5};
    std::vector<int> vec2 = {5,4,3,2,1};

    std::cout << dot_product(vec, vec2);

    return 0;
}

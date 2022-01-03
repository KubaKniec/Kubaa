#include <iostream>
#include <vector>


auto contains_all(std::vector<int> vec_1, std::vector<int> vec_2) -> bool
{
    int wynik;
    for (int i=0;i<vec_1.size();i++)
    {
        for(int j=0;j<vec_2.size();j++)
        {
            if(vec_1[i] == vec_2[j])
            {
                wynik++;
            }
        }
    }
    if (wynik == vec_2.size())
        return true;
    else
        return false;
}

auto main() -> int
{
    std::vector<int> vec_1 = {1,2,3};
    std::vector<int> vec_2 = {2,3};

    if(contains_all(vec_1,vec_2) == true)
        std::cout << "Drugi wektor JEST podzbiorem wektora pierwszego\n\n";
    else
        std::cout << "Drugi wektor NIE JEST podzbiorem wektora pierwszego\n\n";


    std::vector<int> vec_3 = {1,2,3};
    std::vector<int> vec_4 = {4,5};

    if(contains_all(vec_3,vec_4) == true)
        std::cout << "Drugi wektor JEST podzbiorem wektora pierwszego\n\n";
    else
        std::cout << "Drugi wektor NIE JEST podzbiorem wektora pierwszego\n\n";

    return 0;
}

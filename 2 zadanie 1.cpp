#include <iostream>
#include <vector>

auto average_of(std::vector<int> vec) -> double
{
    double suma, wynik;
    for(int i=0;i<vec.size();i++)
    {
        suma += vec[i];
    }
    wynik = suma / vec.size();
    return wynik;
}


auto main()-> int
{
    std::vector<int> liczby = {1,2,3,4,5,6,7,8,9};
    std::cout << average_of(liczby);




    return 0;
}

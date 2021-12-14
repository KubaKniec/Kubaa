#include <iostream>
#include <string>
auto print(std::string, int) -> void;

auto main() -> int
{
    std::string slowo;
    int liczba;

    std::cout << "Podaj slowo: ";
    std::cin >> slowo;
    std::cout << "Co ktora literka ma sie wyswietlac: ";
    std::cin >> liczba;

    print(slowo, liczba);

    return 0;
}


auto print(std::string wyraz, int liczba) -> void
{
    for(int i=0; i<=wyraz.size() ; i++)
    {
        if(i%liczba==0)
        {
            if(i==0)
                continue;
            std::cout << wyraz[i-1] << " ";
        }
    }
}

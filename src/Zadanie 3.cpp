#include <iostream>
#include <string>


auto main() -> int
{
    std::string imie_1, imie_2;
    std::cout << "Witaj, podaj pierwsze imie\n >> ";
    std::cin >> imie_1;
    std::cout << "Teraz podaj kolejne imie\n >> ";
    std::cin >> imie_2;



    if(imie_1.size() == imie_2.size())
    {
        std::cout << "Imiona sa takiej samej dlugosci.";
    }
    else if(imie_1.size() > imie_2.size())
    {
        std::cout << "Imie pierwsze jest dluzsze...";
    }
    else
    {
        std::cout << "Imie drugie jest dluzsze!";
    }

    return 0;
}

#include <iostream>
#include <string>

auto count_chars(std::string, char) -> int;


auto main() -> int
{
    std::string slowo;
    char litera;
    std::cout << "Podaj slowo: ";
    std::cin >> slowo;
    std::cout << "Podaj litere: ";
    std::cin >> litera;
    std::cout << "Litera '" << litera << "' pojawila sie " << count_chars(slowo,litera) << " razy w slowie " << slowo;

    return 0;
}


auto count_chars(std::string wyraz, char znak) -> int
{
    int ilosc= 0;
    for(int i=0; i<wyraz.size() ; i++)
    {
        if(wyraz[i]==znak)
            ilosc++;
    }
    return ilosc;
}

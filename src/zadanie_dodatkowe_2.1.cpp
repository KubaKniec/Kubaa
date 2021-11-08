#include <iostream>
#include <string>
auto zapytaj ( std :: string const prompt ) -> int
{
if ( not prompt . empty ()) {
std :: cout << prompt ;
}
auto value = std :: string {};
std :: getline ( std :: cin , value );
return std :: stoi ( value );
}

auto main() -> int
{
        int i = 0,z = 0 ;
        bool pierwsza = true;
        auto const liczba=zapytaj("liczba: ");


        if (liczba == 0 || liczba == 1)
        {
                std::cout << "0 i 1 to nie liczby pierwsze" << "\n";
        }

        else
        {
                for(i=2; i<=liczba / 2; i++)
                {
                        z++;
                        if (liczba % i == 0)
                        {
                                pierwsza = false;
                                break;
                        }
                }
        }
        if (pierwsza)
                std::cout << liczba << " jest pierwsza" << "\n";
        else
                std::cout << liczba << " nie jest pierwsza" << "\n";
        std::cout << "Petla wykonala sie " << z << " razy";





return 0;


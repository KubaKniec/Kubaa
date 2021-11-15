#include <iostream>
#include <string>
#include <string.h>
auto zapytaj ( std :: string const prompt ) -> int
{
if ( not prompt . empty ()) {
std :: cout << prompt ;
}
auto value = std :: string {};
std :: getline ( std :: cin , value );
return std :: stoi ( value );
}


struct samochod {
                char marka;
                char model;
                int rok;
                int przebieg;
                float cena_wyjsciowa;
                float cena_koncowa;
        }





auto main() -> int
{
	samochod pierwszy;
	samochod.marka = "Ford";
	samochod.model = "Focus";
	samochod.rok = "2010";
	samochod.przebieg = "150000";



return 0;
}


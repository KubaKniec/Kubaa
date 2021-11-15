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

int szerokosc;



auto main() -> int
{

	auto const wysokosc=zapytaj("Podaj wysokosc: ");


	for(szerokosc = 0; szerokosc < wysokosc*2-3; szerokosc ++){                         // pierwsza linijka
	std::cout << "*" ;
	}

	std::cout << "\n";






	for (int i=0; i < wysokosc - 2 ; i++){                                               // środek

		for(int z=0; z<wysokosc - 2 - i;z++){
			std::cout << "*";
		}
		for(int k=0; k<i*2+1 ;k++){
			std::cout << " ";
		}
		for(int z=0; z<wysokosc - 2 -i;z++){
                        std::cout << "*";
                }
		std::cout << "\n";

	}




	for(szerokosc = 0; szerokosc < wysokosc*2-3; szerokosc ++){                        //ostatnia linijka
        std::cout << "*" ;
        }



return 0;
}

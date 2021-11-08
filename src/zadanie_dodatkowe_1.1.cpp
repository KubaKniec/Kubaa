#include <iostream>
# include <string>
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
	int dzien;
	auto const a=zapytaj("Podaj numer od 1 do 7: ");
	dzien = a;
	switch(dzien){
	case 1:
		std::cout << "Poniedzialek" << std::endl;
		break;
	case 2:
                std::cout << "Wtorek" << std::endl;
		break;
	case 3:
                std::cout << "Sroda" << std::endl;
		break;
	case 4:
                std::cout << "Czwartek" << std::endl;
		break;
	case 5:
                std::cout << "Piatek" << std::endl;
		break;
	case 6:
                std::cout << "Sobota" << std::endl;
		break;
	case 7:
                std::cout << "Niedziela" << std::endl;
		break;

	default:
		std::cout << "Twoja liczba nie miesci sie w zakresie 1-7 :)"<<std::endl;
	}






return 0;
}

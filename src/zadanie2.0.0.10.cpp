# include <iostream>
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

int wynik=1, i=0;


auto main () -> int
{
        auto const a=zapytaj ("Podaj a : ");


	do
	{
		i++;
		wynik = wynik*i;
	}while(a>i);

	std::cout << "silnia z liczby "<<a<<" wynosi: "<<wynik<<"\n";




return 0;
}

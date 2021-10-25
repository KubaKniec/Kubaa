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

int suma;


auto main() -> int
{
        auto const a = zapytaj ("Podaj limit: ");
        auto const b = zapytaj ("Podaj dzielnik: ");

	for (int i=0; i<=a ;i++)
	{
		if(i%b == 0)
		{
			suma += i;
		}
	}

	std::cout << "Suma liczb wynosi: "<< suma << "\n";



return 0;
}

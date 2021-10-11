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

auto main () -> int
{
	auto const a = zapytaj("Podaj a: ") ;
	if (a>0)
	{
	std :: cout << 1 << "\n";
	}
	else if (a<0)
	{
	std :: cout << -1 << "\n";
	}
	else 
	{
	std :: cout << 0 << "\n";
	}
return 0;
}

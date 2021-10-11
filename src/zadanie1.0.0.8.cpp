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
	auto const a=zapytaj ("Podaj a : ");
	auto const b=zapytaj ("Podaj b : ");
	auto const c=zapytaj ("Podaj c : ");

	if ((a>=b)&&(a>=c))
	{
	std :: cout << a << "\n";
	}
	else if ((b>=a)&&(b>=c))
	{
	std :: cout << b << "\n";
	}
	else
	{
	std :: cout << c << "\n";
	}
return 0;
}

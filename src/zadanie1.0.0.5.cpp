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

auto main() -> int
{	
	auto const a=zapytaj ("podaj liczbe : ");
	if (a<0)
	{
	std :: cout << -a <<"\n" ;
	}
	else
	{
	std :: cout << a << "\n";
 	} 
return 0 ;
}

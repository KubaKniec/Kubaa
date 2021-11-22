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

auto init(int a[], int n) -> void
{
	for(auto i=0; i<=n ;i++){
		a[i] = 0;
	}
}

auto main() -> int
{

	auto const n=zapytaj ("Podaj rozmiar tablicy: ");

	int a[99999];
	int x = 0;


	init(a,n);
	while (x < n){
		std::cout << a[x];
		x++;
	}

return 0;
}


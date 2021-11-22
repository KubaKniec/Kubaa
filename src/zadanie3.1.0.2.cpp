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


auto iota(int a[], int n, int start) -> void
{
        for(auto i=0; i<=n ;i++){
		a[i] = start++;
        }
}

auto main() -> int
{

        auto const n=zapytaj ("Podaj rozmiar tablicy: ");
	auto const start=zapytaj ("Podaj liczbe startowa: ");
	int a[9999];
        int x = 0;


        iota(a,n,start);
        while (x < n){
                std::cout << a[x];
                x++;
        }

return 0;
}


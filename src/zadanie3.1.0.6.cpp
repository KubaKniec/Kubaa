#include <iostream>
#include <string>

auto zapytaj (std::string const prompt) -> int
{
if (not prompt.empty()) {
std::cout << prompt ;
}
auto value = std::string {};
std::getline (std::cin , value);
return std::stoi (value);
}

auto search(int a[], int n, int needle) -> int
{
    for(int i=0;i<n;i++){
        if(needle == a[i]){
            std::cout << "Twoja liczba ma indeks: " << i;
            return 1;
        }
        else if(i==n-1){
             std::cout << "W tablicy nie ma takiej liczby :(";
             return -1;
        }
    }
}




int liczba = 0;


auto main() -> int
{
	int tab[10] { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };

    auto const liczba = zapytaj("Podaj szukana liczbe: ");

    search(tab,10,liczba);


return 0;
}


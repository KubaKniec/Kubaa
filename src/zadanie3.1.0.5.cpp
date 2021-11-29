#include <iostream>
#include <string>
#include <algorithm>


auto zapytaj (std::string const prompt) -> int
{
if (not prompt.empty()) {
std::cout << prompt ;
}
auto value = std::string {};
std::getline (std::cin , value);
return std::stoi (value);
}

auto amax(int a[], int n) -> int
{
    n = 10;
    int najwieksza;
    for(int i = 1;i < n; ++i){
       if(a[0] < a[i])
           a[0] = a[i];
    }


    najwieksza = a[0];
    std::cout << "Najwieksza liczba to \n>> " << najwieksza ;

    return najwieksza;
}


auto main() -> int
{

	int tab[10] { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };
    amax(tab,1);
return 0;
}

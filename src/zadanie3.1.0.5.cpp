#include <iostream>

auto amax(int a[], int n) -> int
{
    
    int najwieksza = a[0];
    for(int i = 1;i < n; ++i){
       if(najwieksza < a[i])
           najwieksza = a[i];
    }


    std::cout << "Najwieksza liczba to \n>> " << najwieksza ;

    return najwieksza;
}


auto main() -> int
{

	int tab[10] { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };
    amax(tab,10);
return 0;
}

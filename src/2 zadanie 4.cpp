#include <iostream>
#include <vector>
#include <string>


struct student
{
    std::string imie;
    std::string nazwisko;
    std::vector<int> oceny;
    double average_of();
};

auto student::average_of() -> double
{
    double suma;
    double wynik;

    for(int i=0; i < oceny.size(); i++)
    {
        suma += oceny[i];
    }
    wynik = suma / oceny.size();
    return wynik;
}
auto main() -> int
{
    std::vector <int> oceny = {4,5,2,3};
    student Kuba {"Kuba", "Kniec", oceny};

    std::cout << Kuba.average_of();
    return 0;
}

//stara wersja gry, usunac potem, na razie zostawiam, moze sie przyda


#include <iostream>
#include <string>
#include "windows.h"


using namespace std;

int MenuGlowne();
void Pauza(int);
void wprowadzenie();
string decyzja(string, string);

// tutaj dodac klase glownego bohatera





string imie;


// GŁÓWNA GRA //
auto main() -> int
{
    MenuGlowne();

    wprowadzenie();
    system("cls");

    cout << imie << " idac ciasnym tunelem napotyka Goblina. Co powinien zrobic ?\n";
    cout << "atak/ucieczka\n>> ";
    decyzja("atak","ucieczka");
    if(decyzja == "atak")
    {
        cout << "walka"          //tutaj skonczylem $$$$$$$$        // zrobic system walki
    }

    else if (decyzja == "ucieczka")
    {
        // tutaj dopisac
    }





    return 0;
}



// Funkcje //
int MenuGlowne()
{
    cout <<"wersja 1.0\n--------------------------\n|  Witaj w 'nazwa gry'   |\n|          graj          |\n|          exit          |\n--------------------------\n>> ";
    string wybor;
    cin >> wybor;
    cout << wybor << endl;
    if(wybor == "graj")
        system("cls");
    else if(wybor == "exit")
        return -1;
    else
    {

        while(wybor != "graj" || "exit")
        {
            wybor = "";
            cin.clear();
            cout << "Blad, wpisz ponownie\n>> ";
            cin >> wybor;
            cin.ignore(1024, '\n');
            if(wybor == "graj")
            {
                system("cls");
                break;
            }
            else if(wybor == "exit")
                return -1;
        }
    }
}

void Pauza(int sekundy)
{
    int milisekundy = sekundy * 1000;
    Sleep(milisekundy);
}

void wprowadzenie()
{
    cout << "Podaj imie swojej postaci\n>> ";
    cin >> imie;
    system("cls");
    int x = 0;                                          // USTAWIC FINALNIE x = 3

    cout << "    Rozdzial 1\n\n\n";
    Pauza(2);
    cout << imie <<" budzi sie na zimnej, kamiennej pryczy.\n\n";
    Pauza(x);
    cout << "Do okola jest ciemno i nic nie widac.\n\n";
    Pauza(x);
    cout << "Po chwili oczy przyzwyczajaja sie do ciemnosci i "<< imie << " zauwaza, ze jest w  jakiejs celi\n\n";
    Pauza(x);
    cout << "Dostrzega, ze kraty sa uszkodzone i da sie przez nie wyjsc.\n\n";
    Pauza(x);
    cout << imie << " postanawia uciec i tu zaczyna sie przygoda.\n\n";
    Pauza(x);
    cout << "Czy ucieczka sie powiedzie? To zalezy tylko od ciebie. Daj z siebie 101%\n\n";
    system("pause");
    system("cls");
}

string decyzja(string x,string y)
{
    string wybor = "";
    cin >> wybor;
    if(wybor == x)
        return x;
    else if(wybor == y)
        return y;
    else
    {
        while(wybor != x || y)
        {
            wybor = "";
            cin.clear();
            cout << "Blad, wpisz ponownie\n>> ";
            cin >> wybor;
            cin.ignore(1024, '\n');
            if(wybor == x)
            {
                return x;
                break;
            }
            else if(wybor == y)
            {
                return y;
                break;
            }
        }
    }
}



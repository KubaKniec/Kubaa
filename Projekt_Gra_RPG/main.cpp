#include <iostream>
#include <string>
#include "windows.h"
#include <MMSystem.h>


/*                                                                 TO DO List
- funkcja menu glowne (DONE)
- funkcja pauza (DONE)
- funkcja do podejowania decyzji z obsulga bledow przy wpisywaniu (DONE)
- funkcja wyswietlenia statystyk (DONE)
- Funkcja walki (DONE)
- Funkcja LVL Up. Odnawia zycie i mozesz dodac iles tam punktow do obrony lub ataku (DONE)
- Kilka dodatkowych przeciwnikow (DONE)
- Ustawic dobre wartowsci zmiennych w funkcji Walka() bo starcia sa za dlugie !!!!!!
- Ustawiæ statystyki przeciwnikow tak aby dalo sie wygrac i przegrac (nie moze byc za latwo :))
- Pomiedzy walkami jakis event w stylu znalazles skrzynke czy chcesz ja otworzyc? A w srodku jakis super przedmiot czy cos tam nw jeszcze
        Moze cos w stylu funkcji bonus event czy cos ale najpierw zrobic rzeczy wazne !

                                                               Secondary TO DO List
- Sprawdzic literowki itd
- Poprawic ogolny wyglad
- Dodac dzwiek walki (DONE)
*/


// zmienne globalne

std::string imie = "";
int czas = 1.5;  //czas pauzy w sekundach  |   USTAWIC FINALNIE czas = 3 !!!!!



auto MenuGlowne() -> int
{
    std::cout <<"wersja 1.5\n----------------------------\n|  Witaj w Dungeon Escape  |\n|          graj            |\n|          exit            |\n----------------------------\n>> ";
    std::string wybor;
    std::cin >> wybor;

    if(wybor == "graj")
    {
        system("cls");
        return 1;
    }
    else if(wybor == "exit")
        return -1;
    else
    {

        while(wybor != "graj" || "exit")
        {
            wybor = "";
            std::cin.clear();
            std::cout << "Blad, wpisz ponownie\n>> ";
            std::cin >> wybor;
            std::cin.ignore(1024, '\n');
            if(wybor == "graj")
            {
                system("cls");
                return 1;
                break;
            }
            else if(wybor == "exit")
                return -1;
        }
    }
}

auto Pauza(int sekundy) -> void
{
    int milisekundy = sekundy * 1000;
    Sleep(milisekundy);
}

auto Decyzja(std::string x, std::string y) -> std::string
{
    std::string wybor = "";
    std::cin >> wybor;
    if(wybor == x)
        return x;
    else if(wybor == y)
        return y;
    else
    {
        while((wybor != x) || (wybor != y))
        {
            wybor = "";
            std::cin.clear();
            std::cout << "Blad, wpisz ponownie\n>> ";
            std::cin >> wybor;
            std::cin.ignore(1024, '\n');
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




// struktura Bohatera gry oraz wszystkich przeciwnikow (maja takie same parametry) //
struct postac
{
    std::string name;
    int health;
    int attack;
    int defense;

};



auto PrintStats(postac struktura, postac strukturaPrzeciwnik) -> void
{
    std::cout << "|  "<<struktura.name<< "           |           "<<strukturaPrzeciwnik.name << std::endl;
    std::cout << "|  Zdrowie: " << struktura.health << "        |     Zdrowie: " << strukturaPrzeciwnik.health << std::endl;
    std::cout << "|  Atak: " << struktura.attack<< "             |     Atak: " << strukturaPrzeciwnik.attack << std::endl;
    std::cout << "|  Obrona: " << struktura.defense << "           |     Obrona: " << strukturaPrzeciwnik.defense << std::endl;
}


auto Walka(postac & gracz, postac & przeciwnik)-> int
{

    std::cout << "\n   ROZPOCZYNA SIE WALKA\n";
    system("pause");
    int damage_gracz = gracz.attack - przeciwnik.defense/3;                                   //obrazenia dzialaja na zasadzie wzoru | obrazenia = atak - obrona.przeciwnika/3
    int damage_przeciwnik = przeciwnik.attack - gracz.defense/3;
    int tura = 0;
    //std::cout <<"\n\n" << damage_gracz <<std::endl<< damage_przeciwnik;
    do
    {

        tura ++;
        system("cls");
        std::cout << "  Tura " << tura << std::endl;
        PrintStats(gracz, przeciwnik);
        std::cout << std::endl << imie << " wyprowadza cios!\n\n";
        przeciwnik.health -= damage_gracz;
        PlaySound(TEXT("Sound.wav"), NULL,SND_SYNC);
        system("pause");
        system("cls");

        std::cout << "  Tura " << tura << std::endl;
        PrintStats(gracz, przeciwnik);
        std::cout << std::endl << "Przeciwnik wyprowadza cios!\n\n";
        gracz.health -= damage_przeciwnik;
        PlaySound(TEXT("Sound.wav"), NULL,SND_SYNC);
        system("pause");

        if(gracz.health <=0)
        {
            std::cout << imie << " zostaje pokonany !!!\n";
            Pauza(czas);
            std::cout << "               GAME OVER\n\n";
            system("pause");
            return -1;
        }
    }
    while(przeciwnik.health > 0);
    std::cout << "\nWrog zostal pokonany\n\n\n";
    return 0;
}


auto LvlUp (postac & struktura) -> void
{
    std::cout << std::endl << std::endl << std::endl;
    system("pause");
    system("cls");
    struktura.health += 50;
    std::cout << "                 LVL UP \nTwoje zdrowie zostalo lekko zregenerowane.\nWpisz 'atak' lub 'obrona', aby upelszyc statystyki\n>> ";
    std::string decyzja = Decyzja("atak","obrona");
    if(decyzja == "atak")
    {
        struktura.attack += 5;
        system("cls");
        std::cout << "\n\n      (Dodano +5 atak oraz +50hp)";
        Pauza(czas+3);
    }

    else
    {
        struktura.defense += 5;
        system("cls");
        std::cout << "\n\n      (Dodano +5 obrona oraz +50hp)";
        Pauza(czas+3);
    }

    system("cls");


}
auto main() -> int
{

    int zakonczyc = MenuGlowne();

    {
        if(zakonczyc == -1)
            return 0;
    }

    // Personalizacja postaci glownego bohatera gry //

    std::cout << "Podaj imie swojej postaci (jeden wyraz)\n>> ";
    std::cin >>  imie;
    for(int i=0;i<imie.size();i++)
    {
        if(imie[i]==' ')
        {
            imie = "";
            std::cout << "Wprowadz imie (JEDEN WYRAZ)";
            std::cin >> imie;
        }
    }
    std::cout << "Pora ustawic statystyki twojej postaci\n\n";
    system("pause");
    system("cls");
    int atak = 0, obrona = 0, punkty = 10;
    Pauza(czas);
    std::cout << "Masz do dyspozycji 10 punktow umiejetnosci, rozdziel je madrze\n";
    Pauza(czas);
    std::cout << "Masz dostepne 2 glowne statystyki atak oraz obrone\nIle chcesz dac w atak: ";
    std::cin >> atak;
    std::cout << "Ile chcesz dac w obrone: ";
    std::cin >> obrona;
    if(atak+obrona != 10)
    {
        do
        {
            atak = 0;
            obrona = 0;
            std::cout << "\nUzyto zlej ilosci punktow, sprobuj ponownie\nIle chcesz dac w atak: ";
            std::cin >> atak;
            std::cout << "Ile chcesz dac w obrone: ";
            std::cin >> obrona;
        }
        while(atak+obrona != 10);
    }




    /// postac gracza ///
    auto gracz = postac();
    gracz.name = imie;
    gracz.health = 100;
    gracz.attack = atak;
    gracz.defense = obrona;

    // przeciwnik 1 Goblin //
    auto goblin = postac();
    goblin.name = "Goblin";
    goblin.health = 50;
    goblin.attack = 3;
    goblin.defense = 2;

    // przeciwnik 2 Bandyta //
    auto bandyta = postac();
    bandyta.name = "Bandyta";
    bandyta.health = 60;
    bandyta.attack = 5;
    bandyta.defense = 4;

    // przeciwnik bonusowy ELF //
    auto elf = postac();
    elf.name = "Elf";
    elf.health = 30;
    elf.attack = 4;
    elf.defense = 2;

    // przeciwnik 3 Nieumarly //
    auto nieumarly = postac();
    nieumarly.name = "Nieumarly";
    nieumarly.health = 75;
    nieumarly.attack = 6;
    nieumarly.defense = 10;

    // przeciwnik 4 Pajak Gigant //
    auto pajak = postac();
    pajak.name = "Pajak Gigant";
    pajak.health = 80;
    pajak.attack = 10;
    pajak.defense = 6;

    // przeciwnik 5 BOSS (Gorski Golem)//
    auto golem = postac();
    golem.name ="Gorski Golem";
    golem.health = 0;
    golem.attack = 0;
    golem.defense = 0;


    system("cls");


                    // Prolog
    std::cout << "    Rozdzial 1\n\n\n";
    Pauza(czas);
    std::cout << imie <<" budzi sie na zimnej, kamiennej podlodze.\n\n";
    Pauza(czas);
    std::cout << "Do okola jest ciemno i nic nie widac.\n\n";
    Pauza(czas);
    std::cout << "Po chwili oczy przyzwyczajaja sie i "<< imie << " zauwaza, ze jest w  jakiejs celi\n\n";
    Pauza(czas);
    std::cout << "Dostrzega, ze kraty sa uszkodzone i da sie przez nie wyjsc.\n\n";
    Pauza(czas);
    std::cout << imie << " bierze ze soba kawalek metalowej kraty i postanawia uciec, tu zaczyna sie przygoda.\n\n";
    Pauza(czas);
    std::cout << "Czy ucieczka sie powiedzie? To zalezy tylko od ciebie. Daj z siebie 101%\n\n";
    system("pause");
    system("cls");

                        // Glowna gra
    std::cout << "Po chwili marszu " << imie << " dostrzega w cieniu jakas postac.\n\n";
    Pauza(czas);
    std::cout << "Z morku wylania sie Goblin. Niebezpieczna i smierdzaca postac zamieszkujaca te lochy\n\n";
    Pauza(czas);
    std::cout << "Czy " << imie << " pokona Goblina?  Przekonajmy sie!\n\n";
    system("pause");
    system("cls");

    if((Walka(gracz, goblin)) == -1)
        return 0;

    system("cls");
    std::cout << "Goblin zostal pokonany bez najmniejszego problemu.\n\n";
    Pauza(czas);
    std::cout << imie << " idzie dalej przez ciemne korytarze.\n\n";
    Pauza(czas);
    std::cout << "Nagle zauwaza w oddali jakies swiatlo. Postanawiam isc w jego strone.\n\n";
    Pauza(czas);
    std::cout << "To oboz bandytow ! Po lewej widac jednego z nich, ktory pilnuje mostu. Po prawej przepasc, ktora da sie przeskoczyc\n\n";
    Pauza(czas);
    std::cout << "Czy " << imie << " ma isc w lewo czy prawo?    Wpisz(lewo/prawo)\n>> ";
    if((Decyzja("lewo", "prawo")) == "prawo")
    {           //pojscie w prawo -10hp i walka
        system("cls");
        std::cout << imie << " idzie w prawo. Przepasc jest wieksza niz sie wydawala.\n\n";
        Pauza(czas);
        std::cout << "SKOK !\n\n";
        Pauza(czas);
        std::cout << imie << " przewraca sie i odnosi obrazenia -10hp\n\n";
        gracz.health -= 10;
        std::cout << "Bandyta slyszy uderzenie o ziemie i biegnie w jego strone\n\n";
        Pauza(czas);
        std::cout << "Czy " << imie << " pokona Bandyte?  Przekonajmy sie!\n\n";
        system("pause");
        system("cls");
        if((Walka(gracz, bandyta)) == -1)
            return 0;
    }
    else
    {           // pojscie w lewo walka
        system("cls");
        std::cout << imie << " idzie w lewo. Bandyta zorientowal sie ze ktos biegnie w jego strone i wyciaga bron.\n\n";
        Pauza(czas);
        std::cout << "Czy " << imie << " pokona Bandyte?  Przekonajmy sie!\n\n";
        system("pause");
        system("cls");
        if((Walka(gracz, bandyta)) == -1)
            return 0;
    }
    LvlUp(gracz);

    std::cout << imie << " pokonuje bandyte i przemyka obok obozu.\n\n";
    Pauza(czas);
    std::cout << "Po chwili znajduje schody prowadzace na gore.\n\n";
    Pauza(czas);
    std::cout << "Czy to wyjscie ? " << imie << " wchodzi po schodach na gore.\n\n";
    Pauza(czas);
    system("pause");
    system("cls");



    std::cout << "    Rozdzial 2\n\n\n";
    Pauza(czas);
    std::cout << "To pietro wyglada zupelnie inaczej niz poprzednie. Jest to wielka polana.\n\n";
    Pauza(czas);
    std::cout << "Do okola nie ma nic, oprocz wielkiego drzewa na wzniesieniu.\n\n";
    Pauza(czas);
    std::cout << "Czy " << imie << " ma isc w strone drzewa?    Wpisz(tak/nie)\n>> ";
    if (Decyzja("tak","nie") == "tak")
    {
        system("cls");          // 'tak' powoduje podejscie do drzewa i walke bonusowa
        std::cout<< "\n\n" << imie << " podchodzi do drzewa i zauwaza, ze w dziupli cos jest\n\n";
        Pauza(czas);
        std::cout << "Okazalo sie, ze to pradawny zwoj. " << imie << " odwija go i czyta.\n\n";
        Pauza(czas);
        std::cout << "Przeklety zwoj. Daje +2 do ataku, ale rowniez -10 hp\n\n";
        Pauza(czas);
        std::cout << "Czy " << imie << " ma uzyc zwoju ?    Wpisz(tak/nie)\n>> ";
        if (Decyzja("tak","nie") == "tak")
        {
            system("cls");                // 'tak' powoduje uzycie zwoju
            gracz.health -= 10;
            gracz.attack += 2;
            std::cout << "\n\n      (Dodano +2 atak oraz -10hp)";
            Pauza(czas+3);
        }
        system("cls");
        std::cout << "Nagle " << imie << " slysz cos nad glowa.\n\n";
        Pauza(czas);
        std::cout <<"Patrzy w gore i dostrzega elfa, ktory pilnowal zwoju\n\n";
        system("pause");
        system("cls");
        if((Walka(gracz, elf)) == -1)
            return 0;
        system("cls");


        std::cout << imie << " pokonuje Elfa.\n\n";
        Pauza(czas);
        std::cout << "Nagle slyszy w oddali jakis dzwiek i postanawia isc w jego strone\n\n";
        Pauza(czas);
        std::cout << "Po dlugim spacerze przez polane, za wzniesieniem pojawia sie przeogromny cmentarz.\n\n";
        Pauza(czas);
        std::cout << imie <<" uswiadamia sobie, ze to pietro lochow to nie zwykla polana, tylko gigantyczny cmentarz.\n\n";
        Pauza(czas);
        std::cout << "W oddali widac rowniez schody na kolejne pietro.\n\n";
        Pauza(czas);
        std::cout << "Po chwili " << imie << " slyszy znowu jakis dzwiek, odwraca sie, a za plecami stoi Nieumarly, ktory rzuca do walki.\n\n";
        system("pause");
        system("cls");
        if((Walka(gracz, nieumarly)) == -1)
            return 0;
        LvlUp(gracz);
    }
    else                    // 'nie' powoduje ominiecie walki bonusowej i kontynuowanie rozgrywki
    {
        system("cls");
        std::cout << imie << " slyszy w oddali jakis dzwiek i idzie w jego strone\n\n";
        Pauza(czas);
        std::cout << "Po dlugim spacerze przez polane, za wzniesieniem pojawia sie przeogromny cmentarz.\n\n";
        Pauza(czas);
        std::cout << imie <<" uswiadamia sobie, ze to pietro lochow to nie zwykla polana, tylko gigantyczny cmentarz.\n\n";
        Pauza(czas);
        std::cout << "W oddali widac rowniez schody na kolejne pietro./n/n";
        Pauza(czas);
        std::cout << "Po chwili " << imie << " slyszy znowu jakis dzwiek, odwraca sie, a za plecami stoi Nieumarly (zombie), ktory rzuca do walki.\n\n";
        system("pause");
        system("cls");
        if((Walka(gracz, nieumarly)) == -1)
            return 0;
        LvlUp(gracz);
    }


    std::cout << "Po pokonaniu Nieumarlego, " << imie << " idzie dalej w strone schodow prowadzacych na kolejne pietro lochow.\n\n";
    Pauza(czas);
    std::cout << "Po drodze bylo wszedzie pelno pajeczyny.\n\n";
    Pauza(czas);
    std::cout << "Z kazdym krokiem bylo jej co raz wiecej.\n\n";
    Pauza(czas);
    std::cout << imie << " podchodzi do schodow i czuje ze pod nogami jest jakos dziwnie miekko.\n\n";
    Pauza(czas);
    std::cout << "NAGLE ziemie zapada sie i " << imie << " wpada do gniazda Pajaka Giganta.\n\n";
    system("pause");
    system("cls");

    if((Walka(gracz, pajak)) == -1)
            return 0;
    system("pause");
    system("cls");
    std::cout << "Po dlugiej i wyczerpujacej walce " << imie << " wychodzi z gnizda Pajaka Giganta i idzie po schodach na kolejne pietro.\n\n";
    system("pause");



    system("cls");
    std::cout << "    Rozdzial 3 ~ Final\n\n\n";
    std::cout << "[Tutaj bedzie walka z bosem. I moze jeszcze cos ciekawego na koniec jeszcze zobacze :)]";


    return 0;
}

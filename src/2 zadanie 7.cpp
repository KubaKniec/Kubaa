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

struct group
{
    std::string nazwa;
    std::vector<student> studenci;
};

auto Add_To_Group(group & grupa, student & stud) -> void
{
    grupa.studenci.push_back(stud);
}




auto main() -> int
{
    auto student_1 = student();
    student_1.imie = "Jan";
    student_1.nazwisko = "Kowalski";
    student_1.oceny = {1,4,3,2};

    auto student_2 = student();
    student_2.imie = "Adam";
    student_2.nazwisko = "Adamowski";
    student_2.oceny = {3,2,5,2};

    auto student_3 = student();
    student_3.imie = "Kasia";
    student_3.nazwisko = "Kasiowa";
    student_3.oceny = {5,2,2,1};

    auto student_4 = student();
    student_4.imie = "Robert";
    student_4.nazwisko = "Robertowski";
    student_4.oceny = {1,2,3,4};

    auto group_1 = group();
    group_1.nazwa = "Real_G's";
    group_1.studenci = {student_1, student_2};

    auto group_2 = group();
    group_2.nazwa = "Zwykla_grupa";
    group_2.studenci = {student_3, student_4};


    auto student_nowy_1 = student();
    student_nowy_1.imie = "Kuba";
    student_nowy_1.nazwisko = "Kuba";
    student_nowy_1.oceny = {3,4,4,5};

    auto student_nowy_2 = student();
    student_nowy_2.imie = "Roman";
    student_nowy_2.nazwisko = "Romankiewicz";
    student_nowy_2.oceny = {2,2,3,1};

    Add_To_Group(group_1, student_nowy_1);
    Add_To_Group(group_2, student_nowy_2);

    std::cout << "Grupa 1: ";
    for(int i=0;i<group_1.studenci.size();i++)
        std::cout  << group_1.studenci[i].imie << " ";
    std::cout << std::endl<< "Grupa 2: ";;

    for(int i=0;i<group_2.studenci.size();i++)
        std::cout << group_2.studenci[i].imie << " ";


    return 0;
}

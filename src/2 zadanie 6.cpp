#include <iostream>
#include <string>
#include <vector>



struct student
{
    std::string imie;
    std::string nazwisko;
    std::vector<int> oceny;
    double average_of();
};


auto average_of(student A) -> float
{
    int x = 0;
    for(size_t i = 0; i < A.oceny.size(); i++)
    {
        x = x + A.oceny[i];
    }
    return float(x)/float(A.oceny.size());
}

auto get_best_student(std::vector<student> vec) -> student
{
    double temp = 0;
    auto najlepszy = vec[0];
    for(int i=0; i < vec.size() ; i++)
    {
        if(average_of(vec[i])>temp)
        {
            temp = average_of(vec[i]);
            najlepszy = vec[i];
        }
    }
    return najlepszy;
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


    std::vector<student> studenci = {student_1, student_2, student_3};

    auto best = get_best_student(studenci);
    std::cout << best.imie << " " << best.nazwisko << " is the best, Average is: " << average_of(best);
    return 0;
}

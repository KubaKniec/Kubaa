#include <iostream>
#include <string>
auto zapytaj(std::string) -> int;
auto main() -> int
{
auto const y = zapytaj("y = ");
int i;
for (i= 1; y>=i; i++)
{
int j;
for (j= 1;j<=y; j++)
{
if (j==1 || j==y) 
std::cout << "*";
else if (i==1 || i==y)
std::cout << "*";
else
std::cout << " ";
}
std::cout << "\n";
}
    return 0;
}
auto zapytaj(std::string prompt) -> int
{
    std::cout << prompt << " int:";
    auto n = std::string{};
    std::getline(std::cin, n);
    return std::stoi(n);
}

#include <iostream>
#include <string>
#include <vector>

auto box_print(std::string a, std::string b, std::string c, std::string d, std::string e) -> void
{
    std::string tab[5] = { a, b, c, d, e };
    int max_size = 0;
    int current_size = 0;
    for(auto s : tab)
    {
        if (s.size() > max_size)
            max_size = s.size();
    }
    for(int j = 0; j < max_size + 4; j++)
    {
        std::cout<<"*";
    }
    std::cout << std::endl;
    for(auto i = 0; i < 5; i++)
    {
        std::cout<<"* "<<tab[i];
        current_size = tab[i].size();
        for(int l = 0; l < max_size - current_size; l++)
        {
            std::cout<<" ";
        }
        std::cout<<" *"<<std::endl;
    }
    for(int k = 0; k < max_size + 4; k++)
    {
        std::cout<<"*";
    }
    std::cout << std::endl;
}
auto main() -> int
{
    box_print("Hello", "World", "in", "a", "frame");
    return 0;
}

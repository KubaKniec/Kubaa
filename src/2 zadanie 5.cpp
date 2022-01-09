#include <iostream>
#include <vector>
#include <string>


auto split(std::string txt, std::vector<std::string> & vec) -> std::vector<std::string>
{

    std::string temp = "";
    for(int i=0;i<txt.size();i++)
    {
        if (txt[i] == ' ')
        {
            vec.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(txt[i]);

    }
    vec.push_back(temp);
    return vec;
}


auto main() -> int
{
    std::vector<std::string> splited;
    split("Ala ma kota", splited);

    for (int i=0;i<splited.size();i++)
    {
        std::cout << splited[i] << ", ";
    }

    return 0;
}

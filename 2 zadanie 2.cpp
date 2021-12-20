#include <iostream>
#include <vector>

auto is_palindrome(std::string palindrome) -> bool
{
    for (int i=1; i<=palindrome.size(); i++)
    {
        if(palindrome[i-1] != palindrome[palindrome.size() - i])
        {
            return false;
        }
    }
    return true;
}


auto filter_palindromes(std::vector<std::string> vec) -> std::vector<std::string>
{
    std::vector<std::string> wyjscie;

    for(int i=0; i<vec.size(); i++)
    {
        if(is_palindrome(vec[i]))
        {
            wyjscie.push_back(vec[i]);
        }
    }
    return wyjscie;
}



auto main()-> int
{
    std::vector<std::string> vec = {"anna", "kajak", "drzewo"}, przefiltrowane;

    przefiltrowane = filter_palindromes(vec);
    for (int i=0;i<przefiltrowane.size();i++)
    {
        std::cout << przefiltrowane[i]<<" ";
    }

    return 0;
}

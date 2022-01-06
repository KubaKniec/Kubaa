#include <iostream>
#include <string>

auto is_palindrome(std::string palindrome) -> bool
{
    int result = 1;
    for (int i=1;i<=palindrome.size(); i++){
        if(palindrome[i-1] != palindrome[palindrome.size() - i]){
            result=0;
            break;
        }
    }
    return result;
}

int main()
{

std::cout<<is_palindrome("kajak");
std::cout << std::endl;
std::cout<<is_palindrome("domek");
return 0;
}

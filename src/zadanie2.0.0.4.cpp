#include <iostream>
#include <string>
auto pytanie(std ::string const prompt) -> int
{
    if (not prompt.empty()) {
        std ::cout << prompt;
    }
    auto value = std ::string{};
    std ::getline(std ::cin, value);
    return std ::stoi(value);
}
auto main() -> int
{
    int i;
    bool pierwsza = true;
    auto const a  = pytanie("a= ;");
    if (a == 0 || a == 1) {
        std::cout << "To nie sa liczby pierwsze"
                  << "\n";
    }
	 else {
        for (i = 2; i <= a / 2; i++)
	{
            if (a % i == 0) {
                pierwsza = false;
        }    
	}
    }

if (pierwsza)
    std::cout << a << " Jest pierwsza"
              << "\n";
else
    std::cout << a << " Nie jest pierwsza"
              << "\n";
return 0;
}

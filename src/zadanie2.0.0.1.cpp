#include <iostream>
#include <string>
auto Najwieksza(std ::string const prompt) -> int
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
    auto const a = Najwieksza("a=");
    auto const b = Najwieksza("b=");
    for (i = a; i < b; ++i) {
        std::cout << "Liczby te to:" << i << "\n";
    }


    return 0;
}

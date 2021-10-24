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
    int s;
    auto const a = pytanie("a: ");
    auto const b = pytanie("b: ");
    s            = pytanie("s krok petli: ");

    if (s < 0) {
        s = s * -1;
    }

    else if (s == 0) {
        std::cout << "Odrzucam wartosc 0 dla s"
                  << "\n";
    }
    for (i = a; i < b; i = i + s) {
        std::cout << i << "\n";
    }
    return 0;
}

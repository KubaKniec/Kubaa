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
    auto const a = pytanie("a: ");
    auto const b = pytanie("b: ");
    auto const c = pytanie("c dzielnik;");
    for (i = a; i < b; ++i) {
        if (i % c == 0) {
            std::cout << i << "\n";
        }
    }
    return 0;
}

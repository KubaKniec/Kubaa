#include <algorithm>
#include <iostream>

auto sort_asc(int a[], int n) -> void
{
    std::sort(a, a+n);

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
}

auto main() -> int
{
int tab[] = { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };
sort_asc(tab,10);
return 0;
}

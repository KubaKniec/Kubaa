#include <iostream>

auto sort_asc(int a[], int n) -> void
{
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n-i; j++)
            if(a[j-1]>a[j])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
    }
    for(int i=0; i<n; i++)
        std::cout<<a[i]<<" ";
}

auto main() -> int
{
    int tab[] = { 42, 9, -1, 18, 59, 3, 101, 31, 72, 12 };
    sort_asc(tab,10);
    return 0;
}

#include <stdio.h>
#include <array>
#include <iostream>
#include <string>
auto zamiana(int* a, int* b) -> void
{
    int t = *a;
    *a = *b;
    *b = t;
}


auto srodkowa(int arr[], int low, int high) -> int
{
    int wiecej = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= wiecej)
        {
            i++;
            zamiana(&arr[i], &arr[j]);
        }
    }
    zamiana(&arr[i + 1], &arr[high]);
    return (i + 1);

}


void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = srodkowa(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}


void wypisz(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i]<<" ";
}


auto main() -> int
{
    int arr[] = {42, 9, -1, 18, 59, 3, 101, 31, 72, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    std::cout << "Posortowana tablica\n  >> ";
    wypisz(arr, n);
    return 0;
}

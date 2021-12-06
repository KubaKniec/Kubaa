#include<iostream>
#include<algorithm>


bool porownaj(int a, int b)
{
	return a>b;
}

auto main() -> int
{
	int tab[] =  { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };

	std::sort(tab, tab+10, porownaj);

	for(int i=0;i<10;i++)
        std::cout<<tab[i]<<' ';

	return 0;
}

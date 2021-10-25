# include <iostream>
# include <string>
auto zapytaj ( std :: string const prompt ) -> int
{
if ( not prompt . empty ()) {
std :: cout << prompt ;
}
auto value = std :: string {};
std :: getline ( std :: cin , value );
return std :: stoi ( value );
}


auto main () -> int
{

        auto const b=zapytaj("podaj wysokosc: ");


        for(int y=0;y<=b;y++)
        {

                for(int i=b;i>y;i--)
                {
                        std::cout<<"*";
                }



        std::cout<<"\n";
        }




return 0;
}



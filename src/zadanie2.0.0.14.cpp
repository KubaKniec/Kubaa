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

int puste;

auto main () -> int
{

        auto const b=zapytaj("podaj wysokosc: ");


        for(int y=0;y<b;y++)
        {

                for(int i=0;i<b;i++)
                {
			if(i==1)
			{
                        	std::cout<<"*";
			}
			else
			{
				puste=b-2;
				std::cout<<"*";

				for(int z=0;z<=puste;z++)
				{
					std::cout<<" ";
				}
				std::cout<<"*";
			}
                }




        std::cout<<"\n";
        }




return 0;
}



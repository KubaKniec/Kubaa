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




auto main() -> int
{
	auto const rok=zapytaj("Podaj rok: ");
	auto const miesiac=zapytaj("Podaj miesiac(numer): ");

	if (rok%4==0){            //rok przestepny


		if (rok%100==0){         //rok przestepny  XY 00 (np 1600)


			if (rok%400==0){        //rok przestepny 100leci


			}
			else{       //rok nie przestepny 100lecie

			}
		}
		else{    //rok przestepny, Nie XY 00 (np 1600)

		}
	}
	else{      //rok NIE przestepny

	}






return 0;
}

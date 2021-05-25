#include <iostream>
#include "filmlib.h"

using namespace std;

int main()
{
    film ABddC("std::string _name", "std::string _producer", "std::string _scenarist", "std::string _composer", "17.09.2002", 132000);
    film B("std::string _name", "std::string _producer", "std::string _scenarist", "std::string _composer", "25.09.2002", 132000);
    filmlib FF;
    FF.add_film(ABddC);
    FF.add_film(B);
    FF.save_to_file("LOL");
    filmlib SS;
    SS.read_from_file("LOL");
    SS.show_by_producer("std::string _producer");

    return 0;
}


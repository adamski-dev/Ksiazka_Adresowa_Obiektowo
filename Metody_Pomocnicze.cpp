#include "Metody_Pomocnicze.h"
#include <sstream>

string Metody_Pomocnicze::konwerjsa_int_na_string(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}


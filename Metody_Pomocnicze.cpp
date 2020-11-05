#include "Metody_Pomocnicze.h"

string Metody_Pomocnicze::konwerjsa_int_na_string(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
int Metody_Pomocnicze::konwersja_string_na_int (string tekst)
{
    std::string str = tekst;
    int k;
    std::istringstream iss(str);
    iss >> k;
    return k;
}


#ifndef PLIK_TEKSTOWY_H
#define PLIK_TEKSTOWY_H

#include <iostream>


using namespace std;

class Plik_Tekstowy
{
    const string NAZWA_PLIKU_UZYTKOWNIKOW = "Uzytkownicy.txt";
    const string NAZWA_PLIKU_ADRESATOW = "Adresaci.txt";

public:

    string pobierz_nazwe_pliku_uzytkownikow();
    string pobierz_nazwe_pliku_adresatow();
};

#endif

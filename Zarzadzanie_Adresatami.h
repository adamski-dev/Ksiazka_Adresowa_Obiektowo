#ifndef ZARZADZANIE_ADRESATAMI_H
#define ZARZADZANIE_ADRESATAMI_H
#include <vector>
#include <algorithm>
#include "Adresat.h"
#include "Plik_Adresatow.h"

using namespace std;

class Zarzadzanie_Adresatami
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat> adresaci;
    Plik_Adresatow plik_adresatow;


public:
    Zarzadzanie_Adresatami (string nazwa_pliku_adresatow, int id_zalogowanego_uzytkownika): plik_adresatow(nazwa_pliku_adresatow), ID_ZALOGOWANEGO_UZYTKOWNIKA(id_zalogowanego_uzytkownika){adresaci = plik_adresatow.wczytaj_adresatow_z_pliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);};
    string zamien_pierwsza_litere_na_duza_a_pozostale_na_male(string tekst);
    void dodaj_adresata();
    void wypisz_wszystkich_adresatow();
};

#endif

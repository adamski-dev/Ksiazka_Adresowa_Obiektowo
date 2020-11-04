#ifndef ZARZADZANIE_ADRESATAMI_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define ZARZADZANIE_ADRESATAMI_H
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Adresat.h"
#include "Plik_Adresatow.h"

using namespace std;

class Zarzadzanie_Adresatami
{
    vector<Adresat> adresaci;
    int pobierz_id_nowego_adresata();
    Plik_Adresatow plik_adresatow;

public:

    string zamien_pierwsza_litere_na_duza_a_pozostale_na_male(string tekst);
    void dodaj_adresata(int id_zalogowanego_uzytkownika);
    void wypisz_wszystkich_adresatow();
    void wczytaj_adresatow_z_pliku(int id_zalogowanego_uzytkownika);
};

#endif

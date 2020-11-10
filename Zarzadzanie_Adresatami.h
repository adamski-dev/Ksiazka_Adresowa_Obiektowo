#ifndef ZARZADZANIE_ADRESATAMI_H
#define ZARZADZANIE_ADRESATAMI_H
#include <vector>
#include <algorithm>
#include <windows.h>
#include "Adresat.h"
#include "Plik_Adresatow.h"

using namespace std;

class Zarzadzanie_Adresatami
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat> adresaci;
    Plik_Adresatow plik_adresatow;
    void wyswietl_zawartosc (Adresat adresaci);
    void wyswietl_menu_edycji();

public:
    Zarzadzanie_Adresatami (int id_zalogowanego_uzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(id_zalogowanego_uzytkownika){adresaci = plik_adresatow.wczytaj_adresatow_z_pliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);};
    string zamien_pierwsza_litere_na_duza_a_pozostale_na_male(string tekst);
    void dodaj_adresata();
    void wypisz_wszystkich_adresatow();
    void wyszukaj_wedlug_imienia();
    void wyszukaj_wedlug_nazwiska();
    void usun_adresata();
    void edytuj_adresata();
};

#endif

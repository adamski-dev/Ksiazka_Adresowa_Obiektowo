#ifndef KSIAZKA_ADRESOWA_H
#define KSIAZKA_ADRESOWA_H
#include <windows.h>
#include <iostream>
#include "Zarzadzanie_Uzytkownikami.h"
#include "Zarzadzanie_Adresatami.h"

using namespace std;

class Ksiazka_Adresowa
{
    Zarzadzanie_Uzytkownikami zarzadzanie_uzytkownikami;
    Zarzadzanie_Adresatami *zarzadzanie_adresatami;
    const string NAZWA_PLIKU_ADRESATOW;

public:
    Ksiazka_Adresowa(string nazwa_pliku_z_uzytkownikami, string nazwa_pliku_adresatow) : zarzadzanie_uzytkownikami(nazwa_pliku_z_uzytkownikami), NAZWA_PLIKU_ADRESATOW (nazwa_pliku_adresatow) {zarzadzanie_adresatami = NULL;};
    ~Ksiazka_Adresowa(){ delete zarzadzanie_adresatami; zarzadzanie_adresatami = NULL;};
    void rejestracja_uzytkownika();
    void logowanie_uzytkownika();
    void zmiana_hasla();
    void wylogowanie ();
    void dodaj_adresata();
    void wypisz_wszystkich_adresatow();
    void wyswietl_glowne_menu();
    bool czy_ktos_jest_zalogowany ();
    void wyswietl_menu_adresata();
};

#endif

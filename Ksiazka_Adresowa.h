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

public:
    Ksiazka_Adresowa (){zarzadzanie_adresatami = NULL;};
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
    void wyszukaj_wedlug_imienia();
    void wyszukaj_wedlug_nazwiska();
    void usun_adresata();
    void edytuj_adresata();
};

#endif

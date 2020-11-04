#ifndef KSIAZKA_ADRESOWA_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define KSIAZKA_ADRESOWA_H

#include <iostream>
#include "Zarzadzanie_Uzytkownikami.h"
#include "Zarzadzanie_Adresatami.h"

using namespace std;

class Ksiazka_Adresowa
{
    Zarzadzanie_Uzytkownikami zarzadzanie_uzytkownikami;
    Zarzadzanie_Adresatami zarzadzanie_adresatami;

public:
    Ksiazka_Adresowa(string nazwa_pliku_z_uzytkownikami) : zarzadzanie_uzytkownikami(nazwa_pliku_z_uzytkownikami){zarzadzanie_uzytkownikami.wczytaj_uzytkownikow_z_pliku();};
    void rejestracja_uzytkownika();
    void wypisz_wszystkich_uzytkownikow();
    void logowanie_uzytkownika();
    void zmiana_hasla();
    void wylogowanie ();
    void dodaj_adresata();
    void wypisz_wszystkich_adresatow();
    void wczytaj_adresatow_z_pliku();
};

#endif

#ifndef PLIK_UZYTKOWNIKOW_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define PLIK_UZYTKOWNIKOW_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "Metody_Pomocnicze.h"

using namespace std;

class Plik_Uzytkownikow
{
    const string nazwa_pliku_z_uzytkownikami;
    bool czy_plik_jest_pusty();
    string zamien_dane_uzytkownika_na_linie_z_danymi_oddzielona_pionowymi_kreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierz_dane_uzytkownika(string dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami);

public:
    Plik_Uzytkownikow(string NAZWA_PLIKU_UZYTKOWNIKOW) : nazwa_pliku_z_uzytkownikami (NAZWA_PLIKU_UZYTKOWNIKOW){};
    void dopisz_uzytkownika_do_pliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytaj_uzytkownikow_z_pliku();
    void zapisz_wszystkich_uzytkownikow_do_pliku(vector <Uzytkownik> & uzytkownicy);

};

#endif

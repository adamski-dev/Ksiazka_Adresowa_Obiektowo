#ifndef PLIK_UZYTKOWNIKOW_H
#define PLIK_UZYTKOWNIKOW_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Uzytkownik.h"
#include "Metody_Pomocnicze.h"
#include "Plik_Tekstowy.h"

using namespace std;


class Plik_Uzytkownikow: public Plik_Tekstowy
{
    string zamien_dane_uzytkownika_na_linie_z_danymi_oddzielona_pionowymi_kreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierz_dane_uzytkownika(string dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami);

public:
    void dopisz_uzytkownika_do_pliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytaj_uzytkownikow_z_pliku();
    void zapisz_wszystkich_uzytkownikow_do_pliku(vector <Uzytkownik> & uzytkownicy);
};

#endif

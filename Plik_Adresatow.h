#ifndef PLIK_ADRESATOW_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define PLIK_ADRESATOW_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "Metody_Pomocnicze.h"

using namespace std;

class Plik_Adresatow
{
   string zamien_dane_adresata_na_linie_z_danymi_oddzielona_pionowymi_kreskami(Adresat adresat);
   Adresat pobierz_dane_adresata(string dane_jednego_adresata_oddzielone_pionowymi_kreskami);

public:
    void dopisz_adresata_do_pliku(Adresat adresat);
    vector<Adresat> wczytaj_adresatow_z_pliku(int id_zalogowanego_uzytkownika);
};

#endif

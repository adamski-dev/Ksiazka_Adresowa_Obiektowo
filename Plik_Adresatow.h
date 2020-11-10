#ifndef PLIK_ADRESATOW_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define PLIK_ADRESATOW_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Adresat.h"
#include "Metody_Pomocnicze.h"
#include "Plik_Tekstowy.h"

using namespace std;

class Plik_Adresatow: public Plik_Tekstowy
{
   string zamien_dane_adresata_na_linie_z_danymi_oddzielona_pionowymi_kreskami(Adresat adresat);
   Adresat pobierz_dane_adresata(string dane_jednego_adresata_oddzielone_pionowymi_kreskami);
   int id_ostatniego_adresata;
   int pobierz_id_adresata(string dane_ostatniego_adresata);

public:
    vector<Adresat> wczytaj_adresatow_z_pliku(int id_zalogowanego_uzytkownika);
    void dopisz_adresata_do_pliku(Adresat adresat);
    int pobierz_id_ostatniego_adresata();
    void usun_kontakt_z_pliku(int id);
    void zmien_dane_adresata_w_pliku(Adresat adresat);
};

#endif

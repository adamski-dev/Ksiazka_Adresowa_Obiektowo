#ifndef ZARZADZANIE_URZYTKOWNIKAMI_H
#define ZARZADZANIE_URZYTKOWNIKAMI_H
#include <vector>
#include "Uzytkownik.h"
#include "Plik_Uzytkownikow.h"

using namespace std;

class Zarzadzanie_Uzytkownikami
{
    int id_zalogowanego_uzytkownika;
    vector<Uzytkownik> uzytkownicy;
    Uzytkownik podaj_dane_nowego_uzytkownika();
    int pobierz_id_nowego_uzytkownika();
    bool czy_istnieje_login(string login);
    Plik_Uzytkownikow plik_uzytkownikow;

public:
    Zarzadzanie_Uzytkownikami(string nazwa_pliku_z_uzytkownikami) : plik_uzytkownikow(nazwa_pliku_z_uzytkownikami){id_zalogowanego_uzytkownika =0; uzytkownicy = plik_uzytkownikow.wczytaj_uzytkownikow_z_pliku();};
    void logowanie_uzytkownika();
    void rejestracja_uzytkownika();
    void zmiana_hasla();
    void wylogowanie();
    bool czy_ktos_jest_zalogowany();
    int pobierz_id_zalogowanego_uzytkownika();
};

#endif

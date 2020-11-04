#ifndef ZARZADZANIE_URZYTKOWNIKAMI_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define ZARZADZANIE_URZYTKOWNIKAMI_H

#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
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
    int logowanie_uzytkownika();
    Zarzadzanie_Uzytkownikami(string nazwa_pliku_z_uzytkownikami) : plik_uzytkownikow(nazwa_pliku_z_uzytkownikami){};
    void rejestracja_uzytkownika();
    void wypisz_wszystkich_uzytkownikow();
    void wczytaj_uzytkownikow_z_pliku();
    void zmiana_hasla();
    void wylogowanie();

};

#endif

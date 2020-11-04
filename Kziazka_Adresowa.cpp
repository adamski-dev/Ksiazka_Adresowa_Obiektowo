#include "Ksiazka_Adresowa.h"

void Ksiazka_Adresowa::rejestracja_uzytkownika()
{
    zarzadzanie_uzytkownikami.rejestracja_uzytkownika();
}
void Ksiazka_Adresowa::wypisz_wszystkich_uzytkownikow()
{
    zarzadzanie_uzytkownikami.wypisz_wszystkich_uzytkownikow();
}
void Ksiazka_Adresowa::logowanie_uzytkownika()
{
    zarzadzanie_uzytkownikami.logowanie_uzytkownika();
}
void Ksiazka_Adresowa::zmiana_hasla()
{
    zarzadzanie_uzytkownikami.zmiana_hasla();
}
void Ksiazka_Adresowa::wylogowanie ()
{
    zarzadzanie_uzytkownikami.wylogowanie();
}
void Ksiazka_Adresowa::dodaj_adresata()
{
    void* id = & zarzadzanie_uzytkownikami;
    int id_zalogowanego_uzytkownika = *reinterpret_cast<int*>(id);
    zarzadzanie_adresatami.dodaj_adresata(id_zalogowanego_uzytkownika);
}
void Ksiazka_Adresowa::wypisz_wszystkich_adresatow()
{
    zarzadzanie_adresatami.wypisz_wszystkich_adresatow();
}
void Ksiazka_Adresowa::wczytaj_adresatow_z_pliku()
{
    void* id = & zarzadzanie_uzytkownikami;
    int id_zalogowanego_uzytkownika = *reinterpret_cast<int*>(id);
    zarzadzanie_adresatami.wczytaj_adresatow_z_pliku(id_zalogowanego_uzytkownika);
}

#include <iostream>
#include "Ksiazka_Adresowa.h"

using namespace std;

int main()
{

 Ksiazka_Adresowa ksiazka_adresowa ("Uzytkownicy.txt");
 ksiazka_adresowa.wypisz_wszystkich_uzytkownikow();
 //ksiazka_adresowa.rejestracja_uzytkownika();
 ksiazka_adresowa.logowanie_uzytkownika();
 //ksiazka_adresowa.zmiana_hasla();
 //ksiazka_adresowa.wypisz_wszystkich_uzytkownikow();
 //ksiazka_adresowa.wylogowanie();
 //ksiazka_adresowa.dodajAdresata();
 //ksiazka_adresowa.dodajAdresata();

 ksiazka_adresowa.wczytaj_adresatow_z_pliku();
 ksiazka_adresowa.wypisz_wszystkich_adresatow();

 return 0;
}

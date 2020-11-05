#include <iostream>
#include "Ksiazka_Adresowa.h"

using namespace std;

int main()
{
    Ksiazka_Adresowa ksiazka_adresowa ("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        char wybor;
        ksiazka_adresowa.wyswietl_glowne_menu();
        cout << endl << "Wybor:";
        cin >> wybor;

        switch (wybor)
        {
        case '1': ksiazka_adresowa.logowanie_uzytkownika(); break;
        case '2': ksiazka_adresowa.rejestracja_uzytkownika(); break;
        case '3': exit(0); break;
        }
        while (ksiazka_adresowa.czy_ktos_jest_zalogowany())
        {
            ksiazka_adresowa.wyswietl_menu_adresata();
            cout << endl << "Wybor:";
            cin >> wybor;
            switch (wybor)
            {
            case '1': ksiazka_adresowa.dodaj_adresata(); break;
            case '2': /*ksiazka_adresowa.wyszukaj_wedlug_imienia();*/ break;
            case '3': /*ksiazka_adresowa.wyszukaj_wedlug_nazwiska();*/ break;
            case '4': ksiazka_adresowa.wypisz_wszystkich_adresatow(); break;
            case '5': /*ksiazka_adresowa.usun_adresata();*/ break;
            case '6': /*ksiazka_adresowa.edytuj_adresata();*/ break;
            case '7': ksiazka_adresowa.zmiana_hasla(); break;
            case '8': ksiazka_adresowa.wylogowanie(); break;
            }
        }
    }
    return 0;
}

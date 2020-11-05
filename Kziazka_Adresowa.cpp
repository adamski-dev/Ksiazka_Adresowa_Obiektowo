#include "Ksiazka_Adresowa.h"

void Ksiazka_Adresowa::rejestracja_uzytkownika()
{
    zarzadzanie_uzytkownikami.rejestracja_uzytkownika();
}

void Ksiazka_Adresowa::logowanie_uzytkownika()
{
    zarzadzanie_uzytkownikami.logowanie_uzytkownika();
    if (zarzadzanie_uzytkownikami.czy_ktos_jest_zalogowany())
    {
        zarzadzanie_adresatami = new Zarzadzanie_Adresatami (NAZWA_PLIKU_ADRESATOW, zarzadzanie_uzytkownikami.pobierz_id_zalogowanego_uzytkownika());
    }
}

void Ksiazka_Adresowa::zmiana_hasla()
{
    zarzadzanie_uzytkownikami.zmiana_hasla();
}

void Ksiazka_Adresowa::wylogowanie ()
{
    zarzadzanie_uzytkownikami.wylogowanie();
    delete zarzadzanie_adresatami; zarzadzanie_adresatami = NULL;
}

void Ksiazka_Adresowa::dodaj_adresata()
{
    if (zarzadzanie_uzytkownikami.czy_ktos_jest_zalogowany())
    zarzadzanie_adresatami -> dodaj_adresata();
}

void Ksiazka_Adresowa::wypisz_wszystkich_adresatow()
{
    if (zarzadzanie_uzytkownikami.czy_ktos_jest_zalogowany())
    zarzadzanie_adresatami -> wypisz_wszystkich_adresatow();
}

bool Ksiazka_Adresowa:: czy_ktos_jest_zalogowany ()
{
    if (zarzadzanie_uzytkownikami.czy_ktos_jest_zalogowany()) return true;
    else return false;
}

void Ksiazka_Adresowa::wyswietl_glowne_menu()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << "---------------------------"                         << endl;
    cout << " Menu Glowne:"                                       << endl;
    cout << "---------------------------"                         << endl;
    cout << "1.  Logowanie "                                      << endl;
    cout << "2.  Rejestracja konta"                               << endl;
    cout << "3.  Zakoncz program"                                 << endl;
    cout << "---------------------------"                         << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void Ksiazka_Adresowa:: wyswietl_menu_adresata()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << "---------------------------"                         << endl;
    cout << " Menu adresata:"                                 << endl;
    cout << "---------------------------"                         << endl;
    cout << "1.  Dodaj nowy kontakt"                                 << endl;
    cout << "2.  Wyszukaj kontakty wedlug imienia"                              << endl;
    cout << "3.  Wyszukaj kontakty wedlug nazwiska"                                 << endl;
    cout << "4.  Wyswietl wszystkie kontakty"                            << endl;
    cout << "5.  Usun kontakt"                                  << endl;
    cout << "6.  Zmien dane kontaktowe"                                    << endl;
    cout << "7.  Zmiana hasla"                            << endl;
    cout << "8.  Wylogowanie"                                         << endl;
    cout << "---------------------------"                         << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

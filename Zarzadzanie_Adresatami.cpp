#include "Zarzadzanie_Adresatami.h"

string Zarzadzanie_Adresatami::zamien_pierwsza_litere_na_duza_a_pozostale_na_male(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void Zarzadzanie_Adresatami::dodaj_adresata(int id_zalogowanego_uzytkownika)
{
    Adresat adresat;
    adresat.ustaw_id(pobierz_id_nowego_adresata());
    adresat.ustaw_id_uzytkownika(id_zalogowanego_uzytkownika);

    string text="";
    cout << "Podaj imie: ";
    cin >> text;
    adresat.ustaw_imie(zamien_pierwsza_litere_na_duza_a_pozostale_na_male(text));

    cout << "Podaj nazwisko: ";
    cin >> text;
    adresat.ustaw_nazwisko(zamien_pierwsza_litere_na_duza_a_pozostale_na_male(text));

    cout << "Podaj numer telefonu: ";
    cin >> text;
    adresat.ustaw_numer_telefonu(text);

    cout << "Podaj email: ";
    cin >> text;
    adresat.ustaw_email(text);

    cout << "Podaj adres: ";
    cin.sync();
    getline (cin, text);
    adresat.ustaw_adres(text);

    adresaci.push_back(adresat);
    plik_adresatow.dopisz_adresata_do_pliku(adresat);
}
int Zarzadzanie_Adresatami::pobierz_id_nowego_adresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierz_id() + 1;
}
void Zarzadzanie_Adresatami::wypisz_wszystkich_adresatow()
{
    for (int i=0; i < adresaci.size(); i++)
    {
       cout << adresaci[i].pobierz_id()             << "|";
       cout << adresaci[i].pobierz_id_uzytkownika() << "|";
       cout << adresaci[i].pobierz_imie()           << "|";
       cout << adresaci[i].pobierz_nazwisko()       << "|";
       cout << adresaci[i].pobierz_numer_telefonu() << "|";
       cout << adresaci[i].pobierz_email()          << "|";
       cout << adresaci[i].pobierz_adres()          << "|" << endl;
    }
}
void Zarzadzanie_Adresatami::wczytaj_adresatow_z_pliku(int id_zalogowanego_uzytkownika)
{
    adresaci = plik_adresatow.wczytaj_adresatow_z_pliku(id_zalogowanego_uzytkownika);
}

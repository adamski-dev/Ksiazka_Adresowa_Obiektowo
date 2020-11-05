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

void Zarzadzanie_Adresatami::dodaj_adresata()
{
    Adresat adresat;
    adresat.ustaw_id(plik_adresatow.pobierz_id_ostatniego_adresata()+1);
    adresat.ustaw_id_uzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    string tekst="";
    cout << "Podaj imie: ";
    cin >> tekst;
    adresat.ustaw_imie(zamien_pierwsza_litere_na_duza_a_pozostale_na_male(tekst));

    cout << "Podaj nazwisko: ";
    cin >> tekst;
    adresat.ustaw_nazwisko(zamien_pierwsza_litere_na_duza_a_pozostale_na_male(tekst));

    cout << "Podaj numer telefonu: ";
    cin >> tekst;
    adresat.ustaw_numer_telefonu(tekst);

    cout << "Podaj email: ";
    cin >> tekst;
    adresat.ustaw_email(tekst);

    cout << "Podaj adres: ";
    cin.sync();
    getline (cin, tekst);
    adresat.ustaw_adres(tekst);

    adresaci.push_back(adresat);
    plik_adresatow.dopisz_adresata_do_pliku(adresat);
}

void Zarzadzanie_Adresatami::wypisz_wszystkich_adresatow()
{
    cout << endl;
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
    system("pause");
}

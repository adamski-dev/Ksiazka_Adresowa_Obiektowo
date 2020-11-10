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
    if (adresaci.empty())
    cout << "Nie masz jeszcze zadnych zapisanych kontaktow. Dodaj nowy kontakt," << endl;

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

void Zarzadzanie_Adresatami::wyszukaj_wedlug_imienia()
{
    string imie ="";
    cout << endl << "Wpisz imie osoby ktorej dane chcesz odszukac: ";
    cin >> imie;
    imie = zamien_pierwsza_litere_na_duza_a_pozostale_na_male (imie);
    int ilosc_przypadkow = 0;

    for (vector<Adresat>:: iterator it = adresaci.begin(); it != adresaci.end(); ++it)
    {
        if (it -> pobierz_imie() == imie) {wyswietl_zawartosc(*it); ilosc_przypadkow ++;}
    }
    if (ilosc_przypadkow == 0) cout << "Nie odnaleziono kontaktu o takim imieniu, " << endl;
    system("pause");
}

void Zarzadzanie_Adresatami::wyszukaj_wedlug_nazwiska()
{
    string nazwisko ="";
    cout << endl << "Wpisz imie osoby ktorej dane chcesz odszukac: ";
    cin >> nazwisko;
    nazwisko = zamien_pierwsza_litere_na_duza_a_pozostale_na_male (nazwisko);
    int ilosc_przypadkow = 0;

    for (vector<Adresat>:: iterator it = adresaci.begin(); it != adresaci.end(); ++it)
    {
        if (it -> pobierz_nazwisko() == nazwisko) {wyswietl_zawartosc(*it); ilosc_przypadkow ++;}
    }
    if (ilosc_przypadkow == 0) cout << "Nie odnaleziono kontaktu o takim nazwisku, " << endl;
    system("pause");
}

void Zarzadzanie_Adresatami:: wyswietl_zawartosc (Adresat adresaci)
{
       cout << adresaci.pobierz_id()             << "|";
       cout << adresaci.pobierz_id_uzytkownika() << "|";
       cout << adresaci.pobierz_imie()           << "|";
       cout << adresaci.pobierz_nazwisko()       << "|";
       cout << adresaci.pobierz_numer_telefonu() << "|";
       cout << adresaci.pobierz_email()          << "|";
       cout << adresaci.pobierz_adres()          << "|" << endl;
}

void Zarzadzanie_Adresatami:: usun_adresata()
{
    int id = 0;
    int ilosc_przypadkow = 0;
    cout << endl << "Wpisz numer id osoby ktora chcesz usunac z kontaktow: " << endl;
    cin >> id;

    for (int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierz_id()  == id)
        {
            cout <<"Wpisz litere t aby usunac powyzszy kontakt: "<< endl;
            ilosc_przypadkow ++;
            char wybor;
            cin >> wybor;
                if (wybor == 't' || wybor == 'T')
                {
                    adresaci.erase(adresaci.begin() + i);
                    plik_adresatow.usun_kontakt_z_pliku(id);
                    cout << "Kontakt zostal usuniety z ksiazki adresowej..." << endl;
                    system("pause");
                }
                else
                {
                    cout << "Nie wybrales litery t aby potwierdzic - dane pozostaja bez zmian." << endl;
                    system("pause");
                }
        }
    }
    if (ilosc_przypadkow == 0)
    {
        cout << "Nie odnaleziono kontaktu o takim numerze id," << endl;
        system("pause");
    }
}

void Zarzadzanie_Adresatami:: edytuj_adresata()
{
    int id = 0;
    cout << endl << "Wpisz numer id osoby ktorej dane chcesz edytowac: ";
    cin >> id;
    int ilosc_przypadkow = 0;
    for (vector<Adresat>::iterator it = adresaci.begin(); it != adresaci.end(); it++)
    {
        if (it-> pobierz_id() == id)
        {
            wyswietl_menu_edycji();
            ilosc_przypadkow ++;
            cout<<endl<< "Wybierz z powyzszej listy ktore dane chcesz edytowac: ";
            char wybor;
            cin >> wybor;
            string nowe_dane = "";
            string cos;
            switch (wybor)
            {
            case '1': cout << "Wpisz nowe imie adresata: ";
                      cin >> nowe_dane;
                      nowe_dane = zamien_pierwsza_litere_na_duza_a_pozostale_na_male (nowe_dane);
                      it -> ustaw_imie(nowe_dane); break;
            case '2': cout << "Wpisz nowe nazwisko adresata: ";
                      cin >> nowe_dane;
                      nowe_dane = zamien_pierwsza_litere_na_duza_a_pozostale_na_male (nowe_dane);
                      it -> ustaw_nazwisko(nowe_dane); break;
            case '3': cout << "Wpisz nowy numer telefonu adresata: ";
                      cin >> nowe_dane;
                      it -> ustaw_numer_telefonu(nowe_dane); break;
            case '4': cout << "Wpisz nowy email adres adresata: ";
                      cin >> nowe_dane;
                      it -> ustaw_email(nowe_dane); break;
            case '5': cout << "Wpisz nowy adres adresata: ";
                      cin.sync(); getline (cin, nowe_dane);
                      it -> ustaw_adres(nowe_dane); break;
            case '6': break;
            }
            if (wybor !='6') plik_adresatow.zmien_dane_adresata_w_pliku(*it);
        }
    }
    if (ilosc_przypadkow == 0)
    {
        cout << "Nie odnaleziono kontaktu o takim numerze id," << endl;
        system("pause");
    }
}

void Zarzadzanie_Adresatami:: wyswietl_menu_edycji()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << "---------------------------"                      << endl;
    cout << " Menu edycji:"                                    << endl;
    cout << "---------------------------"                      << endl;
    cout << "1.  Zmien imie"                                   << endl;
    cout << "2.  Zmien nazwisko"                               << endl;
    cout << "3.  Zmien numer telefonu"                         << endl;
    cout << "4.  Zmien adres email"                            << endl;
    cout << "5.  Zmien adres pocztowy"                         << endl;
    cout << "6.  Powrot do menu adresata"                      << endl;
    cout << "---------------------------"                      << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

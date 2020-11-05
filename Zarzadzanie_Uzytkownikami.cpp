#include "Zarzadzanie_Uzytkownikami.h"

void Zarzadzanie_Uzytkownikami::rejestracja_uzytkownika()
{
    Uzytkownik uzytkownik = podaj_dane_nowego_uzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plik_uzytkownikow.dopisz_uzytkownika_do_pliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik Zarzadzanie_Uzytkownikami::podaj_dane_nowego_uzytkownika()
{
    Uzytkownik uzytkownik;
    uzytkownik.ustaw_id (pobierz_id_nowego_uzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustaw_login(login);

    } while (czy_istnieje_login(uzytkownik.pobierz_login()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustaw_haslo(haslo);

    return uzytkownik;
}

int Zarzadzanie_Uzytkownikami::pobierz_id_nowego_uzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierz_id() + 1;
}

bool Zarzadzanie_Uzytkownikami::czy_istnieje_login(string login)
{
    for (int i=0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierz_login() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void Zarzadzanie_Uzytkownikami::logowanie_uzytkownika()
{
    string login = "", haslo = "";
    cout << endl << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik> :: iterator it = uzytkownicy.begin();
    while (it != uzytkownicy.end())
    {
        if (it -> pobierz_login() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb --)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (it -> pobierz_haslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl ;
                    id_zalogowanego_uzytkownika = it -> pobierz_id();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        it++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}

void Zarzadzanie_Uzytkownikami:: zmiana_hasla()
{
    string nowe_haslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> nowe_haslo;

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierz_id() == id_zalogowanego_uzytkownika)
        {
            uzytkownicy[i].ustaw_haslo(nowe_haslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plik_uzytkownikow.zapisz_wszystkich_uzytkownikow_do_pliku(uzytkownicy);
}

void Zarzadzanie_Uzytkownikami::wylogowanie()
{
    if (id_zalogowanego_uzytkownika != 0) id_zalogowanego_uzytkownika = 0;
    else cout << "Nikt nie jest aktualnie zalogowany." << endl;
}

bool Zarzadzanie_Uzytkownikami::czy_ktos_jest_zalogowany()
{
    if (id_zalogowanego_uzytkownika != 0) return true;
    else return false;
}

int Zarzadzanie_Uzytkownikami::pobierz_id_zalogowanego_uzytkownika()
{
    return id_zalogowanego_uzytkownika;
}

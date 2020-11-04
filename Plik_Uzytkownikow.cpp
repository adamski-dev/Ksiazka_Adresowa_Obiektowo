#include "Plik_Uzytkownikow.h"

void Plik_Uzytkownikow::dopisz_uzytkownika_do_pliku(Uzytkownik uzytkownik)
{
    string linia_z_danymi_uzytkownika = "";
    fstream plik_tekstowy;
    plik_tekstowy.open(nazwa_pliku_z_uzytkownikami.c_str(), ios::app);

    if (plik_tekstowy.good() == true)
    {
        linia_z_danymi_uzytkownika = zamien_dane_uzytkownika_na_linie_z_danymi_oddzielona_pionowymi_kreskami(uzytkownik);

        if (czy_plik_jest_pusty() == true)
        {
            plik_tekstowy << linia_z_danymi_uzytkownika;
        }
        else
        {
            plik_tekstowy << endl << linia_z_danymi_uzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwa_pliku_z_uzytkownikami << " i zapisac w nim danych." << endl;
    plik_tekstowy.close();
}

bool Plik_Uzytkownikow::czy_plik_jest_pusty()
{
    fstream plik_tekstowy;
    plik_tekstowy.seekg(0, ios::end);
    if (plik_tekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string Plik_Uzytkownikow::zamien_dane_uzytkownika_na_linie_z_danymi_oddzielona_pionowymi_kreskami(Uzytkownik uzytkownik)
{
    string linia_z_danymi_uzytkownika = "";
    linia_z_danymi_uzytkownika += Metody_Pomocnicze::konwerjsa_int_na_string(uzytkownik.pobierz_id())+ '|';
    linia_z_danymi_uzytkownika += uzytkownik.pobierz_login() + '|';
    linia_z_danymi_uzytkownika += uzytkownik.pobierz_haslo() + '|';

    return linia_z_danymi_uzytkownika;
}

vector<Uzytkownik> Plik_Uzytkownikow::wczytaj_uzytkownikow_z_pliku()
{
    Uzytkownik uzytkownik;
    fstream plik_tekstowy;
    vector<Uzytkownik> uzytkownicy;
    string dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami = "";

    plik_tekstowy.open(nazwa_pliku_z_uzytkownikami.c_str(), ios::in);

    if (plik_tekstowy.good() == true)
    {
        while (getline(plik_tekstowy, dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami))
        {
            uzytkownik = pobierz_dane_uzytkownika(dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami);
            uzytkownicy.push_back(uzytkownik);
        }
        plik_tekstowy.close();
    }
    return uzytkownicy;
}

Uzytkownik Plik_Uzytkownikow::pobierz_dane_uzytkownika(string dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami)
{
    Uzytkownik uzytkownik;
    string pojedyncza_dana_uzytkownika = "";
    int numer_pojedynczej_danej_uzytkownika = 1;

    for (int pozycja_znaku = 0; pozycja_znaku < dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami.length(); pozycja_znaku++)
    {
        if (dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami[pozycja_znaku] != '|')
        {
            pojedyncza_dana_uzytkownika += dane_jednego_uzytkownika_oddzielone_pionowymi_kreskami[pozycja_znaku];
        }
        else
        {
            switch(numer_pojedynczej_danej_uzytkownika)
            {
            case 1:
                uzytkownik.ustaw_id(atoi(pojedyncza_dana_uzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustaw_login(pojedyncza_dana_uzytkownika);
                break;
            case 3:
                uzytkownik.ustaw_haslo(pojedyncza_dana_uzytkownika);
                break;
            }
            pojedyncza_dana_uzytkownika = "";
            numer_pojedynczej_danej_uzytkownika++;
        }
    }
    return uzytkownik;
}
void Plik_Uzytkownikow::zapisz_wszystkich_uzytkownikow_do_pliku(vector <Uzytkownik> & uzytkownicy)
{
    fstream plik_tekstowy;
    string linia_z_danymi_uzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();
    plik_tekstowy.open(nazwa_pliku_z_uzytkownikami.c_str(), ios::out);

    if (plik_tekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            linia_z_danymi_uzytkownika = zamien_dane_uzytkownika_na_linie_z_danymi_oddzielona_pionowymi_kreskami(*itr);

            if (itr == itrKoniec)
            {
               plik_tekstowy << linia_z_danymi_uzytkownika;
            }
            else
            {
                plik_tekstowy << linia_z_danymi_uzytkownika << endl;
            }
            linia_z_danymi_uzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nazwa_pliku_z_uzytkownikami << endl;
    }
    plik_tekstowy.close();
}

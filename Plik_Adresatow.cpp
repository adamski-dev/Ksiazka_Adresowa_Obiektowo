#include "Plik_Adresatow.h"

void Plik_Adresatow::dopisz_adresata_do_pliku(Adresat adresat)
{
    string linia_z_danymi_adresata = "";
    fstream plik_tekstowy;
    plik_tekstowy.open(pobierz_nazwe_pliku_adresatow(), ios::app);

    if (plik_tekstowy.good() == true)
    {
        linia_z_danymi_adresata = zamien_dane_adresata_na_linie_z_danymi_oddzielona_pionowymi_kreskami(adresat);
        plik_tekstowy << linia_z_danymi_adresata << endl;
    }
    else
    cout << "Nie udalo sie otworzyc pliku " << pobierz_nazwe_pliku_adresatow() << " i zapisac w nim danych." << endl;
    plik_tekstowy.close();
    id_ostatniego_adresata++;
}

string Plik_Adresatow::zamien_dane_adresata_na_linie_z_danymi_oddzielona_pionowymi_kreskami(Adresat adresat)
{
    string linia_z_danymi_adresata = "";
    linia_z_danymi_adresata += Metody_Pomocnicze::konwerjsa_int_na_string(adresat.pobierz_id())+ '|';
    linia_z_danymi_adresata += Metody_Pomocnicze::konwerjsa_int_na_string(adresat.pobierz_id_uzytkownika())+ '|';
    linia_z_danymi_adresata += adresat.pobierz_imie() + '|';
    linia_z_danymi_adresata += adresat.pobierz_nazwisko() + '|';
    linia_z_danymi_adresata += adresat.pobierz_numer_telefonu() + '|';
    linia_z_danymi_adresata += adresat.pobierz_email() + '|';
    linia_z_danymi_adresata += adresat.pobierz_adres() + '|';

    return linia_z_danymi_adresata;
}
vector<Adresat> Plik_Adresatow::wczytaj_adresatow_z_pliku(int id_zalogowanego_uzytkownika)
{
    Adresat adresat;
    fstream plik_tekstowy;
    vector<Adresat> adresaci;
    string dane_jednego_adresata_oddzielone_pionowymi_kreskami = "";

    plik_tekstowy.open(pobierz_nazwe_pliku_adresatow(), ios::in);

    if (!plik_tekstowy.good()) id_ostatniego_adresata = 0;

    if (plik_tekstowy.good() == true)
    {
        while (getline(plik_tekstowy, dane_jednego_adresata_oddzielone_pionowymi_kreskami))
        {
            adresat = pobierz_dane_adresata(dane_jednego_adresata_oddzielone_pionowymi_kreskami);
            if (adresat.pobierz_id_uzytkownika()== id_zalogowanego_uzytkownika) adresaci.push_back(adresat);
            id_ostatniego_adresata = pobierz_id_adresata (dane_jednego_adresata_oddzielone_pionowymi_kreskami);
        }
        plik_tekstowy.close();
    }
    return adresaci;
}

Adresat Plik_Adresatow::pobierz_dane_adresata(string dane_jednego_adresata_oddzielone_pionowymi_kreskami)
{
    Adresat adresat;
    string pojedyncza_dana_adresata = "";
    int numer_pojedynczej_danej_adresata = 1;

    for (int pozycja_znaku = 0; pozycja_znaku < dane_jednego_adresata_oddzielone_pionowymi_kreskami.length(); pozycja_znaku++)
    {
        if (dane_jednego_adresata_oddzielone_pionowymi_kreskami[pozycja_znaku] != '|')
        {
            pojedyncza_dana_adresata += dane_jednego_adresata_oddzielone_pionowymi_kreskami[pozycja_znaku];
        }
        else
        {
            switch(numer_pojedynczej_danej_adresata)
            {
            case 1: adresat.ustaw_id(atoi(pojedyncza_dana_adresata.c_str())); break;
            case 2: adresat.ustaw_id_uzytkownika(atoi(pojedyncza_dana_adresata.c_str())); break;
            case 3: adresat.ustaw_imie(pojedyncza_dana_adresata); break;
            case 4: adresat.ustaw_nazwisko(pojedyncza_dana_adresata); break;
            case 5: adresat.ustaw_numer_telefonu(pojedyncza_dana_adresata); break;
            case 6: adresat.ustaw_email(pojedyncza_dana_adresata); break;
            case 7: adresat.ustaw_adres(pojedyncza_dana_adresata); break;
            }
            pojedyncza_dana_adresata = "";
            numer_pojedynczej_danej_adresata++;
        }
    }
    return adresat;
}

int Plik_Adresatow::pobierz_id_adresata(string dane_ostatniego_adresata)
{
    size_t pozycja_znaku;
    pozycja_znaku = dane_ostatniego_adresata.find('|');
    string tekst_id="";
    for (int i=0; i< pozycja_znaku; i++) tekst_id += dane_ostatniego_adresata[i];
    int id_ostatniego_adresata = Metody_Pomocnicze::konwersja_string_na_int (tekst_id);
    return id_ostatniego_adresata;
}

int Plik_Adresatow::pobierz_id_ostatniego_adresata()
{
    return id_ostatniego_adresata;
}

void Plik_Adresatow::usun_kontakt_z_pliku(int id)
{
    fstream plik_tekstowy;
    fstream plik_tymczasowy;
    plik_tekstowy.open(pobierz_nazwe_pliku_adresatow(),ios::in);
    string dane_adresata_w_pliku;

    while (getline(plik_tekstowy, dane_adresata_w_pliku))
    {
        string tekst_id = "";
        size_t position = dane_adresata_w_pliku.find('|');
        for (int i=0; i<position; i++) tekst_id+= dane_adresata_w_pliku[i];
        int kontakt_id = Metody_Pomocnicze::konwersja_string_na_int (tekst_id);
        if (kontakt_id != id)
        {
            plik_tymczasowy.open ("temp.txt",ios::out | ios::app);
            plik_tymczasowy << dane_adresata_w_pliku << endl;
            plik_tymczasowy.close();
        }
    }
    plik_tekstowy.close();
    remove(pobierz_nazwe_pliku_adresatow().c_str());
    rename("temp.txt", pobierz_nazwe_pliku_adresatow().c_str());
}

void Plik_Adresatow:: zmien_dane_adresata_w_pliku(Adresat adresat)
{
    fstream plik_tekstowy;
    fstream plik_tymczasowy;
    plik_tekstowy.open(pobierz_nazwe_pliku_adresatow(),ios::in);
    string dane_adresata_w_pliku;

     while (getline(plik_tekstowy, dane_adresata_w_pliku))
     {
        string tekst_id = "";
        size_t position = dane_adresata_w_pliku.find('|');
        for (int i=0; i<position; i++) tekst_id+= dane_adresata_w_pliku[i];
        int kontakt_id = Metody_Pomocnicze::konwersja_string_na_int (tekst_id);
        if (kontakt_id != adresat.pobierz_id())
        {
            plik_tymczasowy.open ("temp.txt",ios::out | ios::app);
            plik_tymczasowy << dane_adresata_w_pliku << endl;
            plik_tymczasowy.close();
        }
        else
        {
            plik_tymczasowy.open ("temp.txt",ios::out | ios::app);
            plik_tymczasowy << adresat.pobierz_id()                << "|";
            plik_tymczasowy << adresat.pobierz_id_uzytkownika()    << "|";
            plik_tymczasowy << adresat.pobierz_imie()              << "|";
            plik_tymczasowy << adresat.pobierz_nazwisko()          << "|";
            plik_tymczasowy << adresat.pobierz_numer_telefonu()    << "|";
            plik_tymczasowy << adresat.pobierz_email()             << "|";
            plik_tymczasowy << adresat.pobierz_adres()             << "|" << endl;
            plik_tymczasowy.close();
        }
     }

    plik_tekstowy.close();
    remove(pobierz_nazwe_pliku_adresatow().c_str());
    rename("temp.txt", pobierz_nazwe_pliku_adresatow().c_str());
    cout << "Dane adresata zostaly pomyslnie zmienione" << endl;
    system ("pause");
}

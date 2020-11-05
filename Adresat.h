#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id, id_uzytkownika;
    string imie, nazwisko, numer_telefonu, email, adres;

   public:
       Adresat (int id=0, int id_uzytkownika=0, string imie="", string nazwisko="", string numer_telefonu="", string email="", string adres="")
       {
           this ->id = id;
           this ->id_uzytkownika = id_uzytkownika;
           this ->imie = imie;
           this ->nazwisko = nazwisko;
           this ->numer_telefonu = numer_telefonu;
           this ->email = email;
           this ->adres = adres;
       }
       void ustaw_id (int nowe_id);
       void ustaw_id_uzytkownika (int nowe_id_uzytkownika);
       void ustaw_imie (string nowe_imie);
       void ustaw_nazwisko (string nowe_nazwisko);
       void ustaw_numer_telefonu (string nowy_numer_telefonu);
       void ustaw_email (string nowy_email);
       void ustaw_adres (string nowy_adres);

       int pobierz_id();
       int pobierz_id_uzytkownika();
       string pobierz_imie();
       string pobierz_nazwisko();
       string pobierz_numer_telefonu ();
       string pobierz_email ();
       string pobierz_adres ();
};

#endif

#include "Adresat.h"

void Adresat::ustaw_id (int nowe_id)
{
    if (nowe_id >= 0)
    id = nowe_id;
}

void Adresat::ustaw_id_uzytkownika (int nowe_id_uzytkownika)
{
    if (nowe_id_uzytkownika != 0)
    id_uzytkownika = nowe_id_uzytkownika;
}

void Adresat::ustaw_imie (string nowe_imie)
{
    imie = nowe_imie;
}

void Adresat::ustaw_nazwisko (string nowe_nazwisko)
{
    nazwisko = nowe_nazwisko;
}

void Adresat::ustaw_numer_telefonu (string nowy_numer_telefonu)
{
    numer_telefonu = nowy_numer_telefonu;
}
void Adresat::ustaw_email (string nowy_email)
{
    email = nowy_email;
}
void Adresat::ustaw_adres (string nowy_adres)
{
    adres = nowy_adres;
}

int Adresat::pobierz_id()
{
    return id;
}

int Adresat::pobierz_id_uzytkownika()
{
    return id_uzytkownika;
}

string Adresat::pobierz_imie()
{
    return imie;
}
string Adresat::pobierz_nazwisko()
{
    return nazwisko;
}
string Adresat::pobierz_numer_telefonu()
{
    return numer_telefonu;
}
string Adresat::pobierz_email()
{
    return email;
}
string Adresat::pobierz_adres()
{
    return adres;
}

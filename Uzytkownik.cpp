#include "Uzytkownik.h"

void Uzytkownik::ustaw_id (int nowe_id)
{
    if (nowe_id >= 0)
    id = nowe_id;
}
void Uzytkownik::ustaw_login (string nowy_login)
{
    login = nowy_login;
}
void Uzytkownik::ustaw_haslo (string nowe_haslo)
{
    haslo = nowe_haslo;
}

int Uzytkownik::pobierz_id()
{
    return id;
}
string Uzytkownik::pobierz_login()
{
    return login;
}
string Uzytkownik::pobierz_haslo()
{
    return haslo;
}

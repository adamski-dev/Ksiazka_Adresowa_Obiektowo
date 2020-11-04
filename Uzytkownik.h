#ifndef UZYTKOWNIK_H  // dodanie tych funkcji likwiduje blad podwojnego dodawania bibliotek
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

    //ponizej stworzenie setterow i getterow aby umozliwic funkcjom z ksiazki adresowej
    //dostep do prywatnych danych z Uzytkownik.h
   public:
       void ustaw_id (int nowe_id);
       void ustaw_login (string nowy_login);
       void ustaw_haslo (string nowe_haslo);

       int pobierz_id();
       string pobierz_login();
       string pobierz_haslo();

};

#endif // UZYTKOWNIK_H

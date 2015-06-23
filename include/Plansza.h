#ifndef PLANSZA_H
#define PLANSZA_H

#include <string>
#include <iostream>

class Gracz;
class Czlowiek;
class Komputer;

class Plansza
{
    public:
        Plansza();
        virtual ~Plansza();
        void pokaz_plansze();
        void wyczysc_plansze();
        char pole[9];
    protected:
    private:
};

class Gra : public Plansza
{
    public:
        Gra();
        virtual ~Gra();
        bool sprawdz_koniec(char pole[], char znak, int i, std::string imie);
        bool nowa_gra();
        void zmiana_gracza(Gracz* &gracz1, Gracz* &gracz2);
        void start(int tryb);
    protected:
    private:
        Plansza* plansza;
        Gracz* gracz1;
        Gracz* gracz2;
        Gracz* aktywnyGracz;
        Gracz* nieAktywnyGracz;
};

#endif // PLANSZA_H

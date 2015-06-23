#ifndef GRACZ_H
#define GRACZ_H
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Plansza;

class Gracz
{
    public:
        virtual ~Gracz(){};
        virtual void postaw_znak(char pole[])=0;
        virtual std::string pokaz_imie()=0;
        virtual char pokaz_znak()=0;
    protected:
        char znak;
        std::string imie;
    private:
};

class Czlowiek : public Gracz
{
    public:
        Czlowiek(char symbol);
        virtual ~Czlowiek();
        void postaw_znak(char pole[]);
        std::string pokaz_imie();
        char pokaz_znak();
        void podaj_imie();
    protected:
    private:
};

class Komputer : public Gracz
{
    public:
        Komputer();
        virtual ~Komputer();
        void postaw_znak(char pole[]);
        std::string pokaz_imie();
        char pokaz_znak();
    protected:
    private:
};
#endif // GRACZ_H

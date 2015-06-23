#include "Plansza.h"

Plansza::Plansza()
{
    for(int i = 0; i < 9; i++)
    {
        pole[i] = 48 + i;
    }
}

Plansza::~Plansza()
{
    //dtor
}

void Plansza::pokaz_plansze()
{
    std::cout<<"____________\n";
    for(int i = 0; i < 9; i++)
    {
        std::cout<<"|_"<<pole[i]<<"_";
        if(i%3==2)
        {
            std::cout<<"|\n";
        }
    }
    return;
}

void Plansza::wyczysc_plansze()
{
    for(int i = 0; i < 9; i++)
    {
        pole[i] = 48 + i;
    }
    return;
}

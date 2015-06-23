#include "Gracz.h"

Komputer::Komputer()
{
    imie = "Komputer";
    znak = 'O';
    srand( time( NULL ) );
}

Komputer::~Komputer()
{
    //dtor
}

void Komputer::postaw_znak(char pole[])
{
    int losowa;
    losowa = std::rand()%9;
    while(pole[losowa]=='X'||pole[losowa]=='O')
    {
        losowa = std::rand()%9;
    }
    pole[losowa] = znak;
    return;
}

std::string Komputer::pokaz_imie()
{
    return imie;
}

char Komputer::pokaz_znak()
{
    return znak;
}

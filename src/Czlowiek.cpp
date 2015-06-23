#include "Gracz.h"

Czlowiek::Czlowiek(char symbol)
{
    podaj_imie();
    znak = symbol;
}

Czlowiek::~Czlowiek()
{
    //dtor
}

void Czlowiek::postaw_znak(char pole[])
{
    unsigned i;
    while(!(std::cin>>i)||pole[i]=='X'||pole[i]=='O'||i > 8)
    {
        std::cin.clear();
        std::cin.ignore( 1000, '\n' );
        std::cout<<"Error! Pole zajete lub bledna wartosc. Powtorz wybor.\n";
    }
    if(pole[i]!='X'&&pole[i]!='O')
    {
        pole[i] = znak;
    }
    return;
}

void Czlowiek::podaj_imie()
{
    std::cout<<"Podaj imie\n";
    std::string name;
    std::cin>>name;
    std::cin.clear();
    std::cin.ignore( 1000, '\n' );
    imie = name;
}

std::string Czlowiek::pokaz_imie()
{
    return imie;
}

char Czlowiek::pokaz_znak()
{
    return znak;
}

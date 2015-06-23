#include "Plansza.h"
#include "Gracz.h"

Gra::Gra()
{
    plansza = new Plansza();
    gracz1 = new Czlowiek('X');
    aktywnyGracz = gracz1;
}

Gra::~Gra()
{
    delete plansza;
    delete gracz1;   //dtor
}

bool Gra::sprawdz_koniec(char pole[], char znak, int i, std::string imie)
{
    if((pole[0]==znak&&pole[1]==znak&&pole[2]==znak)||(pole[3]==znak&&pole[4]==znak&&pole[5]==znak)||(pole[6]==znak&&pole[7]==znak&&pole[8]==znak)||
       (pole[0]==znak&&pole[3]==znak&&pole[6]==znak)||(pole[1]==znak&&pole[4]==znak&&pole[7]==znak)||(pole[2]==znak&&pole[5]==znak&&pole[8]==znak)||
       (pole[0]==znak&&pole[4]==znak&&pole[8]==znak)||(pole[2]==znak&&pole[4]==znak&&pole[6]==znak))
    {
        std::cout<<"Wygral: "<<imie<<"\n";
        return true;
    }
    if(i == 9)
    {
        std::cout<<"Remis!\n";
        return true;
    }
    return false;
}

bool Gra::nowa_gra()
{
    char i;
    std::cout<<"Jeszcze raz?\n\tT - Tak\n\tN - Nie\n";
    while(!(std::cin>>i)||(i!='T'&&i!='N'))
    {
        std::cin.clear();
        std::cin.ignore( 1000, '\n' );
        std::cout<<"Error! Bledna wartosc. Powtorz wybor.\n";
    }
    if(i=='T')
    {
        return true;
    }
    if(i=='N')
    {
        return false;
    }
}

void Gra::zmiana_gracza(Gracz* &gracz1, Gracz* &gracz2)
{
    Gracz* temp = gracz1;
    gracz1 = gracz2;
    gracz2 = temp;
    return;
}

void Gra::start(int tryb)
{
    int licznikRuchow;
    if(tryb == 0)
    {
        gracz2 = new Czlowiek('O');
    }
    else if(tryb == 1)
    {
        gracz2 = new Komputer();
    }
    nieAktywnyGracz = gracz2;
    do
    {
        licznikRuchow = 0;
        while(!sprawdz_koniec(plansza->pole, nieAktywnyGracz->pokaz_znak(), licznikRuchow, nieAktywnyGracz->pokaz_imie()))
        {
            std::cout<<"Ruch gracza: "<<aktywnyGracz->pokaz_imie()<<"\n";
            plansza->pokaz_plansze();
            aktywnyGracz->postaw_znak(plansza->pole);
            zmiana_gracza(aktywnyGracz, nieAktywnyGracz);
            licznikRuchow++;
        }
        plansza->pokaz_plansze();
        plansza->wyczysc_plansze();
    }while(nowa_gra());
    delete gracz2;
    return;
}

#include "Gracz.h"
#include "Plansza.h"

using namespace std;

int main()
{
    cout<<"WITAJ W GRZE KOLKO I KRZYZYK!\n";
    int tryb;
    Gra* gra = new Gra();
    cout<<"Wybierz tryb gry.\n\t0 - Dwuosobowy\n\t1 - Gra z komputerem\n\t2 - Wyjdz\n";
    while(!(cin>>tryb)||(tryb!=0&&tryb!=1&&tryb!=2))
    {
        cin.clear();
        cin.ignore( 1000, '\n' );
        cout<<"Error. Bledna wartosc.\n";
    }
    switch (tryb)
    {
        case 0:
            gra->start(0);
            break;
        case 1:
            gra->start(1);
            break;
        case 2:
            break;
    }
    delete gra;
    std::cout<<"Koniec!\n";
    return 0;
}

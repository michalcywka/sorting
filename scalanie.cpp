
#include <vector>
using namespace std;

void scal(vector<int> &lewa, vector<int> &prawa, vector<int> &wynik)
{
    int rL=lewa.size();
    int rP=prawa.size();
    int wl=0,wp=0,ww=0;

    while(wl<rL && wp<rP)
    {


            if(lewa[wl] <= prawa[wp])
            {
                wynik[ww]=lewa[wl];
                wl++;

            }
            else
            {
                wynik[ww]=prawa[wp];
                wp++;
            }
    ww++;

    }

    while (wl<rL)
    {
                wynik[ww]=lewa[wl];
                wl++;
                ww++;
    }

    while (wp<rP)
    {
                wynik[ww]=prawa[wp];
                wp++;
                ww++;
    }

}

void sortowaniePrzezScalanie(vector<int> &lista)
{
    unsigned int rozmiar=lista.size();
    if(rozmiar<2)
    {
        return;
    }
    unsigned int srodek=rozmiar/2;
    vector<int> lewa;
    lewa.resize(srodek);
    vector<int> prawa;
    prawa.resize(rozmiar-srodek);
    for(unsigned int i=0; i<=srodek-1; i++)
    {
        lewa[i]=lista[i];
    }

    for(unsigned int i=srodek; i<=rozmiar-1; i++)
    {
        prawa[i-srodek]=lista[i];
    }
    sortowaniePrzezScalanie(lewa);
    sortowaniePrzezScalanie(prawa);
    scal(lewa,prawa,lista);
}

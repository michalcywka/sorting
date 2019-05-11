int podziel(vector<int> &lista, int poczatek,int koniec)
{
    int piwot=lista[poczatek];
    int piwotIndeks=poczatek;
    for(int i=poczatek; i<koniec; i++)
    {
        int pomoc=lista[i];
        if(pomoc<=piwot)
        {
            swap(lista[i],lista[piwotIndeks]);
            piwotIndeks++;
        }
    }
     swap(lista[piwotIndeks],lista[koniec]);
     return piwotIndeks;
}

void sortujIntrospektywnie(vector<int> &lista, int poczatek, int koniec, int maksymalnaGlebokosc)
{
    int rozmiar = koniec-poczatek;

    if (rozmiar<16)
    {
        sortowaniePrzezWstawianie(lista, poczatek, koniec);
        return;
    }
    if (maksymalnaGlebokosc==0)
    {
        sortowaniePrzezKopcowanie(lista);
        return;
    }

    int piwot = podziel(lista, poczatek, koniec);
    sortujIntrospektywnie(lista, poczatek, piwot-1, maksymalnaGlebokosc - 1);
    sortujIntrospektywnie(lista, piwot + 1, koniec, maksymalnaGlebokosc - 1);
    return;
}

void sortowanieIntrospektywne(vector<int> &lista , int poczatek, int koniec)
{
    int maksymalnaGlebokosc = 2 * log(koniec-poczatek);
    sortujIntrospektywnie(lista, poczatek, koniec, maksymalnaGlebokosc);
    return;
}

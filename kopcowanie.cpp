
void maksKopiec(vector<int> &lista, int rozmiarKopca, int indeksRodzica)
{
    int maksIndeks=indeksRodzica;
    int leweDziecko=indeksRodzica*2+1;
    int praweDziecko=indeksRodzica*2+2;

    if(leweDziecko < rozmiarKopca && lista[leweDziecko] > lista[maksIndeks] )
    {
       maksIndeks=leweDziecko;
    }

    if(praweDziecko < rozmiarKopca && lista[praweDziecko] > lista[maksIndeks])
    {
        maksIndeks=praweDziecko;
    }

    if(maksIndeks != indeksRodzica)
    {
        swap(lista[maksIndeks],lista[indeksRodzica]);
        maksKopiec(lista,rozmiarKopca,maksIndeks);
    }


}

void sortowaniePrzezKopcowanie(vector<int> &lista)
{
    int rozmiar=lista.size();
    for(int i=rozmiar/2-1; i >= 0; i--)
    {
        maksKopiec(lista,rozmiar,i);
    }

    for(int i=rozmiar-1;i>0;i--)
    {
        swap(lista[0],lista[i]);
        rozmiar--;
        maksKopiec(lista, rozmiar, 0);
    }
}



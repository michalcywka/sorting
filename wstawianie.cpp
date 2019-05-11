

void sortowaniePrzezWstawianie(vector<int> &lista, int poczatek, int koniec)
{

    for (int i = poczatek+1; i <= koniec; i++)
    {
        int wartosc = lista[i];
        int j = i-1;


        while (j >= poczatek && lista[j] > wartosc)
        {
            lista[j+1] = lista[j];
            j = j-1;
        }
        lista[j+1] = wartosc;
   }
}

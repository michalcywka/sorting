int partycjonuj(vector<int> &tablica, int poczatek, int koniec) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x {
{
int x = tablica[poczatek];
int i = poczatek, j = koniec;
while (true)
{
    while (tablica[j] > x)
        j--;
while (tablica[i] < x)
    i++;
if (i < j)
 {
    swap(tablica[i],tablica[j]);
i++;
j--;
}
else
    return j;
}
}

void sortowanieSzybkie(vector<int> &tablica, int poczatek, int koniec) // sortowanie szybkie
{
int piwot;
if (poczatek < koniec) {
    piwot = partycjonuj(tablica, poczatek, koniec);// dzielimy tablice na dwie czesci; q oznacza punkt podzialu
    sortowanieSzybkie(tablica, poczatek, piwot);// wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
    sortowanieSzybkie(tablica, piwot + 1, koniec);// wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
}
}

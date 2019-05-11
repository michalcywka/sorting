#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

#include "szybkie.cpp"
#include "scalanie.cpp"
#include "kopcowanie.cpp"
#include "wstawianie.cpp"
#include "introspektywne.cpp"


int main()
{
    vector<int> x;
    vector<duration<double>> czasy;
    unsigned int rozmiarTablicy=500000;
    unsigned int posortowane=0.25*rozmiarTablicy;
    unsigned int nieposortowane=rozmiarTablicy-posortowane;
    for(int m=0; m<100; m++)
    {
        x.clear();
        for(unsigned int i=0; i<rozmiarTablicy; i++)
        {
            x.push_back(rand()%100);
        }
        /*sortowanieSzybkie(x,0,x.size()-1);
        for(unsigned int i=0; i<nieposortowane; i++)
        {
            x.push_back(rand()%100);
        }*/
        auto poczatek=high_resolution_clock::now();
        sortowanieSzybkie(x,0,x.size()-1);
        auto koniec=high_resolution_clock::now();
        duration<double> czas = koniec-poczatek;
        czasy.push_back(czas);
    }


    duration<double> srednia=czasy[0];

    for(unsigned int j=1; j<czasy.size(); j++)
    {
        srednia+=czasy[j];
    }

    cout << "Sredni czas obliczen: " << srednia.count()/czasy.size() << endl;
    return 0;
}





#include <iostream>
#include <vector>
#include <string>

using namespace std;
//! int promena
/*! pocet skoku */
int min_pocet_skoku = 0;
//! vektorova promena
/*! uklada indexy skoku */
vector<int>* min_skoky;
/** funkce vytvorit_vektor
* na vstupu textovyxy retezec prevede na cisla a vrati vektorove pole danych cisel
* \param vstup je typu string
* \return vector<int>*
*/
vector<int>* vytvorit_vektor(string vstup) {
    vector<int>* pole = new vector<int>;

    for (int i = 0; i < vstup.size(); i++) {
        pole->push_back(vstup[i] - '0');
    }

    return pole;
}
/** funkce vektor_obsahuje
* hleda v poli hodnotu a vraci pravda/nepravda zda se vyskytuje.
* \param pole je ukazatel na vektorove pole hodnot typu int
* \param hodnota je typu int
* \return bool
*/
bool vektor_obsahuje(vector<int>* pole, int hodnota) {
    for (int i = 0; i < pole->size(); i++) {
        if (pole->at(i) == hodnota) {
            return true;
        }
    }
    return false;
}
/** funkce indexy_shodnych_hodnot
* hleda v poli indexy stejne hodnoty a zaroven kontroluje, zda dany index už nebyl použit.
* \param pole je ukazatel na vektorove pole int hodnot
* \param startIndex je hodnota typu int
* \param cesta je ukazatel na vektorove pole int hodnot
* \return vector<int>*
*/
vector<int>* indexy_shodnych_hodnot(vector<int>* pole, int startIndex, vector<int>* cesta) {
    vector<int>* positions = new vector<int>;
    int size = pole->size();
    for (int i = 0; i < size; i++) {
        if (pole->at(i) == pole->at(startIndex) && i != startIndex && !vektor_obsahuje(cesta, i)) {
            positions->push_back(i);
        }
    }
    return positions;
}

/** funkce najit_nejkratsi_cestu 
* rekurzivne vypocitava nejkratsi moznou cestu
* \param pole je ukazatel na vektorove pole int hodnot
* \param pozice je int hodnota
* \param cesta je ukazatel na vektorove pole int hodnot
*/

void najit_nejkratsi_cestu(vector<int>* pole, int pozice, vector<int>* cesta) {
    if (pozice < pole->size() && !vektor_obsahuje(cesta, pozice) && cesta->size() < min_pocet_skoku) {
        vector<int>* nova_cesta = new vector<int>;
        for (int i = 0; i < cesta->size(); i++) {
            nova_cesta->push_back(cesta->at(i));
        }
        nova_cesta->push_back(pozice);
        if (pozice == pole->size() - 1) {
            min_pocet_skoku = nova_cesta->size() - 1;
            min_skoky = nova_cesta;
        }
        else {
            vector<int>* mozne_skoky = indexy_shodnych_hodnot(pole, pozice, nova_cesta);
            for (int i = 0; i < mozne_skoky->size(); i++) {
                najit_nejkratsi_cestu(pole, mozne_skoky->at(i), nova_cesta);
            }
            najit_nejkratsi_cestu(pole, pozice + 1, nova_cesta);
            if (pozice > 0) {
                najit_nejkratsi_cestu(pole, pozice - 1, nova_cesta);
            }
        }
    }
}

/** funkce klokan
* hlavni funkce, jejiž zavolanim se spustí celý projekt
* \param str je typu string
*/
void klokan(string str) {
    vector<int>* vektorove_pole = vytvorit_vektor(str);
    min_pocet_skoku = vektorove_pole->size();
    najit_nejkratsi_cestu(vektorove_pole, 0, new vector<int>());

    cout << "Nejrychlejsi cesta obsahuje: " << min_pocet_skoku << " skoku" << "\n";
    cout << "navstivene pozice: ";
    for (int i = 0; i < min_skoky->size(); i++) {
        cout << min_skoky->at(i) << " ";
    }
    cout << "\n\n";
}

int main(void)
{
    klokan("123415");

    klokan("123451");

    klokan("12345");

    klokan("180557994366325331615166132279");

    return 0;
}
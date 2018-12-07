#include <iostream>
#include <stdlib.h>
#include "Trees.h"

using namespace std;

int main(){
    Data *entrada, *saida;
    entrada = data(15, 03, 1999);
    saida = data(06, 12, 2018);


    Colaborador *col = Criar("Gabriel", entrada, saida);

    Nomes *nomes = NULL;
    addNomes(&nomes, col);

    Colaborador *col2 = Criar("Kelly", data(14,07,1999), data(15,01,2013));
    addNomes(&nomes, col2);
    addNomes(&nomes, col);

    printData(col->entrada);
    cout << "\n";
    return 1;
}

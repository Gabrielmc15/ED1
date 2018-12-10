#include <iostream>
#include <stdlib.h>
#include "lista.h"

using namespace std;

int main(){
    Lista *lista1 = criar();
    Lista *lista2 = criar();

    add(lista1, 2);
    add(lista1, 5);
    add(lista1, 1);
    add(lista1, 8);
    add(lista1, 2);
    add(lista1, 10);
    add(lista1, 5);

    add(lista2, 2);
    add(lista2, 5);
    add(lista2, 1);
    add(lista2, 8);
    add(lista2, 2);
    add(lista2, 10);
    add(lista2, 5);

    concatenar( &lista1, lista2);

    freeAll(&lista1);
    printLista(lista1);
}

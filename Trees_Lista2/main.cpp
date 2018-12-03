#include <iostream>
#include <stdlib.h>
#include "trees.h"

using namespace std;

int main(){
    int n;
    // criar 2 arvores iguais
    // desenho da arvore no arquivo "desenhoArvore"
    No* arv = criarNo(20);
    add(arv, 10);
    add(arv, 30);
    add(arv, 6);
    add(arv, 40);
    add(arv, 24);
    add(arv, 15);
    add(arv, 3);
    add(arv, 13);
    add(arv, 26);
    add(arv, 8);
    add(arv, 17);
    add(arv, 50);
    add(arv, 22);
    add(arv, 35);
    add(arv, 1);
    add(arv, 4);
    add(arv, 7);
    add(arv, 9);
    add(arv, 11);
    add(arv, 14);
    add(arv, 16);
    add(arv, 18);
    add(arv, 21);
    add(arv, 23);
    add(arv, 25);
    add(arv, 28);
    add(arv, 32);
    add(arv, 36);
    add(arv, 45);
    add(arv, 60);

    cout << abpNumNodesHeightH(arv);
    return 0;
}



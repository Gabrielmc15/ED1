#include <iostream>
#include "No.h"

using namespace std;

No::No(int n){
    this->dado = n;
    this->esq = NULL;
    this->dir = NULL;
}

No* No::getDir(){
    return this->dir;
}
No* No::getEsq(){
    return this->esq;
}
int No::getDado(){
    return this->dado;
}

void No::setDir(No* no){
    this->dir = no;
}
void No::setEsq(No* no){
    this->esq = no;
}

void No::setDado(int n){
    this->dado = n;
}



int No::teste(){
    cout << "teste";
    return 1;
}

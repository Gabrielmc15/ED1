#include <iostream>
#include <stdlib.h>
#include "lista.h"

using namespace std;

No *criarNo(int n){
    No *ret = new No;
    ret->dado = n;
    ret->prox = NULL;
    return ret;
}

Lista *criar(){
    Lista *ret = new Lista;
    ret->cab = NULL;
    ret->ult = ret->cab;
    ret->qtd = 0;
    return ret;
}
int add(Lista *lista, int n){
    if(lista!= NULL){
        No *novo = criarNo(n);
        if(lista->qtd == 0){
            lista->cab = novo;
            lista->ult = novo;
        }else if(lista->qtd > 0){
            lista->ult->prox = novo;
            lista->ult = novo;
        }
        lista->qtd++;
        return 1;
    }
    return 0;
}

void printLista(Lista *lista){
    if(lista != NULL){
        No *aux = lista->cab;
        while(aux != NULL){
            cout << aux->dado << " ";
            aux = aux->prox;
        }
    }
}

void concatenar(Lista **lista1, Lista *lista2){
    if(*lista1 != NULL && lista2 != NULL){
        (*lista1)->ult->prox = lista2->cab;
        (*lista1)->ult = lista2->ult;
        (*lista1)->qtd = (*lista1)->qtd + lista2->qtd;
    }
}


void freeAll(Lista **lista){
    if(*lista != NULL){
        No* aux1 = (*lista)->cab;
        No* aux2 = (*lista)->cab;
        while(aux1 != NULL){
            aux1 = NULL;
            cout << "removi\n";
            (*lista)->qtd --;
            aux2 = aux2->prox;
            aux1 = aux2;
        }
        *lista = NULL;
    }
}

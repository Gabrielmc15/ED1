#include <stdlib.h>
#include <iostream>
#include "trees.h"

using namespace std;

Node *criarNode(int value){
    Node *n1 = new Node[1];
    n1->dado = value;
    n1->prox = NULL;
    return n1;
}

Lista *criarLista(){
    Lista *l = new Lista[1];
    l->cab = NULL;
    l->ult = NULL;
    l->qtd = 0;
    return l;
}

int push(Lista *l, int value){
    Node *n1 = NULL;
    if(l != NULL){
        n1 = criarNode(value);
        if(l->qtd == 0){
            l->cab = n1;
            l->ult = n1;
        }else{
            l->ult->prox = n1;
            l->ult = n1;
        }
        l->qtd++;
        return 1;
    }
    return 0;
}

void imprimeLista(Lista* lista){
    if(lista != NULL){
        Node *aux = lista->cab;
        while(aux != NULL){
            cout << aux->dado << " ";
            aux = aux->prox;
        }
    }
}



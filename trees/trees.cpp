#include <iostream>
#include <stdlib.h>
#include "trees.h"
#include "lista.h"

using namespace std;

No *criarNo(int n){
    No* ret = new No;
    ret->dado = n;
    ret->dir = NULL;
    ret->esq = NULL;
    ret->pai = NULL;
    return ret;
}

int add(No *no, int n){
    if(no != NULL){
        if(n < no->dado){
            //continua a funcao aqui adiciona na esquerda
            if(no->esq == NULL){
                no->esq = criarNo(n);
                no->esq->pai = no;
                return 1;
            }
            else
                return add(no->esq, n);
        }
        if(n >= no->dado){
            //continua a funcao aqui adiciona na direita
            if(no->dir == NULL){
                no->dir = criarNo(n);
                no->dir->pai = no;
                return 1;
            }
            else
                return add(no->dir, n);
        }
    }
    criarNo(n);
    return 1;
}

void emOrdem(No* no){
    if(no != NULL && no->dado != NULL){
        emOrdem(no->esq);
        cout << no->dado << " ";
        emOrdem(no->dir);
    }
}

No *busca(No* no,int n){
    if(n < no->dado)//esquerda
        return busca(no->esq, n);
    if(n > no->dado)//direita
        return busca(no->dir, n);
    if(n == no->dado)
        return no;
}

No *minimo(No* no){
    No* aux = no;
    while(aux->esq != NULL)
        aux = aux->esq;
    return aux;
}

No* maximo(No* no){
    No* aux = no;
    while(aux->dir != NULL)
        aux = aux->dir;
    return aux;
}

int remover(No* no, int n){
    if(no!= NULL){
        No* aux = busca(no, n);
        if(aux->dir == NULL && aux->esq == NULL){ //caso 1 nenhum filho
            aux->dado = NULL;
            aux = NULL;
            return 1;
        }
        if(aux->dir == NULL && aux->esq != NULL){ //caso 2: 1 filho a esquerda
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->esq;
                aux->esq->pai = aux->pai;
                aux = NULL;
            }else if(aux == aux->pai->dir){ //filho a direi ta do pai
                aux->pai->dir = aux->esq;
                aux->esq->pai = aux->pai;
                aux = NULL;
            }
        }else if(aux->esq == NULL && aux->dir != NULL){ //caso 2: 1 filho a direita
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->dir;
                aux->dir->pai = aux->pai;
                aux = NULL;
            }else if(aux == aux->pai->dir){ // filho a direita do pai
                aux->pai->dir = aux->dir;
                aux->dir->pai = aux->pai;
                aux = NULL;
            }
        }
        if(aux->dir != NULL && aux->esq != NULL){// caso 3: tem 2 filhos (menor valor do da direita)
            int aux2 = minimo(aux->dir)->dado;
            remover(no, aux2);
            aux->dado = aux2;
        }
        return 1;
    }
    return 0;
}

void imprimeFolhas(No* no){
    if(no != NULL){
        imprimeFolhas(no->esq);
        if(no->esq == NULL && no->dir == NULL)
            cout << no->dado << " ";
        imprimeFolhas(no->dir);
    }
}

void imprimeNivel(No* no, int n){
    if(no != NULL){
        if(n == 0)
            cout << no->dado << " ";
        imprimeNivel(no->esq, n-1);
        imprimeNivel(no->dir, n-1);
    }
}

void listaArvoreAux(No* no, Lista* lista){
    if(no != NULL){
        listaArvoreAux(no->esq, lista);
        push(lista, no->dado);
        listaArvoreAux(no->dir, lista);
    }
}

Lista* listaArvore(No* no){
    Lista* lista = criarLista();
    listaArvoreAux(no, lista);
    return lista;
}

int ocorrencias(No* no, int n){
    if (no != NULL){
        int cont = 0,i, j;
        Lista* lista = listaArvore(no);
        Node*aux = lista->cab;
        while(aux != NULL){
            if(aux->dado == n)
                cont++;
            aux = aux->prox;
        }
        return cont;
    }
}

int arvoresIguais(No* no1, No* no2){

}

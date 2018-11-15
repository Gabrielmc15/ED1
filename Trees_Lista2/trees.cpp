#include <iostream>
#include <stdlib.h>
#include "trees.h"

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

void imprimeFolhas(No* no){    ///funçao da atividade: questao 1
    if(no != NULL){
        imprimeFolhas(no->esq);
        if(no->esq == NULL && no->dir == NULL)
            cout << no->dado << " ";
        imprimeFolhas(no->dir);
    }
}

void imprimeNivel(No* no, int n){       ///funçao da atividade: questao 2
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

int arvoresIguais(No* no1, No* no2){              ///funçao da atividade : questao 3
    Lista *lista1 = listaArvore(no1);
    Lista *lista2 = listaArvore(no2);
    int ret = 0;
    if(lista1->qtd == lista2->qtd){
        while(lista1->cab != NULL &&  lista2->cab != NULL){// como a funçao listaArvore() sempre retorna uma lista ordenada é so comparar elemento por elemento
            if(lista1->cab->dado == lista2->cab->dado)
                ret = 1;
            else ret = 0;
            lista1->cab = lista1->cab->prox;
            lista2->cab = lista2->cab->prox;
        }
    }
    return ret;
}


int ocorrencias(No* no, int n){           ///funçao da atividade: questao 4
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

///fixaçao 2

int addInv(No *no, int n){
    if(no != NULL){
        if(n <= no->dado){
            //continua a funcao aqui adiciona na esquerda
            if(no->dir == NULL){
                no->dir = criarNo(n);
                no->dir->pai = no;
                return 1;
            }
            else
                return addInv(no->dir, n);
        }
        if(n > no->dado){
            //continua a funcao aqui adiciona na direita
            if(no->esq == NULL){
                no->esq = criarNo(n);
                no->esq->pai = no;
                return 1;
            }
            else
                return addInv(no->esq, n);
        }
    }
    no->dado = n;
    no->dir = NULL;
    no->esq = NULL;
    no->pai = NULL;
    return 1;
}

int altura(No* no){
    if (no == NULL)
      return -1; // altura da árvore vazia
    else {
      int he = altura (no->esq);
      int hd = altura (no->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

void espelharAux(No* no, No* ret, int n){
    if(no != NULL){
        if(n == 0){
            addInv(ret, no->dado);
        }
        espelharAux(no->esq, ret, n-1);
        espelharAux(no->dir, ret, n-1);

    }
}

No* espelhar(No* no){
    int h = altura(no);
    int i;
    No* ret = criarNo(no->dado);
    for(i=1; i<= h; i++){
        espelharAux(no, ret, i);
    }
    return ret;
}

#include <iostream>
#include <stdlib.h>
#include "Trees.h"

using namespace std;

No *criarNo(string nome, int matricula, Data entrada, Data saida){
    No* ret = new No;
    ret->nome = nome;
    ret->matricula = matricula;
    ret->entrada = entrada;
    ret->saida = saida;
    ret->dir = NULL;
    ret->esq = NULL;
    ret->pai = NULL;
    return ret;
}

int add(No *no, string nome, int matricula, Data entrada, Data saida){
    if(no != NULL){
        if(matricula < no->matricula){
            //continua a funcao aqui adiciona na esquerda
            if(no->esq == NULL){
                no->esq = criarNo( nome, matricula, entrada, saida);
                no->esq->pai = no;
                return 1;
            }
            else
                return add(no->esq, nome, matricula, entrada, saida);
        }
        if(matricula >= no->matricula){
            //continua a funcao aqui adiciona na direita
            if(no->dir == NULL){
                no->dir = criarNo(nome, matricula, entrada, saida);
                no->dir->pai = no;
                return 1;
            }
            else
                return add(no->dir, nome, matricula, entrada, saida);
        }
    }
    criarNo(nome, matricula, entrada, saida);
    return 1;
}

/*void emOrdem(No* no){
    if(no != NULL && no->dado != NULL){
        emOrdem(no->esq);
        cout << no->dado << " ";
        emOrdem(no->dir);
    }
}*/

No *buscaMatricula(No* no,int matricula){
    if(matricula < no->matricula)//esquerda
        return buscaMatricula(no->esq, matricula);
    if(matricula > no->matricula)//direita
        return buscaMatricula(no->dir, matricula);
    if(matricula == no->matricula)
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

/*int removerMatricula(No* no, int n){
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
}*/

/*void imprimeFolhas(No* no){    ///funçao da atividade: questao 1
    if(no != NULL){
        imprimeFolhas(no->esq);
        if(no->esq == NULL && no->dir == NULL)
            //cout << no->dado << " ";
        imprimeFolhas(no->dir);
    }
}*/

/*void imprimeNivel(No* no, int n){       ///funçao da atividade: questao 2
    if(no != NULL){
        //if(n == 0)
            //cout << no->dado << " ";
        imprimeNivel(no->esq, n-1);
        imprimeNivel(no->dir, n-1);
    }
}*/

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


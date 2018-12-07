#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Trees.h"

using namespace std;

Data *data(int dia, int mes, int ano){
    Data *ret = new Data;
    ret->dia = dia;
    ret->mes = mes;
    ret->ano = ano;
    return ret;
}


void printData(Data *data){
    if(data != NULL){
        cout << data->dia << "/" << data->mes << "/" << data->ano;
    }
}

int dataComp(Data *data1, Data *data2){
     if(data1 != NULL && data2 != NULL){
        if(data1->ano <= data2->ano)
            return -1;
        if(data1->ano > data2->ano)
            return 1;
        if(data1->ano == data2->ano){
            if(data1->mes <= data2->mes)
                return -1;
            if(data1->mes > data2->mes)
                return 1;
            if(data1->mes == data2->mes){
                if(data1->dia <= data2->dia)
                    return -1;
                if(data1->dia > data2->dia)
                    return 1;
                if(data1->dia == data2->dia)
                    return 0;
            }
        }
    }
}

Saidas *criarSaidas(Colaborador *col){
    Saidas *ret = new Saidas;
    ret->col = col;
    ret->dir = NULL;
    ret->esq = NULL;
    ret->pai = NULL;
}

Entradas *criarEntradas(Colaborador *col){
    Entradas *ret = new Entradas;
    ret->col = col;
    ret->dir = NULL;
    ret->esq = NULL;
    ret->pai = NULL;
}

Nomes *criarNomes(Colaborador *col){
    Nomes *ret = new Nomes;
    ret->col = col;
    ret->dir = NULL;
    ret->esq = NULL;
    ret->pai = NULL;
}

Colaborador *Criar(string nome, Data *entrada, Data *saida){
    srand(time(NULL));
    Colaborador *ret = new Colaborador;
    ret->nome = nome;
    ret->entrada = entrada;
    ret->saida = saida;
    ret->matricula = rand()% 1001 + 1000;
    return ret;
}

int addNomes(Nomes **nomes, Colaborador *col){
    if(*nomes == NULL){
        *nomes = new Nomes;
        (*nomes)->col = col;
        (*nomes)->esq = NULL;
        (*nomes)->dir = NULL;
        (*nomes)->pai = NULL;
        cout << "adicionei no nulo\n";
        return 1;
    }
    if(*nomes != NULL){
        if(col->nome <= (*nomes)->col->nome){
            if((*nomes)->esq == NULL){
                (*nomes)->esq = criarNomes(col);
                (*nomes)->esq->pai = *nomes;
                cout << "adicionei na esquerda\n";
                return 1;
            }
            else
                return addNomes((&(*nomes)->esq), col);
        }
        if(col->nome > (*nomes)->col->nome){
            if((*nomes)->dir == NULL){
                (*nomes)->dir = criarNomes(col);
                (*nomes)->dir->pai = *nomes;
                cout << "adicionei na direita\n";
                return 1;
            }
            else
                return addNomes((&(*nomes)->dir), col);
        }
    }
}

/*int addEntradas(Entradas **entradas, Colaborador *col){
    if(*entradas == NULL){
        *entradas = new Entradas;
        (*entradas)->col = col;
        (*entradas)->esq = NULL;
        (*entradas)->dir = NULL;
        (*entradas)->pai = NULL;
        cout << "adicionei no nulo\n";
        return 1;
    }
    if(*entradas != NULL){
        if(dataComp(col->entrada, (*entradas)->col->entrada) <= 0)){ // erro qui
            if((*entradas)->esq == NULL){
                (*entradas)->esq = criarEntradas(col);
                (*entradas)->esq->pai = *entradas;
                cout << "adicionei na esquerda\n";
                return 1;
            }
            else
                return addEntradas((&(*entradas)->esq), col);
        }
        if(dataComp(col->entrada, (*entradas)->col->entrada) > 0)){
            if((*entradas)->dir == NULL){
                (*entradas)->dir = criarEntradas(col);
                (*entradas)->dir->pai = *entradas;
                cout << "adicionei na direita\n";
                return 1;
            }
            else
                return addEntradas((&(*entradas)->dir), col);
        }
    }
}

int addSaidas(Saidas **entradas, Colaborador *col){
    if(*entradas == NULL){
        *entradas = new Entradas;
        (*entradas)->col = col;
        (*entradas)->esq = NULL;
        (*entradas)->dir = NULL;
        (*entradas)->pai = NULL;
        cout << "adicionei no nulo\n";
        return 1;
    }
    if(*entradas != NULL){
        if(dataComp(col->entrada, (*entradas)->col->entrada <= 0)){
            if((*entradas)->esq == NULL){
                (*entradas)->esq = criarEntradas(col);
                (*entradas)->esq->pai = *entradas;
                cout << "adicionei na esquerda\n";
                return 1;
            }
            else
                return addEntradas((&(*entradas)->esq), col);
        }
        if(dataComp(col->entrada, (*entradas)->col->entrada > 0)){
            if((*entradas)->dir == NULL){
                (*entradas)->dir = criarEntradas(col);
                (*entradas)->dir->pai = *entradas;
                cout << "adicionei na direita\n";
                return 1;
            }
            else
                return addEntradas((&(*entradas)->dir), col);
        }
    }
}



int add(Colaborador *col){

}*/

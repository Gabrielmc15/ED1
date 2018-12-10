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
        if(data1->ano < data2->ano)
            return -1;
        if(data1->ano > data2->ano)
            return 1;
        if(data1->ano == data2->ano){
            if(data1->mes < data2->mes)
                return -1;
            if(data1->mes > data2->mes)
                return 1;
            if(data1->mes == data2->mes){
                if(data1->dia < data2->dia)
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
        return 1;
    }
    if(*nomes != NULL){
        if(col->nome <= (*nomes)->col->nome){
            if((*nomes)->esq == NULL){
                (*nomes)->esq = criarNomes(col);
                (*nomes)->esq->pai = *nomes;
                return 1;
            }
            else
                return addNomes((&(*nomes)->esq), col);
        }
        if(col->nome > (*nomes)->col->nome){
            if((*nomes)->dir == NULL){
                (*nomes)->dir = criarNomes(col);
                (*nomes)->dir->pai = *nomes;
                return 1;
            }
            else
                return addNomes((&(*nomes)->dir), col);
        }
    }
}
int addEntradas(Entradas **entradas, Colaborador *col){
    if(*entradas == NULL){
        *entradas = new Entradas;
        (*entradas)->col = col;
        (*entradas)->esq = NULL;
        (*entradas)->dir = NULL;
        (*entradas)->pai = NULL;
        return 1;
    }
    if(*entradas != NULL){
        if(dataComp(col->entrada, ((*entradas)->col->entrada)) <= 0){
            if((*entradas)->esq == NULL){
                (*entradas)->esq = criarEntradas(col);
                (*entradas)->esq->pai = *entradas;
                return 1;
            }
            else
                return addEntradas((&(*entradas)->esq), col);
        }
        if(dataComp(col->entrada, ((*entradas)->col->entrada)) > 0){
            if((*entradas)->dir == NULL){
                (*entradas)->dir = criarEntradas(col);
                (*entradas)->dir->pai = *entradas;
                return 1;
            }
            else
                return addEntradas((&(*entradas)->dir), col);
        }
    }
}
int addSaidas(Saidas **saidas, Colaborador *col){
    if(*saidas == NULL){
        *saidas = new Saidas;
        (*saidas)->col = col;
        (*saidas)->esq = NULL;
        (*saidas)->dir = NULL;
        (*saidas)->pai = NULL;
        return 1;
    }
    if(*saidas != NULL){
        if(dataComp(col->saida, ((*saidas)->col->saida)) <= 0){
            if((*saidas)->esq == NULL){
                (*saidas)->esq = criarSaidas(col);
                (*saidas)->esq->pai = *saidas;
                return 1;
            }
            else
                return addSaidas((&(*saidas)->esq), col);
        }
        if(dataComp(col->saida, ((*saidas)->col->saida)) > 0){
            if((*saidas)->dir == NULL){
                (*saidas)->dir = criarSaidas(col);
                (*saidas)->dir->pai = *saidas;
                return 1;
            }
            else
                return addSaidas((&(*saidas)->dir), col);
        }
    }
}
int add(Colaborador *col, Nomes **nomes, Entradas **entradas, Saidas **saidas){
    if(col != NULL){
        addNomes(&(*nomes), col);
        addEntradas(&(*entradas), col);
        addSaidas(&(*saidas), col);
        return 1;
    }
    return 0;
}

Nomes *minimoNomes(Nomes* nomes){
    Nomes* aux = nomes;
    while(aux->esq != NULL)
        aux = aux->esq;
    return aux;
}
Entradas *minimoEntradas(Entradas* entradas){
    Entradas* aux = entradas;
    while(aux->esq != NULL)
        aux = aux->esq;
    return aux;
}
Saidas *minimoSaidas(Saidas* saidas){
    Saidas* aux = saidas;
    while(aux->esq != NULL)
        aux = aux->esq;
    return aux;
}

void preOrdemNomes(Nomes *nomes){
    if(nomes != NULL){
        cout << nomes->col->nome << " ";
        preOrdemNomes(nomes->esq);
        preOrdemNomes(nomes->dir);
    }
}
void emOrdemNomes(Nomes *nomes){
    if(nomes != NULL && nomes->col != NULL && nomes->col ->nome != ""){
        emOrdemNomes(nomes->esq);
        cout << nomes->col->nome << " ";
        emOrdemNomes(nomes->dir);
    }
}
void posOrdemNomes(Nomes *nomes){
    if(nomes != NULL){
        posOrdemNomes(nomes->esq);
        posOrdemNomes(nomes->dir);
        cout << nomes->col->nome << " ";
    }
}

void preOrdemEntradas(Entradas *entradas){
    if(entradas != NULL){
        printData(entradas->col->entrada);
        cout << " ";
        preOrdemEntradas(entradas->esq);
        preOrdemEntradas(entradas->dir);
    }
}
void emOrdemEntradas(Entradas *entradas){
    if(entradas != NULL){
        emOrdemEntradas(entradas->esq);
        printData(entradas->col->entrada);
        cout << " ";
        emOrdemEntradas(entradas->dir);
    }
}
void posOrdemEntradas(Entradas *entradas){
    if(entradas != NULL){
        posOrdemEntradas(entradas->esq);
        posOrdemEntradas(entradas->dir);
        printData(entradas->col->entrada);
        cout << " ";
    }
}

void preOrdemSaidas(Saidas *saidas){
    if(saidas != NULL){
        printData(saidas->col->saida);
        cout << " ";
        preOrdemSaidas(saidas->esq);
        preOrdemSaidas(saidas->dir);
    }
}
void emOrdemSaidas(Saidas *saidas){
    if(saidas != NULL){
        emOrdemSaidas(saidas->esq);
        printData(saidas->col->saida);
        cout << " ";
        emOrdemSaidas(saidas->dir);
    }
}
void posOrdemSaidas(Saidas *saidas){
    if(saidas != NULL){
        posOrdemSaidas(saidas->esq);
        posOrdemSaidas(saidas->dir);
        printData(saidas->col->saida);
        cout << " ";
    }
}

Nomes *buscarNomes(Nomes *nomes, string nome){
    if(nomes != NULL){
        if(nome < nomes->col->nome)
            return buscarNomes(nomes->esq, nome);
        if(nome > nomes->col->nome)
            return buscarNomes(nomes->dir, nome);
        if(nome == nomes->col->nome)
            return nomes;
    }
    return NULL;
}
Entradas *buscarEntradas(Entradas *entradas, Data *entrada){
    if(entradas != NULL){
        if(dataComp(entrada, entradas->col->entrada) < 0)
            return buscarEntradas(entradas->esq, entrada);
        if(dataComp(entrada, entradas->col->entrada) > 0)
            return buscarEntradas(entradas->dir, entrada);
        if(dataComp(entrada, entradas->col->entrada) == 0)
            return entradas;
    }
    return NULL;
}
Saidas *buscarSaidas(Saidas *saidas, Data* saida){
    if(saidas != NULL){
        if(dataComp(saida, saidas->col->saida) < 0)
            return buscarSaidas(saidas->esq, saida);
        if(dataComp(saida, saidas->col->saida) > 0)
            return buscarSaidas(saidas->dir, saida);
        if(dataComp(saida, saidas->col->saida) == 0)
            return saidas;
        return NULL;
    }
}

int removerNomes(Nomes* nomes, string nome){
    if(nomes != NULL){
        Nomes* aux = buscarNomes(nomes, nome);
        if(aux->dir == NULL && aux->esq == NULL){
            aux->col->nome = "";
            aux->col->matricula = NULL;
            aux->col->entrada = NULL;
            aux->col->saida = NULL;
            aux->col = NULL;
            aux->pai = NULL;
            aux = NULL;
            return 1;
        }
        if(aux->dir == NULL && aux->esq != NULL){
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->esq;
                aux->esq->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }else if(aux == aux->pai->dir){ //filho a direi ta do pai
                aux->pai->dir = aux->esq;
                aux->esq->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }
        }else if(aux->esq == NULL && aux->dir != NULL){ //caso 2: 1 filho a direita
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->dir;
                aux->dir->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }else if(aux == aux->pai->dir){ // filho a direita do pai
                aux->pai->dir = aux->dir;
                aux->dir->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }
        }
        if(aux->dir != NULL && aux->esq != NULL){// caso 3: tem 2 filhos (menor valor do da direita)
            Nomes *aux2 = minimoNomes(aux->dir);
            aux->col->entrada->dia = aux2->col->entrada->dia;
            aux->col->entrada->mes = aux2->col->entrada->mes;
            aux->col->entrada->ano = aux2->col->entrada->ano;
            aux->col->saida->dia = aux2->col->saida->dia;
            aux->col->saida->mes = aux2->col->saida->mes;
            aux->col->saida->ano = aux2->col->saida->ano;
            aux->col->nome = aux2->col->nome;
            aux->col->matricula = aux2->col->matricula;
            removerNomes(nomes, aux2->col->nome);
        }
    }
}
int removerEntradas(Entradas* entradas, Data *entrada){
    if(entradas != NULL){
        Entradas* aux = buscarEntradas(entradas, entrada);
        if(aux->dir == NULL && aux->esq == NULL){
            aux->col->nome = "";
            aux->col->matricula = NULL;
            aux->col->entrada = NULL;
            aux->col->saida = NULL;
            aux->col = NULL;
            aux->pai = NULL;
            aux = NULL;
            return 1;
        }
        if(aux->dir == NULL && aux->esq != NULL){
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->esq;
                aux->esq->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }else if(aux == aux->pai->dir){ //filho a direita do pai
                aux->pai->dir = aux->esq;
                aux->esq->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }
        }else if(aux->esq == NULL && aux->dir != NULL){ //caso 2: 1 filho a direita
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->dir;
                aux->dir->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }else if(aux == aux->pai->dir){ // filho a direita do pai
                aux->pai->dir = aux->dir;
                aux->dir->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }
        }
        if(aux->dir != NULL && aux->esq != NULL){// caso 3: tem 2 filhos (menor valor do da direita)
            Entradas *aux2 = minimoEntradas(aux->dir);
            aux->col->entrada->dia = aux2->col->entrada->dia;
            aux->col->entrada->mes = aux2->col->entrada->mes;
            aux->col->entrada->ano = aux2->col->entrada->ano;
            aux->col->saida->dia = aux2->col->saida->dia;
            aux->col->saida->mes = aux2->col->saida->mes;
            aux->col->saida->ano = aux2->col->saida->ano;
            aux->col->nome = aux2->col->nome;
            aux->col->matricula = aux2->col->matricula;
            removerEntradas(entradas, aux2->col->entrada);
        }
    }
}
int removerSaidas(Saidas* saidas, Data *saida){
    if(saidas != NULL){
        Saidas* aux = buscarSaidas(saidas, saida);
        if(aux->dir == NULL && aux->esq == NULL){
            aux->col->nome = "";
            aux->col->matricula = NULL;
            aux->col->entrada = NULL;
            aux->col->saida = NULL;
            aux->col = NULL;
            aux->pai = NULL;
            aux = NULL;
            return 1;
        }
        if(aux->dir == NULL && aux->esq != NULL){
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->esq;
                aux->esq->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }else if(aux == aux->pai->dir){ //filho a direita do pai
                aux->pai->dir = aux->esq;
                aux->esq->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }
        }else if(aux->esq == NULL && aux->dir != NULL){ //caso 2: 1 filho a direita
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->dir;
                aux->dir->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }else if(aux == aux->pai->dir){ // filho a direita do pai
                aux->pai->dir = aux->dir;
                aux->dir->pai = aux->pai;
                aux->col->nome = "";
                aux->col->matricula = NULL;
                aux->col->entrada = NULL;
                aux->col->saida = NULL;
                aux->col = NULL;
                aux->pai = NULL;
                aux = NULL;
            }
        }
        if(aux->dir != NULL && aux->esq != NULL){// caso 3: tem 2 filhos (menor valor do da direita)
            Saidas *aux2 = minimoSaidas(aux->dir);
            aux->col->entrada->dia = aux2->col->entrada->dia;
            aux->col->entrada->mes = aux2->col->entrada->mes;
            aux->col->entrada->ano = aux2->col->entrada->ano;
            aux->col->saida->dia = aux2->col->saida->dia;
            aux->col->saida->mes = aux2->col->saida->mes;
            aux->col->saida->ano = aux2->col->saida->ano;
            aux->col->nome = aux2->col->nome;
            aux->col->matricula = aux2->col->matricula;
            removerSaidas(saidas, aux2->col->saida);
        }
    }
}

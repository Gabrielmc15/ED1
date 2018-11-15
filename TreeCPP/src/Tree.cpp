#include "Tree.h"
#include <iostream>
#include "No.h"

using namespace std;

Tree::Tree(int n){
    this->root = new No(n);
}

void Tree::addAux(No* no, int n){
    if(n < no->getDado()){
        //continua a funcao aqui adiciona na esquerda
        if(no->getEsq() == NULL)
            no->setEsq(new No(n));
        else
            addAux(no->getEsq(), n);
    }
    if(n >= no->getDado()){
        //continua a funcao aqui adiciona na direita
        if(no->getDir() == NULL)
            no->setDir(new No(n));
        else
            addAux(no->getDir(), n);
    }
}

void Tree::add(int n){
    addAux(this->root, n);
}

void Tree::emOrdemAux(No* no){
    if(no != NULL){
        emOrdemAux(no->getEsq());
        cout << no->getDado() << " ";
        emOrdemAux(no->getDir());
    }
}

void Tree::emOrdem(){
    emOrdemAux(this->root);
}

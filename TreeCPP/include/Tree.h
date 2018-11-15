#ifndef TREE_H
#define TREE_H
#include "No.h"

class Tree{
    private:
        No* root;
        void addAux(No* no, int n);
        void emOrdemAux(No* no);

    public:
        Tree(int n);
        void add(int n);
        void emOrdem();
};

#endif // TREE_H

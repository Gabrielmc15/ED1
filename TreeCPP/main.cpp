#include <iostream>
#include <stdlib.h>
#include "No.h"
#include "Tree.h"

using namespace std;

int main(){
    Tree *arv = new Tree(20);
    arv->add(10);
    arv->add(30);
    arv->add(5);
    arv->add(40);
    arv->add(23);
    arv->add(15);
    arv->add(1);
    arv->add(13);
    arv->add(25);
    arv->add(6);
    arv->add(17);
    arv->add(50);
    arv->add(21);
    arv->add(43);

    arv->emOrdem();
    return 0;
}



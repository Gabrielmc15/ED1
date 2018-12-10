typedef struct _No_{
    int dado;
    _No_ *prox;
}No;
typedef struct _Lista_{
    No *cab;
    No *ult;
    int qtd;
}Lista;

No *criarNo(int n);
Lista *criar();
int add(Lista *lista, int n);

void printLista(Lista *lista);

void concatenar(Lista **lista1, Lista *lista2);

void freeAll(Lista **lista);

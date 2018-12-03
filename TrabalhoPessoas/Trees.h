using namespace std;

typedef struct _Data_{
    int dia;
    int mes;
    int ano;
}Data;
typedef struct _No_{
    //nome, matrícula, data de entrada e data de saida
    string nome;
    int matricula;
    Data entrada; // vai ser struct
    Data saida; // vai ser struct
    _No_ *esq, *dir, *pai;
}No;

typedef struct _node_{
    int dado;
    _node_ *prox;
} Node;

typedef struct _lista_{
    Node *cab;
    Node *ult;
    int qtd;
} Lista;


/**
No *criarNo(int n)- cria uma arvore
@param n- inteiro que sera a raiz da arvore
@return uma arvore alocada
*/
No *criarNo(string nome, int matricula, Data entrada, Data saida);

/**
int add(No* no, int n)- adiciona um dado em uma arvore ja alocada
@param *no- a arvore em que deseja adicionar
@param n-o dado que sera adicionado na arvore
@return- 1 sucesso, 0 falha
*/
int add(No *no, string nome, int matricula, Data entrada, Data saida);

/**
void emOrdem(No* no)- imprime a arvore em ordem crescente
@param *no- a arvore que deseja imprimir
*/
//void emOrdem(No* no);

/**
No *minimo(No* no)- retorna o menor dado da arvore(ultimo a esquerda)
@param *no- arvore
@return- no que contem o menor dado
*/
No *minimo(No* no);

/**
No *maximo(No* no)- retorna o maior dado da arvore(ultimo a direita)
@param *no- arvore
@return- no que contem o menor dado
*/
No* maximo(No* no);

/**
int remover(No* no, int n)- remove o dado da arvore
@param *no- arvore
@param n- dado a ser removido
@return- 1 sucesso, 0 falha
*/
//int remover(No* no, int n);

/**
No *busca(No* no, int n)-funcao de busca na arvore
@param *no- arvore
@param n- o valor que deseja buscar
@return- o no com o dado da busca em caso de sucesso, NULL em caso de falha
*/
No *buscaMatricula(No* no,int matricula);

///funcoes das atividades//////////////////////////////////////////////////////

//void imprimeFolhas(No* no);

//void imprimeNivel(No* no, int n);

int altura(No* no);






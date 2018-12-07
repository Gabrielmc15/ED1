using namespace std;

/*Um laboratório de pesquisa deseja manter informações de seus colaboradores de maneira organizada e de fácil recuperação.
A ideia é se poder cadastrar as informações dos colaboradores em múltiplas árvores que possam ser consultadas com múltiplus
objetivos.
A principio, as árvores terão apenas as informações de nome, matrícula, data de entrada e data de saida de cada colaborador.
E as consultas deverão ser realizadas por nome, data de entrada, data de saída.
As operações que devem ser implementadas:
- cadastro de colaborador
- edição de colaborador
- consulta de colaborador --> por 1 dos critérios
* Você deverá ter 1 árvore para cada parâmetro de consulta
** Mas não deve ser alocado um novo colaborador para cada árvore. O mesmo deve ser compartilhado.
*/

typedef struct _Data_{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct _Colaborador_{
    int matricula;
    string nome;
    Data *entrada;
    Data *saida;
    int qtd;
}Colaborador;

typedef struct _Nomes_{
    //nome, matrícula, data de entrada e data de saida
    Colaborador *col;
    _Nomes_ *esq, *dir, *pai;
}Nomes;

typedef struct _Entradas_{
    //nome, matrícula, data de entrada e data de saida
    Colaborador *col;
    _Entradas_ *esq, *dir, *pai;
}Entradas;

typedef struct _Saidas_{
    //nome, matrícula, data de entrada e data de saida
    Colaborador *col;
    //Dados* col;
    _Saidas_ *esq, *dir, *pai;
}Saidas;

Data *data(int dia, int mes, int ano);

void printData(Data *data);

int dataComp(Data *data1, Data *data2);

Colaborador *Criar(string nome, Data *entrada, Data *saida);

Saidas *criarSaidas(Colaborador *col);

Entradas *criarEntradas(Colaborador *col);

Nomes *criarNomes(Colaborador *col);

int addNomes(Nomes **nomes, Colaborador *col);

int addEntradas(Entradas *entrada, Colaborador *col);

int addSaidas(Saidas *saida, Colaborador *col);

int add(Colaborador *col);

/**
Arv *criarArv(int n)- cria uma arvore
@param n- inteiro que sera a raiz da arvore
@return uma arvore alocada
*/

//Arv *criarArv(string nome, int matricula, Data entrada, Data saida);


/** \brief
 *
 * \param arv Arv*
 * \param nome string
 * \param matricula int
 * \param entrada Data
 * \param saida Data
 * \return int
 *
 */
//int add(Arv *arv, string nome, int matricula, Data entrada, Data saida);

/**
void emOrdem(Arv* arv)- imprime a arvore em ordem crescente
@param *arv- a arvore que deseja imprimir
*/
//void preOrdem(Arv* arv);
//void emOrdem(Arv* arv);
//void posOrdem(Arv* arv);

/**
Arv *minimo(Arv* arv)- retorna o menor dado da arvore(ultimo a esquerda)
@param *arv- arvore
@return- arv que contem o menor dado
*/
//Arv *minimo(Arv* arv);

/**
Arv *maximo(Arv* arv)- retorna o maior dado da arvore(ultimo a direita)
@param *arv- arvore
@return- arv que contem o menor dado
*/
//Arv* maximo(Arv* arv);

/**
int remover(Arv* arv, int n)- remove o dado da arvore
@param *arv- arvore
@param n- dado a ser removido
@return- 1 sucesso, 0 falha
*/
//int remover(Arv* arv, int n);

/**
Arv *busca(Arv* arv, int n)-funcao de busca na arvore
@param *arv- arvore
@param n- o valor que deseja buscar
@return- o arv com o dado da busca em caso de sucesso, NULL em caso de falha
*/
//Arv *buscaMatricula(Arv* arv,int matricula);

///funcoes das atividades//////////////////////////////////////////////////////

//void imprimeFolhas(Arv* arv);

//void imprimeNivel(Arv* arv, int n);

//int altura(Arv* arv);






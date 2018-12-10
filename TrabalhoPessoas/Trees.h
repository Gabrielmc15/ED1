using namespace std;

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
    Colaborador *col;
    _Nomes_ *esq, *dir, *pai;
}Nomes;
typedef struct _Entradas_{
    Colaborador *col;
    _Entradas_ *esq, *dir, *pai;
}Entradas;
typedef struct _Saidas_{
    Colaborador *col;
    _Saidas_ *esq, *dir, *pai;
}Saidas;

//Funcoes pra trabalhar com as datas
Data *data(int dia, int mes, int ano); // aloca uma Data
void printData(Data *data); //imprime uma data
int dataComp(Data *data1, Data *data2); //compara duas datas

Colaborador *Criar(string nome, Data *entrada, Data *saida);// Cria um colabolador
Saidas *criarSaidas(Colaborador *col);//Cria uma arvores de datas de saida
Entradas *criarEntradas(Colaborador *col);//Cria uma arvores de datas de entrada
Nomes *criarNomes(Colaborador *col);//Cria uma arvore de nomes

int add(Colaborador *col, Nomes **nomes, Entradas **entradas, Saidas **saidas); //Adiciona colaborador nas 3 arvores
int addNomes(Nomes **nomes, Colaborador *col);//Adiciona colaborador na arvore de nomes
int addEntradas(Entradas **entradas, Colaborador *col);//Adiciona colaborador na arvore de entradas
int addSaidas(Saidas **saidas, Colaborador *col);//Adiciona colaborador na arvore de saidas

void preOrdemNomes(Nomes *nomes);//percorre nomes preOrdem e imprime
void emOrdemNomes(Nomes *nomes);//percorre nomes emOrdem e imprime
void posOrdemNomes(Nomes *nomes);//percorre nomes posOrdem e imprime

void preOrdemEntradas(Entradas *entradas);//percorre entradas preOrdem e imprime
void emOrdemEntradas(Entradas *entradas);//percorre entradas emOrdem e imprime
void posOrdemEntradas(Entradas *entradas);//percorre entradas posOrdem e imprime

void preOrdemSaidas(Saidas *saidas);//percorre saidas preOrdem e imprime
void emOrdemSaidas(Saidas *saidas);//percorre saidas emOrdem e imprime
void posOrdemSaidas(Saidas *saidas);//percorre saidas posOrdem e imprime

Nomes *minimoNomes(Nomes* nomes);//retorna o no mais a esquerda de nomes
Entradas *minimoEntradas(Entradas* entradas);//retorna o no mais a esquerda de entradas
Saidas *minimoSaidas(Saidas* saidas);//retorna o no mais a esquerda de saidas

Nomes *buscarNomes(Nomes *nomes, string nome);//busca nomes
Entradas *buscarEntradas(Entradas *entradas, Data *entrada);//busca entradas
Saidas *buscarSaidas(Saidas *saidas, Data* saida);//busca saidas

int removerNomes(Nomes* nomes, string nome);//remove nomes
int removerEntradas(Entradas* entradas, Data *entrada);//remove entradas
int removerSaidas(Saidas* saidas, Data *saida);//remove saidas

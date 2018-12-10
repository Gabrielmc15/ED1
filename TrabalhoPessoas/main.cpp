#include <iostream>
#include <stdlib.h>
#include "Trees.h"

using namespace std;

int main(){
    //Criando as variaveis necessarias
    Nomes *nomes = NULL, *buscaNomes = NULL;
    Entradas *entradas = NULL, *buscaEntradas = NULL;
    Saidas *saidas = NULL, *buscaSaidas = NULL;
    int n, dia1, mes1, ano1, dia2, mes2, ano2, parametro;
    string nome, aux;
    Data *entrada = NULL;
    Data *saida = NULL;
    Colaborador *col = NULL;

    //menu
    do{
        cout << "Deseja fazer qual operacao?\n1- Adicionar colaborador\n2- Buscar colaborador\n3- Editar colaborador\n4- Remover colaborador\n5- Listar\n6- sair\n";
        cin >> n;
        system("cls");
        switch(n){
            case 1: //adicionar colaborador
                do{
                    cout << "Digite o nome do colaborador\n";
                    cin >> nome;
                    do{
                        cout << "Digite a data de entrada do colaborador\ndia: ";
                        cin >> dia1;
                        if(dia1 > 31) cout << "\nDia invalido\n";
                    }while(dia1 > 31);
                    do{
                        cout << "\nmes: ";
                        cin >> mes1;
                        if(mes1 > 12) cout << "\nMes invalido\n";
                    }while(mes1 > 12);
                    do{
                        cout << "\nano: ";
                        cin >> ano1;
                        if(ano1 > 2018) cout << "\nAno invalido\n";
                    }while(ano1 > 2018);
                    do{
                        cout << "Digite a data de saida do colaborador\ndia: ";
                        cin >> dia2;
                        if(dia2 > 31) cout << "\nDia invalido\n";
                    }while(dia2 > 31);
                    do{
                        cout << "\nmes: ";
                        cin >> mes2;
                        if(mes2 > 12) cout << "\nMes invalido\n";
                    }while(mes2 > 12);
                    do{
                        cout << "\nano: ";
                        cin >> ano2;
                        if(ano2 > 2018) cout << "\nAno invalido\n";
                    }while(ano2 > 2018);
                    entrada = data(dia1, mes1, ano1);
                    saida = data(dia2, mes2, ano2);
                    if(dataComp(entrada, saida) >= 0){
                        system("cls");
                        cout << "A data de entrada eh mais recente que a data de saida\n";
                    }
                } while(dataComp(entrada, saida) >= 0);
                col = Criar(nome, entrada, saida);
                add(col, &nomes, &entradas, &saidas);
                system("cls");
                cout << "Colaborador adicionado com sucesso!\n";
                break;
            case 2://buscar colaborador
                system("cls");
                cout << "Digite o parametro da busca\n1- Dome\n2- Data de entrada\n3- Data de saida\n";
                cin >> parametro;
                do{
                    switch(parametro){
                        case 1:
                            cout << "Digite o nome que deseja procurar\n";
                            cin >> nome;
                            if(buscarNomes(nomes,nome) != NULL){
                                buscaNomes = buscarNomes(nomes, nome);
                                system("cls");
                                cout << "Nome: " << buscaNomes->col->nome << "\nMatricula: " << buscaNomes->col->matricula << "\nEntrada: ";
                                printData(buscaNomes->col->entrada);
                                cout << "\nSaida: ";
                                printData(buscaNomes->col->saida);
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        case 2:
                            cout << "digite a data que deseja procurar\nDia: ";
                            cin >> dia1;
                            cout << "\nMes: ";
                            cin >> mes1;
                            cout << "\nAno: ";
                            cin >> ano1;
                            if(buscarEntradas(entradas,data(dia1, mes1, ano1)) != NULL){
                                buscaEntradas = buscarEntradas(entradas, data(dia1, mes1, ano1));
                                system("cls");
                                cout << "Nome: " << buscaEntradas->col->nome << "\nMatricula: " << buscaEntradas->col->matricula << "\nEntrada: ";
                                printData(buscaEntradas->col->entrada);
                                cout << "\nSaida: ";
                                printData(buscaEntradas->col->saida);
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        case 3:
                            cout << "digite a data que deseja procurar\nDia: ";
                            cin >> dia2;
                            cout << "\nMes: ";
                            cin >> mes2;
                            cout << "\nAno: ";
                            cin >> ano2;
                            if(buscarSaidas(saidas,data(dia2, mes2, ano2)) != NULL){
                                buscaSaidas = buscarSaidas(saidas, data(dia2, mes2, ano2));
                                system("cls");
                                cout << "Nome: " << buscaSaidas->col->nome << "\nMatricula: " << buscaSaidas->col->matricula << "\nEntrada: ";
                                printData(buscaSaidas->col->entrada);
                                cout << "\nSaida: ";
                                printData(buscaSaidas->col->saida);
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        default:
                            break;
                    }
                }while(parametro > 3);
                break;
            case 3://editar colaborador
                system("cls");
                cout << "Digite o parametro da busca\n1- Dome\n2- Data de entrada\n3- Data de saida\n";
                cin >> parametro;
                do{
                    switch(parametro){
                        case 1:
                            cout << "Digite o nome que deseja procurar\n";
                            cin >> nome;
                            if(buscarNomes(nomes,nome) != NULL){
                                buscaNomes = buscarNomes(nomes, nome);
                                system("cls");
                                do{
                                    cout << "Digite o nome do colaborador\n";
                                    cin >> nome;
                                    do{
                                        cout << "Digite a data de entrada do colaborador\ndia: ";
                                        cin >> dia1;
                                        if(dia1 > 31) cout << "\nDia invalido\n";
                                    }while(dia1 > 31);
                                    do{
                                        cout << "\nmes: ";
                                        cin >> mes1;
                                        if(mes1 > 12) cout << "\nMes invalido\n";
                                    }while(mes1 > 12);
                                    do{
                                        cout << "\nano: ";
                                        cin >> ano1;
                                        if(ano1 > 2018) cout << "\nAno invalido\n";
                                    }while(ano1 > 2018);


                                    do{
                                        cout << "Digite a data de saida do colaborador\ndia: ";
                                        cin >> dia2;
                                        if(dia2 > 31) cout << "\nDia invalido\n";
                                    }while(dia2 > 31);
                                    do{
                                        cout << "\nmes: ";
                                        cin >> mes2;
                                        if(mes2 > 12) cout << "\nMes invalido\n";
                                    }while(mes2 > 12);
                                    do{
                                        cout << "\nano: ";
                                        cin >> ano2;
                                        if(ano2 > 2018) cout << "\nAno invalido\n";
                                    }while(ano2 > 2018);
                                    entrada = data(dia1, mes1, ano1);
                                    saida = data(dia2, mes2, ano2);
                                    if(dataComp(entrada, saida) >= 0){
                                        system("cls");
                                        cout << "A data de entrada eh mais recente que a data de saida\n";
                                    }
                                } while(dataComp(entrada, saida) >= 0);
                                buscaNomes->col->nome = nome;
                                buscaNomes->col->entrada = data(dia1,mes1,ano1);
                                buscaNomes->col->saida = data(dia2,mes2,ano2);
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        case 2:
                            cout << "digite a data que deseja procurar\nDia: ";
                            cin >> dia1;
                            cout << "\nMes: ";
                            cin >> mes1;
                            cout << "\nAno: ";
                            cin >> ano1;
                            if(buscarEntradas(entradas,data(dia1,mes1,ano1)) != NULL){
                                buscaEntradas = buscarEntradas(entradas, data(dia1,mes1,ano1));
                                system("cls");
                                do{
                                    cout << "Digite o nome do colaborador\n";
                                    cin >> nome;
                                    do{
                                        cout << "Digite a data de entrada do colaborador\ndia: ";
                                        cin >> dia1;
                                        if(dia1 > 31) cout << "\nDia invalido\n";
                                    }while(dia1 > 31);
                                    do{
                                        cout << "\nmes: ";
                                        cin >> mes1;
                                        if(mes1 > 12) cout << "\nMes invalido\n";
                                    }while(mes1 > 12);
                                    do{
                                        cout << "\nano: ";
                                        cin >> ano1;
                                        if(ano1 > 2018) cout << "\nAno invalido\n";
                                    }while(ano1 > 2018);


                                    do{
                                        cout << "Digite a data de saida do colaborador\ndia: ";
                                        cin >> dia2;
                                        if(dia2 > 31) cout << "\nDia invalido\n";
                                    }while(dia2 > 31);
                                    do{
                                        cout << "\nmes: ";
                                        cin >> mes2;
                                        if(mes2 > 12) cout << "\nMes invalido\n";
                                    }while(mes2 > 12);
                                    do{
                                        cout << "\nano: ";
                                        cin >> ano2;
                                        if(ano2 > 2018) cout << "\nAno invalido\n";
                                    }while(ano2 > 2018);
                                    entrada = data(dia1, mes1, ano1);
                                    saida = data(dia2, mes2, ano2);
                                    if(dataComp(entrada, saida) >= 0){
                                        system("cls");
                                        cout << "A data de entrada eh mais recente que a data de saida\n";
                                    }
                                } while(dataComp(entrada, saida) >= 0);
                                buscaEntradas->col->nome = nome;
                                buscaEntradas->col->entrada = data(dia1,mes1,ano1);
                                buscaEntradas->col->saida = data(dia2,mes2,ano2);
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        case 3:
                            cout << "digite a data que deseja procurar\nDia: ";
                            cin >> dia2;
                            cout << "\nMes: ";
                            cin >> mes2;
                            cout << "\nAno: ";
                            cin >> ano2;
                            if(buscarSaidas(saidas,data(dia2,mes2,ano2)) != NULL){
                                buscaSaidas = buscarSaidas(saidas,data(dia2,mes2,ano2));
                                system("cls");
                                do{
                                    cout << "Digite o nome do colaborador\n";
                                    cin >> nome;
                                    do{
                                        cout << "Digite a data de entrada do colaborador\ndia: ";
                                        cin >> dia1;
                                        if(dia1 > 31) cout << "\nDia invalido\n";
                                    }while(dia1 > 31);
                                    do{
                                        cout << "\nmes: ";
                                        cin >> mes1;
                                        if(mes1 > 12) cout << "\nMes invalido\n";
                                    }while(mes1 > 12);
                                    do{
                                        cout << "\nano: ";
                                        cin >> ano1;
                                        if(ano1 > 2018) cout << "\nAno invalido\n";
                                    }while(ano1 > 2018);


                                    do{
                                        cout << "Digite a data de saida do colaborador\ndia: ";
                                        cin >> dia2;
                                        if(dia2 > 31) cout << "\nDia invalido\n";
                                    }while(dia2 > 31);
                                    do{
                                        cout << "\nmes: ";
                                        cin >> mes2;
                                        if(mes2 > 12) cout << "\nMes invalido\n";
                                    }while(mes2 > 12);
                                    do{
                                        cout << "\nano: ";
                                        cin >> ano2;
                                        if(ano2 > 2018) cout << "\nAno invalido\n";
                                    }while(ano2 > 2018);
                                    entrada = data(dia1, mes1, ano1);
                                    saida = data(dia2, mes2, ano2);
                                    if(dataComp(entrada, saida) >= 0){
                                        system("cls");
                                        cout << "A data de entrada eh mais recente que a data de saida\n";
                                    }
                                } while(dataComp(entrada, saida) >= 0);
                                buscaSaidas->col->nome = nome;
                                buscaSaidas->col->entrada = data(dia1,mes1,ano1);
                                buscaSaidas->col->saida = data(dia2,mes2,ano2);
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        default:
                            break;
                    }
                }while(parametro > 3);
            case 4://remover colaborador
                system("cls");
                cout << "Digite o parametro da busca\n1- Dome\n2- Data de entrada\n3- Data de saida\n";
                cin >> parametro;
                do{
                    switch(parametro){
                        case 1:
                            cout << "Digite o nome que deseja procurar\n";
                            cin >> nome;
                            if(buscarNomes(nomes,nome) != NULL){
                                removerNomes(nomes,nome);
                                cout << "Colaborador removico com sucesso!\nDigite qualquer tecla para continuar";
                                cin >> aux;
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        case 2:
                            cout << "digite a data que deseja procurar\nDia: ";
                            cin >> dia1;
                            cout << "\nMes: ";
                            cin >> mes1;
                            cout << "\nAno: ";
                            cin >> ano1;
                            if(buscarEntradas(entradas,data(dia1, mes1, ano1)) != NULL){
                                removerEntradas(entradas,entrada);
                                cout << "Colaborador removico com sucesso!\nDigite qualquer tecla para continuar";
                                cin >> aux;
                                system("cls");
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        case 3:
                            cout << "digite a data que deseja procurar\nDia: ";
                            cin >> dia2;
                            cout << "\nMes: ";
                            cin >> mes2;
                            cout << "\nAno: ";
                            cin >> ano2;
                            if(buscarSaidas(saidas,data(dia2, mes2, ano2)) != NULL){
                                removerSaidas(saidas,saida);
                                cout << "Colaborador removico com sucesso!\nDigite qualquer tecla para continuar";
                                cin >> aux;
                                system("cls");
                            }else {
                                system("cls");
                                cout << "Colaborador nao encontrado";
                                cout << "\nDigite qualquer tecla para continuar\n";
                                cin >> aux;
                                system("cls");
                            }
                            break;
                        default:
                            break;
                    }
                }while(parametro > 3);
                break;
            case 5:
                cout << "Listando o nome de todos os colaboradores em ordem alfabetica:\n";
                emOrdemNomes(nomes);
                cout << "\nDigite qualquer tecla para continuar\n";
                cin >> aux;
                system("cls");
                break;
            case 6:
                break;
            default:
                cout << "Entrada invalida\n";
        }
    }while (n != 6);
}

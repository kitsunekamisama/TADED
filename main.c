#ifndef _main_c_
#define _main_c_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#define TRUE 1
#define FALSE 0

/*------------------------------------------------------------------------------
Estrutura _carro_: Declaração de tipo que contém as variáveis que compõem o CARRO.
Variáveis: char    marca[30]: Vetor de String com o nome da marca do CARRO
           int     potencia:  A potencia do CARRO em tipo inteiro
           int     nportas:   O numero de portas do CARRO em tipo inteiro
           float   preco:     O preco do CARRO em tipo float
           long    placa:     O numero da placa do CARRO em tipo long(int)
------------------------------------------------------------------------------*/
//Estrutura Carro
typedef struct _carro_{
    char    marca[30];
    int     potencia;
    int     nportas;
    float   preco;
    long    placa;
}Carro;

/*------------------------------------------------------------------------------
Função comPlaca: Compara a placa de um carro
Parametro: Ponteiro para um elemento k a ser comparado com os elementos dentro do coleção
Retorno: TRUE(1) -  caso o elemento for igual ao do TAD COLEÇÃO;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
//Função de comparação por placa do carro
int comPlaca(void *k, void *elm){
    long *iplaca = (long*)k;
    Carro *Celm = (Carro*)elm;
    long *placa = (long*)Celm ->placa;

    if(iplaca == placa ){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/*------------------------------------------------------------------------------
Função comMarca: Compara a Marca de um carro
Parametro: Ponteiro para um elemento k a ser comparado com os elementos dentro do COLEÇÃO
Retorno: TRUE(1) -  caso o elemento for igual ao do TAD COLEÇÃO;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
//Função de comparação por marca do carro
int comMarca(void *key,void *elm){
	char strkey[30];
	char strelm[30];
	Carro *c = (Carro *)elm;
	strcpy(strkey,(char *)key);

    strcpy(strelm, (char*)c->marca);
    //if( strcmp(strkey,c->marca) == 0){
	if( strcmp(strkey,strelm) == 0){
		return TRUE;
	}
	else{
        return FALSE;
	}
}

/*Variável |op| é para as opcoes do menu principal
 *Variável |op2| é para a opcões de busca e remoção por PLACA ou MARCA
 *Variável |tam| é para o tamanho do COLEÇÃO a ser criado
 *Variavel |destroi| usada para auxiliar na detruicao do COLEÇÃO
 *Variavel |inseriu| verifica se foi inserido um elemento do tipo carro no COLEÇÃO ou não
 *Variavel |cont| usada pra delimitar a quantidade de carros INSERIDOS e REMOVIDOS do COLEÇÃO
 *
 *
*/

int main(){

    int op, op2, tam, destroi, inseriu, cont = 0;
    long placa;
    char marca[30];
    Colecao *c = NULL;
    Carro *car, *busca, *removeu;

    do{
        do{
            printf("\nEscolha uma opcao abaixo:\n");
            printf("1 - Criar uma COLECAO\n");
            printf("2 - Destruir a COLECAO\n");
            printf("3 - Inserir Dados na COLECAO\n");
            printf("4 - Ver Elementos da COLECAO\n");
            printf("5 - Consultar Elementos na COLECAO\n");
            printf("6 - Remover Elementos da COLECAO\n");
            printf("7 - Para Sair do Programa\n");

            scanf("%d",&op);
            if(op<1 || op>7){
                system("cls");
                printf("\nOpcao invalida!!\n");
            }
        }while(op<1 || op>7);
        system("cls");

        switch(op){
            case 1:
                if(c==NULL){
                    printf("\nDigite o numero de elementos para a COLECAO, ex:5\n");
                    scanf("%d", &tam);
                    system("cls");
                    c = colCreate(tam);
                    //car = (Carro*)malloc(sizeof(Carro));
                    if(c!=NULL){
                        printf("\nCOLECAO criada com SUCESSO!!\n");
                        car = NULL;
                        break;
                        system("cls");
                    }
                    else{
                        printf("\nFalha na criacao da COLECAO\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nCOLECAO ja esta criada!!!\n");
                    break;
                    system("cls");
                }
                break;
            case 2:
                if(c!=NULL){
                    destroi = colDestroy(c);
                    if(destroi == TRUE){
                        printf("\nCOLECAO Destruida com SUCESSO!!\n");
                        c = NULL;
                        break;
                        system("pause");
                    }
                    else{
                        destroi = colRemoveAll(c);
                        destroi = colDestroy(c);
                        printf("\nCOLECAO Destruida com SUCESSO!!\n");
                        c = NULL;
                        break;
                        system("pause");
                    }
                }else{
                    printf("\nIMPOSSIVEL DESTRUIR, COLECAO AINDA NAO CRIADA!!\n");
                    break;
                    system("cls");
                }
                break;
            case 3:
                if(c!=NULL){
                    if(cont<tam){
                        car = (Carro*)malloc(sizeof(Carro));

                        if(car!=NULL){
                            printf("\nInsira os dados do CARRO NA COLECAO?\n");
                            printf("\nInsira a MARCA do CARRO:\n");
                            fflush(stdin);
                            fgets(car ->marca, 30, stdin);
                            printf("\nInsira a POTENCIA do CARRO:\n");
                            scanf("%d",&(car ->potencia));
                            printf("\nInsira o NUMERO DE PORTAS do CARRO:\n");
                            scanf("%d",&(car ->nportas));
                            printf("\nInsira o PRECO do CARRO:\n");
                            scanf("%f",&(car ->preco));
                            printf("\nInsira a PLACA do CARRO:\n");
                            scanf("%ld",&(car ->placa));
                            inseriu = colInsert(c,(void*)car);
                            system("cls");
                            if(inseriu == TRUE){
                                printf("\nCARRO inserido com sucesso!!\n");
                                cont ++;
                                break;
                                system("cls");
                            }
                            if(inseriu == FALSE){
                                printf("\nNAO HA mais espaco para inserir CARROS na colecao!!\n");
                                break;
                                system("cls");
                            }
                        }
                    }
                    else{
                        printf("A COLECAO ja esta cheia!!\nEh preciso Remover elementos para inserir outros!\n");
                    }

                }
                else{
                    printf("\nIMPOSSIVEL INSERIR DADOS, COLECAO AINDA NAO CRIADA!!\n");
                    break;
                    system("cls");
                }
                break;
            case 4:
                if(c!=NULL){
                    if(car!=NULL){
                        int i =0;
                        car = (Carro*)colGetFirst(c);
                        if(car!=NULL){
                            printf("\nOs Carros que estao na COLECAO:\n");
                        }else{
                            printf("\nSem elementos ainda na COLECAO!!\n");
                        }
                        while(car!=NULL){
                            printf("\n\t*** Carro %d: ***\n",i);
                            printf("\nMARCA:\t %s\n",car ->marca);
                            printf("\nPOTENCIA:\t %d\n",car ->potencia);
                            printf("\nNUMERO DE PORTAS:\t %d\n",car ->nportas);
                            printf("\nPRECO:\t %.2f\n",car ->preco);
                            printf("\nPLACA:\t %ld\n",car ->placa);
                            printf("\n");
                            car = (Carro*)colGetNext(c);
                            i++;
                        }
                        car = (Carro*)colGetFirst(c);
                        break;
                        system("cls");
                    }
                    else{
                        printf("\nSem elementos ainda na COLECAO!!\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nIMPOSSIVEL VER ELEMENTOS, COLECAO AINDA NAO CRIADA!!\n");
                    break;
                    system("cls");
                }
                break;
            case 5:
                if(c!=NULL){
                    if(car!=NULL){
                        printf("\nEscolha como Buscar o Carro:\n1 - Por Marca\n2 - Por Placa\n");
                        scanf("%d", &op2);
                        if(op2 == 1){
                            printf("\nDigite a Marca do Carro p/ pesquisar:\n");
                            fflush(stdin);
                            fgets(marca, 30, stdin);
                            busca = (Carro*)colQuery(c,(void*)marca,comMarca);
                            if(busca!=NULL){
                                printf("\nO Carro pesquisado foi:\n");
                                printf("\nMARCA:\t %s\n",busca ->marca);
                                printf("\nPOTENCIA:\t %d\n",busca ->potencia);
                                printf("\nNUMERO DE PORTAS:\t %d\n",busca ->nportas);
                                printf("\nPRECO:\t %.2f\n",busca ->preco);
                                printf("\nPLACA:\t %ld\n",busca ->placa);
                                printf("\n");
                                busca = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Carro nao foi encontrado no COLECAO!!\n");
                                busca = NULL;
                                break;
                                system("cls");
                            }
                        }
                        if(op2 == 2){
                            printf("\nDigite a Placa do Carro p/ pesquisar:\n");
                            scanf("%ld",&placa);
                            busca = (Carro*)colQuery(c,(void*)placa,comPlaca);
                            if(busca!=NULL){
                                printf("\nO Carro pesquisado foi:\n");
                                printf("\nMARCA:\t %s\n",busca ->marca);
                                printf("\nPOTENCIA:\t %d\n",busca ->potencia);
                                printf("\nNUMERO DE PORTAS:\t %d\n",busca ->nportas);
                                printf("\nPRECO:\t %.2f\n",busca ->preco);
                                printf("\nPLACA:\t %ld\n",busca ->placa);
                                printf("\n");
                                busca = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Carro nao foi encontrado na COLECAO!!\n");
                                break;
                                system("cls");
                            }
                        }
                    }
                    else{
                        printf("\nSem elementos ainda na COLECAO!!\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nIMPOSSIVEL CONSULTAR, COLECAO AINDA NAO CRIADA!!\n");
                    break;
                    system("cls");
                }
                break;
            case 6:
                if(c!=NULL){
                    if(car!=NULL){
                        op2 = 0;
                        printf("\nEscolha como Remover o Carro:\n1 - Por Marca\n2 - Por Placa\n");
                        scanf("%d", &op2);
                        if(op2 == 1){
                            printf("\nDigite a Marca do Carro que quer remover:\n");
                            fflush(stdin);
                            fgets(marca, 30, stdin);
                            removeu = (Carro*)colRemove(c,(void*)marca,comMarca);
                            if(removeu!=NULL){
                                printf("\nO Carro:\n");
                                printf("\nMARCA:\t %s\n",removeu ->marca);
                                printf("\nPOTENCIA:\t %d\n",removeu ->potencia);
                                printf("\nNUMERO DE PORTAS:\t %d\n",removeu ->nportas);
                                printf("\nPRECO:\t %.2f\n",removeu ->preco);
                                printf("\nPLACA:\t %ld\n",removeu ->placa);
                                printf("\nFOI REMOVIDO COM SUCESSO!!!\n");
                                printf("\n");
                                cont --;
                                removeu = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Carro nao foi encontrado na COLECAO!!\n");
                                removeu = NULL;
                                break;
                                system("cls");
                            }
                        }
                        if(op2 == 2){
                            printf("\nDigite a Placa do Carro que quer remover:\n");
                            scanf("%ld",&placa);
                            removeu = (Carro*)colRemove(c,(void*)placa,comPlaca);
                            if(removeu!=NULL){
                                printf("\nO Carro:\n");
                                printf("\nMARCA:\t %s\n",removeu ->marca);
                                printf("\nPOTENCIA:\t %d\n",removeu ->potencia);
                                printf("\nNUMERO DE PORTAS:\t %d\n",removeu ->nportas);
                                printf("\nPRECO:\t %.2f\n",removeu ->preco);
                                printf("\nPLACA:\t %ld\n",removeu ->placa);
                                printf("\nFOI REMOVIDO COM SUCESSO!!!\n");
                                printf("\n");
                                cont --;
                                removeu = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Carro nao foi encontrado na COLECAO!!\n");
                                break;
                                system("cls");
                            }
                        }
                    }else{
                        printf("\nSem elementos ainda na COLECAO!!\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nIMPOSSIVEL REMOVER, COLECAO AINDA NAO CRIADA!!\n");
                    break;
                    system("cls");
                }
                break;
            case 7:
                printf("\nObrigado por usar o programa!\n");
                colDestroy(c);
                break;
        }


    }while(op!=7);

    return 0;
}
#endif /// _main_c_

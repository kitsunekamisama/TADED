#ifndef _colecao_c_
#define _colecao_c_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"
#define TRUE 1
#define FALSE 0
#endif // _colecao_h_

/*------------------------------------------------------------------------------
Implementação das operações do TAD COLEÇÃO genérico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _colecao_: Declaração de tipo que contém as variáveis que compõem o COLEÇÃO.
Variáveis: void **item:  Vetor com os itens do COLEÇÃO
           int maxItens:      Tamanho máximo de itens do COLEÇÃO
           int nItens:    Número atual de itens no COLEÇÃO
           int cur:      Elemento atual no COLEÇÃO
------------------------------------------------------------------------------*/
typedef struct _colecao_{
    void **item;
    int maxItens;
    int nItens;
    int cur;
}Colecao;

Colecao *colCreate(int n){ //n é o tamanho pra criar o cofo
    Colecao *c;

    if(n>0){
        c = (Colecao*)malloc(sizeof(Colecao));
        if(c!=NULL){
            c -> item = (void**)malloc(sizeof(void*)*n);
            if( c -> item != NULL ){
                c -> nItens = 0; // QUANTIDADE DE ELEMENTOS NO VETOR/ COLEÇÃO
                c -> maxItens = n;
                c -> cur = -1; // Porque não tem elementos
                return c;
            }
            else{
                free(c);
            }
        }
    }
    return NULL;
}

int colInsert(Colecao *c, void *item){

    if(c != NULL){
        if(c -> nItens < c -> maxItens){ //SE A QUANTIDADE DE ELEMENTOS FOR MENOR QUE A CAPACIDADE MAXIMA, ENTAO INSERE
            c -> item[c -> nItens] = item;
            c -> nItens ++;
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    return FALSE;
}

void *colRemove(Colecao *c, void *key, int (*cmp)(void*,void*)){
    int i, j, stat;// aux;
    void *aux;

    if(c != NULL){
        if( c -> nItens > 0 ){
            i = 0;
            stat = cmp(key, c -> item[i]);
            while( stat != TRUE && i< c -> nItens ){
                i++;
                stat = cmp(key, c -> item[i]);
            }
            if( stat == TRUE ){
                aux = c -> item[i];
                for(j = i; j < c ->nItens-1; j++){
                    c -> item[j] = c -> item[j+1];
                }
                c -> nItens --;
                return aux;
            }
        }
    }
    return NULL;
}

void *colQuery( Colecao *c, void *key, int (*cmp)(void*, void*) ){
    int i, stat;
    void *aux;

    if(c != NULL){
        if(c -> nItens > 0){
            i = 0;
            stat = (int)cmp(key, c ->item[i]);
            while( stat != TRUE && i < c -> nItens ){
                i++;
                stat = (int)cmp(key, c ->item[i]);
            }
            if( stat == TRUE ){
                aux = c -> item[i];
                return aux;  // RETORNA O PROPRIO ELEMENTO
            }
            else{
                return NULL;
            }
        }
    }
    return NULL;
}

void *colGetFirst(Colecao *c){
    if(c!=NULL){
        if(c -> nItens > 0){
            c -> cur = 0;
            return c -> item[c -> cur];
        }
    }
    return NULL;
}

void *colGetNext(Colecao *c){
    if(c!=NULL){
        if(c -> nItens > 0){
            c -> cur++;
            if(c -> cur < c -> nItens){
                return c -> item[c -> cur];
            }
            else{
                return NULL;
            }
        }
        else{
            return NULL;
        }
    }
    return NULL;
}

int colRemoveAll(Colecao *c){
    if(c!=NULL){
        c ->nItens = 0;
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int colDestroy(Colecao *c){

    if(c != NULL){
        if( c -> nItens == 0 ){ //SE A QUANTIDADE DE ELEMENTOS FOR IGUAL A ZERO
            free(c -> item); //DESALOCA OS ELEMENTOS DO VETOR
            free(c); // DESALOCA O COLEÇÃO
            return TRUE;
        }
    }
    return FALSE;
}

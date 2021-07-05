#ifndef _colecao_h_
#define _colecao_h_

/*------------------------------------------------------------------------------
Especificação das operações do TAD COLEÇÃO genérico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _colecao_: Declaração de tipo que contém as variáveis que compõem o COLEÇÃO.
------------------------------------------------------------------------------*/
typedef struct _colecao_ Colecao;
#endif // _colecao_h_
#ifdef _colecao_c_

Colecao *colCreate(int n);
int colInsert( Colecao *c, void *item );
void *colRemove( Colecao *c, void *key, int (*cmp)(void*,void*) );
int colRemoveAll(Colecao *c);
void *colQuery( Colecao *c, void *key, int (*cmp)(void*,void*) );
void *colGetFirst( Colecao *c );
void *colGetNext( Colecao *c );
int colDestroy(Colecao *c);

#else

/*------------------------------------------------------------------------------
Função colCreate: Cria um novo TAD COLEÇÃO
Parametro: Recebe o número de itens para o COLEÇÃO ser criada
(n!=NULL)
Retorno: Ponteiro para um novo TAD COLEÇÃO vazio;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern Colecao *colCreate(int n);

/*------------------------------------------------------------------------------
Função colInsert: Insere um item no COLEÇÃO
Parametros: TAD COLEÇÃO existente, não cheio e o item a ser inserido (item!=NULL)
Retorno: TRUE(1) - Item incluído no TAD COLEÇÃO;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int colInsert( Colecao *c, void *item );

/*------------------------------------------------------------------------------
Função colRemove: Remove um item de um TAD COLEÇÃO
Parametros: TAD COLEÇÃO existente, não vazia e o item a ser removido (item!=NULL)
Retorno: Ponteiro para o item removido do TAD COLEÇÃO;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *colRemove( Colecao *c, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Função colRemoveAll: Remove todos os itens de um TAD COLEÇÃO
Parametros: TAD Coleção existente e não vazia
Retorno: TRUE(1) - Todos os itens retirados do TAD COLEÇÃO;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int colRemoveAll(Colecao *c);

/*------------------------------------------------------------------------------
Função colQuery: Busca um item em um TAD COLEÇÃO
Parametros: TAD COLEÇÃO existente, não vazia e o item a ser buscado (key!=NULL)
Retorno: Ponteiro para o item buscado do TAD COLEÇÃO;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *colQuery( Colecao *c, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Função colGetFirst: Pega o primeiro item de um TAD COLEÇÃO
Parametros: TAD COLEÇÃO existente e não vazia
Retorno: Ponteiro para o primeiro item do TAD COLEÇÃO;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *colGetFirst( Colecao *c );

/*------------------------------------------------------------------------------
Função colGetNext: pega o próximo item de um TAD COLEÇÃO
Parametros: TAD COLEÇÃO existente, não vazia
Retorno: Ponteiro para o próximo item do TAD COLEÇÃO;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *colGetNext( Colecao *c );

/*------------------------------------------------------------------------------
Função colDestroy: Destrói um TAD COLEÇÃO
Parametro: Ponteiro para um TAD COLEÇÃO
Retorno: TRUE(1) - TAD COLEÇÃO destruído liberando seu espaço da memória;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int colDestroy(Colecao *c);
#endif // _cofo_c_

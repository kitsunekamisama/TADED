#ifndef _colecao_h_
#define _colecao_h_

/*------------------------------------------------------------------------------
Especifica��o das opera��es do TAD COLE��O gen�rico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _colecao_: Declara��o de tipo que cont�m as vari�veis que comp�em o COLE��O.
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
Fun��o colCreate: Cria um novo TAD COLE��O
Parametro: Recebe o n�mero de itens para o COLE��O ser criada
(n!=NULL)
Retorno: Ponteiro para um novo TAD COLE��O vazio;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern Colecao *colCreate(int n);

/*------------------------------------------------------------------------------
Fun��o colInsert: Insere um item no COLE��O
Parametros: TAD COLE��O existente, n�o cheio e o item a ser inserido (item!=NULL)
Retorno: TRUE(1) - Item inclu�do no TAD COLE��O;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int colInsert( Colecao *c, void *item );

/*------------------------------------------------------------------------------
Fun��o colRemove: Remove um item de um TAD COLE��O
Parametros: TAD COLE��O existente, n�o vazia e o item a ser removido (item!=NULL)
Retorno: Ponteiro para o item removido do TAD COLE��O;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *colRemove( Colecao *c, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Fun��o colRemoveAll: Remove todos os itens de um TAD COLE��O
Parametros: TAD Cole��o existente e n�o vazia
Retorno: TRUE(1) - Todos os itens retirados do TAD COLE��O;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int colRemoveAll(Colecao *c);

/*------------------------------------------------------------------------------
Fun��o colQuery: Busca um item em um TAD COLE��O
Parametros: TAD COLE��O existente, n�o vazia e o item a ser buscado (key!=NULL)
Retorno: Ponteiro para o item buscado do TAD COLE��O;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *colQuery( Colecao *c, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Fun��o colGetFirst: Pega o primeiro item de um TAD COLE��O
Parametros: TAD COLE��O existente e n�o vazia
Retorno: Ponteiro para o primeiro item do TAD COLE��O;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *colGetFirst( Colecao *c );

/*------------------------------------------------------------------------------
Fun��o colGetNext: pega o pr�ximo item de um TAD COLE��O
Parametros: TAD COLE��O existente, n�o vazia
Retorno: Ponteiro para o pr�ximo item do TAD COLE��O;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *colGetNext( Colecao *c );

/*------------------------------------------------------------------------------
Fun��o colDestroy: Destr�i um TAD COLE��O
Parametro: Ponteiro para um TAD COLE��O
Retorno: TRUE(1) - TAD COLE��O destru�do liberando seu espa�o da mem�ria;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int colDestroy(Colecao *c);
#endif // _cofo_c_

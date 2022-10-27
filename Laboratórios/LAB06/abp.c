// Bibliotecas padrao da linguagem C e assinaturas das funcoes criadas:
#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

// Funcao tipo pNodoA que cria uma arvore ABP:
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     // Se a arvore estiver vazia
     if (a == NULL)
     {
         // Alocao de memoria
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         // Atualizacao de ponteiros:
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         // Retorno do ponteiro da arvore
         return a;
     }
     else
          // Se a chave for menor do que o conteudo do nodo
          if (ch < a->info)
              // Chamada da recursao
              a->esq = InsereArvore(a->esq,ch);
          // Se a chava for maior do que o conteudo do nodo
          else if (ch > a->info)
              // Chamada da recursao
              a->dir = InsereArvore(a->dir,ch);
     // Retorno do ponteiro da arvore
     return a;
}

// Funcao tipo void que imprime uma arvore
// (modo pre-fixado a esquerda):
void preFixadoE(pNodoA *a)
{
     if (a!= NULL)
     {
          printf("%d - ",a->info);
          preFixadoE(a->esq);
          preFixadoE(a->dir);
      }
}

// Funcao tipo int que verifica se duas arvores tem a mesma estrutura:
int iguaisABP(pNodoA *a, pNodoA *b)
{
    // Se as arvores forem vazias:
    if(a==NULL && b==NULL)
        return 1;

    // Se as arvores tiverem ao menos um elemento:
    if(a != NULL && b != NULL)
    {
        return
        (
            // Compara o que esta armazenado no nodo
            // e chama as recursoes
            a->info == b->info && iguaisABP(a->esq, b->esq) && iguaisABP(a->dir, b->dir)
        );
    }

    // Caso contrario:
    return 0;
}

// Funcao do tipo criado que espelha os elementos de uma arvore:
pNodoA* espelhoABP(pNodoA *a)
{
    // Se a arvore estiver vazia:
    if(a==NULL)
        return;
    else
    {
        // Variavel do tipo criado
        pNodoA *aux;

        // Chamadas das recursoes:
        espelhoABP(a->esq);
        espelhoABP(a->dir);

        // Atualizacao de ponteiros:
        aux = a->esq;
        a->esq = a->dir;
        a->dir = aux;

        return a;
    }
}

// Funcao tipo int que verifica se uma arvore e ABP
int checaABP(pNodoA *a)
{
    // Se a arvore estiver vazia:
    if(a==NULL)
        return 1;

    // Se o nodo do lado esquerdo for diferente de NULL
    // e se o seu conteudo for maior do que o conteudo guardado pelo nodo anterior
    if(a->esq != NULL && a->esq->info > a->info)
        return 0;

    // Se o nodo do lado direito for diferente de NULL
    // e se o seu conteudo for menor do que o conteudo guardado pelo nodo anterior
    if(a->dir != NULL && a->dir->info < a->info)
        return 0;

    // Chamada das recursoes:
    if(!checaABP(a->esq) || !checaABP(a->dir))
        return 0;

    // Caso contrario,
    return 1;
}



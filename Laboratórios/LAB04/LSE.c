// Bibliotecas padrão da linguagem C
#include <stdio.h>
#include <stdlib.h>
// Assinaturas das funcoes criadas
#include "LSE.h"

// Cria a lista:
ptLSE *criaLista(void)
{
    // Retorna NULL:
    return NULL;
}

// Insere numero:
ptLSE *insere_num (ptLSE* ptlista, int num)
{
    // Declaracao de ponteiros auxiliares
    ptLSE *novo;
    ptLSE *ant = NULL;
    ptLSE *ptaux = ptlista;

    // Alocacao de memoria para o novo elemento
    novo = (ptLSE*) malloc(sizeof(ptLSE));

    novo->numero = num;
    // Enquanto o ponteiro auxiliar for diferente de NULL
    while ((ptaux!=NULL))
    {
        ant = ptaux;
        ptaux = ptaux->prox;
    }

    // Se o elemento anterior for igual a NULL
    if (ant == NULL)
    {
        novo->prox = ptlista;
        ptlista = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    // Retorno da lista
    return ptlista;
}

// Imprime a lista:
void imprime(ptLSE *ptLista)
{
    // Declaracao de ponteiro auxiliar
    ptLSE *ptauxiliar;

    // Se a lista estiver vazia
    if(ptLista == NULL)
    {
        printf("\nA lista esta vazia!\n");
    }
    else // Caso contrario
    {
        for(ptauxiliar = ptLista; ptauxiliar != NULL; ptauxiliar = ptauxiliar->prox)
        {
            printf("%d -> ", ptauxiliar->numero);
        }
    }
}

// Remove do fim da lista:
ptLSE *remove_fim(ptLSE *ptlista)
{
    if(ptlista == NULL)
        printf("A lista ja esta vazia!");
    else if(ptlista->prox == NULL)
    {
        free(ptlista);
        ptlista = NULL;
    }
    else
    {
        ptLSE *ptaux = ptlista;
        ptLSE *ptaux2 = ptlista;

        while(ptlista->prox != NULL)
        {
            ptaux2 = ptaux;
            ptaux = ptaux->prox;
        }

        ptaux2->prox = NULL;
        free(ptaux);
        ptaux = NULL;
    }

    // Retorno da lista
    return ptlista;
}

// Remove do inicio da lista:
ptLSE *remove_inicio(ptLSE *ptlista)
{
    // Declaracao de ponteiro auxiliar
    ptLSE *ptaux = ptlista;

    // O primeiro elemento e excluido
    ptlista = ptlista->prox;
    // Libera o ponteiro auxiliar
    free(ptaux);

    ptaux = NULL;

    // Retorno da lista
    return ptlista;
}

// Insere no comeco:
void insere_comeco(ptLSE *ptlista, ptLSE *ptaux, int num_escolhido)
{
    // Declaracao de ponteiros auxiliares que receberao, respectivamente,
    // o menor elemento e o maior elemento
    ptLSE *menor;
    ptLSE *maior;

    // Alocacao de memoria para o menor elemento
    menor = (ptLSE*) malloc(sizeof(ptLSE));
    menor->numero = num_escolhido - 1;

    menor->prox = ptlista;
    ptlista = menor;

    // Alocacao de memoria para o maior elemento
    maior = (ptLSE*) malloc(sizeof(ptLSE));
    maior->numero = num_escolhido + 1;

    maior->prox = ptaux->prox;
    ptaux->prox = maior;

    // Chamada da funcao que imprime a lista
    imprime(ptlista);
}

// Inclui numero:
void inclui_num(ptLSE *ant, ptLSE *ptaux, ptLSE *ptlista, int num_escolhido)
{
    // Declaracao de ponteiros auxiliares que receberao, respectivamente,
    // o menor elemento e o maior elemento
    ptLSE *menor;
    ptLSE *maior;

    // Alocacao de memoria para o menor elemento
    menor = (ptLSE*) malloc(sizeof(ptLSE));
    menor->numero = num_escolhido - 1;

    menor->prox = ant->prox;
    ant->prox = menor;

    // Alocacao de memoria para o maior elemento
    maior = (ptLSE*) malloc(sizeof(ptLSE));
    maior->numero = num_escolhido + 1;

    maior->prox = ptaux->prox;
    ptaux->prox = maior;

    // Chamada da funcao que imprime a lista
    imprime(ptlista);
}

// Insere na lista:
ptLSE *insere(ptLSE *ptlista, int num_escolhido)
{
    // Declaracao de ponteiros auxiliares
    ptLSE *ant = NULL;
    ptLSE *ptaux = ptlista;

    // Se o numero guardado e igual ao numero escolhido
    if(ptlista->numero == num_escolhido)
    {
        insere_comeco(ptlista, ptaux, num_escolhido);
        // Retorno da lista
        return ptlista;
    }

    // Enquanto o ponteiro auxiliar for diferente de NULL
    while (ptaux != NULL)
    {
        ant = ptaux;
        ptaux = ptaux->prox;
        // Se o numero guardado e igual ao numero escolhido
        if(ptaux->numero == num_escolhido)
        {
            // Chamada da funcao inclui_num
            inclui_num(ant, ptaux, ptlista, num_escolhido);
            // Retorno da lista
            return ptlista;
        }
    }

    // Chamada da funcao remove_fim
    remove_fim(ptlista);
    // Chamada da funcao remove_inicio
    remove_inicio(ptlista);
    // Chamada da funcao que imprime a lista
    imprime(ptlista);

    // Retorno da lista
    return ptlista;
}

// Destroi a lista:
ptLSE *destroi(ptLSE *ptlista)
{
    // Declaracao de ponteiro auxiliar
    ptLSE *ptaux;
    // Enquanto a lista for diferente de NULL
    while (ptlista != NULL)
    {
        ptaux = ptlista;
        ptlista = ptlista->prox;
        // Libera a posicao de memoria ocupada pelo ponteiro auxiliar
        free(ptaux);
    }
    // Libera a posicao de memoria ocupada pela lista
    free(ptlista);
    // Retorna NULL
    return NULL;
}


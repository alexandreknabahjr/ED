/*
Este programa implementa algumas funcoes referentes as Arvores Binarias de Pesquisa.
Aqui, temos a criacao de uma ABP, a compaparacao entre duas arvores, a verificacao de uma
arvore e o espelhamento de uma arvore.
*/

// Bibliotecas padrao da linguagem C e assinaturas das funcoes criadas:
#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

void nmaior(pNodoA *a, int n, int c)
{
    if(a == NULL || c >= n)
        return;

    nmaior(a->dir, n, c);

    c++;

    if(c == n)
    {
        printf("O n-esimo maior valor e: %d\n\n", a->info);
        return;
    }

    nmaior(a->esq, n, c);
}

void nesimo(pNodoA *a, int n)
{
    int c = 0;

    nmaior(a, n, c);
}

int main()
{
    // Variavel do tipo criado
    pNodoA *arv1 = NULL;
    pNodoA *arv2 = NULL;
    pNodoA *arv3 = NULL;

    // Nodos sao inseridos na arvore 1:
    arv1 = InsereArvore(arv1,30);
    arv1 = InsereArvore(arv1,45);
    arv1 = InsereArvore(arv1,25);
    arv1 = InsereArvore(arv1,90);
    arv1 = InsereArvore(arv1,80);
    arv1 = InsereArvore(arv1,95);

    // Nodos sao inseridos na arvore 2:
    arv2 = InsereArvore(arv2,30);
    arv2 = InsereArvore(arv2,90);
    arv2 = InsereArvore(arv2,25);
    arv2 = InsereArvore(arv2,100);
    arv2 = InsereArvore(arv2,80);
    arv2 = InsereArvore(arv2,29);

    // Nodos sao inseridos na arvore 3
    arv3 = InsereArvore(arv3, 35);
    arv3 = InsereArvore(arv3, 6);
    arv3 = InsereArvore(arv3, 71);
    arv3 = InsereArvore(arv3, 2);
    arv3 = InsereArvore(arv3, 49);
    arv3 = InsereArvore(arv3, 28);
    arv3 = InsereArvore(arv3, 73);

    printf("Comparacao entre as arvores 1 e 2:\n\n");
    // Teste de comparacao entre as arvores 1 e 2:
    if(iguaisABP(arv1, arv2))
        printf("As arvores sao iguais!\n\n");
    else
        printf("As arvores NAO sao iguais!\n\n");

    printf("****************************\n\n");

    printf("Arvore 1:\n\n");
    // Chamada da funcao que imprime uma arvore:
    preFixadoE(arv1);

    printf("\n\n");

    // Testa se a arvore dada e uma ABP
    if(checaABP(arv1))
        printf("E ABP!\n\n");
    else
        printf("Nao e ABP!\n\n");

    printf("****************************\n\n");

    // Chamada da funcao que espelha os elementos de uma arvore:
    espelhoABP(arv1);

    printf("Arvore espelhada:\n\n");
    // Chamada da funcao que imprime a arvore espelhada:
    preFixadoE(arv1);

    printf("\n\n");

    // Testa a arvore espelhada:
    if(checaABP(arv1))
        printf("E ABP!\n\n");
    else
        printf("Nao e ABP!\n\n\n\n");

    nesimo(arv3, 1);

    return 0;
}

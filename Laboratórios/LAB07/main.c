/*
Este programa cria uma arvore, calcula o fator dos nodos dessa arvore,
testa se ela e uma arvore do tipo AVL e retorna o numero mais proximo
daquele procurado.
*/

// Bibliotecas padrao da linguagem C e TAD criada:
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    // Variavel do tipo criado
    pNodoA *a = NULL;
    // Variavel tipo int de controle da insercao
    int ok;

    // Insercao de nodos na arvore
    a = InsereAVL(a, 20, &ok);
    a = InsereAVL(a, 12, &ok);
    a = InsereAVL(a, 40, &ok);
    a = InsereAVL(a, 10, &ok);
    a = InsereAVL(a, 45, &ok);

    // Os fatores dos nodos da arvore criada
    printf("Fatores dos nodos:\n\n");
    printf("Nodo 20: %d\n", fator(a, 20, &ok));
    printf("Nodo 12: %d\n", fator(a, 12, &ok));
    printf("Nodo 40: %d\n", fator(a, 40, &ok));
    printf("Nodo 10: %d\n", fator(a, 10, &ok));
    printf("Nodo 45: %d\n\n", fator(a, 45, &ok));

    printf("********************************");

    // Testa se a arvore criada e do tipo AVL
    if(checaAVL(a))
        printf("\n\nA arvore criada e do tipo AVL!\n\n");
    else
        printf("\n\nA arvore criada NAO e do tipo AVL!\n\n");

    printf("********************************");

    // Alguns exemplos de numeros proximos daqueles inseridos na arvore criada
    printf("\n\nNumeros mais proximos:\n\n");

    printf("O numero mais proximo de 90: %d\n\n", proximo(a, 90));
    printf("O numero mais proximo de 1000: %d\n\n", proximo(a, 1000));
    printf("O numero mais proximo de 0: %d\n\n", proximo(a, 0));
    printf("O numero mais proximo de 20: %d\n\n", proximo(a, 20));

    return 0;
}

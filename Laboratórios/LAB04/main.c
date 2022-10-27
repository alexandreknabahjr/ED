// Bibliotecas padrão da linguagem C
#include <stdio.h>
#include <stdlib.h>
// Assinaturas das funcoes criadas
#include "LSE.h"

int main()
{
    // Definicao de variavel do tipo ptLSE
    ptLSE *ptlista;
    // Definicao de variaveis do tipo int e do tipo char
    int num, num_escolhido;
    char continua, escolhe;

    // Chamada da funcao que cria a lista
    ptlista = criaLista();

    printf("Deseja inserir elementos na lista(s)(n)? ");
    scanf(" %c", &escolhe);

    // Se escolhe for igual a 's'
    if(escolhe == 's')
    {
        // Faca enquanto a resposta for diferente de 'n'
        do
        {
            printf("Insira o numero: ");
            scanf("%d", &num);
            // Chamada da funcao insere_num
            ptlista = insere_num(ptlista, num);
            printf("Continua(s)(n)? ");
            scanf(" %c", &continua);
        }while (continua!='n');
    }

    // Chamada da funcao que imprime a lista
    imprime(ptlista);

    printf("\nInsira o numero escolhido: ");
    scanf("%d", &num_escolhido);

    // Testa se ptlista e igual a NULL
   if(ptlista == NULL)
    {
         ptlista = insere_num(ptlista, num_escolhido);
         imprime(ptlista);
    }
    else
    {
        insere(ptlista, num_escolhido);
    }

    // Chamada da funcao que destroi a lista
    destroi(ptlista);

    return 0; // Retorna 0
}

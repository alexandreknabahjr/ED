/*
Este programa insere num_procurado - 1
em uma posicao anterior ao numero numero procurado
e insere num_procurado + 1 em uma posicao posterior ao numero procurado,
se tal numero for encontrado em uma LDEC. Caso contrario,
o primeiro elemento e o ultimo elemento dessa LDEC serao excluidos.
*/

// Bibliotecas padrao da linguagem C:
#include <stdio.h>
#include <stdlib.h>
// TAD criada:
#include "LDEC.h"

int main()
{
    // Definicao de variavel do tipo criado
    ptLDEC *ptlista;

    // Primeiro teste:

    // Chamada da funcao cria_lista()
    ptlista = cria_lista();

    // Chamada da funcao insere_vazio
    ptlista = insere_vazio(7);
    // Chamada da funcao insere_inicio
    ptlista = insere_inicio(ptlista, 1);
    // Chamada da funcao insere_fim
    ptlista = insere_fim(ptlista, 3);
    // Chamada da funcao imprime
    imprime(ptlista);

    // Chamada da funcao insere
    ptlista = insere(ptlista, 7);
    imprime(ptlista);

    // Chamada da funcao destroi
    destroi(ptlista);

    // Segundo teste:

    ptlista = cria_lista();

    ptlista = insere_vazio(7);
    ptlista = insere_inicio(ptlista, 1);
    ptlista = insere_fim(ptlista, 3);
    ptlista = insere_fim(ptlista, 4);
    ptlista = insere_fim(ptlista, 5);
    imprime(ptlista);

    ptlista = insere(ptlista, 9);
    imprime(ptlista);

    destroi(ptlista);

    return 0; // Retorna 0 quando o programa acaba
}


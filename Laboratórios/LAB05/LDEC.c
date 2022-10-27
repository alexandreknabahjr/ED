// Bibliotecas padrao da linguagem C:
#include <stdio.h>
#include <stdlib.h>
// TAD criada:
#include "LDEC.h"

// Funcao que cria a lista:
ptLDEC *cria_lista(void)
{
    // Retorna NULL
    return NULL;
}

// Funcao que imprime a lista
// da esquerda para a direita:
void imprime(ptLDEC *ptlista)
{
    // Se ptlista for igual a NULL
    if(ptlista == NULL)
        printf("A lista esta vazia!");
    else
    {
        // A variavel temp recebe o proximo elemento de ptlista
        ptLDEC *temp = ptlista->prox;
        do
        {
            printf("%d -> ", temp->numero);
            temp = temp->prox;
        }while(temp != ptlista->prox); // Enquanto temp for diferente do proximo elemento de ptlista
    }

    printf("\n\n\n\n");
}

// Funcao que insere um numero na lista vazia:
ptLDEC *insere_vazio(int num)
{
    // Alocacao de memoria
    ptLDEC *temp = (ptLDEC*) malloc(sizeof(ptLDEC));
    temp->ant = temp;
    temp->numero = num;
    temp->prox = temp;

    // Retorna a variavel temporaria
    return temp;
}

// Funcao que insere um numero no comeco da lista:
ptLDEC *insere_inicio(ptLDEC *ptlista, int num)
{
    // Variavel do tipo criada recebe
    // o retorno de insere_vazio
    ptLDEC *novo = insere_vazio(num);

    // Se ptlista estiver vazia
    if(ptlista == NULL)
    {
        return novo;
    }
    else
    {
        // A variavel temp do tipo criado recebe o proximo elemento de ptlista
        ptLDEC *temp = ptlista->prox;
        // Atualizacao de ponteiros:
        novo->ant = ptlista;
        novo->prox = temp;
        temp->ant = novo;
        ptlista->prox = novo;

        // Retorno da lista
        return ptlista;
    }
}

// Funcao que insere um numero no final da lista:
ptLDEC *insere_fim(ptLDEC *ptlista, int num)
{
    // Variavel do tipo criado recebe
    // o retorno de insere_vazio
    ptLDEC *novo = insere_vazio(num);

    // Se ptlista estiver vazia
    if(ptlista == NULL)
    {
        return novo;
    }
    else
    {
        // Variavel temp do tipo criado recebe o proximo elemento de ptlista
        ptLDEC *temp = ptlista->prox;
        // Atualizacao de ponteiros:
        novo->prox = temp;
        novo->ant = ptlista;
        ptlista->prox = novo;
        temp->ant = novo;
        ptlista = novo;
        // Retorno da lista
        return ptlista;
    }
}

// Funcao que procura por um numero na lista:
int *procura(ptLDEC *ptlista, int num_procurado)
{
    // Variavel temp do tipo criado recebe ptlista
    ptLDEC *temp = ptlista;
    // Variavel tipo int e inicializada com 0
    int encontrado = 0;
    // Indice de controle do laco e inicializado com 0
    int i = 0;

    // Se a variavel temp do tipo criado for igual a NULL
    if(temp != NULL)
    {
        while(1)
        {
            // Incremento de i
            i++;
            // Se o numero guardado por temp for igual a num_procurado
            if(temp->numero == num_procurado)
            {
                // Incremento de encontrado
                encontrado++;
                break;
            }
            // Variavel temp recebe o proximo elemento
            temp = temp->prox;
            // Se temp for igual a ptlista
            if(temp == ptlista)
                break;
        }
        if(encontrado == 1)
            // Retorna 1, se o numero for encontrado
            return 1;
        else
            // Retorna 0, se o numero nao for encontrado
            return 0;
    }
}

ptLDEC *remove_inicio(ptLDEC *ptlista)
{
    // Se a lista estiver vazia
    if(ptlista == NULL)
        // Retorna a propria lista
        return ptlista;

    // Variavel temp do tipo criado que recebe o proximo elemento da lista
    ptLDEC *temp = ptlista->prox;

    // Se a variavel temp do tipo criado for igual a ptlista
    if(temp == ptlista)
    {
        // A posicao de memoria e liberada
        free(ptlista);
        ptlista = NULL;
        // Retorno da lista
        return ptlista;
    }

    // Atualizacao de ponteiros:
    ptlista->prox = temp->prox;
    temp->prox->ant = ptlista;
    // A posicao de memoria e liberada
    free(temp);

    // Retorno da lista
    return ptlista;
}

// Funcao que remove o ultimo elemento da lista:
ptLDEC *remove_fim(ptLDEC *ptlista)
{
    // Definicao de variavel do tipo criado
    ptLDEC *temp;

    // Se a lista estiver vazia
    if(ptlista == NULL)
        // Retorna a propria lista
        return ptlista;

    // Se a variavel temp for igual a ptlista
    if(temp == ptlista)
    {
        // A posicao de memoria e liberada
        free(ptlista);
        // ptlista recebe NULL
        ptlista = NULL;
    }

    // Atualizacao de ponteiros:
    temp = ptlista->ant;
    temp->prox = ptlista->prox;
    ptlista->prox->ant = temp;
    free(ptlista);
    ptlista = temp;

    // Retorno da lista
    return ptlista;
}

// Funcao que encontra a posicao de um determinado
// elemento na lista:
int *posicao(ptLDEC *ptlista, int num_procurado)
{
    // Variavel temp do tipo criado recebe ptlista
    ptLDEC *temp = ptlista;
    // Variavel tipo int e inicializado com 0
    int contador = 0;

    // Se a lista estiver vazia
    if(ptlista == NULL)
        // Retorna 0
        return 0;

    do
    {
        // Incremento do contador
        contador++;
        // Variavel temp recebe o proximo elemento da lista
        temp = temp->prox;
    } while(temp->numero != num_procurado); // Enquanto o numero que guardado por temp
                                            // for diferente do numero procurado

    // Retorno de contador
    return contador;
}

// Funcao que insere num_procurado - 1 em uma
// posicao anterior:
ptLDEC *insere_antes(ptLDEC *ptlista, int num_procurado)
{
    // Variavel tipo int que recebe a diferenca num_procurado - 1
    int num = num_procurado - 1;
    // Variavel do tipo criado recebe
    // o retorno de insere_vazio
    ptLDEC *novo = insere_vazio(num);
    // Variavel tipo int que recebe o retorno da funcao posicao
    // somado a 5
    int posicao_a_inserir = posicao(ptlista, num_procurado) + 5;

    // Se a lista estiver vazia
    if(ptlista == NULL)
        // Retorna novo
        return novo;

    // Variavel temp do tipo criado recebe o proximo elemento da lista
    ptLDEC *temp = ptlista->prox;

    // Enquanto posicao_a_inserir for maior do que 1
    while(posicao_a_inserir > 1)
    {
        // A variavel temp recebe o proximo elemento
        temp = temp->prox;
        // Decremento de posicao_a_inserir
        posicao_a_inserir--;
    }

    // Atualizacao de ponteiros:
    novo->ant = temp;
    novo->prox = temp->prox;
    temp->prox->ant = novo;
    temp->prox = novo;

    // Se a variavel temp for igual a ptlista
    if(temp == ptlista)
        // Atualizacao de ptlista
        ptlista = ptlista->prox;

    // Retorno da lista
    return ptlista;

}

// Funcao que insere num_procurado + 1 em uma
// posicao posterior:
ptLDEC *insere_depois(ptLDEC *ptlista, int num_procurado)
{
    // Variavel tipo int que recebe a soma num_procurado + 1
    int num = num_procurado + 1;
    // Variavel do tipo criado recebe
    // o retorno de insere_vazio
    ptLDEC *novo = insere_vazio(num);
    // Variavel tipo int que recebe o retorno da funcao posicao
    // somado a 3
    int posicao_a_inserir = posicao(ptlista, num_procurado) + 3;

    // Se a lista estiver vazia
    if(ptlista == NULL)
        // Retorna novo
        return novo;

    // Variavel temp do tipo criado recebe o proximo elemento da lista
    ptLDEC *temp = ptlista->prox;

    // Enquanto posicao_a_inserir for maior do que 1
    while(posicao_a_inserir > 1)
    {
        // A variavel temp recebe o proximo elemento
        temp = temp->prox;
        // Decremento de posicao_a_inserir
        posicao_a_inserir--;
    }

    // Atualizacao de ponteiros:
    novo->ant = temp;
    novo->prox = temp->prox;
    temp->prox->ant = novo;
    temp->prox = novo;

    // Se a variavel temp for igual a ptlista
    if(temp == ptlista)
        // Atualizacao de ptlista
        ptlista = ptlista->prox;

    // Retorno da lista
    return ptlista;

}

// Funcao que insere:
ptLDEC *insere(ptLDEC *ptlista, int num_procurado)
{
    // Teste de procura:
    // Se o retorno da funcao procura for igual a 1
    if(procura(ptlista, num_procurado))
    {
        // Chamada da funcao insere_antes
        insere_antes(ptlista, num_procurado);
        // Chamada da funcao insere_depois
        insere_depois(ptlista, num_procurado);
    }
    else // Caso contrario
    {
        // Chamada da funcao remove_inicio
        remove_inicio(ptlista);
        // Chamada da funcao remove_fim
        remove_fim(ptlista);
    }
}

// Funcao que destroi a lista:
ptLDEC *destroi(ptLDEC *ptlista)
{
    // Definicao de variaveis do tipo criado:
    ptLDEC *ptaux;
    ptLDEC *ptfim = ptlista;

    // Se ptlista estiver vazia
    if(ptlista != NULL)
    {
        do
        {
            // Atualizacao de ponteiros:
            ptaux = ptlista;
            ptlista = ptlista->prox;
            // A posicao de memoria e liberada
            free(ptaux);
        }while((ptlista != ptfim)); // Enquanto ptlista for diferente do fim
    }

    // Retorna NULL
    return NULL;
}


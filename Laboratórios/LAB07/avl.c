// Bibliotecas padrao da linguagem C e TAD criada
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// Estrutura de dados criada:
struct TNodoA
{
    TipoInfo info;
    int FB;
    struct TNodoA *esq;
    struct TNodoA *dir;
};

pNodoA* InsereArvore(pNodoA* a, TipoInfo ch)
{
    if (a == NULL)
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0; // o nodo é sempre inserido como folha então seu fator de balanceamento é 0
    }
    else if (ch < (a->info))
        a->esq = InsereArvore(a->esq,ch);
    else
        a->dir = InsereArvore(a->dir,ch);
    return a;
}

int Altura (pNodoA *a)
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
        return 0;
    else
    {
        Alt_Esq = Altura (a->esq);
        Alt_Dir = Altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}

int Calcula_FB(pNodoA *a)
{
    return (Altura(a->esq) - Altura(a->dir));
}

void Desenha(pNodoA *a, int nivel)
{
    int x;

    if (a !=NULL)
    {
        for (x=1; x<=nivel; x++)
            printf("=");
        printf("%d FB= %d\n", a->info, Calcula_FB(a));
        if (a->esq != NULL)
            Desenha(a->esq, (nivel+1));
        if (a->dir != NULL)
            Desenha(a->dir, (nivel+1));
    }
}

int is_avl(pNodoA *a)
{
    int alt_esq, alt_dir;

    if (a!=NULL)
    {
        alt_esq = Altura(a->esq);
        alt_dir = Altura(a->dir);
        return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) && (is_avl(a->esq)) && (is_avl(a->dir)) );
    }
    else
        return 1;
}


pNodoA* rotacao_direita(pNodoA *pt)
{
    pNodoA* ptu;

    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoA* rotacao_esquerda(pNodoA *pt)
{
    pNodoA* ptu;

    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoA* rotacao_dupla_direita (pNodoA* pt)
{
    pNodoA* ptu, *ptv;

    ptu = pt->esq;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    pt->esq = ptv->dir;
    ptv->dir = pt;
    if (ptv->FB == 1)
        pt->FB = -1;
    else
        pt->FB = 0;
    if (ptv->FB == -1)
        ptu->FB = 1;
    else
        ptu->FB = 0;
    pt = ptv;
    return pt;
}

pNodoA* rotacao_dupla_esquerda (pNodoA* pt)
{
    pNodoA *ptu, *ptv;

    ptu = pt->dir;
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    pt->dir = ptv->esq;
    ptv->esq = pt;
    if (ptv->FB == -1)
        pt->FB = 1;
    else
        pt->FB = 0;
    if (ptv->FB == 1)
        ptu->FB = -1;
    else
        ptu->FB = 0;
    pt = ptv;
    return pt;
}


pNodoA* Caso1 (pNodoA* a, int *ok)
{
    pNodoA *ptu;

    ptu = a->esq;
    if (ptu->FB == 1)
    {
        printf("fazendo rotacao direita em %d\n",a->info);
        a = rotacao_direita(a);
    }
    else
    {
        printf("fazendo rotacao dupla direita em %d\n",a->info);
        a = rotacao_dupla_direita(a);
    }

    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoA* Caso2 (pNodoA *a, int *ok)
{
    pNodoA *ptu;

    ptu = a->dir;
    if (ptu->FB == -1)
    {
        Desenha(a,1);
        printf("fazendo rotacao esquerda em %d\n",a->info);
        a=rotacao_esquerda(a);
    }
    else
    {
        Desenha(a,1);
        printf("fazendo rotacao dupla esquerda em %d\n",a->info);
        a=rotacao_dupla_esquerda(a);
    }
    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoA* InsereAVL (pNodoA *a, TipoInfo x, int *ok)
{
    /* Insere nodo em uma arvore AVL, onde A representa a raiz da arvore,
      x, a chave a ser inserida e h a altura da arvore */

    if (a == NULL)
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (x < a->info)
    {
        a->esq = InsereAVL(a->esq,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case -1:
                a->FB = 0;
                *ok = 0;
                break;
            case  0:
                a->FB = 1;
                break;
            case  1:
                a=Caso1(a,ok);
                break;
            }
        }
    }
    else
    {
        a->dir = InsereAVL(a->dir,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case  1:
                a->FB = 0;
                *ok = 0;
                break;
            case  0:
                a->FB = -1;
                break;
            case -1:
                a = Caso2(a,ok);
                break;
            }
        }
    }
    return a;
}
//*****************************************

// Funcao que calcula o fator:
int fator(pNodoA *a, TipoInfo num, int *ok)
{
    // Se o nodo for igual a NULL
    if(a == NULL)
    {
        *ok = 0;
        return 0;
    }

    // Se o numero for igual ao conteudo do nodo
    if(num == a->info)
    {
        *ok = 1;
        // Chamada da funcao Altura
        return (Altura(a->esq) - Altura(a->dir));
    }

    // Se o numero for maior do que o conteudo do nodo
    if(num > a->info)
    {
        // Chamada da recursao para o lado direito da arvore
        return fator(a->dir, num, ok);
    }

    // Caso contrario
    else
    {
        // Chamada da recursao para o lado esquerdo da arvore
        return fator(a->esq, num, ok);
    }
}

// Funcao que verifica se uma arvore e AVL:
int checaAVL(pNodoA *a)
{
    // Variaveis tipo int
    int altura_esquerda, altura_direita;

    // Se o nodo for nulo
    if(a == NULL)
        // 1 equivale a TRUE
        return 1;
    else
    {
        // Chamada das recursoes
        altura_esquerda = Altura(a->esq);
        altura_direita = Altura(a->dir);

        // Teste que verifica se a diferenca entre as alturas
        // e maior do que duas unidades
        if(((altura_direita - altura_esquerda > -2)) &&
           ((altura_direita - altura_esquerda) < 2))
        {
            return (checaAVL(a->dir) && checaAVL(a->esq));
        }
        else
            // 0 equivale a FALSE
            return 0;
    }
}

// Funcao que retorna o numero mais proximo daquele procurado:
int proximo(pNodoA *a, TipoInfo num)
{
    // Variaveis tipo int
    int aux1, aux2, aux3;

    // Se o nodo for igual a NULL
    if(a == NULL)
        return 0;
    else
    {
        // Se ambos os lados da arvore forem igual a NULL
        if(a->dir == NULL && a->esq == NULL)
            return a->info;
        // Se somente o lado direito for igual a NULL
        else if(a->dir == NULL)
        {
            // Se o conteudo do nodo do lado esquerdo for maior do que o numero procurado
            if(a->esq->info > num)
                return proximo(a->esq, num);
            else
            {
                // Variaveis auxiliares guardam a operacoes
                aux1 = a->info - num;
                aux3 = a->esq->info - num;

                if(aux1 < aux3)
                    return a->info;
                else
                    return a->esq->info;
            }
        }
        // Se somente o lado esquerdo for igual a NULL
        else if(a->esq == NULL)
        {
            // Se o conteudo do nodo do lado direito for menor do que o numero procurado
            if(a->dir->info < num)
                return proximo(a->dir, num);
            else
            {
                // Variaveis auxiliares guardam as operacoes
                aux1 = a->info - num;
                aux2 = a->dir->info - num;

                if(aux1 < aux2)
                    return a->info;
                else
                    return a->dir->info;
            }
        }
        // Se o conteudo do nodo do lado direito for menor do que o numero procurado
        else if(a->dir->info < num)
            return (proximo(a->dir, num));
        // Se o conteudo do nodo do lado esquerdo for maior do que o numero procurado
        else if(a->esq->info > num)
            return (proximo(a->esq, num));
        else
        {
            // Se o conteudo do nodo for igual ao numero procurado
            if(a->info == num)
                return a->info;
            // Se o numero procurado for menor do que o conteudo do nodo
            else if(num > a->info)
            {
                // Variaveis auxiliares guardam as operacoes
                aux1 = a->info - num;
                aux2 = a->dir->info - num;

                if(aux1 < aux2)
                    return a->info;
                else
                    return a->dir->info;
            }
            else
            {
                // Variaveis auxiliares guardam as operacoes
                aux1 = a->info - num;
                aux2 = a->esq->info - num;

                if(aux1 < aux2)
                    return a->info;
                else
                    return a->esq->info;
            }
        }
    }
}


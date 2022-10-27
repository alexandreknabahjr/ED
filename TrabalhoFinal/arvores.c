#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"

// Funcoes ABP:

ABP *insere_abp(ABP *a, COMIDA ingerida)
{
    if(a == NULL)
    {
        a = (ABP*)malloc(sizeof(ABP));
        a->ingerida = ingerida;
        a->esq = NULL;
        a->dir = NULL;
        nodos_ABP += 1;
    }
    else if(strcmp(a->ingerida.alimento, ingerida.alimento) < 0)
        a->dir = insere_abp(a->dir, ingerida);
    else if(strcmp(a->ingerida.alimento, ingerida.alimento) > 0)
        a->esq = insere_abp(a->esq, ingerida);

    return a;
}

int altura_abp(ABP *a)
{
    int altura_esquerda = 0;
    int altura_direita = 0;

    if(a == NULL)
        return 0;
    else
    {
        altura_esquerda = altura_abp(a->esq);
        altura_direita = altura_abp(a->dir);

        if(altura_esquerda < altura_direita)
            return altura_direita + 1;
        else
            return altura_esquerda + 1;
    }
}

ABP* consulta_abp(ABP *a, char *chave){
    while (a!=NULL){
        comparacoes_ABP++;
        if (!strcmp(a->ingerida.alimento,chave)){
            comparacoes_ABP++;
            return a;
        }
        else {
            comparacoes_ABP++;
            if (strcmp(a->ingerida.alimento,chave)>0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}


// Funcoes AVL:

int Altura(AVL *a)
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

int Calcula_FB(AVL *a)
{
    return (Altura(a->esq) - Altura(a->dir));
}

AVL* rotacao_direita(AVL *pt){
   AVL* ptu;

   ptu = pt->esq;
   pt->esq = ptu->dir;
   ptu->dir = pt;
   pt->FB = 0;
   pt = ptu;
   rotacoes_AVL += 1;
   return pt;
}

AVL* rotacao_esquerda(AVL *pt){
   AVL* ptu;

   ptu = pt->dir;
   pt->dir = ptu->esq;
   ptu->esq = pt;
   pt->FB = 0;
   pt = ptu;
   rotacoes_AVL += 1;
   return pt;
}

AVL* rotacao_dupla_direita (AVL* pt){
   AVL* ptu, *ptv;

   ptu = pt->esq;
   ptv = ptu->dir;
   ptu->dir = ptv->esq;
   ptv->esq = ptu;
   pt->esq = ptv->dir;
   ptv->dir = pt;
   if (ptv->FB == 1)   pt->FB = -1;
      else pt->FB = 0;
   if (ptv->FB == -1)  ptu->FB = 1;
      else ptu->FB = 0;
   pt = ptv;
    rotacoes_AVL += 1;
   return pt;
}

AVL* rotacao_dupla_esquerda (AVL* pt){
   AVL *ptu, *ptv;

   ptu = pt->dir;
   ptv = ptu->esq;
   ptu->esq = ptv->dir;
   ptv->dir = ptu;
   pt->dir = ptv->esq;
   ptv->esq = pt;
   if (ptv->FB == -1) pt->FB = 1;
     else pt->FB = 0;
   if (ptv->FB == 1) ptu->FB = -1;
      else ptu->FB = 0;
   pt = ptv;
    rotacoes_AVL += 1;
   return pt;
}


AVL* Caso1(AVL* a , int *ok)
{
    AVL *ptu;

	ptu = a->esq;
	if (ptu->FB == 1)
    {
        a = rotacao_direita(a);
     }
    else
    {
        a = rotacao_dupla_direita(a);
    }

    a->FB = 0;
	*ok = 0;
	return a;
}

AVL* Caso2 (AVL *a , int *ok)
{
    AVL *ptu;

	ptu = a->dir;
	if (ptu->FB == -1)
    {
       a=rotacao_esquerda(a);
    }
    else
    {
       a=rotacao_dupla_esquerda(a);
    }
	a->FB = 0;
	*ok = 0;
	return a;
}

AVL* InsereAVL (AVL *a, COMIDA ingerida_avl, int *ok)
{
     if (a == NULL)
     {
     	a = (AVL*) malloc(sizeof(AVL));
        a->ingerida_avl = ingerida_avl;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
	    *ok = 1;
	    nodos_AVL += 1;
     }
     else
     if (strcmp(a->ingerida_avl.alimento, ingerida_avl.alimento) > 0)
     {
		a->esq = InsereAVL(a->esq, ingerida_avl, ok);
        if (*ok)
        {
   		    switch (a->FB) {
        	  case -1:  a->FB = 0; *ok = 0; break;
			  case  0:  a->FB = 1;  break;
			  case  1:  a=Caso1(a,ok); break;
            }
         }
     }
	 else
     {
  		    a->dir = InsereAVL(a->dir,ingerida_avl,ok);
            if (*ok)
            {
              switch (a->FB) {
                case  1:  a->FB = 0; *ok = 0; break;
                case  0:  a->FB = -1; break;
			    case -1:  a = Caso2(a,ok); break;
             }
            }
     }

     return a;
}

AVL* consulta_avl(AVL *a, char *chave){
    while (a!=NULL){
        comparacoes_AVL++;
        if (!strcmp(a->ingerida_avl.alimento,chave)){
            comparacoes_AVL++;
            return a;
        }
        else {
            comparacoes_AVL++;
            if (strcmp(a->ingerida_avl.alimento,chave)>0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}




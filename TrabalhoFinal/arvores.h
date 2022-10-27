typedef struct comida{
    int calorias;
    char alimento[50];;
}COMIDA;

// ABP:
typedef struct abp{
        COMIDA ingerida;
        struct abp *esq;
        struct abp *dir;
}ABP;


ABP* insere_abp(ABP *a, COMIDA ingerida);
int altura_abp(ABP *a);
ABP* consulta_abp(ABP *a, char *chave);

int nodos_ABP;
int rotacoes_ABP;
int comparacoes_ABP;

// AVL:
typedef struct avl{
        COMIDA ingerida_avl;
        struct avl *esq;
        struct avl *dir;
        int FB;
}AVL;

int nodos_AVL;
int rotacoes_AVL;
int comparacoes_AVL;

int Altura (AVL *a);
int Calcula_FB(AVL *a);
AVL* rotacao_direita(AVL *pt);
AVL* rotacao_esquerda(AVL *pt);
AVL* rotacao_dupla_direita(AVL *pt);
AVL* rotacao_dupla_esquerda(AVL *pt);
AVL* Caso1(AVL *a , int *ok);
AVL* Caso2(AVL *a , int *ok);
AVL* InsereAVL(AVL *a, COMIDA ingerida_avl, int *ok);
AVL* consulta_avl(AVL *a, char *chave);



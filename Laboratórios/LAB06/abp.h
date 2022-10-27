// Estrutura criada:
typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

// Funcao que insere os elementos na arvore
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);

// Funcao que imprime uma arvore
// (modo pre-fixado a esquerda):
void preFixadoE(pNodoA *a);

// Funcao que verifica se duas arvores tem a mesma estrutura
int iguaisABP(pNodoA *a, pNodoA *b);

// Funcao que espelha os elementos da arvore ABP
pNodoA* espelhoABP(pNodoA *a);

// Funcao que verifica se uma arvore e ABP
int checaABP(pNodoA *a);


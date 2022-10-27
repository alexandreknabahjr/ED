// Definicao de nomes significativos para a estrutura:
typedef int TipoInfo;

typedef struct TNodoA pNodoA;

// Funcoes fornecidas pela prof. Renata Galante:
pNodoA * InsereArvore(pNodoA * a, TipoInfo ch);
int Altura (pNodoA * a);
int Calcula_FB(pNodoA * a);
void Desenha(pNodoA * a , int nivel);
int is_avl(pNodoA * a);
pNodoA * rotacao_direita(pNodoA * pt);
pNodoA * rotacao_esquerda(pNodoA * pt);
pNodoA * rotacao_dupla_direita (pNodoA * pt);
pNodoA * rotacao_dupla_esquerda (pNodoA * pt);
pNodoA * Caso1 (pNodoA * a , int *ok);
pNodoA * Caso2 (pNodoA * a , int *ok);
pNodoA * InsereAVL (pNodoA * a, TipoInfo x, int *ok);

// Funcoes criadas pela dupla:

// Funcao tipo int que calcula o fator de um nodo:
int fator(pNodoA *a, TipoInfo num, int *ok);

// Funcao tipo int que checa se uma arvore e AVL:
int checaAVL(pNodoA *a);

// Funcao tipo int que retorna o nodo mais proximo daquele procurado:
int proximo(pNodoA *a, TipoInfo num);


// Estrutura de dados criada:
typedef struct tipoNo ptLDEC;

struct tipoNo{
 int numero;
 ptLDEC *prox;
 ptLDEC *ant;
};

// Funcao tipo ptLDEC que cria a lista:
ptLDEC *cria_lista(void);

// Funcao tipo void que imprime a lista
// da esquerda para a direita:
void imprime(ptLDEC *ptlista);

// Funcao tipo ptLDEC que insere um numero na lista
// vazia:
ptLDEC *insere_vazio(int num);

// Funcao tipo ptLDEC que insere um numero no comeco
// da lista:
ptLDEC *insere_inicio(ptLDEC *ptlista, int num);

// Funcao tipo ptLDEC que insere um numero no final
// da lista:
ptLDEC *insere_fim(ptLDEC *ptlista, int num);

// Funcao tipo int que procura por um numero
// na lista:
int *procura(ptLDEC *ptlista, int num_procurado);

// Funcao tipo ptLDEC que remove o primeiro elemento
// da lista:
ptLDEC *remove_inicio(ptLDEC *ptlista);

// Funcao tipo ptLDEC que remove o ultimo elemento
// da lista:
ptLDEC *remove_fim(ptLDEC *ptlista);

// Funcao tipo int que encontra a posicao de um determinado
// elemento na lista:
int *posicao(ptLDEC *ptlista, int num_procurado);

// Funcao tipo ptLDEC que insere num_procurado - 1 em uma
// posicao anterior:
ptLDEC *insere_antes(ptLDEC *ptlista, int num_procurado);

// Funcao tipo ptLDEC que insere num_procurado + 1 em uma
// posicao posterior:
ptLDEC *insere_depois(ptLDEC *ptlista, int num_procurado);

// Funcao tipo ptLDEC que insere:
ptLDEC *insere(ptLDEC *ptlista, int num_procurado);

// Funcao tipo ptLDEC que destroi a lista:
ptLDEC *destroi(ptLDEC *ptlista);



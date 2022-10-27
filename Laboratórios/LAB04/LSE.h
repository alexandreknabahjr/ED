// Definicao do novo tipo de dado
typedef struct tipoNo ptLSE;
struct tipoNo
{
    int numero;
    ptLSE *prox;
};

// Funcao tipo ptLSE que cria a lista
ptLSE *criaLista(void);

// Funcao tipo ptLSE que insere um numero
ptLSE *insere_num (ptLSE* ptlista, int num);

// Funcao tipo void que imprime a lista:
void imprime(ptLSE *ptLista);

// Funcao tipo ptLSE que remove um numero do fim
ptLSE *remove_fim(ptLSE *ptlista);

// Funcao tipo ptLSE que remove um numero do inicio
ptLSE *remove_inicio(ptLSE *ptlista);

// Funcao tipo void que insere no comeco
void insere_comeco(ptLSE *ptlista, ptLSE *ptaux, int num_escolhido);

// Funcao tipo void que inclui um numero
void inclui_num(ptLSE *ant, ptLSE *ptaux, ptLSE *ptlista, int num_escolhido);

// Funcao tipo ptLSE que insere
ptLSE *insere(ptLSE *ptlista, int num_escolhido);

// Funcao tipo ptLSE que destroi a lista
ptLSE *destroi(ptLSE *ptlista);


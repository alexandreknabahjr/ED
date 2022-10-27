// Bibliotecas que sao padra na linguagem C
#include <stdio.h>
#include <string.h>

// Constantes utilizadas
#define NOME 50
#define JOGADORES 23
#define M_GOLS 1

// Estrutura que armazena os dados dos jogadores
typedef struct
{
    char nome[NOME];
    int idade;
    int num_gols;
    int num_faltas;
    int num_passes_errados;
    int num_passes_corretos;
} JOGADOR;

// Funcao que atribui dados aos jogadores.
// Nesta funcao, o usuario escolhe a quantidade
// de jogadores a serem incluidos no vetor.
void atribui_dados(JOGADOR j[], int qtd);

// Funcao que exibe as estatisticas dos jogadores.
// Nesta funcao, sao mostrados os gols de cada jogador
// armazenado no vetor de qtd posicoes.
void exibe_estatisticas(JOGADOR j[], int qtd);

// Funcao que testa se um jogador e bom.
// Um jogador em determinada posicao no vetor e bom quando a media de gols
// e maior do que 1.
int eh_o_bom(JOGADOR j[], int posicao, int partidas);

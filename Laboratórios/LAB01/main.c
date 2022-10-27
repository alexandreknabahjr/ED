// Biblioteca padrao na linguagem C
#include <stdlib.h>
// Assinaturas da funcoes criadas e estrutura criada
#include "jogadores.h"

int main()
{
    // Variavel do tipo criado
    JOGADOR jogador[JOGADORES];
    // Variaveis do tipo int
    int posicao;
    int partidas;
    int qtd;

    printf("Digite a quantidade de jogadores a serem inseridos no vetor: ");
    scanf("%d", &qtd);
    printf("\n");
    // Chamada da funcao que atribui dados aos jogadores
    atribui_dados(jogador, qtd);
    // Chamada da funcao que exibe as estatisticas dos jogadores
    exibe_estatisticas(jogador, qtd);

    printf("Digite a posicao no vetor do jogador escolhido: ");
    scanf("%d", &posicao);
    printf("Digite o numero de partidas disputadas pelo jogador: ");
    scanf("%d", &partidas);

    // Teste da funcao que determina se um jogador e bom ou nao
    if(eh_o_bom(jogador, posicao, partidas))
        printf("\nEh o bom!\n\n");
    else
        printf("\nNao eh o bom!\n\n");

    return 0;
}

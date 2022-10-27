// Assinaturas da funcoes criadas e estrutura criada
#include "jogadores.h"

// Atribuicao de dados aos jogadores:
void atribui_dados(JOGADOR j[], int qtd)
{
    int i; // Indice do laco

    for(i = 0; i < qtd; i++)
    {
        printf("Nome: ");
        fflush(stdin); // Limpa o buffer
        fgets(j[i].nome, NOME, stdin);
        printf("Idade: ");
        scanf("%d", &j[i].idade);
        printf("Numero de gols: ");
        scanf("%d", &j[i].num_gols);
        printf("Numero de faltas: ");
        scanf("%d", &j[i].num_faltas);
        printf("Numero de passes errados: ");
        scanf("%d", &j[i].num_passes_errados);
        printf("Numero de passes corretos: ");
        scanf("%d", &j[i].num_passes_corretos);
        printf("\n");
    }
}

// Exibicao das estatisticas dos jogadores:
void exibe_estatisticas(JOGADOR j[], int qtd)
{
    int i; // Indice do laco
    printf("Gols - Nome\n\n");
    // Imprime os gols e os nomes dos jogadores que os marcaram
    for(i = 0; i < qtd; i++)
    {
        printf("%d - %s\n", j[i].num_gols, j[i].nome);
    }
}

// Testa se um jogador e bom:
int eh_o_bom(JOGADOR j[], int posicao, int partidas)
{
    // Criterio utilizado: numero de gols divido pelo numero de partidas
    if(j[posicao].num_gols / partidas >= M_GOLS)
        return 1; // Retorna 1, que equivale a TRUE
    else
        return 0; // Retorna 0, que equivale a FALSE
}

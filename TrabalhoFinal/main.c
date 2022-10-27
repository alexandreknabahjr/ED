#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvores.h"

int main(int argc, char *argv[])
{
    // Ponteiros para os arquivos
    FILE *base, *entrada, *saida;

    // Inicialiacao da arvore ABP
    ABP *abp = NULL;
    ABP *abp2 = NULL;

    nodos_ABP = 0;
    rotacoes_ABP = 0;
    comparacoes_ABP = 0;

    // Inicialiacao da arvore AVL
    AVL *avl = NULL;
    AVL *avl2 = NULL;

    nodos_AVL = 0;
    rotacoes_AVL = 0;
    comparacoes_AVL = 0;

    // Estrutura auxiliar do tipo Comida
    COMIDA comida1;
    COMIDA comida2;
    char linha[300];
    int ok;
    char *nome_alimento1;
    char *calorias1;
    char *palavra;
    char *gramas;
    int gramas_convertidas = 0;
    int total_calorias = 0;

    if(argc != 4)
    {
        printf("Numero insuficiente de parametros!\n Lembre-se de digitar: %s <arquivo_base> <arquivo_entrada <arquivo_saida>\n", argv[0]);
        return 1;
    }

    base = fopen(argv[1], "r");
    if((base = fopen(argv[1], "r")) == NULL)
    {
        printf("Houve um erro ao abrir o arquivo base %s \n", argv[1]);
        return 1;
    }

    entrada = fopen(argv[2], "r");
    if((entrada = fopen(argv[2], "r")) == NULL)
    {
        printf("Houve um erro ao abrir o arquivo de entrada %s \n", argv[2]);
        return 1;
    }

    saida = fopen(argv[3], "w");
    if((saida = fopen(argv[3], "w")) == NULL)
    {
        printf("Houve um erro ao abrir o arquivo de saida %s \n", argv[3]);
        return 1;
    }

    while(fgets(linha, 1000, base))
    {
        nome_alimento1 = strtok(linha, ";");

        for(int i = 0; i < strlen(nome_alimento1); i++)
            nome_alimento1[i] = tolower(nome_alimento1[i]);

        strcpy(comida1.alimento, nome_alimento1);

        calorias1 = strtok(NULL, ";");
        comida1.calorias = atoi(calorias1);

        while(calorias1 != NULL)
        {
            abp = insere_abp(abp, comida1);
            avl = InsereAVL(avl, comida1, &ok);
            calorias1 = strtok(NULL, ";");
        }
    }

    fprintf(saida, "Calorias calculadas para %s usando a tabela %s\n", argv[2], argv[1]);

    while(fgets(linha, 1000, entrada))
    {
        palavra = strtok(linha, ";");

        for(int j = 0; j < strlen(palavra); j++)
            palavra[j] = tolower(palavra[j]);

        abp2 = consulta_abp(abp, palavra);
        avl2 = consulta_avl(avl, palavra);

        gramas = strtok(NULL, ";");
        gramas_convertidas = atoi(gramas);

        if(abp2 != NULL && avl2 != NULL)
        {
            strcpy(comida2.alimento, abp2->ingerida.alimento);
            comida2.calorias = abp2->ingerida.calorias;
            total_calorias += (comida2.calorias * gramas_convertidas / 100);

            fprintf(saida, "\n%dg de %s (%d calorias por 100g) = %d\n", gramas_convertidas, comida2.alimento, comida2.calorias, (comida2.calorias * gramas_convertidas / 100));
        }
    }

    fprintf(saida, "\nTotal de %d calorias consumidas no dia.\n\n", total_calorias);

    // Estatisticas:
    fprintf(saida, "\n======== Estatisticas ABP ========\n");
    fprintf(saida, "Numero de nodos: %d\n", nodos_ABP);
    fprintf(saida, "Altura: %d\n", altura_abp(abp));
    fprintf(saida, "Rotacoes: %d\n", rotacoes_ABP);
    fprintf(saida, "Comparacoes: %d\n", comparacoes_ABP);
    fprintf(saida, "\n======== Estatisticas AVL ========\n");
    fprintf(saida, "Numero de nodos: %d\n", nodos_AVL);
    fprintf(saida, "Altura: %d\n", Altura(avl));
    fprintf(saida, "Rotacoes: %d\n", rotacoes_AVL);
    fprintf(saida, "Comparacoes: %d\n", comparacoes_AVL);

    fclose(base);
    fclose(entrada);
    fclose(saida);

    return 0;
}


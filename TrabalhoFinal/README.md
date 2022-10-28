# Contando Calorias

Contando Calorias foi o Trabalho Final da disciplina Estruturas de Dados (INF01203) no semestre 2022/1. Com ele, pudemos aplicar os conhecimentos adquiridos no decorrer da cadeira: modularização, aprofundamento em ponteiros e armazenamento/consulta de dados em memória.

## Objetivo

O objetivo deste projeto foi de avaliar o desempenho de duas Árvores Binárias de Pesquisa: ABP e AVL. Para isso, analisamos o número de nodos adicionados, a altura, as rotações e as comparações de cada estrutura de dados.

## Entradas & Saídas

Entradas: dois arquivos com extensão .csv. O primeiro arquivo contém o nome dos alimentos e a quantidade de calorias a cada 100g. No segundo arquivo, temos o nome dos alimentos e a quantidade ingerida, em gramas, de cada alimento.

Saída: um arquivo com extensão .txt. Nele, temos a quantidade de calorias ingeridas, a quantidade total de calorias ingeridas ao longo do dia e as estatísticas de ambas as árvores. 

## Exemplo de chamada

```bash
C:\TrabalhoFinal allShuffled.csv day2.csv saidaallShuffled.txt
```

## ABP

```c
typedef struct abp{
        COMIDA ingerida;
        struct abp *esq;
        struct abp *dir;
}ABP;
```

## AVL

```c
typedef struct avl{
        COMIDA ingerida_avl;
        struct avl *esq;
        struct avl *dir;
        int FB;
}AVL;
```


## COMIDA

```c
typedef struct comida{
        int calorias;
        char alimento[50];
}COMIDA;
```

## Integrantes 

Alexandre Bartolo Knabah Júnior

Laura Becker Ramos



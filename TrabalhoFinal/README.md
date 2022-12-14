# Contando Calorias

Contando Calorias foi o Trabalho Final da disciplina Estruturas de Dados (INF01203) no semestre 2022/1. Com ele, pudemos aplicar os conhecimentos adquiridos no decorrer da cadeira: modularização, aprofundamento em ponteiros e armazenamento/consulta de dados em memória.

## Objetivo

O objetivo deste projeto foi de avaliar o desempenho de duas Árvores Binárias de Pesquisa: ABP e AVL. Para isso, analisamos o número de nodos adicionados, a altura, as rotações e as comparações de cada estrutura de dados.

## Entradas & Saídas

Entradas: dois arquivos com extensão .csv. O primeiro arquivo contém o nome dos alimentos e a quantidade de calorias a cada 100g. No segundo arquivo, temos os nomes dos alimentos e a quantidade ingerida, em gramas, de cada alimento.

Saída: um arquivo com extensão .txt. Nele, temos a quantidade de calorias ingeridas por alimento, a quantidade total de calorias ingeridas ao longo do dia e as estatísticas de ambas as árvores. 

## Exemplo de chamada

```bash
C:\TrabalhoFinal allShuffled.csv day2.csv saidaallShuffled.txt
```

## Estruturas

### ABP

```c
typedef struct abp{
        COMIDA ingerida;
        struct abp *esq;
        struct abp *dir;
}ABP;
```

### AVL

```c
typedef struct avl{
        COMIDA ingerida_avl;
        struct avl *esq;
        struct avl *dir;
        int FB;
}AVL;
```


### COMIDA

```c
typedef struct comida{
        int calorias;
        char alimento[50];
}COMIDA;
```

## Funções & Contadores

### ABP

```c
// Assinaturas:
ABP* insere_abp(ABP *a, COMIDA ingerida);
int altura_abp(ABP *a);
ABP* consulta_abp(ABP *a, char *chave);

// Contadores:
int nodos_ABP;
int rotacoes_ABP;
int comparacoes_ABP;
```

### AVL

```c
// Assinaturas:
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

// Contadores:
int nodos_AVL;
int rotacoes_AVL;
int comparacoes_AVL;
```

## Estatísticas 

### 1000Shuffled.csv e day1.csv
======== Estatisticas ABP ========  
Numero de nodos: 1000  
Altura: 22  
Rotacoes: 0  
Comparacoes: 310  

======== Estatisticas AVL ========  
Numero de nodos: 1000  
Altura: 12  
Rotacoes: 449  
Comparacoes: 248  

### 1000Sorted.csv e day1.csv
======== Estatisticas ABP ========  
Numero de nodos: 1000  
Altura: 867  
Rotacoes: 0  
Comparacoes: 6440  

======== Estatisticas AVL ========  
Numero de nodos: 1000  
Altura: 10  
Rotacoes: 986  
Comparacoes: 238  

### allShuffled.csv e day2.csv
======== Estatisticas ABP ========  
Numero de nodos: 1993  
Altura: 29  
Rotacoes: 0  
Comparacoes: 506  

======== Estatisticas AVL ========  
Numero de nodos: 1993  
Altura: 13  
Rotacoes: 934  
Comparacoes: 438  

### allSorted.csv e day2.csv
======== Estatisticas ABP ========  
Numero de nodos: 1993  
Altura: 1814  
Rotacoes: 0  
Comparacoes: 33484  

======== Estatisticas AVL ========  
Numero de nodos: 1993  
Altura: 12  
Rotacoes: 1869  
Comparacoes: 400  

## Integrantes 

Alexandre Bartolo Knabah Júnior  
Laura Becker Ramos

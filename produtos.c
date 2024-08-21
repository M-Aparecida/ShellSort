#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

Produto* lerProdutos(const char* nome_do_arquivo, int* n) {
    FILE *arquivo = fopen(nome_do_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return NULL;
    }

    int capacidade = 50;
    Produto *produtos = (Produto*) malloc(capacidade * sizeof(Produto));
    if (produtos == NULL) {
        printf("Erro ao alocar memoria");
        fclose(arquivo);
        return NULL;
    }

    *n = 0;
    while (fscanf(arquivo, "%s %f", produtos[*n].nome, &produtos[*n].preco) != EOF) {
        (*n)++;
        if (*n >= capacidade) {
            capacidade *= 2;
            produtos = (Produto*) realloc(produtos, capacidade * sizeof(Produto));
            if (produtos == NULL) {
                printf("Erro ao realocar memoria");
                fclose(arquivo);
                return NULL;
            }
        }
    }

    fclose(arquivo);
    return produtos;
}

void exibirProdutos(const Produto* produtos, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }
}

void ordenarProdutosPorPreco(Produto* produtos, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Produto temp = produtos[i];
            int j;
            for (j = i; j >= gap && produtos[j - gap].preco > temp.preco; j -= gap) {
                produtos[j] = produtos[j - gap];
            }
            produtos[j] = temp;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "produtos.h"

int main() {
    int n;
    Produto *produtos = lerProdutos("produtos.txt", &n);

    if (produtos == NULL || n == 0) {
        printf("Nenhum produto foi lido.\n");
        return 1;
    }

    clock_t inicio = clock();

    ordenarProdutosPorPreco(produtos, n);

    clock_t fim = clock();

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Produtos ordenados por preco:\n");
    exibirProdutos(produtos, n);

    printf("\nTempo de execucao: %.6f segundos\n", tempo_execucao);

    free(produtos);
    return 0;
}
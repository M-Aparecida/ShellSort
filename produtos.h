#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
} Produto;

/*Função para ler os produtos do arquivo*/
Produto* lerProdutos(const char* nome_do_arquivo, int* n);

/*Função para exibir os produtos*/
void exibirProdutos(const Produto* produtos, int n);

/*Função para ordenar os produtos usando Shell Sort*/
void ordenarProdutosPorPreco(Produto* produtos, int n);
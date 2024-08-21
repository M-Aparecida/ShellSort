# Shell Sort

## Objetivo do programa
- Implementar um algoritmo que manipula um tipo estruturado Produtos e que possui a funcionalidade de ordenar 50 produtos em ordem crescente de preço utilizando o Algoritmo de Ordenação Shell Sort.

## Desenvolvedora
- Maria Aparecida da Silva. 

## Como funciona
-  O Shell Sort compara elementos que estão a uma certa "distância" um do outro. Essa "distância" é determinada por uma sequência de incrementos ou intervalos, chamada de "gap", que diminui gradualmente até se tornar 1.

## Implementação
``` c
void ordenarProdutosPorPreco(Produto* produtos, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) { // O laço define o gap, começando com metade do tamanho do array e reduzindo-o pela metade em cada finalização
        for (int i = gap; i < n; i++) { //percorre o array a partir do índice gap até o final
            Produto temp = produtos[i]; //armazena o produto atual em uma variável temporária
            int j; //declara uma variável para o laço de inserção
            for (j = i; j >= gap && produtos[j - gap].preco > temp.preco; j -= gap) { // Move os produtos maiores para a posição correta, comparando o preço do produto atual com os produtos que estão gap posições atrás
                produtos[j] = produtos[j - gap]; // desloca o produto maior para a frente no array
            }
            produtos[j] = temp;  //insere o produto temporário na posição correta após o loop interno.
        }
    }
```

## Complexidade de tempo
### Melhor caso
Quando a coleção de entrada está parcialmente ordenada
````
O(nlogn)
````
### Pior caso
Varia dependendo da sequência de intervalos utilizada, se precisar ordenar um array inverso
````
O(n^2)
````
## Complexidade de espaço
### Melhor e pior caso
Não requer espaço adicional além do necessário para armazenar os dados de entrada
````
O(1)
````
## Como rodar o programa?

Clone o repositório no seu terminal

```
git clone https://github.com/M-Aparecida/ShellSort
```

Vá até o diretório onde o arquivo .c se encontra, e no terminal use o seguinte comando
```
gcc main.c produtos.c -o produtos_precos
./produtos_precos
```


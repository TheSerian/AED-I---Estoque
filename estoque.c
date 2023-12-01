#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

#define tamanho_inicial 10
#define tamanho_incremento 10

void informacoesProduto (Produto *produto){
  printf("Insira o numero de identificacao do produto: ");
  scanf("%i", &produto->id);

  printf("Insira a descricao do produto (max. 50 caracteres): " );
  getchar();
  fgets(produto->descricao, 51, stdin);
  produto->descricao[strcspn(produto->descricao, "\n")] = '\0';

  printf("Insira a categoria do produto: ");
  scanf("%i", &produto->categoria);

  printf("Insira o valor (em reais) do produto: ");
  scanf("%f", &produto->valor);

  printf("Insira a quantidade do produto: ");
  scanf("%i", &produto->quantidade);

}

int inserirInicio (Produto produto, Estoque *estoque){
  if (estoque->qtdProdutos % tamanho_incremento == 0){
    estoque->produtos = realloc(estoque->produtos, estoque->qtdProdutos + tamanho_incremento * sizeof(Produto));
  }
  if (estoque->produtos == NULL){
    printf("Erro de alocacao de memoria.\n");

    return 0; //alocacao mal sucedida
  }
  for (int i = estoque->qtdProdutos; i > 0; i--){
    estoque->produtos [i] = estoque->produtos [i-1];
  }
  estoque->produtos[0] = produto;
  estoque->qtdProdutos++;
  printf("Insercao bem sucedida.\n");

  return 1;
}

int inserirFim (Produto produto, Estoque *estoque){
  if (estoque->qtdProdutos % tamanho_incremento == 0){
    estoque->produtos = realloc(estoque->produtos, estoque->qtdProdutos + tamanho_incremento * sizeof(Produto));
  }
  if (estoque->produtos == NULL){
    printf("Erro de alocacao de memoria.\n");

    return 0; //alocacao mal sucedida
  }
  estoque->produtos[estoque->qtdProdutos] = produto;
  estoque->qtdProdutos++;
  printf("Insercao bem sucedida.\n");

  return 1;
}

int inserirPosicao (Produto produto, int posicao, Estoque *estoque){
  if (posicao < 0 || posicao > estoque->qtdProdutos){
    printf("Posicao invalida.\n");

    return 0;
  }
  if (estoque->qtdProdutos % tamanho_incremento == 0){
    estoque->produtos = realloc(estoque->produtos, estoque->qtdProdutos + tamanho_incremento * sizeof(Produto));
  }
  if (estoque->produtos == NULL){
    printf("Erro de alocacao de memoria.\n");

    return 0; //alocacao mal sucedida
  }
  for (int i = estoque->qtdProdutos; i > posicao; i--){
    estoque->produtos[i] = estoque->produtos[i-1];
  }
  estoque->produtos[posicao] = produto;
  estoque->qtdProdutos++;
  printf("Insercao bem sucedida.\n");

  return 1;
}

void listar (Estoque estoque){
    if(estoque.qtdProdutos == 0){
        printf("Estoque vazio.\n");

        return;
  }
    printf("Lista de Produtos no Estoque:\n");
    int j = 0;
    for(int i = 0; i < estoque.qtdProdutos; i++){
        printf("\nProduto %i: %s\n", j + 1, estoque.produtos[i].descricao);
        printf("ID: %i\n", estoque.produtos[i].id);
        printf("Categoria: %i\n", estoque.produtos[i].categoria);
        printf("Valor: %.2f reais\n", estoque.produtos[i].valor);
        printf("Quantidade: %i\n", estoque.produtos[i].quantidade);
        j++;
  }
}

int removerPosicao (int posicao, Estoque *estoque){
    if(estoque->qtdProdutos == 0){
        printf("Estoque vazio, impossivel remover.\n");

        return 0;
    }

    if (posicao < 0 || posicao > estoque->qtdProdutos){
        printf("Posicao invalida.\n");

        return 0;
    }
    for (int i = posicao; i < estoque->qtdProdutos; i++){
    estoque->produtos[i] = estoque->produtos[i+1];
    }
    estoque->qtdProdutos--;
    printf("Remocao bem sucedida.\n");

    return 1;
  }

int removerValor (int id, Estoque *estoque){
    if(estoque->qtdProdutos == 0){
            printf("Estoque vazio, impossivel remover.\n");

            return 0;

  }
    for (int i = 0; i < estoque->qtdProdutos; i++){
            if (estoque->produtos[i].id == id){
                estoque->produtos[i] = estoque->produtos[i+1];
                printf("Remocao bem sucedida.\n");
                estoque->qtdProdutos--;

                return 1;
    }

  }
  printf("Nao existe um produto com esse id no estoque.\n");

  return -1;

}

int procurar (int id, Estoque *estoque){
    if(estoque->qtdProdutos == 0){
            printf("Estoque vazio.\n");

    return 0;
  }
    for (int i = 0; i < estoque->qtdProdutos; i++){
            if (estoque->produtos[i].id == id){
                printf("O produto de id %i esta na posicao %i.\n", id, i + 1);

                return 1;

        }
    }
    printf("Nao existe um produto com esse id no estoque.\n");

    return -1;
}

int tamanho (Estoque *estoque){
    if (estoque->qtdProdutos == 0){
        printf("Estoque vazio.\n");

    return 0;
    }
    printf("Tamanho do estoque: %i\n", estoque->qtdProdutos);

    return 1;
}

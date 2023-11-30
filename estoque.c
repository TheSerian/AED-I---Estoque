#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

#define tamanho_inicial 10
#define tamanho_incremento 10

int inserirInicio (Produto produto, Estoque *estoque){
  if (estoque->qtdProdutos % tamanho_incremento == 0){
    estoque->produtos = realloc(estoque->produtos, estoque->qtdProdutos + tamanho_incremento * sizeof(Produto));
  }
  if (estoque->produtos == NULL){
    printf("Erro de alocacao de memoria.\n");
    return 0; //alocacao mal sucedida
  }
  for (int i = estoque->qtdProdutos; i < 0; i--){
    estoque->produtos [i] = estoque->produtos [i--];
  }
  estoque->produtos[0] = produto;
  estoque->qtdProdutos++;
  return 1; //insercao bem sucedida
}



int inserirFim (Produto produto, Estoque *estoque);
int inserirPosicao (Produto produto, int posicao, Estoque *estoque);
void listar (Estoque estoque);
int removerPosicao (int posicao, Estoque *estoque);
int removerValor (int id, Estoque *estoque);
int procurar (int id, Estoque *estoque);
int tamanho (Estoque *estoque);
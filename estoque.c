#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

#define tamanho_inicial 10
#define tamanho_incremento 10

void informacoesProduto (Produto *produto){
  printf("Insira o numero de identificacao do produto: ");
  scanf("%i", &produto->id);
  
  printf("Insira a descricao do produto (max. 50 caracteres):" );
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
  for (int i = estoque->qtdProdutos; i < 0; i--){
    estoque->produtos [i] = estoque->produtos [i--];
  }
  estoque->produtos[0] = produto;
  estoque->qtdProdutos++;
  
  return 1; //insercao bem sucedida
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
  
  return 1; //insercao bem sucedida
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
    estoque->produtos[i] = estoque->produtos[i--];
  }
  estoque->produtos[posicao] = produto;
  estoque->qtdProdutos++;

  return 1; //insercao bem sucedida
  
}
void listar (Estoque estoque);
int removerPosicao (int posicao, Estoque *estoque);
int removerValor (int id, Estoque *estoque);
int procurar (int id, Estoque *estoque);
int tamanho (Estoque *estoque);

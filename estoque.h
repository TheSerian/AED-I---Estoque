#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct{ //estrutura do produto
  int id;
  char descricao[50];
  int categoria;
  float valor;
  int quantidade;
} Produto;

typedef struct{ //organização do estoque
  produto *produtos;
  int qtdProdutos;
} Estoque;

int inserirInicio (Produto produto, Estoque *estoque);
int inserirFim (Produto produto, Estoque *estoque);
int inserirPosicao (Produto produto, int posicao, Estoque *estoque);
void listar (Estoque estoque);
int removerPosicao (int posicao, Estoque *estoque);
int removerValor (int id, Estoque *estoque);
int procurar (int id, Estoque *estoque);
int tamanho (Estoque *estoque);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

#define tamanho_inicial 10
#define tamanho_incremento 10

int main() {
  Estoque estoque;
  Produto produto;
  char opcao;
  int posicao;

  estoque.produtos = malloc(tamanho_inicial * sizeof(Produto));
  estoque.qtdProdutos = 0;

  if (estoque.produtos == NULL){
    printf("Erro de alocacao de memoria.\n");
    return 1;
  }
  do{
    printf("\n1. Inserir produto no inicio do estoque.\n");
    printf("2. Inserir produto no fim do estoque.\n");
    printf("3. Escolher a posicao na qual o produto sera inserido.\n");
    printf("4. Listar os produtos no estoque.\n");
    printf("5. Escolher a posicao na qual o produto sera removido.\n");
    printf("6. Escolher qual produto sera removido.\n");
    printf("7. Procurar um produto no estoque.\n");
    printf("8. Tamanho do estoque.\n");
    printf("0. Sair do estoque.\n");
    printf("Escolha a opcao: ");
    scanf("%c", &opcao);
    getchar();

    switch(opcao){
      case '1':
        informacoesProduto (&produto);
        getchar();
        inserirInicio (produto, &estoque);
        break;
      
      case '2':
        informacoesProduto (&produto);
        getchar();
        inserirFim (produto, &estoque);
        break;
      
      case '3':
        printf("Posicoes disponiveis: %i\n", estoque.qtdProdutos + 1);
        printf("Informe a posicao na qual deseja inserir o produto: ");
        scanf("%i", &posicao);
        informacoesProduto (&produto);
        getchar();
        inserirPosicao (produto, posicao - 1, &estoque);
        break;
      
      case '4':
        listar (estoque);
        break;
      
      case '5':
        printf("Posicoes disponiveis: %i\n", estoque.qtdProdutos + 1);
        printf("Informe a posicao na qual deseja remover o produto: ");
        scanf("%i", &posicao);
        removerPosicao (posicao, estoque);
        break;
      
      case '6':
      case '7':
      case '8':
      case '0':
        printf("Encerrando o programa...\n");
        break;
      
      default:
        printf("Opcao invalida.\n");
        getchar();
    }
  }while (opcao != '0');

  free(estoque.produtos);

  return 0;  
}

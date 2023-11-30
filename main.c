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
    printf("1. Inserir produto no inicio do estoque.\n");
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
        informacoesProduto (&produto);
        getchar();
        break;
      
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '0':
        printf("Encerrando o programa...\n");
        break;
      
      default:
        printf("Opcao invalida.\n");
    }
  }while (opcao != '0');

  free(estoque.produtos);

  return 0;  
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

void inserir_inicio(No **lista, int num){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
  }
}

void inserir_fim(No **lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;

    if(*lista==NULL)
      *lista=novo;
    else{
      aux = *lista;
      while(aux->proximo)
        aux=aux->proximo;
      aux->proximo=novo;
    }
  }
}

void inserir_meio(No **lista, int num, int ant){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor=num;

    if(*lista==NULL){
      novo->proximo=NULL;
      *lista=novo;
    }else{
      aux=*lista;
      while(aux->valor != ant && aux->proximo)
        aux=aux->proximo;
      novo->proximo=aux->proximo;
      aux->proximo=novo;
    }
  }
}

void imprimir(No *no){
  printf("\nLista: ");
  while(no){
    printf("%d ",no->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

int main(void) {
  int opcao, valor, anterior;
  No *lista = NULL;

  do{
    printf("[1] Inserir no inicio\n[2] Inserir no fim\n[3] Inserir no meio\n[4] Imprimir\n[0] Sair\n\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        system("clear");
        printf("\n Valor: ");
        scanf("%d",&valor);
        inserir_inicio(&lista,valor);
        break;
      case 2:
        system("clear");
        printf("\n Valor: ");
        scanf("%d",&valor);
        inserir_fim(&lista,valor);
        break;
      case 3:
        system("clear");
        printf("\n Valor: ");
        scanf("%d",&valor);
        printf("\n Anterior: ");
        scanf("%d",&anterior);
        inserir_meio(&lista,valor,anterior);
        break;
      case 4:
        imprimir(lista);
        break;
      default:
        if(opcao!=0)
          printf("Opção inválida\n");
    }
  }while(opcao!=0);
}

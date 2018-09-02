#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int info;
    struct Elemento *prox;
}TElemento;

typedef struct Lista{
    TElemento *inicio;
    TElemento *fim;
}TLista;

void inicializa_lista(TLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;

}
int inserir_elemento(TLista *lista){
    TElemento *novo;
    novo = malloc(sizeof(TElemento));

    scanf("%d",&novo->info);
    novo->prox =NULL;

    if(lista->inicio == NULL){
        lista->inicio=novo;
        lista->fim=novo;
    }
    else{
        lista->fim->prox = novo;
        lista->fim = novo;

    }
}
void apresentar_elementos(TLista *lista){
    TElemento *aux;
    aux = lista->inicio;

    if(aux == NULL){
        printf("Lista Vazia!!!");
    }
    else{
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->prox;

        }
    }
}
void busca_exclusao(TLista *lista){
    int valor;
    TElemento *anterior, *atual;

    scanf("%d",&valor);

    if(lista->inicio==NULL){
        printf("\n lista vazia!");
    }
    else{
        anterior=lista->inicio;
        atual= lista->inicio;
        while(atual!=NULL){

            if(atual->info == valor){

                if(atual == lista->inicio){

                    lista->inicio = lista->inicio->prox;
                    free(atual);
                    break;
                }
                else{
                    if(atual == lista->fim){
                        lista->fim = anterior;
                    }
                    anterior->prox = atual->prox;
                    free(atual);
                    break;
                }
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
            
        }

    }

}

int x=0, z=0, j, i;
int main(){
    TLista Li;

    inicializa_lista(&Li);

    scanf("%d",&i);
    while(x<i){
        inserir_elemento(&Li);
        x++;
    }

    scanf("%d",&j);
    while(z<j){
        busca_exclusao(&Li);
        z++;
    }
    apresentar_elementos(&Li);

}

#include <stdio.h>
#include<stdlib.h>

typedef struct NO{
    int dado;
    struct NO* prox;
} NO;

typedef struct FILA{
    NO* inicio;
    NO* fim;
} FILA;

FILA *f;

void enfileira(int valor){
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = valor;
    ptr->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = ptr;
    else
        f->fim->prox = ptr;
    f->fim = ptr;
}

int desenfileira(){
    NO* ptr = f->inicio;
    int dado;
    if(ptr != NULL){
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
    return -1;
}    

//Inserido por mim
void print_fila(FILA *fila){
    //armazena o primeiro elemento da fila num Nó auxiliar;
    NO *aux = fila->inicio;

    //verifica se a fila esta vazia
    if(aux == NULL){
        printf("ERRO: A FILA ESTÁ VAZIA!\n");
    }

    // Percorre a fila dinamicamente ate chegar o nó com poteiro nulo
    else {
        while (aux != NULL)
        {
            //imprime o dado do no atual
            printf("%d ", aux->dado);
            //pula para o proximo nó
            aux = aux->prox;
        }
    }
    printf("\n");
}

int main(){
    f = (FILA *) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;
    enfileira(10);
    enfileira(30);
    enfileira(50);
    desenfileira();
    enfileira(14);

    print_fila(f);
}
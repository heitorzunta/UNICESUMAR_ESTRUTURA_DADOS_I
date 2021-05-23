/* Implentação da estrutura de dados FILA
    tem como estrutura base ser FIFO - First In First Out
*/    

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura do NO
typedef struct NODE
{
    // Estrutura do NÓ = NODE
    int data; //armazena dados neste caso int
    struct NODE *next; //ponteiro que armazena a posicao do próximo NODE
}NODE;

// Estrutura da FILA
typedef struct FILA
{
    NODE *first;
    NODE *last;
}FILA;

// Operacao com a FILA
// 1. Enfileirar
void push_back(FILA *fila, int data){
    NODE *ptr = (NODE *) malloc(sizeof(NODE));
    ptr->data = data;
    ptr->next = NULL;

    if(fila->first == NULL){
        fila->first = ptr;
    }

    else {
        //O "ultimo do fila" agora aponta para o novo ultimo da fila "ptr"
        fila->last->next = ptr;
    }

    /* "ptr" torna-se oficialmente o ultimo da fila
        aqui ele esta fora do else porque ocorre em ambos os casos
    */
    fila->last = ptr;
}

// 2. Desenfileirar
bool pop(FILA *fila) {
    /* Como temos uma FILA a regra de negócios e FIFO,
     assim precisamos remover o primeiro elemento, 
     para isto vamos carrega-lo num NO auxiliar
    */ 

   NODE *aux = fila->first;

    // se a fila não esta vazia
   if(aux->next != NULL){
        //o segundo elemento da fila sera agora o primeiro elemento
       fila->first = fila->first->next;
       // desconectamos o antigo primeiro elemento agora aux
       aux->next = NULL;
       // No meu caso como estou fazendo um teste bool vou imprimir o dado do NÓ
       printf("%d\n", aux->data);
       //destruindo na memoria o NO removido
       free(aux);
       return true;
   }
    // Quando a fila estiver vazia retirna falso para o metodo pop()
    return false;    
}

void print_fila(FILA *fila){
    //armazena o primeiro elemento da fila num Nó auxiliar;
    NODE *aux = fila->first;

    //verifica se a fila esta vazia
    if(aux == NULL){
        printf("ERRO: A FILA ESTÁ VAZIA!\n");
    }

    // Percorre a fila dinamicamente ate chegar o nó com poteiro nulo
    else {
        while (aux != NULL)
        {
            //imprime o dado do no atual
            printf("%d ", aux->data);
            //pula para o proximo nó
            aux = aux->next;
        }
    }
    printf("\n");
}

// Implementando os métodos para teste
int main(int argc, char const *argv[])
{
    //Criando a fila (ponteiro) de teste, toda fila que se preze chama-se 'f'
    FILA *f = (FILA *) malloc(sizeof(FILA));
    f->first = NULL;
    f->last = NULL;

    // povoando a fila com numeros
    printf("Inserindo o numero 5\n");
    push_back(f, 5);
    printf("Inserindo o numero 2\n");
    push_back(f, 2);
    printf("Inserindo o numero 10\n");
    push_back(f, 10);
    printf("Inserindo o numero 4\n");
    push_back(f, 4);
    

    printf("Imprimindo a fila: ");
    print_fila(f);

    //Removendo o primeiro elemento
    printf("Removendo o primeiro elemento atual da fila: ");
    pop(f);

    //imprime a fila novamente
    printf("Imprimindo a fila: ");
    print_fila(f);
    return 0;
}

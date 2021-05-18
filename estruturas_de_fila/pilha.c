//Definição de pilhs dinamicamente alocada

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Aqui iremos inicializar o nó, lembre-se que o nó é um estrutura mista de dados (comporta dados e um ponteiro)
 * aqui  os dados podem ser ate um estrutura mista como os dados de um pessoa, produto etc, ja o ponteiro tem a 
 * funçao de indicar onde esta o próximo nó, pois estamos trabalhando com memória dinamicamente alocada. Note que
 * inicializamos o indicador de nó como NULL isto quer dizer que a caixa ainda nao aponta para nada. 
 */ 
typedef struct Node
{
        int data;
        struct Node *next;
} Node;

/**
 * Aqui iremos iniciar nossa estrutura de trabalho que neste caso sera um pilha, a pilha e conhecida por ser LIFO
 * Last In First Out, ouse seja so iremos usar o topo para inserir e remover elementos (nós) da pilha. Como podemos ver
 * uma pilha nada mais é que uma coleçao de nós. o que vai mudar e como suas propriedades se comportam. 
*/
typedef struct Stack
{
    Node *top;
}Stack ;

//Uma das duas funcoes principais da pilha o método empilha tem como função inserir no topo o novo nó de dados
bool push(int number, Stack *stack)
{
    Node *node = (Node*) malloc(sizeof(Node));  // nesta linha usamos o malloc para criar um nó dinamico na memória
                                                // Note que como nosso nó armazena nós, usamos no malloc
                                                // o tamanho de um nó.
    /**
     *  If que verifica se o nó foi criado na memoria, caso a memoria estiver cheia ele nao será e o malloc retorna false
     */
    if(node == NULL) {
        printf("Erro na criação do nó.\n");
        return false;
    }

    /**
     * Senão ele faz a operacao do push()
     */
    else {
        node->data = number; //povoa a dado no novo nó
        node->next = stack->top; //o nó recem criado recebe o dado do atual topo.
        stack->top = node; // o novo nó torna-se o novo topo da pilha
        return true;
    }
}

/**
*Remove (se houver) o elemento da pilha (desempilhar), neste caso ele retorna o elemento numérico
*/
bool pop(Stack *stack)
{
    //verifica-se se a pilha esta vazia!
    if(stack->top == NULL){  
        printf("Impossivel remover! A pilha está vazia!\n");
        return false;
    }
    else {
        Node *auxiliary = (Node*) malloc(sizeof(Node));
        //verifica se temos espaço em memória para remover o nó
        if(auxiliary == NULL){
            printf ("Erro ao criar nó, memoria insuficiente!");
            return false;
        }
        //remove o no do topo e exibe seu valor
        else {
            auxiliary = stack->top;          //no auxiliar que recebera o no do topo atual
            stack->top = auxiliary->next;  // recupera o endereco de memoria onde fica o proximo nó depois da antigo topo
                                           // e transforma ele em topo da pilha. 
            printf("%d\n", auxiliary->data); //exibe o conteudo (numerico) do nó removido
            free(auxiliary);               // destroi o nó na memória
            return true;
        }
    }
}
/**
 *  Imprime os elementos na pilha
 */
void print_elements_stack(Stack *stack)
{
    //Cria o nó auxiliar
    Node *auxiliary = stack->top;

    //Verifica se a pilha não está vazia
    if(auxiliary == NULL){
        printf ("Pilha vazia!\n");
    }
    //Caso não esteja percorre exibindo todos os dados até a base
    else {
        while (auxiliary != NULL){ //enquanto não chegar na base(a base nao aponta para ninguem NULL)
            printf("%d ", auxiliary->data); //imprime o dado armazenado no nó
            auxiliary = auxiliary->next; // vai para o proximo nó
        }
    }
    free(auxiliary); //destruindo o nó auxiliar
    printf("\n"); //separa a linha de resposta
}

int main(int argc, char const *argv[])
{

    //inicializando a pilha!
    Stack *pilha =(Stack*) malloc(sizeof(Stack));

    //se não tiver espaço em memoria gera erro
    if(pilha == NULL){
        printf("Erro ao gerar a pilha!\n"); // mensagem de erro
        return -1; //codigo de erro escolhido por mim, pode ser qualquer numero menos o 0
    }

    //teste de remover elemento com pilha vazia
    pop(pilha);

    //Inserindo numeros na pilha
    push(1, pilha);
    push(2, pilha);
    push(3,pilha);

    //imprimindo elementos na pilha
    printf("Imprimindo a pilha: ");
    print_elements_stack(pilha);

    //removendo os elementos da pilha
    printf("removendo o top atual: ");
    pop(pilha);

    //Mostrando os elemenetos restantes;
    printf("Imprimindo os elementos restantes: ");
    print_elements_stack(pilha);

    return 0;
}

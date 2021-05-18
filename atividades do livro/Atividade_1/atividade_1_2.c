// 2. Uma famosa fábrica de semáforos está testando um novo protótipo, menor, mais barato e eficiente. Foi solicitado à equipe de TI um programa em linguagem C para fazer o teste do novo hardware. O semáforo
// tem três objetos, cada um contém um atributo cor e outro id. Devido às limitações de memória e processamento, é necessária a criação de um ponteiro que vai percorrendo a memória e imprimindo o valor na tela.
// Crie uma estrutura que tenha dois atributos: cor (cadeia de caracteres) e id (inteiro).
// Crie três variáveis com o tipo definido no item a. Crie um ponteiro do mesmo tipo.
// Inicialize as estruturas da seguinte forma:
// • cor vermelha, id 1.
// • cor amarela, id 2.
// • cor verde, id 3.
// Inicialize o ponteiro apontando para a primeira variável criada.
// Por meio de operações aritméticas com ponteiros, percorra a memória e imprima o valor de cada uma das variáveis criadas nesse programa.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct 
{
    char cor[20];
    int id;
}typedef Objeto;




int main()
{
    //Criando as estruturas de dados
    Objeto objeto1;
    Objeto objeto2;
    Objeto objeto3;

    //Povoando as estruturas de dados
    strcpy(objeto1.cor, "vermelha");
    objeto1.id = 1;

    strcpy(objeto2.cor, "amarela");
    objeto2.id = 2;

    strcpy(objeto3.cor, "verde");
    objeto3.id = 3;

    //Inicializando o ponteiro
    Objeto *ponteiro_de_objetos;
    ponteiro_de_objetos = &objeto1;

    //percorrendo o ponteiro com a operacao entre ponteiro
        printf("No objeto %d, temos a cor %s e a valor de id %d\n", ponteiro_de_objetos->id, ponteiro_de_objetos->cor, ponteiro_de_objetos->id);
        ponteiro_de_objetos = ponteiro_de_objetos + 1;
        printf("No objeto %d, temos a cor %s e a valor de id %d\n", ponteiro_de_objetos->id, ponteiro_de_objetos->cor, ponteiro_de_objetos->id);
        ponteiro_de_objetos = ponteiro_de_objetos + 1;
        printf("No objeto %d, temos a cor %s e a valor de id %d\n", ponteiro_de_objetos->id, ponteiro_de_objetos->cor, ponteiro_de_objetos->id);
    return 0;
}

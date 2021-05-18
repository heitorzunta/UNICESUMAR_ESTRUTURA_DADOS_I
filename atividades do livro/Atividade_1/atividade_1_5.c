// 5. Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com o tamanho
// lido e outro com o dobro desse tamanho. Preencha esses vetores respectivamente com potências
// de 2 e potências de 3.
// a) Crie uma variável inteira e dois ponteiros do tipo inteiro.
// b) Pergunte ao usuário o tamanho do vetor dinâmico e leia esse valor na variável inteira.
// c) Aloque dinamicamente os dois vetores usando a função malloc.
// d) Faça um laço de repetição para preencher o primeiro vetor com potências
// de 2.
// e) Faça um segundo laço de repetição para preencher o outro vetor com potências de 3.
// f) Não se esqueça de usar a biblioteca math.h para poder usar o cálculo de potência (pow).

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //item f

int main(int argc, char const *argv[])
{
    //item  a
    int tamanho; //variavel inteira
    int *ponteiro_1, *ponteiro_2; //ponteiros inteiros

    //item b
    printf("Digite o tamanho do vetor dinâmico que você quer usar?: ");
    scanf("%d", &tamanho);

    //item c
    ponteiro_1 = (int *) malloc(sizeof(int) * tamanho); //capacidade de 1 inteiro multiplicado pelo tamanho
    ponteiro_2 = (int *) malloc(sizeof(int) * tamanho);

    //item d
    for (int i = 0; i < tamanho; i++){
        ponteiro_1[i] = pow(2, i);
    }

    //item e
    for (int i = 0; i < tamanho; i++){
        ponteiro_2[i] = pow(3, i);
    }

    //teste

    for (int i=0; i<tamanho; i++){
        printf("2 elevado a %d e igual a: %d\n", i, ponteiro_1[i]);
    }
    printf("\n\n");
    for (int i=0; i<tamanho; i++){
        printf("3 elevado a %d e igual a: %d\n", i, ponteiro_2[i]);
    }
    //extra
    //desalocacao de memoria do ponteiro
    free(ponteiro_1);
    free(ponteiro_2);
    return 0;
}

// 1. Faça um pequeno programa para testar seus conhecimentos sobre ponteiros e alocação dinâmica na memória.
// a) Defina um ponteiro do tipo inteiro.
// b) Faça alocação dinâmica para o ponteiro recém-criado.
// c) Preencha a memória com o valor 42.
// d) Imprima o endereço do ponteiro na memória e o valor contido nele.

#include <stdlib.h>
#include <stdio.h>

int main () {

    int *ponteiro_inteiro;

    ponteiro_inteiro = (int *) malloc(sizeof(int));

    *ponteiro_inteiro = 42;

    printf("Endereco memoria ponteiro: %p e valor alocado ponteiro: %d\n", ponteiro_inteiro, *ponteiro_inteiro); 
    free(ponteiro_inteiro);
    return 0;
}

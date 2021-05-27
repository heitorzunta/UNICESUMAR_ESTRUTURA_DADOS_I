/**
 *  Introdução a aplicação de grafos na linguagem C
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Definição do tamanho maximo do nossos array fixos
#define tamanho_maximo 10

// Declaração das variaveis
int tamanho = 0, grafo[tamanho_maximo], 
    matriz_adjacente[tamanho_maximo][tamanho_maximo], 
    opcao = -1;

//Funcoes utilizadas
//Tamanho do Grafo
int grafo_tamanho() {
    int tamanho;

    printf ("Digite a quantidade de vértices que teremos em nosso grafo: ");
    scanf ("%d", &tamanho);
    return tamanho;    
}
//Inserir aresta no grafo
void inserir_aresta()
{
    int origem, destino;

    //validando e armazenando a origem
    do {
        printf ("Digite o vertice de origem, o vertice vária de 0 até %d: ", tamanho - 1);
        scanf("%d", &origem);
    } while (origem < 0 || origem >= tamanho);

    //validando e armazenando a origem
    do {
        printf ("Digite o vertice de destino, o vertice vária de 0 até %d: ", tamanho - 1);
        scanf("%d", &destino);
    } while (destino < 0 || destino >= tamanho);

    matriz_adjacente[origem][destino] = 1;
    matriz_adjacente[destino][origem] = 1;
}

/**
 * Remover aresta do grafo
 */
void remover_aresta()
{
    int origem, destino;

    //validando e armazenando a origem
    do {
        printf ("Digite o vertice de origem, o vertice vária de 0 até %d: ", tamanho - 1);
        scanf("%d", &origem);
    } while (origem < 0 || origem >= tamanho);

    //validando e armazenando a origem
    do {
        printf ("Digite o vertice de destino, o vertice vária de 0 até %d: ", tamanho - 1);
        scanf("%d", &destino);
    } while (destino < 0 || destino >= tamanho);

    matriz_adjacente[origem][destino] = 0;
    matriz_adjacente[destino][origem] = 0;
}

/**
 * Exibe os Vertice do GRAFO
 */

void desenhar_vertice_grafo()
{
    //Imprime os n-1 elementos
    printf ("Imprimindo os vértices do grafo: [");
    for(int i = 0; i < tamanho - 1; i++){
        printf("%d, ", grafo[i]);
    }
    //Imprime o ultimo elemento
    printf ("%d]\n", grafo[tamanho - 1]);
}

void desenhar_matriz_adjacente()
{
    //Imprime a matriz adjacente 
    printf("Imprimindo a matriz adjacente:\n");
    for(int i = 0; i < tamanho; i++){
        printf("|");
        for(int j = 0; j < tamanho; j++){
            printf("\t%d\t", matriz_adjacente[i][j]);
        }
        printf("|\n");
    }
}

void menu(){
    printf("\nEscolha uma opcao:\n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair do programa\n");
}

int main(int argc, char const *argv[])
{

    //validando e recebendo a função grafo_tamanho()
    while (tamanho <= 0 || tamanho > tamanho_maximo){
        tamanho = grafo_tamanho();

        if (tamanho <= 0 || tamanho > tamanho_maximo){
            printf ("Escolha valores entre 1 a %d", tamanho_maximo);
        }

        //se passar a validação inicialize os valores dos vertices no grafo.
        else {
            for (int i = 0; i < tamanho; i++){
                grafo[i] = i;
            }
        }
    }

    // GERANDO O MENU DE OPCOES
    while (opcao != 0)
    {
        desenhar_vertice_grafo();
        desenhar_matriz_adjacente();

        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;     
        case 1:
            inserir_aresta();
            break;

        case 2:
            remover_aresta();
            break;
        
        default:
            printf("Opção inválida!\n");
            sleep(3);
            break;
        }
    }
    return 0;
}



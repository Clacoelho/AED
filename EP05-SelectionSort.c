#include <stdio.h>

#include <stdlib.h>

#include <time.h>





//Função retirada do livro indicado

void Seleção (int n, int v[]) {
    int i, j, min, x;
    for (i = 0; /*A*/ i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min]) min = j;
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}




int main() {

    int i, n = 5000; //é necessário alterar para n = 10000 n = 15000 n = 20000

    int v[n];//declara de forma manual o número máximo de elementos do vetor.

    clock_t tempo_inicial, tempo_final;

    double tempo_total;

    

    srand(time(NULL));



    // Lê seus elementos que são gerados de forma aleatória. 

    for (i = 0; i < n; i++) {

        v[i] = rand() % 5000; //é necessário alterar para 10000, 15000 ou 20000 de acordo com o n escolhido 

    }

    

    tempo_inicial = clock();



    // Chama a função de ordenação

    Seleção(n, v);

    

    tempo_final = clock();

    

    // cálculo do tempo total e exibição do vetor ordenado

    tempo_total = (double) (tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("Tempo total de execução: %f segundos\n", tempo_total);





    // Imprime o vetor ordenado

    for (i = 0; i < n; i++) {

        printf("%d ", v[i]);

    }

    printf("\n");



    return 0;

}

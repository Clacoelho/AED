#include <stdio.h>

#include <stdlib.h>

#include <time.h>





//Função retirada do livro indicado

void Inserção (int n, int v[]) {

int i, j, x;

for (j = 1; /*A*/ j < n; j++) {

x = v[j];

for (i = j-1; i >= 0 && v[i] > x; i--)

v[i+1] = v[i];

v[i+1] = x;

}

}



int main() {

    int i, n = 5000;

    int v[n];//declara de forma manual o número máximo de elementos do vetor.

    clock_t tempo_inicial, tempo_final;

    double tempo_total;

    

    srand(time(NULL));



    // Lê seus elementos que são gerados de forma aleatória. 

    for (i = 0; i < n; i++) {

        v[i] = rand() % 5000;

    }

    

    tempo_inicial = clock();



    // Chama a função de ordenação

    Inserção(n, v);

    

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

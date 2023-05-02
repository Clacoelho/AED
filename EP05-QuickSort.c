#include <stdio.h>

#include <stdlib.h>

#include <time.h>

//Função retirada do livro indicado

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

int main() {

    int i, p = 5000; //é necessário alterar para n = 10000 n = 15000 n = 20000

    int v[p];//declara de forma manual o número máximo de elementos do vetor.

    clock_t tempo_inicial, tempo_final;

    double tempo_total;

    

    srand(time(NULL));



    // Lê o tamanho do vetor e seus elementos. 

    for (i = 0; i < p; i++) {

        v[i] = rand() % 5000; //é necessário alterar para 10000, 15000 ou 20000 de acordo com o n escolhido 

    }

    

    tempo_inicial = clock();



    // Chama a função de ordenação

    Quicksort(0, p, v);

    

    tempo_final = clock();

    

    // cálculo do tempo total e exibição do vetor ordenado

    tempo_total = (double) (tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("Tempo total de execução: %f segundos\n", tempo_total);





    // Imprime o vetor ordenado

    for (i = 0; i < p; i++) {

        printf("%d ", v[i]);

    }

    printf("\n");



    return 0;

}

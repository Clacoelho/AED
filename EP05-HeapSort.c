#include <stdio.h>

#include <stdlib.h>

#include <time.h>





//Função retirada do livro indicado

void InsereEmHeap (int m, int v[]) {

    int f = m+1;

    while /*X*/ (f > 1 && v[f/2] < v[f]) {

        int t = v[f/2]; v[f/2] = v[f]; v[f] = t;

        f = f/2;

    }

}



void SacodeHeap (int m, int v[]) {

    int t, f = 2;

    while /*X*/ (f <= m) {

        if (f < m && v[f] < v[f+1]) ++f;

        if (v[f/2] >= v[f]) break;

        t = v[f/2]; v[f/2] = v[f]; v[f] = t;

        f *= 2;

    }

}



void Heapsort (int n, int v[]) {

    int m;

    for (m = 1; m < n; m++)

        InsereEmHeap (m, v);

    for (m = n; /*X*/ m > 1; m--) {

        int t = v[1]; v[1] = v[m]; v[m] = t;

        SacodeHeap (m-1, v);

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

    Heapsort(p, v);

    

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

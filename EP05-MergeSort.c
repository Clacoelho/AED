#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Função retirada do livro indicado
void Intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free (w); 
}

void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
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
    Mergesort(0, p, v);
    
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
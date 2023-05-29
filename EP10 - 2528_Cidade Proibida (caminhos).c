#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <limits.h>



// Estrutura de uma rota

typedef struct {

    int cidade1;

    int cidade2;

} Rota;



// Função para encontrar o menor número de horas usando o algoritmo de Dijkstra

int encontrarMenorNumeroHoras(int N, int M, Rota rotas[], int C, int R, int E) {

    // Vetor de distâncias

    int dist[N + 1];



    // Vetor de visitados

    bool visitados[N + 1];



    // Inicialização dos vetores de distâncias e visitados

    for (int i = 1; i <= N; i++) {

        dist[i] = INT_MAX;

        visitados[i] = false;

    }



    // A distância de C a C é 0

    dist[C] = 0;



    // Loop do algoritmo de Dijkstra

    for (int i = 1; i <= N; i++) {

        // Encontra o vértice não visitado com a menor distância

        int minDist = INT_MAX;

        int minVertice = -1;

        for (int j = 1; j <= N; j++) {

            if (!visitados[j] && dist[j] < minDist) {

                minDist = dist[j];

                minVertice = j;

            }

        }



        // Marca o vértice como visitado

        visitados[minVertice] = true;



        // Atualiza as distâncias dos vértices adjacentes

        for (int j = 0; j < M; j++) {

            if ((rotas[j].cidade1 == minVertice || rotas[j].cidade2 == minVertice) &&

                ((rotas[j].cidade1 != E && rotas[j].cidade2 != E))) {

                int adjacente = (rotas[j].cidade1 == minVertice) ? rotas[j].cidade2 : rotas[j].cidade1;

                if (!visitados[adjacente] && dist[minVertice] + 1 < dist[adjacente]) {

                    dist[adjacente] = dist[minVertice] + 1;

                }

            }

        }

    }



    // Retorna o número mínimo de horas de C a R

    return dist[R];

}



int main() {

    int N, M;

    while (scanf("%d %d", &N, &M) == 2) {

        Rota rotas[M];



        // Leitura das rotas

        for (int i = 0; i < M; i++) {

            scanf("%d %d", &rotas[i].cidade1, &rotas[i].cidade2);

        }



        int C, R, E;

        scanf("%d %d %d", &C, &R, &E);



        int menorNumeroHoras = encontrarMenorNumeroHoras(N, M, rotas, C, R, E);



        printf("%d\n", menorNumeroHoras);

    }



    return 0;

}

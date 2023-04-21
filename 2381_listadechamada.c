#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main() {

    int N, K, i, j;

    char nome[30];

    scanf("%d %d", &N, &K);

    char lista[N][30];

    i=0;

    while (i < N) {

        scanf("%s", nome);

        strcpy(lista[i], nome);

        i++;

    }

    for(i = 0; i < N; i++) {

        for(j = i+1; j < N; j++) {

            if(strcmp(lista[i], lista[j]) > 0) {

                char aux[30];

                strcpy(aux, lista[i]);

                strcpy(lista[i], lista[j]);

                strcpy(lista[j], aux);

            }

        }

    }

    printf("%s", lista[K-1]);

    return 0;

}

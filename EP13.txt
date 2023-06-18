#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* idioma_falado(char** strings, int num_strings) {
    for (int i = 1; i < num_strings; i++) {
        if (strcmp(strings[i], strings[0]) != 0) {
            return "ingles";  // As strings são diferentes
        } 
        
    }
            
        return strings[0];
        
}

int main() {
    // Quantidade de testes
    int N;
    scanf("%d", &N);

    // Percorre a quantidade de testes
    // Leitura da quantidade de linhas de cada teste
    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        
        char** strings = (char**)malloc(K * sizeof(char*));
        
        // Percorrendo cada linha 
        for (int j = 0; j < K; j++) {
            strings[j] = (char*)malloc(21 * sizeof(char));
            // Leitura do idioma
            scanf("%s", strings[j]);
        }
        
        char* idioma = idioma_falado(strings, K);
        printf("%s\n", idioma);

        for (int j = 0; j < K; j++) {
            free(strings[j]);
        }
        
        free(strings);
    }

    return 0;
}

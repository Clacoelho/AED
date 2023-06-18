#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 10000
#define MAX_LENGTH 201
#define MAX_WORDS 5000
#define MAX_DELIMITERS 100

int compare_words(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    char text[MAX_LINES][MAX_LENGTH];
    char* words[MAX_WORDS];
    int num_words = 0;

    char delimiters[MAX_DELIMITERS];
    int num_delimiters = 0;

    // Ler as linhas de texto até o final da entrada (EOF)
    int num_lines = 0;
    while (fgets(text[num_lines], sizeof(text[num_lines]), stdin) != NULL) {
        num_lines++;
    }

    // Identificar e armazenar os caracteres especiais como delimitadores
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < strlen(text[i]); j++) {
            char ch = text[i][j];
            if (!isalpha(ch) && !isspace(ch)) {
                int found = 0;
                for (int k = 0; k < num_delimiters; k++) {
                    if (delimiters[k] == ch) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    delimiters[num_delimiters] = ch;
                    num_delimiters++;
                }
            }
        }
    }

    // Adicionar o espaço como delimitador
    delimiters[num_delimiters] = ' ';
    num_delimiters++;

    // Separar as palavras e armazená-las no vetor de palavras
    for (int i = 0; i < num_lines; i++) {
        char* token = strtok(text[i], delimiters);
        while (token != NULL) {
            // Converter a palavra para letras minúsculas
            for (int j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }
            
            // Remover caracteres especiais da palavra, mantendo apenas letras
            int len = strlen(token);
            int k = 0;
            for (int j = 0; j < len; j++) {
                if (isalpha(token[j])) {
                    token[k++] = token[j];
                }
            }
            token[k] = '\0';

            // Adicionar a palavra ao vetor de palavras
            if (strlen(token) > 0) {
                words[num_words] = strdup(token);
                num_words++;
            }

            token = strtok(NULL, delimiters);
        }
    }

    // Ordenar o vetor de palavras em ordem alfabética
    qsort(words, num_words, sizeof(char*), compare_words);

    // Remover palavras duplicadas, mantendo apenas as palavras distintas
    int j = 0;
    for (int i = 1; i < num_words; i++) {
        if (strcmp(words[i], words[j]) != 0) {
            j++;
            words[j] = words[i];
        } else {
            free(words[i]);
        }
    }
    num_words = j + 1;

    // Imprimir as palavras distintas
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    // Liberar a memória alocada
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}

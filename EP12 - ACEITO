#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int calculate_hash(char* str, int line_number, int position) {
    int hash = 0;
    char letra;
    int alphabet_position;
    int valor;

    letra = toupper(str[position]);
    alphabet_position = letra - 'A';
    valor = alphabet_position + line_number + position;
    //printf("%c: %d\n", letra, alphabet_position);
    //printf("%d %d %d\n", alphabet_position, line_number, position);
    //printf("%d\n", valor);
    hash += valor;

    return hash;
}


int main() {
    //testes
    int num_cases;
    scanf("%d", &num_cases);
    
    //linhas
    for (int i = 0; i < num_cases; i++) {
        int num_lines;
        scanf("%d", &num_lines);

        int total_hash = 0;
        //strings de cada linha
        for (int j = 0; j < num_lines; j++) {
            char str[51];
            scanf("%s", str);

            int line_number = j;

            for (int k = 0; k < strlen(str); k++) {
                int position = k;
                int hash = calculate_hash(str, line_number, position);
                total_hash += hash;
            }
        }

        printf("%d\n", total_hash);
    }

    return 0;
}

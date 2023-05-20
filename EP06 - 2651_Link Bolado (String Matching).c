#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int trivial(char a[], int m, char b[], int n) {
    int k, r, ocorrs;
    ocorrs = 0;
    for (k = m - 1; k <= n; k++) {
        r = 0;
        while (r < m && a[m - r - 1] == b[k - r]) r += 1;
        if (r >= m) ocorrs += 1;
    }
    return ocorrs;
}

int main() {
    int m = 5;
    char palavra[] = "ZELDA";
    int n = 100000;
    char texto[n];
    scanf("%s", texto);

    texto[strcspn(texto, "\n")] = '\0';

    int i = 0;
    while (texto[i]) {
        texto[i] = toupper(texto[i]);
        i++;
    }

    if (trivial(palavra, m, texto, strlen(texto)) == 1) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Declaração do array bidimensional que representa o mapa
char mapa[100][100];
int visitado[100][100];  // Array para marcar as células visitadas

// Função para verificar se o caminho é válido
int verificarCaminho(int largura, int altura, int x, int y, char direcao) {
    // Verificar se os comandos estão dentro do tamanho do mapa
    if (x >= largura || y >= altura || x < 0 || y < 0) {
        return 0;  // Caminho inválido
    }

    // Verificar se a célula já foi visitada anteriormente
    if (visitado[y][x]) {
        return 0;  // Caminho inválido
    }

    char celula = mapa[y][x];  // Obter o caractere da célula atual

    // Verificar se encontrou um asterisco
    if (celula == '*') {
        return 1;  // Caminho válido
    }

    // Marcar a célula como visitada
    visitado[y][x] = 1;

    // Se o caractere muda a direção
    if (celula != '.' && celula != '*') {
        direcao = celula;  // Obter a nova direção
    }  // Senão continua com a mesma direção

    // Movimentar para a próxima célula de acordo com o comando
    if (direcao == '>') {
        x++;
    } else if (direcao == '<') {
        x--;
    } else if (direcao == 'v') {
        y++;
    } else if (direcao == '^') {
        y--;
    }

    // Verificar se retornou ao início (mapa em círculo)
    if (x == 0 && y == 0) {
        return 0;  // Caminho inválido
    }

    int resultado = verificarCaminho(largura, altura, x, y, direcao);

    // Desmarcar a célula como visitada (backtracking)
    visitado[y][x] = 0;

    return resultado;
}

int main() {
    // Declaração das variáveis locais
    int largura, altura;

    // Leitura do tamanho da largura < 100
    scanf("%d", &largura);

    // Leitura do tamanho da altura < 100
    scanf("%d", &altura);

    // Leitura dos comandos e preenchimento do mapa
    for (int i = 0; i < altura; i++) {
        scanf("%s", mapa[i]);
    }

    // Zerar o array de células visitadas
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            visitado[i][j] = 0;
        }
    }

    // Verificação do caminho
    if (verificarCaminho(largura, altura, 0, 0, '.')) {
        printf("*\n");  // Caminho válido
    } else {
        printf("!\n");  // Caminho inválido
    }

    return 0;
}

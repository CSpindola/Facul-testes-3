#include <stdio.h>

#define SIZE 10
#define SHIP_VAL 3

int main(void) {
    int board[SIZE][SIZE];
    int i, j;

    // Inicializa todas as posições com 0 (água) 
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Posiciona navios (tamanho fixo = 3; Cruzador
    // Dois na horizontal/vertical e dois na diagonal  

    // Navio 1 – horizontal 
    int r1 = 1, c1 = 2;        // coordenadas iniciais do Navio 1
    int len = 3;
    if (c1 + len - 1 < SIZE) {
        for (j = c1; j < c1 + len; j++) {
            board[r1][j] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 1 fora dos limites\n");
    }

    // Navio 2 – vertical 
    int r2 = 4, c2 = 5;
    if (r2 + len - 1 < SIZE) {
        for (i = r2; i < r2 + len; i++) {
            board[i][c2] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 2 fora dos limites\n");
    }

    // Navio 3 – diagonal “\” (linha e coluna aumentam) 
    int r3 = 6, c3 = 0;
    if (r3 + len - 1 < SIZE && c3 + len - 1 < SIZE) {
        for (i = 0; i < len; i++) {
            board[r3 + i][c3 + i] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 3 fora dos limites\n");
    }

    // Navio 4 – diagonal “/” (linha aumenta, coluna diminui) 
    int r4 = 0, c4 = 9;
    if (r4 + len - 1 < SIZE && c4 - (len - 1) >= 0) {
        for (i = 0; i < len; i++) {
            board[r4 + i][c4 - i] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 4 fora dos limites\n");
    }

    // Simples verificação de sobreposição: 
    // Nessa etapa, as posições foram definidas manualmente para não se sobreporem.
     

    // Exibir o tabuleiro 
    printf("Tabuleiro 10x10:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

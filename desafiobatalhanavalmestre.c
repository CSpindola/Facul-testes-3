#include <stdio.h>
#include <stdlib.h>

#define SIZE 10              /* Tamanho do tabuleiro: 10×10 */
#define SHIP_VAL 3           /* Valor para navio no tabuleiro */
#define EFFECT_VAL 5         /* Valor para área de efeito da habilidade */

int main(void) {
    int board[SIZE][SIZE];
    int i, j;

    /* 1. Inicializar o tabuleiro – todas as posições com 0 (água) */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    /* 2. Posicionar quatro navios com valor SHIP_VAL (=3) */
    int len = 3;  /* comprimento fixo = 3 */

    /* Navio 1 – horizontal */
    int r1 = 1, c1 = 2;
    if (c1 + len - 1 < SIZE) {
        for (j = c1; j < c1 + len; j++) {
            board[r1][j] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 1 fora dos limites\n");
    }

    /* Navio 2 – vertical */
    int r2 = 4, c2 = 5;
    if (r2 + len - 1 < SIZE) {
        for (i = r2; i < r2 + len; i++) {
            board[i][c2] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 2 fora dos limites\n");
    }

    /* Navio 3 – diagonal “\” (linha e coluna aumentam) */
    int r3 = 6, c3 = 0;
    if (r3 + len - 1 < SIZE && c3 + len - 1 < SIZE) {
        for (i = 0; i < len; i++) {
            board[r3 + i][c3 + i] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 3 fora dos limites\n");
    }

    /* Navio 4 – diagonal “/” (linha aumenta, coluna diminui) */
    int r4 = 0, c4 = 9;
    if (r4 + len - 1 < SIZE && c4 - (len - 1) >= 0) {
        for (i = 0; i < len; i++) {
            board[r4 + i][c4 - i] = SHIP_VAL;
        }
    } else {
        printf("Erro: navio 4 fora dos limites\n");
    }

    /* ------------------------------------------ */
    /* 3. Definir matrizes de habilidade (área de efeito) */
    /* Vamos usar tamanho 5×5 para cada habilidade */
    #define HSIZE 5
    int cone[HSIZE][HSIZE];
    int cross[HSIZE][HSIZE];
    int octa[HSIZE][HSIZE];

    /* 3a. Construir “cone” com topologia: ponto no topo, expandindo para baixo */
    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < HSIZE; j++) {
            /* linha i = 0 é topo, conforme i aumenta o “cone” se abre */
            if (i == 0 && j == HSIZE/2) {
                cone[i][j] = 1;
            } else if (i == 1 && (j == HSIZE/2 - 1 || j == HSIZE/2 || j == HSIZE/2 + 1)) {
                cone[i][j] = 1;
            } else if (i == 2 && (j >= HSIZE/2 - 2 && j <= HSIZE/2 + 2)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    /* 3b. Construir “cruz” com ponto de origem no centro */
    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < HSIZE; j++) {
            if (i == HSIZE/2 || j == HSIZE/2) {
                cross[i][j] = 1;
            } else {
                cross[i][j] = 0;
            }
        }
    }

    /* 3c. Construir “octaedro” visto de frente (formato losango) */
    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < HSIZE; j++) {
            /* Distância ao centro (linha, coluna) */
            int di = abs(i - HSIZE/2);
            int dj = abs(j - HSIZE/2);
            if (di + dj <= HSIZE/2) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }

    /* ------------------------------------------ */
    /* 4. Definir pontos de origem no tabuleiro para cada habilidade */
    /* Posições fixas definidas no código */
    int originConeRow   = 2, originConeCol   = 2;
    int originCrossRow  = 5, originCrossCol  = 7;
    int originOctaRow   = 8, originOctaCol   = 3;

    /* 5. Sobrepor cada matriz de habilidade no tabuleiro */
    /* 5a. Cone */
    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < HSIZE; j++) {
            if (cone[i][j] == 1) {
                int tr = originConeRow + i - HSIZE/2;  /* ajustar para centralizar ou parte superior; escolhi usar top como origem */
                int tc = originConeCol + j - HSIZE/2;
                if (tr >= 0 && tr < SIZE && tc >= 0 && tc < SIZE) {
                    /* somente se água ou navio ainda mantemos? Aqui sobrescrevemos tudo por simplicidade */
                    if (board[tr][tc] == 0) {
                        board[tr][tc] = EFFECT_VAL;
                    } else {
                        /* Se for navio ou outra coisa, podemos decidir sobrescrever ou não. Aqui NÃO sobrescrevemos navios. */
                        if (board[tr][tc] == SHIP_VAL) {
                            /* mantém navio, opcionalmente marcar efeito sobre navio se quiser */
                        }
                    }
                }
            }
        }
    }

    /* 5b. Cruz */
    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < HSIZE; j++) {
            if (cross[i][j] == 1) {
                int tr = originCrossRow + i - HSIZE/2;
                int tc = originCrossCol + j - HSIZE/2;
                if (tr >= 0 && tr < SIZE && tc >= 0 && tc < SIZE) {
                    if (board[tr][tc] == 0) {
                        board[tr][tc] = EFFECT_VAL;
                    }
                }
            }
        }
    }

    /* 5c. Octaedro */
    for (i = 0; i < HSIZE; i++) {
        for (j = 0; j < HSIZE; j++) {
            if (octa[i][j] == 1) {
                int tr = originOctaRow + i - HSIZE/2;
                int tc = originOctaCol + j - HSIZE/2;
                if (tr >= 0 && tr < SIZE && tc >= 0 && tc < SIZE) {
                    if (board[tr][tc] == 0) {
                        board[tr][tc] = EFFECT_VAL;
                    }
                }
            }
        }
    }

    /* ------------------------------------------ */
    /* 6. Exibir o tabuleiro completo no console */
    printf("Tabuleiro 10x10 (Água=0, Navio=3, Efeito=5):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

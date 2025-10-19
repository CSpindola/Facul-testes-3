#include <stdio.h>

#define TAB_LINHAS 10     // número de linhas do tabuleiro
#define TAB_COLUNAS 10    // número de colunas do tabuleiro
#define NAVIO_TAM 3       // tamanho fixo de cada navio

int main(void) {
    int tabuleiro[TAB_LINHAS][TAB_COLUNAS];
    int i, j;

    // 1) Inicializar o tabuleiro com 0 (representando água)
    for (i = 0; i < TAB_LINHAS; i++) {
        for (j = 0; j < TAB_COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2) Definir coordenadas iniciais para os navios 
    //    Navio A (horizontal) começa na linha 2, coluna 4
    int navA_linha = 2;
    int navA_coluna = 4;
    int navA_orientacao = 1; // 1 = horizontal, 0 = vertical

    //    Navio B (vertical) começa na linha 5, coluna 7
    int navB_linha = 5;
    int navB_coluna = 7;
    int navB_orientacao = 0; // 1 = horizontal, 0 = vertical

    // 3) Validar se os navios cabem dentro do tabuleiro
    //    Para navio A:
    if (navA_orientacao == 1) {
        if (navA_coluna + NAVIO_TAM - 1 >= TAB_COLUNAS) {
            printf("Erro: navio A (horizontal) não cabe no tabuleiro.\n");
            return 1;
        }
    } else {
        if (navA_linha + NAVIO_TAM - 1 >= TAB_LINHAS) {
            printf("Erro: navio A (vertical) não cabe no tabuleiro.\n");
            return 1;
        }
    }

    //    Para navio B:
    if (navB_orientacao == 1) {
        if (navB_coluna + NAVIO_TAM - 1 >= TAB_COLUNAS) {
            printf("Erro: navio B (horizontal) não cabe no tabuleiro.\n");
            return 1;
        }
    } else {
        if (navB_linha + NAVIO_TAM - 1 >= TAB_LINHAS) {
            printf("Erro: navio B (vertical) não cabe no tabuleiro.\n");
            return 1;
        }
    }

    // 4) Validar que os navios não se sobrepõem
    //    Marcar navio A no tabuleiro com valor 3
    for (i = 0; i < NAVIO_TAM; i++) {
        int linha = navA_linha + (navA_orientacao == 0 ? i : 0);
        int coluna = navA_coluna + (navA_orientacao == 1 ? i : 0);
        tabuleiro[linha][coluna] = 3;
    }

    //    Verificar navio B posições livres
    for (i = 0; i < NAVIO_TAM; i++) {
        int linha = navB_linha + (navB_orientacao == 0 ? i : 0);
        int coluna = navB_coluna + (navB_orientacao == 1 ? i : 0);
        if (tabuleiro[linha][coluna] != 0) {
            printf("Erro: navio B se sobrepõe a outro navio.\n");
            return 1;
        }
    }

    //    Marcar navio B no tabuleiro com valor 3
    for (i = 0; i < NAVIO_TAM; i++) {
        int linha = navB_linha + (navB_orientacao == 0 ? i : 0);
        int coluna = navB_coluna + (navB_orientacao == 1 ? i : 0);
        tabuleiro[linha][coluna] = ;
    }

    // 5) Exibir o tabuleiro no console
    printf("Tabuleiro (0 = água, 3 = navio):\n");
    for (i = 0; i < TAB_LINHAS; i++) {
        for (j = 0; j < TAB_COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

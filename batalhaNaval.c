#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Posição inicial do navio horizontal
    int linha_h = 2;
    int coluna_h = 4;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = NAVIO;
        }
    }

    // Posição inicial do navio vertical
    int linha_v = 5;
    int coluna_v = 7;

    // Verifica se o navio vertical cabe no tabuleiro e não sobrepõe o outro
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == NAVIO) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = NAVIO;
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}

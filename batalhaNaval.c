#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {

        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}



int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : (direcao == 3 ? -i : 0));
        int c = coluna + (direcao == 0 ? i : (direcao == 2 ? -i : 0));

        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != 0) {
            return 0;
        }
    }
    return 1;
}


void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    if (podePosicionar(tabuleiro, linha, coluna, direcao)) {
        for (int i = 0; i < NAVIO; i++) {
            int l = linha + (direcao == 1 ? i : (direcao == 3 ? -i : 0));
            int c = coluna + (direcao == 0 ? i : (direcao == 2 ? -i : 0));
            tabuleiro[l][c] = NAVIO;
        }
    }
}





void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tipo) {
    if (tipo == 1) { // Cone
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int l = linha + i;
                int c = coluna + j;
                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                    if (tabuleiro[l][c] != NAVIO) tabuleiro[l][c] = HABILIDADE;
                }
            }


        }
    } else if (tipo == 2) { // Cruz
        for (int i = -1; i <= 1; i++) {
            if (linha + i >= 0 && linha + i < TAMANHO && tabuleiro[linha + i][coluna] != NAVIO)
                tabuleiro[linha + i][coluna] = HABILIDADE;
            if (coluna + i >= 0 && coluna + i < TAMANHO && tabuleiro[linha][coluna + i] != NAVIO)
                tabuleiro[linha][coluna + i] = HABILIDADE;
        }



    } else if (tipo == 3) { // Octaedro
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if ((i) + (j) <= 2) {
                    int l = linha + i;
                    int c = coluna + j;
                    if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                        if (tabuleiro[l][c] != NAVIO) tabuleiro[l][c] = HABILIDADE;
                    }
                }
            }
        }
    }
}



int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionando navio

    posicionarNavio(tabuleiro, 1, 1, 0);
    posicionarNavio(tabuleiro, 3, 3, 1);

    // Aplicando habilidades


    aplicarHabilidade(tabuleiro, 5, 5, 1); // Cone
    aplicarHabilidade(tabuleiro, 7, 7, 2); // Cruz
    aplicarHabilidade(tabuleiro, 2, 6, 3); // Octaedro


    // Exibir tabuleiro

    printf("\n### Tabuleiro Batalha Naval ###\n");
    exibirTabuleiro(tabuleiro);









    return 0;
}

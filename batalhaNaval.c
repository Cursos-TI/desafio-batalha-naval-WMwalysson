#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3


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
    } else {
        printf("Erro: Não é possível posicionar o navio em (%d, %c).\n", linha + 1, 'A' + coluna);
 }
}




int main() {
         int tabuleiro[TAMANHO][TAMANHO];
         inicializarTabuleiro(tabuleiro);


      // Posicionando dois navios horizontal/vertical

    posicionarNavio(tabuleiro, 1, 1, 0); // Horizontal
    posicionarNavio(tabuleiro, 2, 3, 1); // Vertical


     // Posicionando dois navios diagonais

    posicionarNavio(tabuleiro, 5, 5, 0); // Diagonal principal
    posicionarNavio(tabuleiro, 7, 7, 2); // Diagonal secundária


     // Exibir tabuleiro

    printf("\n### Tabuleiro Batalha Naval ###\n");
    exibirTabuleiro(tabuleiro);








    return 0;
}

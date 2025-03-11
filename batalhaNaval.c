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

int podePosicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + NAVIO > TAMANHO) return 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0;
         }
    return 1;
}


int podePosicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + NAVIO > TAMANHO) return 0;
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    return 1;
}




void posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (podePosicionarHorizontal(tabuleiro, linha, coluna)) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
            printf("navio horizontal em: (%d, %c)\n", linha + 1, 'A' + coluna + i);
    }
    } else {
        printf("Erro: Não é possivel posiciona o navio horizontal em (%d, %c).\n", linha + 1, 'A' + coluna);
    }
    }

void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (podePosicionarVertical(tabuleiro, linha, coluna)) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
            printf("Navio vertical em: (%d, %c)\n", linha + i + 1, 'A'+ coluna);
    }
    } else {
        printf("Erro: Não é possível posicionar o navio vertical em (%d, %c).\n", linha + 1, 'A' + coluna);
    }
 }

    int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posições iniciais dos navios
    int linhaH = 1, colunaH = 1; // navio horizontal

    int linhaV = 2, colunaV = 3; // posição do navio vertical

    // Posicionando os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaH, colunaH);

    posicionarNavioVertical(tabuleiro, linhaV, colunaV);

    // Exibindo o tabuleiro
    printf("\n### Tabuleiro batalha naval ###\n");
    exibirTabuleiro(tabuleiro);
   




    return 0;
}

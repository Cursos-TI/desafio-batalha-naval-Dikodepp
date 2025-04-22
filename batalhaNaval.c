#include <stdio.h>

// Definições de tamanho do tabuleiro
#define LINHA 10
#define COLUNA 10

// Variáveis globais para posições e tamanho dos navios
int tamanho_navioBasico = 3;             // Tamanho padrão de um navio
int linha_horizontal = 2;                // Linha onde o navio horizontal será posicionado
int coluna_vertical = 9;                 // Coluna onde o navio vertical será posicionado
int linha_inicioVertical = 4;            // Linha inicial para o navio vertical
int linha_diagonal1 = 0;                 // Linha inicial para navio na diagonal principal
int coluna_diagonal1 = 0;                // Coluna inicial para navio na diagonal principal
int linha_diagonal2 = 3;                 // Linha inicial para navio na diagonal secundária
int coluna_diagonal2 = 8;                // Coluna inicial para navio na diagonal secundária

// Tabuleiro principal do jogo
int tabuleiro[LINHA][COLUNA];

/**
 * Função que imprime as letras do topo do tabuleiro.
 * Representa as colunas de A até J.
 */
void letras() {
    char letras[LINHA] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("   "); // Espaço para alinhar com os números das linhas
    for (int i = 0; i < LINHA; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");
}

/**
 * Inicializa todos os espaços do tabuleiro com o valor 0 (representando água).
 */
void inicializa_tabuleiro() {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

/**
 * Imprime o tabuleiro atual com números de 1 a 10 nas linhas.
 */
void imprime_tabuleiro() {
    for (int i = 0; i < LINHA; i++) {
        printf("%2d", i + 1); // Linhas numeradas de 1 a 10
        for (int j = 0; j < COLUNA; j++) {
            printf(" %d", tabuleiro[i][j]); // 0 = água, 3 = parte de navio
        }
        printf("\n");
    }
}

/**
 * Posiciona um navio na horizontal a partir da linha `linha_horizontal`.
 * O navio ocupa 3 posições consecutivas nas colunas.
 */
void navio_Horizontal() {
    for (int j = 5; j <= 7; j++) {
        tabuleiro[linha_horizontal][j] = tamanho_navioBasico;
    }
}

/**
 * Posiciona um navio na vertical, começando da linha `linha_inicioVertical`.
 * O navio ocupa 3 posições consecutivas nas linhas.
 */
void navio_vertical() {
    for (int i = 0; i < tamanho_navioBasico; i++) {
        tabuleiro[linha_inicioVertical + i][coluna_vertical] = tamanho_navioBasico;
    }
}

/**
 * Posiciona um navio na diagonal principal (↘), se houver espaço suficiente no tabuleiro.
 * A posição inicial é dada por `linha_diagonal1` e `coluna_diagonal1`.
 */
void navio_diagonalPrimaria() {
    if (linha_diagonal1 + tamanho_navioBasico <= LINHA && coluna_diagonal1 + tamanho_navioBasico <= COLUNA) {
        for (int i = 0; i < tamanho_navioBasico; i++) {
            tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = tamanho_navioBasico;
        }
    } else {
        printf("O navio não cabe na diagonal primária a partir de [%d][%d]!\n", linha_diagonal1, coluna_diagonal1);
    }
}

/**
 * Posiciona um navio na diagonal secundária (↙), se houver espaço suficiente no tabuleiro.
 * A posição inicial é dada por `linha_diagonal2` e `coluna_diagonal2`.
 */
void navio_diagonalSecundaria() {
    if (linha_diagonal2 + tamanho_navioBasico <= LINHA && coluna_diagonal2 - (tamanho_navioBasico - 1) >= 0) {
        for (int i = 0; i < tamanho_navioBasico; i++) {
            tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = tamanho_navioBasico;
        }
    } else {
        printf("O navio não cabe na diagonal secundária a partir de [%d][%d]!\n", linha_diagonal2, coluna_diagonal2);
    }
}

/**
 * Função principal do programa.
 * Exibe o título, inicializa o tabuleiro e posiciona os navios.
 */
int main() {
    
    printf("*** Tabuleiro Batalha Naval ***\n");

    letras();                       // Imprime letras A–J no topo
    inicializa_tabuleiro();        // Preenche o tabuleiro com água
    navio_Horizontal();            // Posiciona navio na horizontal
    navio_vertical();              // Posiciona navio na vertical
    navio_diagonalPrimaria();      // Posiciona navio na diagonal ↘
    navio_diagonalSecundaria();    // Posiciona navio na diagonal ↙
    imprime_tabuleiro();           // Exibe o tabuleiro final

    return 0;
}

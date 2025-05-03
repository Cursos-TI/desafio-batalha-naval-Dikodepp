#include <stdio.h>
#include <stdlib.h>

// Define o tamanho da matriz do tabuleiro
#define LINHA 10
#define COLUNA 10

// Define o tamanho dos navios em formato de área especial (5x5)
#define TAMANHO_NAVIO 5

// Define o tamanho específico da matriz para o navio tipo Octaedro
#define octaedro_linha 3
#define octaedro_coluna 5

// Matriz do tabuleiro principal
int tabuleiro[LINHA][COLUNA];

// Matrizes para os diferentes formatos de navio
int cone[TAMANHO_NAVIO][TAMANHO_NAVIO];       // forma de cone
int cruz[TAMANHO_NAVIO][TAMANHO_NAVIO];       // forma de cruz
int octaedro[TAMANHO_NAVIO][TAMANHO_NAVIO];   // forma de octaedro

// Função para gerar a forma de cone 
void gerarCone() {
    int centro = TAMANHO_NAVIO / 2;  // índice central
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            // Preenche apenas a parte triangular do cone
            if (i <= centro && j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para gerar a forma de cruz
void gerarCruz() {
    int centro = TAMANHO_NAVIO / 2;  // índice central
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            // Linha central e pontos acima/abaixo dela
            if (i == centro)
                cruz[i][j] = 1;
            else if ((i == centro - 1 || i == centro + 1) && j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para gerar a forma de octaedro
void gerarOctaedro() {
    int centroLinha = octaedro_linha / 2;
    int centroColuna = octaedro_coluna / 2;
    for (int i = 0; i < octaedro_linha; i++) {
        for (int j = 0; j < octaedro_coluna; j++) {
            // Preenche os pontos cuja distância até o centro é ≤ 1
            if (abs(i - centroLinha) + abs(j - centroColuna) <= 1) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Posiciona o navio tipo Cone no tabuleiro
void colocarNavioCone(int origemLinha, int origemColuna) {
    int offset = TAMANHO_NAVIO / 2;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (cone[i][j] == 1) {
                // Converte coordenadas locais para globais
                int x = origemLinha + i - offset;
                int y = origemColuna + j - offset;
                // Verifica se está dentro do tabuleiro antes de colocar
                if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA)
                    tabuleiro[x][y] = 3; // Valor representando navio especial
            }
        }
    }
}

// Posiciona o navio tipo Cruz no tabuleiro
void colocarNavioCruz(int origemLinha, int origemColuna) {
    int offset = TAMANHO_NAVIO / 2;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (cruz[i][j] == 1) {
                int x = origemLinha + i - offset;
                int y = origemColuna + j - offset;
                if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA)
                    tabuleiro[x][y] = 3;
            }
        }
    }
}

// Posiciona o navio tipo Octaedro no tabuleiro
void colocarOctaerdro(int origemLinha, int origemColuna) {
    int offsetLinha = octaedro_linha / 2;
    int offsetColuna = octaedro_coluna / 2;
    for (int i = 0; i < octaedro_linha; i++) {
        for (int j = 0; j < octaedro_coluna; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemLinha + i - offsetLinha;
                int y = origemColuna + j - offsetColuna;
                if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA)
                    tabuleiro[x][y] = 3;
            }
        }
    }
}

// Imprime cabeçalho com letras A-J para facilitar visualização
void letras() {
    printf("*** Tabuleiro Batalha Naval ***\n");
    char letras[COLUNA] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("   ");
    for (int i = 0; i < COLUNA; i++)
        printf("%c ", letras[i]);
    printf("\n");
}

// Inicializa o tabuleiro com zeros (sem navios)
void inicializa_tabuleiro() {
    for (int i = 0; i < LINHA; i++)
        for (int j = 0; j < COLUNA; j++)
            tabuleiro[i][j] = 0;
}

// Imprime o tabuleiro na tela
void imprime_tabuleiro() {
    for (int i = 0; i < LINHA; i++) {
        printf("%2d ", i + 1); // Números das linhas
        for (int j = 0; j < COLUNA; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
}

// Função principal
int main() {
    letras();                // Exibe o cabeçalho com letras
    inicializa_tabuleiro();  // Gera o tabuleiro zerado
    gerarCone();             // Gera a matriz do navio cone
    gerarCruz();             // Gera a matriz do navio cruz
    gerarOctaedro();         // Gera a matriz do navio octaedro

    // Posiciona cada navio no tabuleiro
    colocarNavioCone(2, 2);        // Coloca o cone na posição (2,2)
    colocarNavioCruz(5, 3);        // Coloca a cruz na posição (5,3)
    colocarOctaerdro(7, 7);        // Coloca o octaedro na posição (7,7)

    imprime_tabuleiro();   // Mostra o tabuleiro final com os navios
    return 0;
}
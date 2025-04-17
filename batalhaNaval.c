#include <stdio.h>

int main(){
    
    int linha_horizontal = 2; // Variável para a linha 2 do índice (horizontal)
    int coluna = 9;  // Variável para a coluna 9 do índice         
    int linha_inicioVertical = 4;  // Variável para a linha de início na Vertical do índice
    int tamanho_navioBasico = 3; // Variável para o tamanho básico de um navio
    int linha_diagonal1 = 0; // Variável para linha em diagonal primaria
    int coluna_diagonal1 = 0; // Variável para coluna em diagonal primaria
    int linha_diagonal2 = 3; // Variável para linha em diagonal secundaria
    int coluna_diagonal2 = 8; // Variável para coluna em diagonal secundaria

    // Inicializa o tabuleiro com as letras de A, J.
    char letras[10] = {'A', 'B','C', 'D','E', 'F', 'G', 'H','I', 'J'}; 

    // Matriz de tamanho 10x10 para formar o tabuleiro
    int tabuleiro[10][10];

    // Inicializa a matriz utilizando o valor 0 representando a água
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Posição do navio básico na horizontal
    for (int j = 5; j <= 7; j++){
        tabuleiro[linha_horizontal][j] = tamanho_navioBasico;
    }
    
    // Posição do navio básico na vertical
    for (int i = 0; i < tamanho_navioBasico; i++) {
        tabuleiro[linha_inicioVertical + i][coluna] = tamanho_navioBasico;
    }
    
    // Verificação para garantir que o navio na diagonal primária cabe no tabuleiro
    if (linha_diagonal1 + tamanho_navioBasico <= 10 && coluna_diagonal1 + tamanho_navioBasico <= 10) {
        // Posições válidas para a diagonal primária
        for (int i = 0; i < tamanho_navioBasico; i++) {
        tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = 3;
        }
    } else {
        printf("O navio não cabe na diagonal primária a partir de [%d][%d]!\n", linha_diagonal1, coluna_diagonal1);
    }


    // Verificação para a diagonal secundária
    if (linha_diagonal2 + tamanho_navioBasico <= 10 &&
        coluna_diagonal2 - (tamanho_navioBasico - 1) >= 0) {
        // Posições válidas
        for (int i = 0; i < tamanho_navioBasico; i++){
            tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = 3;
        }
    } else {
        printf(" O navio não cabe na diagonal secundária a partir de [%d][%d]!\n", linha_diagonal2, coluna_diagonal2);
    }

    printf("***Tabuleiro Batalha Naval***\n");

    // Imprime as letras no topo do tabuleiro
    printf("   "); // Espaço para alinhar com os números da esquerda
    for (int i = 0; i < 10; i++){
        printf("%c ", letras[i]);
    }
    printf("\n");

    // Imprime o tabuleiro com os números ao lado
    for (int i = 0; i < 10; i++){
        printf("%2d", i + 1); // Números de 1 a 10, alinhados
        for (int j = 0; j < 10; j++){
            printf(" %d", tabuleiro[i][j]); // Imprime 0 para água
        }
        printf("\n");
    }
    
    return 0;
}

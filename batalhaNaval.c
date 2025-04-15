#include <stdio.h>

int main(){
    
    int linha = 2; //variavel para chamar a linha 2 do indice
    int coluna = 9;  //variavel para chamar a coluna 9 do indice         
    int linha_inicioVertical = 4;  // variavel para chamar a linha de inicio na Vertical do indice
    int tamanho_navioBasico = 3; // variavel para tamanho basico de um navio

    // incia o tabuleiro com as letras de A, J.
    char letras[10] = {'A', 'B','C', 'D','E', 'F', 'G', 'H','I', 'J'}; 

    // Matriz de tamanho 10x10 para formar o tabuleiro
    int tabuleiro [10][10];

    // incializa a matriz utilizando o valor 0 representado a água
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
        
    }

        // posição do navio basico na horizontal

    for (int coluna = 5; coluna <= 7; coluna++){
        tabuleiro[linha][coluna] = tamanho_navioBasico;
    }
    
     // posição do navio basico na vertical
    
    for (int i = 0; i < tamanho_navioBasico; i++) {
        tabuleiro[linha_inicioVertical + i][coluna] = tamanho_navioBasico;
    }
        
        
    printf("***Tabuleiro Batalha Naval***\n");


    //imprime as letras no topo do tabuleiro
    printf("   "); //Espaço para alinhar com os números da esquerda
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", letras[i]);
    }
    printf("\n");

    //imprime o tabuleiro com os números  ao lado
    for (int i = 0; i < 10; i++){
        printf("%2d" , i + 1); // Números de 1 a 10, alinhados
        for (int j = 0; j < 10; j++){
            printf(" %d", tabuleiro[i][j]); // Imprime 0 para água
        }
        printf("\n");
    }
    
    return 0;
}
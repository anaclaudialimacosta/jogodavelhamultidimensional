#include <stdio.h>
#define DIM 5
vez=1;

void exibeTabuleiro(int tabuleiro[DIM][DIM], int tl){
     int linha, coluna;
     printf("TABULEIRO \n");

     printf("\n\n");

    for(linha = 0 ; linha < tl; linha++)
    {
        for(coluna = 0 ; coluna < tl ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf("  X ");
                else
                    printf("  O ");

            if(coluna != (tl-1))
                printf("|");
        }
            printf("\n");
    }
    printf("\n");
}
void zeraTabuleiro(int tabuleiro[][DIM], int tl)
{
    int linha, coluna;
    for(linha = 0 ; linha < tl ; linha++)
        for(coluna = 0 ; coluna < tl ; coluna++)
            tabuleiro[linha][coluna] = 0;
}

int checaLocal(int tabuleiro[][DIM], int linha, int coluna, int tl){

if(linha < 0 || linha > (tl-1) || coluna < 0 || coluna > (tl-1) || tabuleiro[linha][coluna] != 0)
        return 0;
    else
        return 1;
}
int checaLinha(int tabuleiro[][DIM], int tl){
int linha, coluna,soma;

    for(linha = 0 ; linha < tl ; linha++)
    {
        soma=0;

        for(coluna = 0 ; coluna < tl ; coluna++)
            soma += tabuleiro[linha][coluna];

        if(soma==tl || soma == (-1)*tl)
            return 1;
    }

    return 0;
}
int checaColuna(int tabuleiro[][DIM], int tl){
 int linha, coluna,soma;
    for(coluna = 0 ; coluna < tl ; coluna++)
    {
        soma=0;

        for(linha = 0 ; linha < tl ; linha++)
            soma += tabuleiro[linha][coluna];

        if(soma==tl || soma == (-1)*tl)
            return 1;
    }

    return 0;
}
int checaDiagonal(int tabuleiro[][DIM], int tl){
    int linha,diagonal_principal=0, diagonal_secundaria = 0;

    for(linha = 0 ; linha < tl ; linha++)
    {
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][tl-linha-1];
    }

    if(diagonal_principal==tl || diagonal_principal==(-1)*tl ||
       diagonal_secundaria==tl || diagonal_secundaria==(-1)*tl)
       return 1;

    return 0;

}
int checaEmpate(int tabuleiro[][DIM], int tl){
    int linha, coluna;

    for(linha = 0 ; linha < tl ; linha++)
        for(coluna = 0 ; coluna < tl; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;

    return 1;
}
int checaTermino(int tabuleiro[][DIM], int vez, int tl){
     if(checaLinha(tabuleiro,tl))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro,tl);
        return 1;
    }

    if(checaColuna(tabuleiro,tl))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro,tl);
        return 1;
    }

    if(checaDiagonal(tabuleiro,tl))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro,tl);
        return 1;
    }

    if(checaEmpate(tabuleiro,tl))
    {
        printf("Jogo encerrado. Ocorreu um empate! !\n\n");
        exibeTabuleiro(tabuleiro,tl);
        return 1;
    }

    return 0;

}
void jogada(int tabuleiro[][DIM], int tl){
    int linha, coluna;
    vez++;
    printf("\n--> Jogador %d \n", (vez % 2) + 1);

    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;

        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;

        if(checaLocal(tabuleiro, linha, coluna,tl) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");

    } while(checaLocal(tabuleiro, linha, coluna,tl) == 0);

    if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;


}

main(){
    int vez;
    int tabuleiro[DIM][DIM], tl;
    printf("  Jogo da Velha \n ");
    printf("  Digite o tamanho da matriz: ");
    scanf("%d",&tl);
    zeraTabuleiro(tabuleiro,tl);
    do
    {
     int linha, coluna;
     printf("TABULEIRO \n");

    for(linha = 0 ; linha < tl; linha++)
    {
        for(coluna = 0 ; coluna < tl ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf("  X ");
                else
                    printf("  O ");

            if(coluna != (tl-1))
                printf("|");
        }
            printf(" \n ");
    }
    printf("\n");
        jogada(tabuleiro,tl);

    }while(checaTermino(tabuleiro, vez, tl) != 1);

}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TADQuadro.h"

void ImprimeArt(TipoQuadro *Quad){
    int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<80;j++){
            printf("%c",Quad->quadro[i][j]);
        }
    }
}

int SubMenu(){
    int qtd;
    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    scanf("%d",&qtd);

    return qtd;

}


void Inicializa(TipoQuadro *Quad){


    int i,j;

    for(i=0;i<20;i++){
        for(j=0;j<80;j++){
            Quad->quadro[i][j]= ' ';//limpa possiveis valores de lixo de memoria

        }
    }

    for(i=1;i<19;i++){
        for(j=0;j<80;j++){
            if (j == 0 || j==79){
                Quad->quadro[i][j]= '|';
            }
        }
    }


    for(i=0;i<20;i++){
        for(j=0;j<80;j++){

            if (i == 0){
                Quad->quadro[i][j]= '-';
            }

            if (i == 19){
                Quad->quadro[i][j]= '-';
            }
        }
    }

    return;
}

void AsteriscoArt(TipoQuadro *Quad, int qtd, short flag){ // opcao 1

    int i,j,k,opcao = 0;
    srand(time(NULL));

    if (qtd >100){
        qtd = 100;
    }else {
        if (qtd <= 0) { qtd = rand() % 100; };//para valores menores iguais a 0, deve-se gerar uma quantidade aleat�ria
    }

    for (k = 0;k<qtd;k++){
        i = 1 + (rand() % 19);// para i [1,19]
        j = 1 + (rand() % 77);// para j [1,78]

        if (Quad->quadro[i][j] != '*') {//trata caracteres ja existentes
            Quad->quadro[i][j] = '*';
        }else {
            k--;//valor decrementado, pois houve conflito de valores.
        }
    }


    if (flag){
    ImprimeArt(Quad);
    Inicializa(Quad);

    printf("Deseja fazer um novo quadro com este mesmo valor? 1 - sim 2 - nao\n");
    scanf("%d",&opcao);
    if (opcao == 1)
        AsteriscoArt(Quad,qtd,1);
    else
        return;
    }

}
void MaisArt(TipoQuadro *Quad, int qtd,short flag){

    int i,j,k,opcao;
    srand(time(NULL));

    if (qtd >100)
        qtd = 100;

    else if (qtd <= 0) qtd = rand() % 100;//para valores menores iguais a 0, deve-se gerar uma quantidade aleat�ria

    for (k = 0;k<qtd;k++){
        i = 2 + (rand() % 16);//ocupa posicoes 2 a 18
        j = 2 + (rand() % 76);

        if (Quad->quadro[i][j] != '|' && Quad->quadro[i][j] != '*' && Quad->quadro[i][j-1] != '*' && Quad->quadro[i][j+1]!= '*' && Quad->quadro[i-1][j]!= '*' && Quad->quadro[i+1][j]!= '*'){
                Quad->quadro[i][j]= '*';
                Quad->quadro[i][j+1] = '*';
                Quad->quadro[i][j-1] = '*';
                Quad->quadro[i-1][j] = '*';
                Quad->quadro[i+1][j] = '*';
        }
        else
            k--;//valor decrementado, pois houve conflito de valores.
    }

    if (flag){
    ImprimeArt(Quad);
    Inicializa(Quad);

    printf("Deseja fazer um novo quadro com este mesmo valor? 1 - sim 2 - nao\n");
    scanf("%d",&opcao);
    if (opcao == 1)
        MaisArt(Quad,qtd,1);
    else
        return;
    }

}

void XArt(TipoQuadro *Quad, int qtd,short flag){
    int i,j,k,opcao;
    srand(time(NULL));

    if (qtd > 100)
        qtd = 100;

    else if (qtd <= 0) qtd = rand() % 100;//para valores menores iguais a 0, deve-se gerar uma quantidade aleat�ria

    for (k = 0;k<qtd;k++){
        i = 2 + (rand() % 16);
        j = 2 + (rand() % 76);

        if (Quad->quadro[i][j] != '|' && Quad->quadro[i][j] != '*' && Quad->quadro[i+1][j+1] != '*' && Quad->quadro[i-1][j-1] != '*' && Quad->quadro[i+1][j-1] != '*' && Quad->quadro[i-1][j+1] != '*' && Quad->quadro[i+1][j] != '*' && Quad->quadro[i-1][j] != '*'){
           Quad->quadro[i+1][j+1] = '*';
           Quad->quadro[i-1][j-1] = '*';
           Quad->quadro[i+1][j-1] = '*';
           Quad->quadro[i-1][j+1] = '*';
           Quad->quadro[i][j] = '*';
        }


        else
            k--;//valor decrementado, pois houve conflito de valores.
    }


    if (flag){
    ImprimeArt(Quad);
    Inicializa(Quad);

    printf("Deseja fazer um novo quadro com este mesmo valor? 1 - sim 2 - nao\n");
    scanf("%d",&opcao);
    if (opcao == 1)
        XArt(Quad,qtd,1);
    else
        return;
    }
}

void AleatorioArt(TipoQuadro *Quad, int qtd,short flag){

    int limite = 0,opcao;
    short indice;
    srand(time(NULL));

    if (qtd > 50)
        qtd = 50;

    else if (qtd <= 0) qtd = rand() % 50;//para valores menores iguais a 0, deve-se gerar uma quantidade aleat�ria

    while (limite < qtd){//valores aleatorios de 0 a 3
        indice = rand() % 4;
        if (indice == 0){AsteriscoArt(Quad,1,0); limite++;}
        if (indice == 1){MaisArt(Quad,1,0);limite++;}
        if (indice == 2){XArt(Quad,1,0);limite++;}
        if (indice == 3){CruzArt(Quad,1,0);limite++;}

    }


    if (flag){
    ImprimeArt(Quad);
    Inicializa(Quad);

    printf("Deseja fazer um novo quadro com um novo valor aleatorio? 1 - sim 2 - nao\n");
    scanf("%d",&opcao);
    if (opcao == 1)
        AleatorioArt(Quad,(rand() % 45),1);
    else
        return;
    }


}
void CruzArt(TipoQuadro *Quad, int qtd,short flag){

    int i,j,k,opcao;
    srand(time(NULL));

    if (qtd > 40)
        qtd = 40;

    else if (qtd <= 0) qtd = rand() % 40;//para valores menores iguais a 0, deve-se gerar uma quantidade aleat�ria

    for (k = 0;k<qtd;k++){
        i = 1 + (rand() % 12);
        j = 3 + (rand() % 75);

        if (Quad->quadro[i][j]!= '*') {
            if(Quad->quadro[i+1][j+1]!= '*' && Quad->quadro[i+2][j+1]!= '*' && Quad->quadro[i+3][j+1]!= '*' && Quad->quadro[i+4][j+1]!= '*' && Quad->quadro[i-1][j+1]!= '*' && Quad->quadro[i-2][j+1]!= '*'){
                if(Quad->quadro[i+1][j-1]!= '*' && Quad->quadro[i+2][j-1]!= '*' && Quad->quadro[i+3][j-1]!= '*' && Quad->quadro[i+4][j-1]!= '*' && Quad->quadro[i-1][j-1]!= '*' && Quad->quadro[i-2][j-1]!= '*'){
                    if(Quad->quadro[i+1][j+1]!= '*' && Quad->quadro[i+1][j+2]!= '*' && Quad->quadro[i+1][j+3]!= '*' && Quad->quadro[i+1][j-1]!= '*' && Quad->quadro[i+1][j-2]!= '*' && Quad->quadro[i+1][j-3]!= '*'){
                        if(Quad->quadro[i-1][j+1]!= '*' && Quad->quadro[i-1][j+2]!= '*' && Quad->quadro[i-1][j+3]!= '*' && Quad->quadro[i-1][j-1]!= '*' && Quad->quadro[i-1][j-2]!= '*' && Quad->quadro[i-1][j-3]!= '*'){
                            if(Quad->quadro[i][j+4]!= '|' && Quad->quadro[i+5][j]!= '-' && Quad->quadro[i][j-4]!= '|' && Quad->quadro[i-3][j]!= '-'){
                                Quad->quadro[i][j]= '*';
                                Quad->quadro[i][j+1]= '*';
                                Quad->quadro[i][j+2]= '*';
                                Quad->quadro[i][j+3]= '*';
                                Quad->quadro[i][j+4]= '*';
                                Quad->quadro[i][j+5]= '*';
                                Quad->quadro[i][j+6]= '*';
                                Quad->quadro[i+4][j+3]= '*';
                                Quad->quadro[i+3][j+3]= '*';
                                Quad->quadro[i+2][j+3]= '*';
                                Quad->quadro[i+1][j+3]= '*';
                                Quad->quadro[i-1][j+3]= '*';
                                Quad->quadro[i-2][j+3]= '*';
                            }

                        }
                    }
                }
            }
        }

        else
            k--;//valor decrementado, pois houve conflito de valores.
    }


    if (flag){
    ImprimeArt(Quad);
    Inicializa(Quad);

    printf("Deseja fazer um novo quadro com este mesmo valor? 1 - sim 2 - nao\n");
    scanf("%d",&opcao);
    if (opcao == 1)
        CruzArt(Quad,qtd,1);
    else
        return;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "TADQuadro.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    TipoQuadro Quad;
    int opcao = 0,qtd;


    int i,j;


    do{
        Inicializa(&Quad);
        printf("\n\nPROGRAMA GERADOR DE OBRA DE ARTE:\n");
        printf("====================================\n");
        printf("Escolha o tipo de figura básica a ser usada para criar a obra:\n");
        printf("1 - Asterisco simples.\n");
        printf("2 - Símbolo de soma com asteriscos.\n");
        printf("3 - Letra X com asteriscos.\n");
        printf("4 - Figuras aleatorias\n");
        printf("5 - Cruz com asteriscos (max: 45)\n");
        printf("6 - Sair\n");

        printf("Digite o tipo de figura básica desejada: ");
        scanf("%d",&opcao);
        fflush(stdin);

        switch(opcao){
        case 1:
            qtd = SubMenu();
            AsteriscoArt(&Quad,qtd,1);
            break;

        case 2:
            qtd = SubMenu();
            MaisArt(&Quad,qtd,1);
            break;
        case 3:
            qtd = SubMenu();
            XArt(&Quad,qtd,1);
            break;
        case 4:
            qtd = SubMenu();
            AleatorioArt(&Quad,qtd,1);
            break;
        case 5:
            qtd = SubMenu();
            CruzArt(&Quad,qtd,1);
            break;
        default:
            if(opcao != 6)printf("Escolha uma opção válida!\n");
            break;
        }
    }while (opcao != 6);

    return 0;
}

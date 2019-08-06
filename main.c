#include <stdio.h>
#include <stdlib.h>
#include "Questoes.h"

int main()
{
    int opc;
    printf("Escolha o numero da questao (de 1 a 6), e 7 para sair: ");
    scanf("%d",&opc);
    while(opc != 7)
    {
        if(opc == 1) questao1();
        if(opc == 2) questao2();
        if(opc == 3) questao3();
        if(opc == 4) questao4();
        if(opc == 5) questao5();
        if(opc == 6) questao6();
        system("pause");
        system("cls");
        printf("Escolha o numero da questao (de 1 a 6), e 7 para sair: ");
        scanf("%d",&opc);
    }

}

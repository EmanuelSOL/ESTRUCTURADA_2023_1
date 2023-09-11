//Sexo_SOE_ACT1_4
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int sexo;
    system("CLS");
    printf("1) Para hombre\n");
    printf("2) Para mujer\n\n");

    printf("Dame tu sexo: ");
    scanf("%d", &sexo);

    if (sexo == 1 && sexo != 2)
    {
        printf("HOLA, ERES HOMBRE ");
    }

    else if (sexo ==2 && sexo != 1);
    {
        printf("HOLA, ERES MUJER");

    }

    return 0;

}
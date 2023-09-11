//NumeroMayor_SOE_ACT2_3
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main ()
{
    int num1, num2, num3, num4, num5, num6, numM;
    system("CLS");
    printf("Dame el primer numero\n");
    scanf("%d", &num1);

    printf("Dame el segundo numero\n");
    scanf("%d", &num2);

    printf("Dame el tercer numero\n");
    scanf("%d", &num3);

    printf("Dame el cuarto numero\n");
    scanf("%d", &num4);

    printf("Dame el quinto numero\n");
    scanf("%d", &num5);

    printf("Dame el sexto numero\n");
    scanf("%d", &num6);

    numM = num1;

    if (num2 > numM)
    {
        numM = num2;
    }

    if (num3 > numM)
    {
        numM = num3;
    }

    if (num4 > numM)
    {
        numM = num4;
    }

    if (num5 > numM)
    {
        numM = num5;
    }

    if (num6 > numM)
    {
        numM = num6;
        
    }

    printf("Numero mayor es %d\n", numM);
    
    return 0;
}
//numero ascendente_SOE_ACT1_9
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, num3;
    system("CLS");

    printf("Dame el primer numero: \n");
    scanf("%d", &num1);

    printf("Dame el segundo numero: \n");
    scanf("%d", &num2);

    printf("Dame el tercer numero: \n");
    scanf("%d", &num3);

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            if (num2 > num3)
            {
                printf("Forma ascendente: %d, %d, %d", num3, num2, num1);
            }
            else
            {
                printf("Forma ascendente: %d, %d, %d", num2, num3, num1);
            }
        }
        else
        {
            printf("Forma ascendente: %d, %d, %d", num2, num1, num3);
        }
    }
    else
    {
        if (num1 > num3)
        {
            printf("Forma ascendente: %d, %d, %d",  num3, num1, num2);
        }
        else
        {
            if (num2 > num3)
            {
                printf("Forma ascendente: %d, %d, %d", num1, num3, num2);
            }
            else
            {
                printf("Forma ascendente: %d, %d, %d", num1, num2, num3);
            }
        }
    }

    return 0;

}
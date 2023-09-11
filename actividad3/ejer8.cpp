//numero de enmedio_SOE_ACT1_8
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
            if(num2 > num3)
            {
                printf("El numero del medio es: %d", num2);
            }
            else
            {
                printf("El numero del medio es: %d", num3);
            }
        }
        else
        {
            printf("El numero del medio es: %d", num1);
        }

    }
    else
    {
        if (num1 > num3)
        {
            printf("El numero del medio es: %d", num1);
        }
        else
        {
            if (num2 > num3)
            {
                printf("El numero del medio es: %d", num3);
            }
            else
            {
                printf("El numero del medio es: %d", num2);
            }
        }
    }

    return 0;
}

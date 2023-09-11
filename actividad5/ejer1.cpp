//SOE_ACT5_1
//SOLIS OROZCO EMANUEL 00369154
//Valor de n y desplegar numero enteros positivos en orden descendente
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    int num,i;

    system("CLS");

    printf("Dame un numero: ");
    scanf("%d", &num);

    if (num<=0)
    {
        printf("Ingresa un numero positivo ");
    }
    else
    {

        for(i = num; i > 0; i--)
        {
            printf("%d \n",i);
        }

    }


    return 0;
}

//SOE_ACT3_2
//SOLIS OROZCO EMANUEL 00369154
//num mayor
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    int num1, num2, num3;
    printf("Dame en numero 1: \n");
    scanf("%d", &num1);
    printf("Dame el numero 2: \n");
    scanf("%d", &num2);
    printf("Dame el numero 3: \n");
    scanf("%d", &num3);

    if (num1 > num2 && num1 > num3)
    {
        printf("El numero mayor es: %d", num1);
    }
    else
    {
        if (num2 > num1 && num2 > num3)
        {
            printf("El numero mayor es: %d", num2);
        }
        else
        {
            printf("El numero mayor es: %d", num3);
        }
    }

    return 0;
}
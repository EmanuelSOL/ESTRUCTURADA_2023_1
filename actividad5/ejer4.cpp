//SOE_ACT5_4
//SOLIS OROZCO EMANUEL 00369154
//Tabla de multimplicar del 1-20
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    int num, i, mult;

    printf("Dame un numero del 1 al 20: ");
    scanf("%d", &num);



    if (num<=0 || num>20)
    {
       printf("Ingresa un numero dentro de los valores ");
    }
    else if (num>0 || num<=20)
    {
        printf("Tabla del %d \n",num);
        
        for (i = 1; i <= 10; i++)
        {
            mult = num * i;
            printf("%d * %d = %d \n", num, i, mult);
        }
    }

    return 0;

}
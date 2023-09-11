//SOE_ACT5_3
//SOLIS OROZCO EMANUEL 00369154
//Genera 35 numeros del 100-200 despliega el numero mayor y el numero menor
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));

    int numR, mayor, menor, i, media, suma;

    i = 1;
    suma = 0;
    mayor = 0;
    menor = 201;

    while(i <= 35)
    {
        numR = ((rand() % 101) + 100);

        printf("%d\n", numR);

        if(numR > mayor)
        {
            mayor = numR;
        }

        if(numR < menor)
        {
            menor = numR;
        }

        i++;
    }

    printf("El numero mayor es: %d\n", mayor);
    printf("El numero menor es: %d\n", menor);

    return 0;
}
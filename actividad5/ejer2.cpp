//SOE_ACT5_2
//SOLIS OROZCO EMANUEL 00369154
//Genera 40 numeros del 0-200 y dice si es par o impar y la suma de estos 
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));

    float sumaP, sumaI;
    int i, j, totP, totI, numR;

    i = 0;
    j = 0;
    while (i <= 40)
    {
        numR = (rand() % 201);
        if(numR == 0)
        {
            i == 40;
        }
        else
        {
            if(numR % 2 == 0)
            {
                printf("El numero %d es par\n", numR);
                sumaP = sumaP + numR;
                totP = j;
                j = j + 1;
            }
            else
            {
                printf("El numero %d es impar\n", numR);
                sumaI = sumaI + numR;
                totI = i - totP;
            }
            i = i + 1;
        }
    }

    printf("La suma de los numeros pares es igual a: %.0f\n", sumaP);
    printf("El total de numeros pares es de: %d\n", totP);
    printf("La suma de los numeros impares es igual a: %.0f\n", sumaI);
    printf("El total de numeros impares es de: %d\n", totI);
    
    return 0;
}
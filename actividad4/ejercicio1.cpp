//MenuOpSimple_SOE_ACT2_1
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main ()
{
    float num1, num2, sum, rest, mult, div;
    int opcion;
    system("CLS");
    printf("MENU\n");
    printf("1).- Suma\n2).- Resta\n3).- Multiplicacion\n4).- Division\n ");
    
    printf("Que operacion deseas realizar? \n");
    scanf("%d", &opcion);

    printf("Dame el primer numero: \n");
    scanf("%f", &num1);

    printf("Dame el segundo numero: \n");
    scanf("%f", &num2);

    div = (num1 / num2);
    mult = (num1 * num2);
    rest = (num1 - num2);
    sum = (num1 + num2);

    if (opcion < 0 || opcion > 4)
    {
        printf("Error, elija una opcion valida\n");
    }
    else
    {
        if (opcion == 1)
        {
            printf("El resultado de la suma es: %.2f", sum);
        }
        else
        {
            if (opcion == 2)
            {
                printf("El resultado de la resta es: %.2f", rest);
            }
            else
            {
                if (opcion == 3)
                {
                    printf("El resultado de la multiplicacion es: %.2f", mult);
                }

                else
                {
                    if (opcion == 4)
                    {
                        printf("El resultado de la division es: %.2f", div);
                    }
                }
            }
        }
    }
        return 0;
}

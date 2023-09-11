//Llamada_SOE_ACT2_5
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main ()
{
    int tipo;
    float min, subT, IVA, total;
    system("CLS");

    printf("1).- Llamada local\n2).- Llamada nacional\n3).- Llamada internacional\n\n");

    printf("Que tipo de llamada usaste: \n");
    scanf("%d", &tipo);

    printf("Cuantos minutos usaste: \n");
    scanf("%f", &min);
    
    if (tipo < 0 || tipo > 3) 
    {
        printf("Error, elija una opcion valida\n");
    }
    else
    {

        if (tipo == 1)
        {
            subT = 3;
        }
        else
        {
            if (tipo == 2)
             {
                if (min <= 3)
                {
                    subT = 7;
                }
                else
                {
                    subT = 7 + ((min - 3) * 2);
                }
             }
            else
            {
                if (min <= 2)
                {
                    subT = 9;
                }
                else
                {
                    subT = 9 + ((min - 2) * 4);
                }
            }
        }
    }

    IVA = subT * 0.16;
    total = subT + IVA;
    printf("El subtotal es de: %.2f\n", subT);
    printf("IVA: %.2f\n", IVA);
    printf("El total de tu llamada telefonica es de : %.2f\n", total);

    return 0;
}
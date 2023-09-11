//SOE_ACT3_1
//SOLIS OROZCO EMANUEL 00369154
//prom de 3 calificaciones 
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main ()
{
    float cal1, cal2, cal3, prom;
    printf("Dame la calificacion 1: ");
    scanf("%f", &cal1);

    printf("Dame la calificacion 2: ");
    scanf("%f", &cal2);

    printf("Dame la calificacion 3: ");
    scanf("%f", &cal3);

    prom = (cal1 + cal2 + cal3) / 3;
    printf("El promedio es de: %.2f \n", prom);

    if (prom >= 80)
    {
        if (prom >= 98)
        {
            if (prom > 100)
            {
                printf("Error en promedio");
            }
            else
            {
                printf("Excelente");
                
            }
        }
        else
        {
            if (prom >= 90)
            {
                printf("Muy bien");
            }
            else
            {
                printf("bien");
            }
            
        }
    } 
    else
    {
        if (prom >= 60)
        {
            if (prom >= 70)
            {
                printf("Regular");
            }
            else
            {
                printf("Suficiente");
            }
        }
        else
        {
            if (prom >= 30)
            {
                printf("Extraordinario");
            }
            else
            {
                printf("Repetir");
            }
        }
    }

    return 0;
}

//Promedio_SOE_ACT1_5
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float calif1, calif2, calif3, prom;
    system("CLS");

    printf("Dame la primera calificacion: \n ");
    scanf("%f", &calif1);

    printf("Dame la segunda calificacion: \n ");
    scanf("%f", &calif2);

    printf("Dame la tercera calificacion: \n ");
    scanf("%f", &calif3);

    prom = (calif1 + calif2 + calif3) / 3;
    printf("Tu promedio es: %.0f \n", prom);

    if (prom >= 30)
    {
        if (prom >= 60)
        {
            if (prom >= 70)
            {
                if (prom >= 80)
                {
                    if (prom >= 90)
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
                            printf("Muy bien");
                        }
                    }
                    else
                    {
                        printf("Bien");
                    }
                }
                else
                {
                    printf("Regular");
                }
            }
            else
            {
                printf("Suficiente");
            }
        }
        else
        {
            printf("Extraordinario");
        }
        
    }
    else
    {
        printf("Repetir");
    }

    return 0;

}
//aprobado o reprobado con 4 calificaciones_SOE_ACT1_3
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float calif1, calif2, calif3, calif4, prom;
    system("CLS");

    printf("Dame la primera calificacion \n");
    scanf("%f", &calif1);

    printf("Dame la segunda califiacion \n");
    scanf("%f", &calif2);

    printf("Dame la tercera calificacion \n");
    scanf("%f", &calif3);

    printf("Dame la cuarta calificacion \n");
    scanf("%f", &calif4);

    prom = (calif1 + calif2 + calif3 + calif4) / 4;

    printf("Tu promedio es %.2f\n", prom);

    if (prom >= 60 && prom<=100)
        printf("APROBADO");

    else
        printf("REPROBADO");

    return 0;
}
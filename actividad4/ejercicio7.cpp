//Promedio_SOE_ACT2_1
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main ()
{
    float cal1, cal2, cal3, cal4, cal5, prom, calMenor;
    system("CLS");

    printf("Dame la primera calificacion: \n");
    scanf("%f", &cal1);

    printf("Dame la segunda calificacion: \n");
    scanf("%f", &cal2);

    printf("Dame la tercera calificacion: \n");
    scanf("%f", &cal3);

    printf("Dame la cuarta calificacion: \n");
    scanf("%f", &cal4);

    printf("Dame la quinta calificacion: \n");
    scanf("%f", &cal5);

    calMenor = cal1;

    if (cal2 < calMenor)
    {
        calMenor = cal2;
    
    }

    if (cal3 < calMenor)
    {
        calMenor = cal3;
    
    }

    if (cal4 < calMenor)
    {
        calMenor = cal4;
    
    }

    if (cal5 < calMenor)
    {
        calMenor = cal5;
    }

    prom = ((cal1 + cal2 + cal3 + cal4 + cal5) - calMenor) / 4;

    printf("El promedio final es de: %.2f", prom);

    return 0;
}

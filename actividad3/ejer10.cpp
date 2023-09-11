//Horas trabajadas_SOE_ACT1_10
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float horastrab, salhora, horasextra, salnormal, salextra, saltotal;
    system("CLS");
    
    printf("Dame las horas trabajadas \n");
    scanf("%f", &horastrab);

    printf("Dame el salario por hora \n");
    scanf("%f", &salhora);

    horasextra = horastrab - 40;

    if (horasextra < 0)
    {
        salnormal = salhora * horastrab;
        salextra = 0;
    }
    else
    {
        if(horasextra <= 9) 
        {
            salnormal = (salhora * 40);
            salextra = (horasextra * salhora * 2);
        }
        else
        {
            salnormal = (salhora * 40);
            salextra = (salhora * 18) + ((horasextra - 9) * salhora);
        }
    }

    saltotal = salnormal + salextra;

    printf("Salario por hora: %.1f\n", salhora);
    printf("Horas trabajadas: %.1f\n", horastrab);
    printf("Salario normal: %.1f\n", salnormal);
    printf("Salario extra: %.1f\n", salextra);
    printf("Salario Total: %.1f\n", saltotal);

    return 0;
}
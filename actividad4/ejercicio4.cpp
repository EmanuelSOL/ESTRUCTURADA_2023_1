//Salario_SOE_ACT2_4
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float horasTra, salHora, salExtra, salNormal, horasExtra, salTotal;
    system("CLS");
    printf("Dame las horas trabajadas durante la semana\n");
    scanf("%f", &horasTra);
    printf("Dame el salario por hora\n");
    scanf("%f", &salHora);
    
    if (horasTra <= 40)
    {
        salExtra = 0;
        salNormal = horasTra * salHora;
    }
    else
    {
        if (horasTra <= 49)
        {
            horasExtra = horasTra - 40;
            salNormal = salHora * 40;
            salExtra = (salHora * horasExtra * 2);
        }
        else
        {
            horasExtra = horasTra - 49;
            salNormal = salHora * 40;
            salExtra = (salHora * 9 * 2) + (salHora * horasExtra * 3);
        }
    }

    salTotal = salNormal + salExtra;

    printf("Salario por hora: %.2f\n", salHora);
    printf("Horas trabajadas: %.2f\n", horasTra);
    printf("Salario normal: %.2f\n", salNormal);
    printf("Salario extra: %.2f\n", salExtra);
    printf("Salario Total: %.2f\n", salTotal);

    return 0;
}
//Minutos en llamadas_SOE_ACT1_11
//SOLIS OROZCO EMANUEL 00369154
//22-08-23 //27-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

    float minutos, tipoLlamada, iva, subTotal, total;
    system("CLS");

    printf("Que tipo de llamada usaste: \n 1) Llamada Local\n 2) Llamada Nacional\n 3) Llamada Internacional\n");
    scanf("%f", &tipoLlamada);

    printf("Dame la durabilidad de la llamada en minutos: \n");
    scanf("%f", &minutos);

    if (tipoLlamada == 1)
    {
        subTotal = 3;
    }
    else
    {
        if ( tipoLlamada == 2)
        {
            if (minutos <= 3)
            {
                subTotal = 7;
            }
            else
            {
                subTotal = 7 + ((minutos - 3) * 2);
            }
        }
    }

    if (tipoLlamada == 3)
    {
        if (minutos <= 2)
        {
            subTotal = 9;
        }
        else
        {
            subTotal = 9 + ((minutos - 2) * 4);
        }
    }

    iva = subTotal * 0.16;
    total = subTotal + iva;

    printf("Subtotal a pagar: %.2f\n", subTotal);
    printf("IVA: %.2f\n", iva);
    printf("Total a pagar: %.2f\n", total);


}
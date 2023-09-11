//M3Agua_SOE_ACT2_6
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float m3, subTotal, iva, total;
    system("CLS");

    printf("Dame los metros cubicos de agua: \n");
    scanf("%f", &m3);

    if ( m3 >= 0)
    {
        if(m3 <= 4)
        {
            subTotal = 50;
        }
        else
        {
            if (m3 >= 5)
            {
                if (m3 <= 15)
                {
                    subTotal = 8;
                }
                else
                {
                    if(m3 >= 16)
                    {
                        if(m3 <= 50)
                        {
                            subTotal = 10;
                        }
                        else
                        {
                            if (m3 >= 51)
                            {
                                subTotal = 11;
                            }
                        }
                    }
                }
            }
        }
    }

    else
    {
        printf("Error");
    }

    iva = subTotal * 0.16;
    total = subTotal + iva;

    printf("El subtotal es de: %.2f\n", subTotal);
    printf("IVA: %.2f\n", iva);
    printf("El total de es: %.2f", total);

    return 0;

}

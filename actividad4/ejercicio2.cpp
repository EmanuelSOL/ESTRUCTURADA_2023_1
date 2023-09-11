//Conversiones_SOE_ACT2_2
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float cm, pulg, km, millas, pies, num, op;
    int opcion;
    system("CLS");
    printf("MENU\n");
    printf("1).- Cm a pulgadas\n2).- Cm a pies\n");  
    printf("3).- Km a millas\n4).- Pulgadas a cm\n");
    printf("5).- Pies a cm\n6).- Millas a km\n");

    printf("Que operacion deseas? \n");
    scanf("%d", &opcion);

    printf("Dame la cantidad a convertir \n");
    scanf("%f", &num);

    if (opcion == 1)
    {
        op = num * 0.393701;
        printf("La equivalencia es de %.2f pulgadas", op);
        }
    else
    {
        if (opcion == 2)
        {
            op = num * 0.0328084;
            printf("La equivalencia es de %.2f pies", op);
        }
        else
        {
            if (opcion == 3)
            {
                op = num * 0.621371;
                printf("La equivalencia es de %.2f millas", op);
            }

            else
            {
                if (opcion == 4)
                {
                    op = num * 2.54;
                    printf("La equivalencia es de %.2f centimetros", op);
                }
                else
                {
                    if (opcion == 5)
                    {
                        op = num * 30.48;
                        printf("La equivalencia es de %.2f centimetros", op);
                    }
                    else
                    {
                        if (opcion == 6)
                        {
                            op = num * 1.60934;
                            printf("La equivalencia es de %.2f kilometros", op);
                        }
                    }
                }
            }
        }
    }


    return 0;
}
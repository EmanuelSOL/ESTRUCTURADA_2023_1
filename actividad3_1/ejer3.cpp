//SOE_ACT3_2
//SOLIS OROZCO EMANUEL 00369154
//chinchampu seleccion multiple
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define piedra 1
#define papel 2
#define tijera 3

int main()
{
    int j1, comp;
    srand(time(NULL));

    printf("1. Piedra\n2. Papel\n3. Tijera\n\n");

    printf("Elije\n");
    scanf("%d", &j1);

    comp = (rand() % 3) + 1;

    switch (j1)
    {

    case 1:

        if (j1 == comp)
        {
            printf("Empate");
        }
        else
        {
            if (j1 == piedra)
            {
                if (comp == papel)
                {
                    printf("La computadora gana\n");
                    printf("Papel gana a piedra\n");
                }
                else
                {
                    printf("Has ganado\n");
                    printf("Piedra gana a tijera\n");
                }
            }
        }
        break;

    case 2:

        if (j1 == comp)
        {
            printf("Empate");
        }
        else
        {
            if (j1 == papel)
            {
                if (comp == piedra)
                {
                    printf("Has ganado\n");
                    printf("Papel gana a piedra\n");
                }
                else
                {
                    printf("La computadora gana\n");
                    printf("Tijera gana a papel\n");
                }
            }
        }
        break;

    case 3:

        if (j1 == comp)
        {
            printf("Empate");
        }
        else
        {
            if (comp == piedra)
            {
                printf("La computadora gana\n");
                printf("Piedra gana a Tijera\n");
            }
            else
            {
                printf("Has ganado\n");
                printf("Tijera gana a papel\n");
            }
        }

        break;
    }

    return 0;
}
//ParImpatr_SOE_ACT1_2
//SOLIS OROZCO EMANUEL 00369154
//22-08-23

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num1;
    system("CLS");

    printf("Dame un numero\n");
    scanf("%d", &num1);

    if (num1 % 2 == 0)
        printf("PAR");

    if (num1 % 2 != 0)
        printf("IMPAR");

    return 0;

}
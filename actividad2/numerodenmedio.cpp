#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num1,num2,num3;
    printf("Dame el primer numero: ");
    scanf("%d",num1);
    printf("Dame el segundo numero: ");
    scanf("%d",num2);
    printf("Dame el tercer numero: ");
    scanf("%d",num3);

    if(num1>num2 && num2>num3 || num3>num2 && num2>num1)

    {
        printf("El numero de enmedio es el numero %d",num2);

    }
    else if (num2>num3 && num3>num1 || num1>num3 && num3>num2)
    {
        printf("El numero de enmedio es el numero %d",num3);
    }
    else if (num3>num1 && num1>num2 || num2>num1 && num1>num3)
    {
        printf("El numero de enmedio es el numero %d",num1);
    }

    return 0;
    

}
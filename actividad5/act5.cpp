//SOE_ACT5_1
//SOLIS OROZCO EMANUEL 00369154
//Un menu con los 4 ejercicios que nos pido
//06-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int msge();

void menu();
void positivos();
void parimpar(void);
void mayormenor(void);
void tabla(void);


int main()
{
    menu();
    return 0;
}

int msge()//Menu, este es el menu que salira en la pantalla del usuario 
{
    int op;
    system("CLS");
    printf("MENU\n\n");
    printf("1.- Positivos en orden descendente\n");
    printf("2.- Par e impar\n");
    printf("3.- Numero mayor y numero menor\n");
    printf("4.- Tabla de multiplicar\n");
    printf("5.- Salir\n");
    printf("Escoge una opcion: ");
    scanf("%d", &op);

    return op;

}

void menu()//Este void menu tiene un switch que depende del numero que hayas puesto te manda a lo que selecionaste 
{
    int op;
    do
    {
        op = msge();
        switch (op)
        {
        case 1:
            positivos();
            break;

        case 2:
            parimpar();
            break;

        case 3:
            mayormenor();
            break;
        
        case 4:
            tabla();
            break;
        }
    } while (op != 0);
}

void positivos(void)
{
    int num,i;

    printf("Dame un numero: ");
    scanf("%d", &num);

    if (num<=0)
    {
        printf("Dame un numero positivo: ");
    }
    else
    {

        for (i = num; i > 0; i--)
        {
            printf("%d \n",i);
        }

    }


    system("PAUSE");
}

void parimpar(void)
{
    srand(time(NULL));

    float sumaPar, sumaImp;
    int i, j, totPar, totImp, numRand;

    i = 0;
    j = 0;
    while (i <= 40)//Es un ciclo que se parara cuando la cantidad de numeros sea de 40
    {
        numRand = (rand() % 201);//Genera un numero random del 0 - 200
        if(numRand == 0)
        {
            i == 40;
        }
        else
        {
            if(numRand % 2 == 0)
            {
                printf("El numero %d es par\n", numRand);
                sumaPar = sumaPar + numRand;
                totPar = j;
                j = j + 1;
            }
            else
            {
                printf("El numero %d es impar\n", numRand);
                sumaImp = sumaImp + numRand;
                totImp = i - totPar;
            }

            i = i + 1;
        }
    }

    printf("La suma de los numeros pares es: %.0f\n", sumaPar);
    printf("El total de numeros pares es: %d\n", totPar);
    printf("La suma de los numeros impares es: %.0f\n", sumaImp);
    printf("El total de numeros impares es: %d\n", totImp);
    
    system("PAUSE");
}

void mayormenor(void)
{
    srand(time(NULL));

    int numR, mayor, menor, i, media, suma;

    i = 1;
    suma = 0;
    mayor = 0;
    menor = 201;

    while(i <= 35)
    {
        numR = ((rand() % 101) + 100);

        printf("%d\n", numR);

        if(numR > mayor)
        {
            mayor = numR;
        }

        if(numR < menor)
        {
            menor = numR;
        }

        i++;
    }

    printf("El numero mayor es: %d\n", mayor);
    printf("El numero menor es: %d\n", menor);

    system("PAUSE");
}

void tabla(void)
{
    int num, i, mult;

    printf("Dame un numero del 1 al 20: ");
    scanf("%d", &num);


    if (num<=0 || num>20)
    {
       printf("Ingresa un numero dentro de los valores ");
    }
    else if (num>0 || num<=20)
    {
        printf("Tabla del %d \n",num);
        
        for (i = 1; i <= 10; i++)
        {
            mult = num * i;
            printf("%d * %d = %d \n", num, i, mult);
        }
    }

    system("PAUSE");
}
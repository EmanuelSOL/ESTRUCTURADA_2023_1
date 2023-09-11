// ACT_06
// Solis Orozco Emanuel 00369154

#include <stdio.h>
#include <stdlib.h>

int msg();
int msgfibonacci();
int msgfactorial();
int msgcantidadD();

void menu();
void menufibonacci();
void menufactorial();
void menucantidadD();

void fibonaccicw(void);
void fibonaccicf(void);
void fibonaccicd(void);
void factorialcw(void);
void factorialcf(void);
void factorialcd(void);
void cantidadcw(void);
void cantidadcf(void);
void cantidadcd(void);

//Este es nuestro main principal

int main()
{
    menu();

    return 0;
}

//Este es el menu que saldra al correr el programa

int msg()
{
    int op1;
    system("CLS");
    printf("MENU \n");
    printf("1.- Fibonacci\n");
    printf("2.- Factorial\n");
    printf("3.- Cantidad de digitos\n");
    printf("0.- SALIR  \n");
    scanf("%d", &op1);

    return op1;
}

//Si selecciona fibonacci te saldra este menu
//aqui seleccionara con que ciclo realizar la operacion

int msgfibonacci()
{
    int op2;
    system("CLS");
    printf("MENU \n");
    printf("1.- Fibonacci While\n");
    printf("2.- Fibonacci For\n");
    printf("3.- Fibonacci Do-While\n");
    printf("0.- SALIR  \n");
    scanf("%d", &op2);

    return op2;
}

//Si selecciona factorial te saldra este menu
//aqui seleccionara con que ciclo realizar la operacion

int msgfactorial()
{
    int op3;
    system("CLS");
    printf("MENU \n");
    printf("1.- Factorial While\n");
    printf("2.- Factorial For\n");
    printf("3.- Factorial Do-While\n");
    printf("0.- SALIR  \n");
    scanf("%d", &op3);

    return op3;
}

//Si selecciona cantidad de digitos te saldra este menu
//aqui seleccionara con que ciclo realizar la operacion

int msgcantidadD()
{
    int op4;
    system("CLS");
    printf("MENU \n");
    printf("1.- Cantidad numeros While\n");
    printf("2.- Cantidad numeros For\n");
    printf("3.- Cantidad numeros Do-While\n");
    printf("0.- SALIR  \n");
    scanf("%d", &op4);

    return op4;
}

void menu()
{

    int op1;
    do
    {
        op1 = msg();
        switch (op1)
        {
            case 1:
                menufibonacci();
                break;

            case 2:
                menufactorial();
                break;

            case 3:
                menucantidadD();
                break;
        }

    } 
    while (op1 != 0);
}

void menufibonacci() //si se elige la operacion fibonacci sale otro menu con ciclos   
//los gatitos luciran muy lindos vestiditos
{
    int op2;
    do
    {
        op2 = msgfibonacci();
        switch (op2)
        {
        case 1:
            fibonaccicw();
            break;

        case 2:
            fibonaccicf();
            break;

        case 3:
            fibonaccicd();
            break;
        }

    } 
    while (op2 != 0);
}

void menufactorial()//si se elige la operacion factorial sale otro menu con ciclos
{
    int op3;
    do
    {
        op3 = msgfactorial();
        switch (op3)
        {
        case 1:
            factorialcw();
            break;

        case 2:
            factorialcf();
            break;

        case 3:
            factorialcd();
            break;
        }

    } 
    while (op3 != 0);
}


void menucantidadD() //si se elige la operacion cantidad de digitos sale otro menu con ciclos
{
    int op4;
    do
    {
        op4 = msgcantidadD();
        switch (op4)
        {
        case 1:
            cantidadcw();
            break;

        case 2:
            cantidadcf();
            break;

        case 3:
            cantidadcd();
            break;
        }

    }

    while (op4 != 0);
}

void fibonaccicw(void) //Este es el procedimiento para fibonacci con while
{
    long num1 = 1, num2 = 0, numad = 0, num;

    int i;

    system("CLS");

    printf("Dame un numero: \n");
    scanf("%ld", &num);

    i = 0;
    while (i < num)
    {
        printf("%ld ", numad);
        num2 = numad;
        numad = num1;
        num1 = (num2 + num1);
        i++; 
    }

    printf("\n");
    system("pause");
}

void fibonaccicf(void) //Este es el procedimiento para fibonacci con for
{


    int i;

    system("CLS");

    long num1 = 1, num2 = 0, numad = 0,num;

    printf("Dame un numero \n");
    scanf("%ld", &num);

    for (i = 0; i < num; i++)
    {
        printf("%ld ", numad);
        num2 = numad;
        numad = num1;
        num1 = (num2 + num1);

    }

    printf("\n");
    system("pause");
}

void fibonaccicd(void) //Este es el procedimiento para fibonacci con Do
{

  {
        long num1 = 1, num2 = 0, numad = 0, num;

        int i;

        system("CLS");

        printf("Dame un numero \n");
        scanf("%ld", &num);

        i = 0;
        do
        {
            printf("%ld ", numad);
            num2 = numad;
            numad = num1;
            num1 = (num2 + num1);
            i++; 

        } 
        
        while (i < num);

        printf(" \n");
        system("pause");
  }
}

void factorialcw(void) //Este es el procedimiento para el factorial con while
{

    int i, num, factorial;
    system("CLS");

    printf("Que numero quieres hacerlo en factorial?: ");
    scanf("%d", &num);

    i = 1;
    factorial = 1;

    while (i <= num)
    {
        factorial = (factorial * i);
        i++;
    }

    printf("%d", factorial);

    printf("\n");
    system("pause");
}

void factorialcf(void) //Este es el procedimiento para el factorial con for
{

    int i, num, factorial;
    system("CLS");

    printf("Que numero quieres hacerlo en factorial?: ");
    scanf("%d", &num);

    factorial = 1;

    for (i = 1; i <= num; i++)
    {
        factorial =(factorial*i);
    }

    printf("El factorial del numero es: %d", factorial);

    printf("\n");
    system("pause");
}

void factorialcd(void) //Este es el procedimiento para el factorial con while
{

    int i, num, factorial;
    system("CLS");

    printf("Que numero quieres hacerlo en factorial?: ");
    scanf("%d", &num);

    i = 1;
    factorial = 1;

    do
    {
        factorial = (factorial * i);
        i++;
    } 
    while (i <= num);

    printf("El factorial del numero es: %d", factorial);

    printf("\n");
    system("pause");
}


void cantidadcw() //Este es el procedimiento para mostrar la cantidad de digitos con while
{


    int i, num;
    system("CLS");

    printf("Dame un numero ");
    scanf("%d", &num);

    i = 0;
    while (num >= 1)
    {
        num = (num/10);
        i++;
    }

    printf("La cantidad de digitos es de: %d", i);

    printf("\n");
    system("pause");
}

void cantidadcf() //Este es el procedimiento para mostrar la cantidad de digitos con for
{

    int i, x, num;
    system("CLS");

    printf("Dame un numero ");
    scanf("%d", &num);
    x = num;

    for (i = 0; x >= 1; i++)
    {
        x = (x / 10);
    }

    printf("La cantidad de digitos es de: %d", i);

    printf("\n");
    system("pause");
}

void cantidadcd() //Este es el procedimiento para mostrar la cantidad de digitos con Do
{

    int i, x, num;
    system("CLS");

    printf("Dame un numero ");
    scanf("%d", &num);
    i = 0;
    x = num;
    
    do
    {
        x = (x / 10);
        i++;

    } while (x >= 1);

    printf("La cantidad de digitos es de: %d", i);

    printf("\n");
    system("pause");
}


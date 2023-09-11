#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tatalib.h"


int msge();
void menu();

void cargarm();
void imprimirm();
void medarit();
void moda();
void mediana();
void desvestandar();
void terccuartil();
void genarchtxt();
void genarchbin();
void imparchbin();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}


int msge()
{
    int op;
    system("CLS");
    printf("MENU\n");
    printf("1.- Cargar muestra\n");
    printf("2.- Imprimir muestra\n");
    printf("3.- Media aritmetica\n");
    printf("4.- Moda\n");
    printf("5.- Mediana\n");
    printf("6.- Desviacion estandar\n");
    printf("7.- Tercer cuartil\n");
    printf("8.- Generar archivo texto\n");
    printf("9.- Generar archivo binario\n");
    printf("10.- Imprimir archivo binario\n");
    printf("0.- Salir\n");
    scanf("%d",&op);
    return op;

    system("pause");

}


void menu()
{
    int op,datos;

    FILE *arch;
    arch = fopen("muestra.txt", "r");
    if (arch)
    {
        datos = sizeof(arch);
    }
    fclose(arch);

    do
    {
        op =msge();
        switch (op)
        {
        case 1:
                cargarm();
                break;
            case 2:
                imprimirm();
                break;
            case 3:
                medarit();
                break;
            case 4:
                moda();
                break;
            case 5:
                mediana();
                break;
            case 6:
                desvestandar();
                break;
            case 7:
                terccuartil();
                break;
            case 8:
                genarchtxt();
                break;
            case 9:
                genarchbin();
                break;
            case 10:
                imparchbin();
                break;
        }

    } 
    while (op!=0);

}



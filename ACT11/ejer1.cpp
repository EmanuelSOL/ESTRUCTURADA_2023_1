// Menu SOE_ACT11
// Descripcion: Menu de la actividad 11
// Solis Orozco Emanuel 00369154


#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tatalib11.h"
#define N 2000

int msg();
void menu();
int valida_int(int ri, int rf, char msg[], char msgError[]);
int existeTsReg(long mat, TsReg *reg, int tam);
int busq_sec(TsReg *vect, int tam, long matricula);
int busq_bin(TsReg *vect, int tam, long matri);
TsReg agregar_reg(TsReg registros[], int tam);
int cargar_reg(TsReg registros[], int tam);
void eliminar_reg(TsReg registros[], int tam, int band);
void buscar_reg(TsReg registros[], int tam, int band);
void burbuja(TsReg vect[], int tam);
void quickSort(TsReg registros[], int limIzq, int limDer);
int ordenar_reg(TsReg registros[], int tam, int band);
void imprimir_reg(TsReg registros[], int tam);
void gen_arch(TsReg registros[], int tam);

int main()
{
    system("clear");
    srand(time(NULL));
    menu();

    return 0;

}

int msg()
{
    system("clear");
    int op;

    printf(" MENU \n");
    printf("1.- Agregar\n");
    printf("2.- Eliminar Registro\n");
    printf("3.- Buscar\n");
    printf("4.- Ordenar\n");
    printf("5.- Imprimir\n");
    printf("6.- Archivo Texto\n");
    printf("0.- Salir\n");
    op = valida_int(0, 6, "ESCOGE UNA OPCION: ", "OPCION FUERA DE RANGO");

    return op;

}


void menu()
{
    TsReg reg[N];
    int op, band, tam;
    tam = 0;
    band = 0;

    do{
        op = msg();
        switch(op)
        {
            case 1:
                tam = cargar_reg(reg, tam);
                break;
            case 2:
                eliminar_reg(reg, tam, band);
                break;
            case 3:
                buscar_reg(reg, tam, band);
                break;
            case 4: 
                band = ordenar_reg(reg, tam, band);
                break;
            case 5:
                imprimir_reg(reg, tam);
                break;
            case 6:
                gen_arch(reg, tam);
                break;
        }

    }while (op != 0);

}
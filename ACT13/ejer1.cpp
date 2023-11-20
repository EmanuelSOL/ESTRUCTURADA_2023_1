
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tatalib13.h"
#define N 2500

int valida_long(long ri, long rf, char msg[], char msgError[]);
int valida_int(int ri, int rf, char msg[], char msgError[]);
void validaCadOb(char cadena[], const char *msg);
int busqSec(TsReg *vect, int tam, long matricula);
int busq_bin(TsReg *vect, int tam, long matri);
int existeTsReg(long mat, TsReg *reg, int tam);
TsReg cargar_reg(TsReg registros[], int tam);
int agregar_reg(TsReg registros[], int tam);
void eliminar_reg(TsReg registros[], int tam, int band);
void burbuja(TsReg vect[], int tam);
void quickSort(TsReg registros[], int limIzq, int limDer);
int ordenar_reg(TsReg registros[], int tam, int band);
void buscar_reg(TsReg registros[], int tam, int band);
void imprimir_reg(TsReg registros[], int tam);
void genarch_txt(TsReg registros[], int tam);
void editar_reg(TsReg registros[], int tam, int band);
void cargar_arch_bin(TsReg registros[], int *tam, int max, int *band);
void menu();
int msg();

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
    printf("1.- Agregar 100 registros\n");
    printf("2.- Editar registro\n");
    printf("3.- Eliminar registro\n");
    printf("4.- Buscar\n");
    printf("5.- Ordenar\n");
    printf("6.- Imprimir\n");
    printf("7.- Generar archivo de texto\n");
    printf("8.- Ver archivo de texto\n");
    printf("9.- Crear archivo binario\n");
    printf("10.- Cargar archivo binario\n");
    printf("0.- SALIR\n");
    op = valida_int(0, 10, "ESCOGE UNA OPCION: ", "OPCION FUERA DE RANGO");

    return op;
}

void menu()
{
    TsReg reg[N];
    int op, band, band2, tam;
    tam = 0;
    band = 0;
    band2 = 0;

    do{
        op = msg();
        switch(op)
        {
            case 1:
                tam = agregar_reg(reg, tam);
                break;
            case 2:
                editar_reg(reg, tam, band);
                break;
            case 3:
                eliminar_reg(reg, tam, band);
                break;
            case 4:
                buscar_reg(reg, tam, band);
                break;
            case 5:
                band = ordenar_reg(reg, tam, band);
                break;
            case 6:
                imprimir_reg(reg, tam);
                break;
            case 7:
                genarch_txt(reg, tam);
                break;
            case 8:
                imprimir_txt(reg, tam);
                break;
            case 9:
                genarch_bin(reg, tam);
                break;
            case 10:
                cargar_arch_bin(reg, &tam, N, &band2);
                break;
        }

    }while (op != 0);
}
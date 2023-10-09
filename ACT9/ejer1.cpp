// SOE_ACT9_ENSENADA
// Actividad 8
// Solis Orozco Emanuel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tatalib.h"

int msg();
void menu();
int valida_num(int ri, int rf, const char *msg);
int busqueda_sec(int vect[], int tam, int num);
void llenar_vect(int vect[], int tam, int ri, int rf);
void imprimir_vect(int vect[], int tam, const char *msg);
void llenar_matri(int matri[][C], int tam, int ri, int rf);
void imprimir_matri(int matri[][C], int tam, const char *msg);
void ordenar_vect(int vect[], int tam);
void buscar_valor_vect(int vect[], int tam);

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

int msg()//Aqui se mostrara el menu del programa donde se mostrara una lista de cosas que puedes hacer
{
    int op;
    system("clear");

    printf("1) LLENAR VECTOR\n");
    printf("2) LLENAR MATRIZ\n");
    printf("3) IMPRIMIR VECTOR\n");
    printf("4) IMPRIMIR MATRIZ\n");
    printf("5) ORDENAR VECTOR\n");
    printf("6) BUSCAR VALOR EN VECTOR\n");
    printf("0) SALIR\n");
    op = valida_num(0, 6, "");//Aqui se manda el numero que escrito y lo manda a la funcion que valida el numero

    return op;//Retorna el numero validado

}

void menu()//Dependiendo del numero que retorne se selecciona una opcion del switch
{
    int op;
    int vect1[N], vect2[M], matri[4][C];

    do
    {
        op = msg();
        switch (op)
        {
        case 1://Si es el caso uno se va a la funcion
            llenar_vect(vect1, N, 100, 200);//Se llena el vector con N numeros del 100-200 aleatoriamente
            break;
        case 2://Si es el caso dos se va a llenar la matriz
            llenar_vect(vect2, M, 1, 16);//Se llena el vector con M numero y numero alatorios del 1-16
            llenar_matri(matri, C, vect2);//Se llena la matriz con C numeros y con el vector anterior
            break;
        case 3:
            imprimir_vect(vect1, N, "VECTOR\n");//Se imprime el vector numero 1 
            break;
        case 4:
            imprimir_matri(matri, C, "MATRIZ\n");//Se imprime la matriz
            break;
        case 5:
            ordenar_vect(vect1, N);//Llama a la funcion ordenar_vector
            break;
        case 6:
            buscar_valor_vect(vect1, N);//Llama a la funcion buscar_valor_vector
            break;
        }
        
    } while (op != 0);
}


// SOE_ACT8_ENSENADA
// Actividad 8
// Solis Orozco Emanuel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 10
#define C 4

#define TRUE 1
#define FALSE 0

int msge();
void menu();
int validanum(int ri, int rf, char msge[],char msgeerror[]);
void vectm(int vect[], int len);
void vecta(int vect[], int len, int ri, int rf);
void impvector(int vect1[], int vect2[], int len);
void llenamat(int mat[][C], int len, int vect1[], int vect2[]);
void impmat(int mat[][C], int len);

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}
int validanum(int ri, int rf, char msge[], char msgeerror[])
{
    int num;
    char char_num[25];

    do{
        printf("%s", msge);
        fflush(stdin);
        gets(char_num);
        num = atoi(char_num);

        if (num < ri || num > rf)
        {
            printf("%s\n", msgeerror);
        }
    }
    while(num < ri || num > rf);

    return num;
}

int existe_vect(int num, int *vect, int len)
{
    int i;
    for(i=0; i <= len; i++)
    {
        if (num == vect[i])
        {
            return 1;
        }
    }
    return 0;
}

int msge()
{
    int op;
    system("CLS");
    printf("MENU\n");
    printf("1.- LLENAR VECTOR 1 (MANUALMENTE)\n");
    printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE\n");
    printf("3.- IMPRIMIR VECTORES\n");
    printf("4.- LLENA MATRIZ 4 X 4\n");
    printf("5.- IMPRIMIR MATRIZ\n");
    printf("0.- SALIR\n");
    printf("");
    scanf("%d",&op);
    return op;

}

void menu()
{
    int op;
    int vector1[N];
    int vector2[N];
    int mat[4][C];

    do
    {
        op =msge();
        switch (op)
        {
        case 1:
                vectm(vector1, N);
                break;
            case 2:
                vecta(vector2, N, 0, 20);
                break;
            case 3:
                impvector(vector1, vector2, N);
                break;
            case 4:
                llenamat(mat, C, vector1, vector2);
                break;
            case 5:
                impmat(mat, C);
                break;
        }
        
    } 
    while (op!=0);

}

void vectm(int vect[], int len)
{
    int i, num;
    system("cls");
    for(i=0; i < len; i++)
    {
        num = validanum(30, 70, "Dame un numero: ", "INVALIDO Tiene que estar entre 30-70");
        vect[i] = num;
    }
    printf("Vector llenado \n");
    system ("PAUSE");
}

void vecta(int vect[], int len, int ri, int rf)
{
    int i, rand_num, rango;
    system("CLS");
    rango = (rf - ri) + 1;
    if(rango >= len)
    {
        for(i=0; i < len; i++)
        {
            rand_num = (rand() % rango) + ri;
            while(existe_vect(rand_num, vect, len) == 1)
            {
                rand_num = (rand() % 20) + 1;
            }
            vect[i] = rand_num;
        }
        printf("Vector llenado automaticamente \n");
        system("PAUSE");
    }
    else
    {
        printf("Error \n");
        system("PAUSE");
    }
}

void impvector(int vect1[], int vect2[], int len)
{
    int i;
    system("cls");
    printf("Vector 1         Vector 2\n");
    printf("Indice   Valor      Indice        Valor\n");
    for(i=0; i < len; i++)
    {
        printf("%d        [%d]       %d           [%d]\n", i, vect1[i], i, vect2[i]);
	}
    system ("PAUSE");
}


void llenamat(int mat[][C], int len, int vect1[], int vect2[])
{
    int i, j, k, l;
    system("CLS");
    k = l = 0;
    for(i=0; i < len; i++)
    {
        for(j=0; j < len; j++)
        {
        if(k - 8)
            {
                mat[i][j] = vect1[k];
                k++;

            }
            else
            {
                if(l - 8)
                {


                    mat[i][j] = vect2[l];
                    l++;
                }
            }
        }
    }
    printf("Matriz llena\t \n");
    system("PAUSE");
}

void impmat(int mat[][C], int len)
{
    int i, j;
    system("CLS");
    printf("      1       2       3       4\n");
    for(i=0; i < len; i++)
    {
        printf("%d    ", i);
        for(j=0; j < len; j++)
        {
            printf("[%d]    ", mat[i][j]);
        }
        printf("\n");
    }
    system("pause");   
}

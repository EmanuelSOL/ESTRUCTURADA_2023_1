// SOE_ACT7_ENSENADA
// Actividad 7
// Parte 1
// Solis Orozco Emanuel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu1();
void menu();

void salida1(void);
void salida2(void);
void salida3(void);
void salida4(void);
void salida5(void);
void salida6(void);
void salida7(void);
void salida8(void);
void salida9(void);


int main()
{
    menu();
    return 0;
}

int menu1()
{
    int num;
    printf("MENU \n");
    printf("SALIDA 1 \n");
    printf("SALIDA 2 \n");
    printf("SALIDA 3 \n");
    printf("SALIDA 4 \n");
    printf("SALIDA 5 \n");
    printf("SALIDA 6 \n");
    printf("SALIDA 7 \n");
    printf("SALIDA 8 \n");
    printf("SALIDA 9 \n");
    printf("Presione 0 para salir\n");
    printf("Seleccione la opcion: ");
    scanf("%d",&num);
    return num;
}

void menu()
{
    int num;
    while (num != 0);
    {
        switch(num)
        {
            case 1:
                salida1();
                break;

            case 2:
                salida2();
                break;

            case 3:
                salida3();
                break;

            case 4:
                salida4();
                break;

            case 5:
                salida5();
                break;

            case 6:
                salida6();
                break;
                    
            case 7:
                salida7();
                break;
                    
            case 8:
                salida8();
                break;
                    
            case 9:
                salida9();
                break;
        }
    }
}

void salida1(void)
{
    char cadena[30];
    int tam,i;
    system ("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    printf("%s",cadena);
    printf("\n");
    system("PAUSE");

}

void salida2(void)
{
    char cadena[30];
    int tam,i;
    system ("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    strrev(cadena);
    printf("%s",cadena);
    printf("\n");
    system("PAUSE");

}

void salida3(void)
{

    char cadena[30];
    int tam,i;
    system ("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    tam =strlen(cadena);
    for(i=0;i<tam; i++)
    {
        printf("%c\n", cadena[i]);
    }
    printf("\n");
    system("PAUSE");

}

void salida4(void)
{
    char cadena[30];
    int i, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    strrev(cadena);
    tam = strlen(cadena);

    for (i=0;i<tam;i++)
    {
        printf("%c\n", cadena[i]);
    }

    printf("\n");
    system("PAUSE");
}

void salida5(void)
{
    char cadena[30];
    int i,j, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    tam = strlen(cadena);

    for (i=tam;i>=0;i--)
    {
        for (j=0;j<i;j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    printf("\n");
    system("PAUSE");

}

void salida6(void)
{
    char cadena[30];
    int i,j, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    strrev(cadena);
    tam = strlen(cadena);

    for (i=tam;i>=0;i--)
    {
        for (j=0;j<i;j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    printf("\n");
    system("PAUSE");
}

void salida7(void)
{
    char cadena[30];
    int i,j, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    tam = strlen(cadena);

    for (i=0;i<=tam;i++)
    {
        for (j= i; j<= tam; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    printf("\n");
    system("PAUSE");
}

void salida8(void)
{
    char cadena[30];
    int i,j, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strrev(cadena);
    strupr(cadena);
    tam = strlen(cadena);
    for (i=0;i<=tam;i++)
    {
        for (j= i; j<= tam; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
    printf("\n");
    system("PAUSE");
}

void salida9(void)
{
    char cadena[30];
    int i, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strupr(cadena);
    tam = strlen(cadena);

    for (i=0;i<tam;i++)
    {
        if (cadena[i] != 'A')
        {
            if (cadena[i] != 'E')
            {
                if (cadena[i] != 'I')
                {
                    if (cadena[i] != 'O')
                    {
                        if (cadena[i] != 'U')
                        {
                            printf("%c ", cadena[i]);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    system("PAUSE");
}
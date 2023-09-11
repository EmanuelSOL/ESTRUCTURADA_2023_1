// SOE_ACT7_ENSENADA
// Actividad 7
// Parte 1
// Solis Orozco Emanuel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcion(void);
int main()
{
    funcion();

    return 0;

}

void funcion(void)
{

    /*char cadena[30];
    int tam,i;
    system ("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strrev(cadena);
    printf("%s",cadena);
    printf("\n");
    system("PAUSE");

    char cadena[30];
    int tam,i;
    system ("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    printf("%s",cadena);
    printf("\n");
    system("PAUSE");

    char cadena[30];
    int tam,i;
    system ("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    tam =strlen(cadena);
    for(i=0;i<tam; i++)
    {
        printf("%c\n", cadena[i]);
    }
    printf("\n");
    system("PAUSE"); 

    char cadena[10];
    int i, tam;
    system("CLS");
    printf("Dame una palabra: \n");
    fflush(stdin);
    gets(cadena);
    strrev(cadena);
    tam = strlen(cadena);

    for (i=0;i<tam;i++)
    {
        printf("%c\n", cadena[i]);
    }

    printf("\n");
    system("PAUSE"); 



    char ciudad[10];
    int i, j, tam;
    system("CLS");
    printf("Ingresa una palabra\n");
    fflush(stdin);
    gets(ciudad);
    strupr(ciudad);
    strrev(ciudad);
    tam = strlen(ciudad);

    for (i = tam; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("%c", ciudad[j]);
        }
        printf("\n");
    }
    printf("SALIDA 5\n");
    system("PAUSE"); 
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

    char cadena[20];
        int i;
        system("CLS");

        printf("Ingresar una palabra \n");
        fflush(stdin);
        gets(cadena);
        for (i = 0; cadena[i] != '\0'; i++)
        {
            if (cadena[i] >= 'a')
            {
                if (cadena[i] <= 'z')
                {
                    cadena[i] = cadena[i] - 32;
                }
            }
            printf("%c", cadena[i]);
        }

        system("PAUSE"); 

    char cadena[30];
    int i;
    system("CLS");
    printf("Ingresa un texto \n");
    fflush(stdin);
    gets(cadena);
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                cadena[i] = cadena[i] + 32;
            }
        }
        printf("%c", cadena[i]);
    }
    system("PAUSE"); 
    char cadena[30];
    int i;
    system("CLS");
    printf("Ingresa un texto \n");
    fflush(stdin);
    gets(cadena);
    if (cadena[0] >= 'a')
    {
        if (cadena[0] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
    for (i = 1; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                cadena[i] = cadena[i] + 32;
            }
        }
        
    }
    
    printf("%c", cadena[i]);
    system("PAUSE"); 

    char cadena[30];
    int i,  tam;
    system("CLS");
    printf("Ingresa un texto \n");
    fflush(stdin);
    gets(cadena);
    for (i = 0; cadena[i] != '\0'; i++)
    {
    }
    tam = strlen(cadena);
    printf("La cantidad de caracteres que tienes es de: %d", tam);
    system("PAUSE"); */
    char cadena[30];
    int i, tam;
    system("CLS");

    printf("Ingresa una palabra\n");
    fflush(stdin);
    gets(cadena);

    tam = strlen(cadena);

    for (i = 0; i < strlen(cadena) / 2; i++)
    {
        char temp = cadena[i];
        cadena[i] = cadena[tam - i - 1];
        cadena[tam - i - 1] = temp;
    }

    puts(cadena);
    printf("\nCANTIDAD CARACTERES INVERSA\n");
    system("PAUSE");

}
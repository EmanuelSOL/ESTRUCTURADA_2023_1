// SOE_ACT7_ENSENADA
// Actividad 7
// Parte 2
// Solis Orozco Emanuel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menup();
void menu();
void fmayus(void);
void fminus(void);
void fcaract(void);
void fcaractinv(void);
void fsinespacios(void);


int main()
{
    menu();
    return 0;
}

int menup()
{
    int num;
    system("CLS");
    printf("MENU \n");
    printf("1.- Mayusculas \n");
    printf("2.- Minusculas \n");
    printf("3.- Caracteres de la cadena  \n");
    printf("4.- Caracteres a la inversa \n");
    printf("5.- Sin espacios \n");
    printf("Presione 0 para salir \n");
    printf("Seleccione la opcion: ");
    scanf("%d",&num);
    return num;

}

void menu()
{
    int num;
    while (num != 0);
    {
        switch (num)
        {
        case 1:
            fmayus();
            break;
        case 2:
            fminus();
            break;
        case 3:
            fcaract();
            break;
        case 4:
            fcaractinv();
            break;
        case 5:
            fsinespacios();
            break;
        }

    }
}

void fmayus(void)
{
    char cadena[30];
        int i;
        system("CLS");
        printf("Ingresar un texto \n");
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
}

void fminus(void)
{
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

}

void fcaract(void)
{
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
    system("PAUSE");
}

void fcaractinv(void)
{
    char cadena[30];
    int i, tam;
    system("CLS");
    printf("Ingresa un texto \n");
    fflush(stdin);
    gets(cadena);
    tam = strlen(cadena);
    for (i= 0; i < strlen(cadena)/2; i++)
    {
        char temp = cadena[i];
        cadena[i] =cadena[tam - i -1];
        cadena[tam- i -1] = temp;
    }
    puts(cadena);
    system("PAUSE");
}

void fsinespacios(void)
{
    char cadena[30];
    int i;
    system("CLS");

    printf("Ingresa un texto\n");
    fflush(stdin);
    gets(cadena);
    for (i = 0; cadena[i]!= '\0'; i++)
    {
    if (cadena[i]!= ' ')
        {
         printf("%c",cadena[i]);
        }
        
    }
    system("PAUSE");
}
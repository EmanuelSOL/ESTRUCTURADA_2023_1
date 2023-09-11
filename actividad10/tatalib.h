#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int valida_num(int ri, int rf, const char *msg)
{

    char xnum[30];
    int num;

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(xnum);

        num = atoi(xnum);

        if(num  < ri || num > rf)
        {
            printf("Ingresa un numero valido\n");     
        }

    } 
    while(num < ri || num > rf);
    return num;
}


void valida_cadnum1(int ri, int rf, char cadena[], int max, const char *msg, char errorMsg[])
{

    char xnum[30];
    int num;

    do
    {
        
        printf("%s", msg);
        fflush(stdin);
        gets(xnum);

        num = atoi(xnum);

        if(num  < ri || num > rf)
        {
            printf("%s\n", errorMsg);   
        }
        
    } 
    while((num < ri || num > rf) || strlen(xnum) > max);
    
    strcpy(cadena, xnum);
}

int eliminar_esp(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);

    if(cadena[0] == '\0')
    {
        return 0;
    }

    for(i = 0; i <= tam; i++)
    {
        if(cadena[i] == ' ' && cadena[i + 1] == ' ')
        {
            return -1;
        }
    }
}

int solo_let(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);

    if(eliminar_esp(cadena) == 0)
    {
        return 0;
    }

    for(i =  0; i <= tam; i++)
    {
        if(cadena[i] < 'A' || cadena[i] > 'z')
        {
            return -1;
        }
        if(cadena[i] > 'Z' && cadena[i] < 'a')
        {
            return -1;
        }

        return 0;
    }
}

void valida_num_cad(int ri, int rf, char cadena[], int max, const char *msg, char errorMsg[])
{

    char xnum[30];
    int num;

    do
    {
        
        printf("%s", msg);
        fflush(stdin);
        gets(xnum);

        num = atoi(xnum);

        if(num  < ri || num > rf)
        {
            printf("%s\n", errorMsg);   
        }
        
    } 
    while((num < ri || num > rf) || strlen(xnum) > max);
    
    strcpy(cadena, xnum);
}

char solo_voc(char vocales[])
{
    int i, tam;

    tam = strlen(vocales);

    for(i = 1; i < tam; i++)
    {
        if(vocales[i] == 'A' || vocales[i] == 'E' || vocales[i] == 'I' || vocales[i] == 'O' || vocales[i] == 'U')
        {
            return vocales[i];
        }
    }

    return 'X';
}

char solo_voc_del(char vocales[])
{
    int i, tam;
    tam = strlen(vocales);

    for(i = 4; i < tam; i++)
    {
        if(vocales[i] == 'A' ||vocales[i] == 'E'|| vocales[i] == 'I'|| vocales[i] == 'O'|| vocales[i] == 'U')
        {
            return vocales[i];
        }
    }

    return 'X';

}

char solo_voc_dela(char vocales[])
{

    int i, tam;
    tam = strlen(vocales);

    for(i = 6; i < tam; i++)
    
    {
        if(vocales[i]=='A' || vocales[i] == 'E' ||vocales[i] =='I'|| vocales[i] == 'O'||vocales[i] == 'U')
        {


            return vocales[i];
        }
    }
    return 'X';

}

char solo_consonantes(char cons[])
{
    int i, tam;

    tam = strlen(cons);

    for(i = 1; i <= tam; i++)
    {
        if(cons[i] != 'A' && cons[i] != 'E' && cons[i] != 'I' && cons[i] != 'O' && cons[i] != 'U')
        {
            return cons[i];
        }
    }
    return 'X';
}


char solo_con_dela(char cons[])
{
    int i, tam;

    tam = strlen(cons);

    for(i = 6; i <= tam; i++)
    {
        if(cons[i] != 'A' && cons[i] != 'E' && cons[i] != 'I' && cons[i] != 'O' && cons[i] != 'U')
        {
            return cons[i];
        }
    }

    return 'X';
}

char solo_con_del(char cons[])
{
    int i, tam;
    tam = strlen(cons);

    for(i = 4; i <= tam; i++)
    {
        if(cons[i] != 'A' && cons[i]!= 'E' && cons[i]!= 'I' && cons[i]!= 'O' && cons[i] != 'U')
        {
            return cons[i];
        }
}
    return 'X';

}

int del_dela(char apellido[])

{

    if(apellido[0] == 'D' && apellido[1] == 'E' && apellido[2] == ' ' && apellido[3] == 'L' && apellido[4] == 'A' && apellido[5] == ' ')

    {

        return 2;

    }


    else

    {
        if(apellido[0] == 'D' && apellido[1] == 'E' && apellido[2] == 'L' && apellido[3] == ' ')

        {

            return 1;
        }

    }

    return 0;
}
char remplazar_ene(char cadena[])
{
    int i, tam;

    tam = strlen(cadena);

    for(i = 0; i < tam; i++)
    {
        if (cadena[i] == -91 || cadena[i] == -92)
        {
            return 'X';
        }
    }

}



void valida_cad_obg(char cadena[], const char *msg)
{
    int tam, band;

    band = 1;
    do{

        printf("%s", msg);
        fflush(stdin);
        gets(cadena);

        if (cadena[0] == '\0')
        {
            printf("Ingresa lo que se indica\n");
            continue;
        }

        if (solo_let(cadena) == 0)
        {
            if(eliminar_esp(cadena) == -1)
            {
                printf("No acepta espacios\n");
                continue;
            }
        }
        else
        {
            if(cadena[0] == ' ')
            {
                printf("No acepta espacios\n");
                continue;
            }
            else
            {
                printf("Solo letreas\n");
                continue;
            }
        }

        strupr(cadena);
        band = 0;

    }
    while(band == 1);      
}

void valida_cad(char cadena[], const char *msg)
{
    int tam, band;

    band = 1;
    do{

        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        
        if (solo_let(cadena) == 0)
        {
            if(eliminar_esp(cadena) == -1)
            {
                printf("No acepta espacios\n");
                continue;
            }
        }
        else
        {
            if(cadena[0] == ' ')
            {
                printf("No acepta espacios\n");
                continue;
            }
            else
            {
                printf("Solo letras\n");
                continue;
            }
        }

        strupr(cadena);
        band = 0;

    }
    while(band == 1);      
}

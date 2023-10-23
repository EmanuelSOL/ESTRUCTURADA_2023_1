#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tatalib.h"

const char *entidades[] = {"Aguascalientes", "Baja California", "Baja California Sur",
    "Campeche", "Coahulia", "Colima", "Chiapas", "Chihuahua", "Distrito Federal", "Durango",
    "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Estado de mexico", "Michoaca", "Morelos",
    "Nayarit", "Nuevo Leon", "Oaxaca", "Pueblo", "Queretaro", "Quintana Roo", "San Luis Potosi",
    "Sinaloa", "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas",
    "Nacido en el extranjero"};

const char *abreviadas[] = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG", "GT",
    "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC",
    "TS", "TL", "VZ", "YN", "ZS", "NE"};

const char *meses[] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

const char *palabrotas[] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO",
    "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO",
    "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE",
    "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO",
    "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA",
    "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA",
    "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI",
    "WUEY"};

void genecurp();
void palabras_inconvenientes(char cadena[]);
int mesess(char mes[], char xyear[]);
char sexo(char xcadena[]);
void estados(char cadena[]);
void estados_ini(char cadena[], char curp[]);
char decada(char xanio[]);
void verificar_datos(char p_nombre[], char s_nombre[], char paterno[], char materno[], char dia[], char mes[], char anio[], char estado[], char genero[]);
void validardeldela(char paterno[], char materno[], char curp[]);
void validardeldela2(char paterno[], char materno[], char curp[]);
void jose_m_nombres(char p_nombre[], char s_nombre[], char curp[]);
void jose_m_con(char p_nombre[], char s_nombre[], char curp[]);

void menu();
int msg();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msg()
{

    int num;
    system("CLS");
    printf("MENU \n");
    printf("1.- Generar curp \n");
    printf("0.- Salir \n");
    num = valida_num(0, 1, "");

    return num;

   
}

void menu()
{
    int num;
    do
    {
        num = msg();
        switch(num)
        {
            case 1:
                genecurp();
                break;
        }
    }
    while (num != 0);
}

void genecurp()
{

	char p_nombre[31], s_nombre[50], paterno[31], materno[31], genero[2], anio[5], mes[12], dia[3], estado[3];
    char curp[18];
    int mes_dias, i, band;

    do
    {
        system("cls");
        valida_cad_obg(p_nombre, "Primer nombre: ");
        system("CLS");
        valida_cad(s_nombre, "Otros nombres: ");
        system("CLS");
        valida_cad_obg(paterno, "Apellido paterno: ");
        system("CLS");
        valida_cad(materno, "Apellido materno: ");
        system("CLS");
        valida_num_cad(1900, 2023, anio, 4, "Anio de nacimiento (1900 - 2023): ", "Fecha invalida");
        system("CLS");
        valida_num_cad(1, 12, mes, 2,"Mes (2 DIGITOS, 1 - 12): ", "Mes invalido");
        system("CLS");
        valida_num_cad(1, 31, dia, 2,"Dia (2 DIGITOS, 1 - 31): ", "Dia invalido");
        system("CLS");
        valida_num_cad(1, 2, genero, 1, " 1.- Masculino\n 2.- Femenino\n Seleccione una opcion: ", "Opcion invalida");
        system("CLS");
        estados(estado);
        verificar_datos(p_nombre, s_nombre, paterno, materno, anio, mes, dia, estado, genero);

        band = valida_num(1, 2,"Son correctos los datos?\n 1.- SI \n 2.- NO\n");

    }

    while(band == 2);

    remplazar_ene(p_nombre);
    remplazar_ene(s_nombre);
    remplazar_ene(paterno);
    remplazar_ene(materno);
    
    validardeldela(paterno, materno, curp);
    jose_m_nombres(p_nombre, s_nombre, curp);
    palabras_inconvenientes(curp);
    curp[4] = anio[2];
    curp[5] = anio[3];
    curp[6] = mes[0];
    curp[7] = mes[1];
    curp[8] = dia[0];
    curp[9] = dia[1];
    curp[10] = sexo(genero); 
    estados_ini(estado, curp);
    validardeldela2(paterno, materno, curp);
    jose_m_con(p_nombre, s_nombre, curp);
    curp[16] = decada(anio);
    curp[17] = ((rand() % 9) + 1) + '0';
    curp[18] = '\0';
    system("CLS");

    for(i = 0; i < 18; i++)
    {
        printf("%c", curp[i]);
    }

    printf("\n");
    system("PAUSE");
}

void verificar_datos(char p_nombre[], char s_nombre[], char paterno[], char materno[], char dia[], char mes[], char anio[], char estado[], char genero[])
{
        system("CLS");

        printf("\nPrimer nombre: %s\n", p_nombre);

        if(s_nombre[0] != '\0')
        {
            printf("Segundo nombre: %s\n", s_nombre);
        }
        else
        {
            printf("Segundo nombre: SIN DATOS\n");
        }

        printf("Apellido Paterno: %s\n", paterno);
        
        if(materno[0] != '\0')
        {
            printf("Apellido materno: %s\n", materno);
        }
        else
        {
            printf("Apellido materno: SIN DATO\n");
        }

        printf("Fecha de nacimiento: %s/%s/%s\n", dia, mes, anio);
        printf("Entidad federativa: %s\n\n", entidades[atoi(estado)]);

        printf("1.HOMBRE     2.MUJER\n");
        printf("SEXO: %s\n", genero);
}

void palabras_inconvenientes(char cadena[])
{
    int i, inv;
    inv = sizeof(palabrotas)/sizeof(palabrotas[0]);

    for(i = 0; i < inv; i++)
    {
        if(strcmp(cadena, palabrotas[i]) == 0)
        {
            cadena[1] = 'X';
        }
    }
}

int mesess(char xmes[], char xyear[])
{
    int meses[12];
    int year, mes;

    year = atoi(xyear);
    mes = atoi(xmes);

    meses[0] = 31;

    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        meses[1] = 29;
    }


    else
    {
        meses[1] = 28;
    }
    
    meses[2] = 31;
    meses[3] = 30;
    meses[4] = 31;
    meses[5] = 30;
    meses[6] = 31;
    meses[7] =  31;
    meses[8] = 30;
    meses[9] = 31;
    meses[10] =  30;
    meses[11] = 31;

    
    return meses[mes - 1];
}

char sexo(char xcadena[])
{
    int sexo, cadena;
    
    cadena = atoi(xcadena);

    if(cadena == 1)
    {
        return 'H';
    }


    else
    {
        
        return'M';
    }

}

void estados(char xcadena[])
{
    int i;
    
    for(i = 0; i < 33; i++)
    {
        printf("%d- " "%s\n" , i, entidades[i]);
    }

    valida_cadnum1(0, 32, xcadena, 2, "Ingresa tu estado: ", "OPCION INVALIDA ");
}

void estados_ini(char cadena[], char curp[])
{
    int cadenae;

    cadenae = atoi(cadena);

    curp[11] = abreviadas[cadenae][0];
    curp[12] = abreviadas[cadenae][1];
}

void validardeldela(char paterno[], char materno[], char curp[])
{
    if(del_dela(paterno) == 0)
    {
        curp[0] = paterno[0];
        curp[1] = solo_voc(paterno);
    }
    else
    {
        if(del_dela(paterno) == 1)
        {
            curp[0] = paterno[4];
            curp[1] = solo_voc_del(paterno);
        }
        else
        {
            if(del_dela(paterno) == 2)
            {
                curp[0] = paterno[6];
                curp[1] = solo_voc_dela(paterno);
            }
        }
    }

    if(materno[0] != '\0')
    {
        if(del_dela(materno) == 0)
        {
        curp[2] = materno[0];
        }

        else
        {
            if(del_dela(materno) == 1)
            {
                curp[2] = materno[4];
            }

            else
            {
                if(del_dela(materno) == 2)
                {
                    curp[2] = materno[6];
                }
            }
        }
    }

    else
    {
        curp[2] = 'X';
    }

}

void validardeldela2(char paterno[], char materno[], char curp[])
{
    if(del_dela(paterno) == 0)
    {
        curp[13] = solo_consonantes(paterno);
    }
    else
    {
        if(del_dela(paterno) == 1)
        {
            curp[13] = solo_con_del(paterno);
        }
        else
        {
            if(del_dela(paterno) == 2)
            {
                curp[13] = solo_con_dela(paterno);
            }
        }
    }
    

    if(materno [0] != '\0')
    {
        if(del_dela(materno) == 0)
        {
            curp[14] = solo_consonantes(materno);
        }

        else
        {
            if(del_dela(materno) == 1)
            {
                curp[14] = solo_con_del(materno);
            }
            else

            {
                if(del_dela(materno) == 2)
                {
                    curp[14] = solo_con_dela(materno);
                }
            }
        }
    }


    else
    {
        curp[14] = 'X';
    }
}

int josem(char p_nombre[], char s_nombre[])
{
    if (strcmp(p_nombre, "JOSE") == 0 && s_nombre[0] != '\0')

    {
        return 0;
    }
    else
    {
        if (strcmp(p_nombre, "MARIA") == 0 && s_nombre[0] != '\0')
    {
        return 0;
    }
        
    }
    return 1;

}

void jose_m_nombres(char p_nombre[], char s_nombre[], char curp[])
{
    if(josem(p_nombre, s_nombre) == 1)
    {
        curp[3] = p_nombre[0];
    }

    else
    {
        if(josem(p_nombre, s_nombre) == 0)
        {
            curp[3] = s_nombre[0];
        }
    }
}

void jose_m_con(char p_nombre[], char s_nombre[], char curp[])
{
    if(josem(p_nombre, s_nombre) == 1)
    {
        curp[15] = solo_consonantes(p_nombre);
    }

    else
    {
        if(josem(p_nombre, s_nombre) == 0)
        {
            curp[15] = solo_consonantes(s_nombre);
        }
    }

}

char decada(char xanio[])
{   
    int anio;
    anio = atoi(xanio);

    if (anio < 2000)
    {
        return '0';
    } 

    else
    {
        if (anio < 2010)
        {
            return 'A';
        }
        else

        {
            if (anio < 2020)
            {
                return 'B';
            }
            else

            {
                
                if (anio < 2030)
                {
                    return 'C';
                }
            }
        }
    }

}



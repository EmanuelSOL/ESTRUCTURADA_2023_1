
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _treg
{
    long matri;
    char nom[31];
    char apellidoP[31];
    char apellidoM[31];
    int status;
    int genero;
    int edad;

}TsReg;

int validaL(long ri, long rf, char msg[], char msgError[])
{
    long num;
    char xnum[30];

    do
    {
        puts(msg);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);

        if (num < ri || num > rf)
        {
            printf("%s", msgError);
            printf("\n");
        }
    } while (num < ri || num > rf);

    return num;
}

int valida_int(int ri, int rf, char msg[], char msgError[])
{
    int num;
    char xnum[30];

    do
    {
        puts(msg);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);

        if (num < ri || num > rf)
        {
            printf("%s", msgError);
            printf("\n");
        }
    } while (num < ri || num > rf);

    return num;
}

int existeTsReg(long mat, TsReg *reg, int tam)
{
    int i;
    
    for(i = 0; i <= tam; i++)
    {
        if (mat == reg[i].matri)
        {
            return 1;
        }
    }
    return 0;
}

int busq_sec(TsReg *vect, int tam, long matricula)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if(vect[i].matri == matricula)
        {
            return i;
        }
    }

    return -1;
}

int busq_bin(TsReg *vect, int tam, long matri)
{
    int mid, ini, fin;
    ini = 0;
    fin = tam - 1;

    while(ini <= fin)
    {
        mid = (ini + fin) / 2;

        if (vect[mid].matri == matri)
        {
            return mid;
        }
        else
        {
            if(matri < vect[mid].matri)
            {
                fin = mid - 1;
            }
            else
            {
                ini = mid + 1;
            }
        }
    }   
    return -1;
}

TsReg agregar_reg(TsReg registros[], int tam)
{
    char nombreH[30][20] = {"EMANUEL", "DAVID", "CARLOS", "ALEX", "MARTIN", "PABLO", "ALEXIS", "RAMON", "ANGEL", "ARMANDO", "IVAN", "JONATHAN", "JAFET", "JOSHED", "RUBEN", "JOSUE", "ANDRES", "ABRAHAM", "FRANCISCO", "HUGO", "JUAN", "ALFREDO", "MATEO", "SANTIAGO", "ALEJANDRO", "DANIEL", "MANUEL", "EMMANUEL", "MIGUEL", "MARCOS"};
    char nombreM[30][20] = {"MARIA", "LAURA", "ANA", "SOFIA", "VALERIA", "ISABELLA", "EMMA", "LUCIA", "MARTA", "ANDREA", "NATALIA", "ELENA", "CARMEN", "PAULA", "JULIA", "SARA", "BEATRIZ", "CARLA", "ALEJANDRA", "ADRIANA", "PATRICIA", "ROSA", "MARINA", "VERONICA", "GABRIELA", "RAQUEL", "LIDIA", "DIANA", "LORENA", "PALOMA"};
    char apellidos[30][30] = {"ALVAREZ", "VELAZQUEZ", "RIOS", "NAVARRO", "MENDOZA", "GUERRERO", "BENITEZ", "MEDINA", "RIVAS", "DELGADO", "CERVANTES", "QUINTERO", "PAREDES", "GUZMAN", "ESCOBAR", "ZAMORA", "MONTOYA", "GALLEGOS", "CISNEROS", "ACOSTA", "IBARRA", "SOLIS", "URIBE", "FIGUEROA", "LEON", "PERALTA", "VALENCIA", "BARAJAS", "CARDONA", "BUSTAMANTE"};

    TsReg reg;
    int sexo;
    int edad;
    int status;
    long matri;

    matri = (rand() % 99999) + 300000;
    while(existeTsReg(matri, registros, tam) == 1)

    {
        matri = (rand() % 99999) + 300000;
    }

    edad = (rand() % 80) + 17;
    status = rand() % 2;
    sexo = (rand() % 2) + 1;

    reg.status = status;
    reg.matri = matri;
    reg.edad = edad;
    reg.genero = sexo;

    int apP = rand() % 20;
    strcpy(reg.apellidoP, apellidos[apP]);

    int apM = rand() % 20;
    strcpy(reg.apellidoM, apellidos[apM]);

    if (sexo == 1)
    {
        int nomH = rand() % 30;
        strcpy(reg.nom, nombreH[nomH]);
    }
    else
    {
        if(sexo == 2)
        {
            int nomM = rand() % 30;
            strcpy(reg.nom, nombreM[nomM]);
        }
    }

    return reg; 
}

int cargar_reg(TsReg registros[], int tam)
{   
    system("clear");

    int i;

    for(i = 0; i < 100; i++)
    {
        system("clear");
        registros[tam] = agregar_reg(registros, tam);
        system("clear");
        tam++;
    }

    printf("SE GENERARON 100 REGISTROS\n");
    getchar();

    return tam;
}

void eliminar_reg(TsReg registros[], int tam, int band)
{
    system("clear");

    long id;
    int pos, op;
    char *sexo;

    id = validaL(300000, 399999, "INGRESA LA MATRICULA QUE QUIERES ELIMINAR: ", "MATRICULA INVALIDA");

    if (band == 0)
    {
        pos = busq_sec(registros, tam, id);
    }
    else
    {
        pos = busq_bin(registros, tam, id);
    }

    if (pos != -1)
    {
        system("clear");

        printf("%-15s %-23s %-15s %-20s %-20s %-10s %-10s", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        
        if(registros[pos].genero == 1)
        {
            sexo = "HOMBRE";
        }
        else
        {
            sexo = "MUJER";
        }

        printf("%-15d %-20ld %-15s %-20s %-20s %-10d %-10s\n", registros[pos].status, registros[pos].matri, registros[pos].nom, registros[pos].apellidoP, registros[pos].apellidoM, registros[pos].edad, sexo);
        op = valida_int(1, 2, "\n1) ELIMINAR\n2) NO ELIMINAR", "OPCION FUERA DE RANGO");

        if (op == 1)
        {
            registros[pos].status = 0;
        }    
    }
    else
    {
        printf("LA MATRICULA NO EXISTE\n");
    }

    getchar();
}

void buscar_reg(TsReg registros[], int tam, int band)
{
    system("clear");

    long mat;
    int pos, id, i;
    char *sexo;

    id = validaL(300000, 399999, "INGRESA LA MATRICULA QUE QUIERES BUSCAR: ", "MATRICULA INVALIDA");

    if (band == 0)
    {
        pos = busq_sec(registros, tam, id);
    }
    else
    {
        pos = busq_bin(registros, tam, id);
    }

    if (pos != -1)
    {
        system("clear");

        printf("%-15s %-23s %-15s %-20s %-20s %-10s %-10s", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        
        if(registros[pos].genero == 1)
        {
            sexo = "HOMBRE";
        }
        else
        {
            sexo = "MUJER";
        }

        printf("%-15d %-20ld %-15s %-20s %-20s %-10d %-10s\n", registros[pos].status, registros[pos].matri, registros[pos].nom, registros[pos].apellidoP, registros[pos].apellidoM, registros[pos].edad, sexo);
        
    }
    else
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }

    getchar();
}

void burbuja(TsReg vect[], int tam)
{
    system("clear");

    int i, j;
    TsReg burbuja;

    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if (vect[j].matri < vect[i].matri)
            {
                burbuja = vect[j];
                vect[j] = vect[i];
                vect[i] = burbuja;            
            }
        }
    }

    getchar();
}

void quickSort(TsReg registros[], int limIzq, int limDer)
{
    int izq, der, tem;
    TsReg central;

    izq = limIzq;
    der = limDer;
    central.matri = registros[(izq + der) / 2].matri;

    do{

        while(registros[izq].matri < central.matri && izq < limDer)
        {
            izq++;
        }
        
        while(central.matri < registros[der].matri && der > limIzq)
        {
            der--;
        }

        if ( izq <= der)
        {
            tem = registros[izq].matri;
            registros[izq].matri = registros[der].matri;
            registros[der].matri = tem;
            izq++;
            der--;
        }
    }while(izq <= der);

    if (limIzq < der)
    {
        quickSort(registros, limIzq, der);
    }

    if (limDer > izq)
    {    
        quickSort(registros, izq, limDer);
    }
}

int ordenar_reg(TsReg registros[], int tam, int band)
{
    system("clear");

    if(tam > 0)
    {
        if(band == 0)
        {
            burbuja(registros, tam);
            band = 1;
        }

        else
        {
            quickSort(registros, 0, tam);
        }
        
        printf("HAS ORDENADO LOS DATOS\n");
        getchar();
        return band;
    }
    else
    {
        printf("PRIMERO DEBE HABER DATOS\n");
        getchar();
        return 0;
    }
}

void imprimir_reg(TsReg registros[], int tam)
{
    system("clear");
    TsReg reg;
    int i, j;
    char *sexo;
    
    if (tam > 0)
    {   
        i = 0;
        while( i < tam)
        {
            printf("\n%-16s %-10s %-14s %-15s %-20s %-20s %-10s %-10s\n", "NUM. REGISTRO", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
            
            for (j = 0; j < 40; j++)
            {
                if(registros[i].genero == 1)
                {
                    sexo = "HOMBRE";
                }
                else
                {
                    sexo = "MUJER";
                }

                if (registros[i].status != 0 && registros[i].matri >= 300000)
                {
                    printf("%-16d %-10d %-14ld %-15s %-20s %-20s %-10d %-10s\n", j + 1,registros[i].status, registros[i].matri, registros[i].nom, registros[i].apellidoP, registros[i].apellidoM, registros[i].edad, sexo);
                }
                i++;
            }
        }
    }
    else
    {
        printf("INGRESE DATOS PARA PODER IMPRIMIR\n");
    }

    printf("\n");
    getchar();
}

void gen_arch(TsReg registros[], int tam)
{
    system("clear");

    int i;
    char *sexo;
    TsReg reg;
    FILE *archi;

    archi = fopen("Registros.txt", "w");

    if (archi == NULL)
    {
        printf("EL ARCHIVO NO EXISTE");
    }

    for( i = 0; i < tam; i++)
    {
        reg = registros[i];
        if(registros[i].genero == 1)
        {
            sexo = "HOMBRE";
        }
        else
        {
            sexo = "MUJER";
        }

        if (registros[i].status != 0 && registros[i].matri >= 300000)
        {
            fprintf(archi, "%-16d %-10d %-14ld %-15s %-20s %-20s %-10d %-10s\n", i + 1, reg.status, reg.matri, reg.nom, reg.apellidoP, reg.apellidoM, reg.edad, sexo);
        }
    }
    fclose(archi);
    printf("HAS GENERADO UN ARCHIVO\n");

    getchar();

}

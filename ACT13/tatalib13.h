
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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

void minus(char *cadena) 
{
    while (*cadena) 
    {
        *cadena = tolower(*cadena);
        cadena++;
    }
}

int valida_long(long ri, long rf, char msg[], char msgError[])
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

int eliminarEsp(char cadena[])
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

int soloLetras(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);

    if(eliminarEsp(cadena) == 0)
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

void validaCadOb(char cadena[], const char *msg)
{
    int tam, band;

    band = 1;
    do{

        printf("%s", msg);
        fflush(stdin);
        gets(cadena);

        if (cadena[0] == '\0')
        {
            printf("INGRESA LO INDICADO\n");
            continue;
        }

        if (soloLetras(cadena) == 0)
        {
            if(eliminarEsp(cadena) == -1)
            {
                printf("NO SE PERMITEN ESPACIOS\n");
                continue;
            }
        }
        else
        {
            if(cadena[0] == ' ')
            {
                printf("NO SE PERMITEN ESPACIOS\n");
                continue;
            }
            else
            {
                printf("INGRESA SOLO LETRAS\n");
                continue;
            }
        }

        //strupr(cadena);//No la pude usar

        for (int i = 0; cadena[i] != '\0'; i++) 
        {
            cadena[i] = toupper(cadena[i]);
        }

        band = 0;

    }while(band == 1);      
}

int busqSec(TsReg *vect, int tam, long matricula)
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

TsReg cargar_reg(TsReg registros[], int tam)
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

int agregar_reg(TsReg registros[], int tam)
{   
    system("clear");

    int i;

    for(i = 0; i < 100; i++)
    {
        system("clear");
        registros[tam] = cargar_reg(registros, tam);
        system("clear");
        tam++;
    }

    printf("HAS GENERADO 100 REGISTROS\n");
    getchar();

    return tam;
}

void editar_reg(TsReg registros[], int tam, int band)
{
    system("clear");

    TsReg reg;
    long id;
    int pos, op, i;
    char *sexo;
    char apPat[21], apMat[21], nombre[41];

    id = valida_long(300000, 399999, "INGRESA LA MATRICULA QUE QUIERES EDITAR: ", "MATRICULA INVALIDA");

    if (band == 0)
    {
        pos = busqSec(registros, tam, id);
    }
    else
    {
        pos = busq_bin(registros, tam, id);
    }

    if (pos != -1)
    {
        system("clear");
        
        printf("%-15s %-18s %-15s %-20s %-20s %-10s %-10s", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        
        if(registros[pos].genero == 1)
        {
            sexo = "HOMBRE";
        }
        else
        {
            sexo = "MUJER";
        }

        printf("%-12d %-18ld %-15s %-20s %-20s %-10d %-10s\n", registros[pos].status, registros[pos].matri, registros[pos].nom, registros[pos].apellidoP, registros[pos].apellidoM, registros[pos].edad, sexo);

        do{
            registros[pos].status = valida_int(0, 1, "0)INACTIVO  1)ACTIVO", "FUERA DE RANGO");
            id = valida_long(300000, 399999, "INGRESE LA MATRICULA: ", "MATRICULA INVALIDA");

            if(existeTsReg(id, registros, tam) == 1)
            {
                printf("ESTA MATRICULA YA EXISTE \n INGRESE UNA MATRICULA VALIDA\n");
            }
    
        }while(existeTsReg(id, registros, tam) == 1);
    
        registros[pos].matri = id;

        validaCadOb(apPat, "INGRESE EL APELLIDO PATERNO: \n");
        strcpy(registros[pos].apellidoP, apPat);

        validaCadOb(apMat, "INGRESE EL APELLIDO MATERNO: \n");
        strcpy(registros[pos].apellidoM, apMat);

        validaCadOb(nombre, "INGRESE EL NOMBRE: \n");
        strcpy(registros[pos].nom, nombre);

        registros[pos].edad = valida_int(17, 80, "INGRESA LA EDAD: ", "EDAD FUERA DE RANGO");
        registros[pos].genero = valida_int(1, 2, "INGRESE EL GENERO\n1)HOMBRE  2)MUJER", "OPCION FUERA DE RANGO");
    }
    else
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
        getchar();
        return;
    }

    getchar();
}

void eliminar_reg(TsReg registros[], int tam, int band)
{
    system("clear");

    long id;
    int pos, op;
    char *sexo;

    id = valida_long(300000, 399999, "INGRESA LA MATRICULA QUE QUIERES ELIMINAR: ", "MATRICULA INVALIDA");

    if (band == 0)
    {
        pos = busqSec(registros, tam, id);
    }
    else
    {
        pos = busq_bin(registros, tam, id);
    }

    if (pos != -1)
    {
        system("clear");
                
        printf("%-15s %-18s %-15s %-20s %-20s %-10s %-10s", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");

        if(registros[pos].genero == 1)
        {
            sexo = "HOMBRE";
        }
        else
        {
            sexo = "MUJER";
        }
        printf("%-12d %-18ld %-15s %-20s %-20s %-10d %-10s\n", registros[pos].status, registros[pos].matri, registros[pos].nom, registros[pos].apellidoP, registros[pos].apellidoM, registros[pos].edad, sexo);
        op = valida_int(1, 2, "\n1)ELIMINAR  2)NO ELIMINAR", "OPCION FUERA DE RANGO");

        if (op == 1)
        {
            registros[pos].status = 0;
        }    
    }
    else
    {
        printf("LA MATRICULA NO EXISTE\n");
        getchar();
        return;
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

void buscar_reg(TsReg registros[], int tam, int band)
{
    system("clear");

    long mat;
    int pos, id, i;
    char *sexo;

    id = valida_long(300000, 399999, "INGRESA LA MATRICULA QUE QUIERES BUSCAR: ", "MATRICULA INVALIDA");

    if (band == 0)
    {
        pos = busqSec(registros, tam, id);
    }
    else
    {
        pos = busq_bin(registros, tam, id);
    }

    if (pos != -1)
    {
        system("clear");
        
        printf("%-15s %-18s %-15s %-20s %-20s %-10s %-10s", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        
        if(registros[pos].genero == 1)
        {
            sexo = "HOMBRE";
        }
        else
        {
            sexo = "MUJER";
        }

        printf("%-12d %-18ld %-15s %-20s %-20s %-10d %-10s\n", registros[pos].status, registros[pos].matri, registros[pos].nom, registros[pos].apellidoP, registros[pos].apellidoM, registros[pos].edad, sexo);
    }
    else
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }

    getchar();
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
            printf("\n%-16s %-14s %-14s %-15s %-20s %-20s %-10s %-10s\n", "NUM. REGISTRO", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
            
            for (j = 0; j < tam; j++)
            {
                if(registros[i].genero == 1)
                {
                    sexo = "HOMBRE";
                }
                else
                {
                    sexo = "MUJER";
                }

                if (registros[i].status != 0)
                {   
                    printf("%-16d %-14d %-14ld %-15s %-20s %-20s %-10d %-10s\n", j + 1, registros[i].status, registros[i].matri, registros[i].nom, registros[i].apellidoP, registros[i].apellidoM, registros[i].edad, sexo);
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

void genarch_txt(TsReg registros[], int tam)
{
    system("clear");

    int i;
    char *sexo;
    char nombre_txt[30];
    TsReg reg;
    FILE *archi;

    validaCadOb(nombre_txt, "INGRESA EL NOMBRE DEL ARCHIVO DE TEXTO: \n");
    minus(nombre_txt);
    strcat(nombre_txt,".txt");

    archi = fopen(nombre_txt, "w");
    
    fprintf(archi, "%s", "--------------------------------------------------------------------------------------------------------------------------------------");
    fprintf(archi ,"\n%-16s %-15s %-14s %-15s %-20s %-20s %-10s %-10s\n", "NUM. REGISTRO |", "ESTATUS |", "MATRICULA |", "NOMBRE | ", "APELLIDO PATERNO | ", "APELLIDO MATERNO | ", "EDAD | ", "GENERO");
    fprintf(archi, "%s", "--------------------------------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < tam; i++)
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

        fprintf(archi, "%-16d %-15d %-14ld %-15s %-20s %-20s %-10d %-10s\n", i + 1, reg.status, reg.matri, reg.nom, reg.apellidoP, reg.apellidoM, reg.edad, sexo);
    }
    
    fclose(archi);
    printf("HAS GENERADO UN ARCHIVO\n");
    getchar();
}

void imprimir_txt(TsReg registros[], int tam)
{
    system("clear");
    int op;
    TsReg reg;
    FILE *archi;
    char c;
    char nom_arch[40];

    validaCadOb(nom_arch, "INGRESA EL NOMBRE DEL ARCHIVO DE TEXTO: \n");
    minus(nom_arch);
    strcat(nom_arch, ".txt");

    archi = fopen(nom_arch, "r");
        
    if (!archi) 
    {
        printf ("NO SE PUEDE IMPRIMIR EL ARCHIVO: %s YA QUE NO EXISTE\n", nom_arch);
        fclose (archi);
        getchar();
        return;
    }

    while (!feof (archi)) 
    {
        c = getc (archi);
        printf ("%c", c);
    }

    fclose(archi);
    getchar();
}

void genarch_bin(TsReg registros[], int tam)
{
    system("clear");
    int i;
    char nombre_bin[30];
    TsReg reg;
    FILE *archi;

    validaCadOb(nombre_bin, "INGRESA EL NOMBRE DEL ARCHIVO BINARIO:\n");
    minus(nombre_bin);
    strcat(nombre_bin,".dat");

    archi = fopen(nombre_bin, "wb");
    
    for (i = 0;  i < tam; i++)
    {
        reg = registros[i];
        fwrite(&reg, sizeof(TsReg), 1, archi);
    }
    fclose(archi);
    printf("HAS GENERADO UN ARCHIVO BINARIO CORRECTAMENTE\n");
    getchar();
}   

void cargar_arch_bin(TsReg registros[], int *tam, int max, int *band)
{
    int i , band2;
    FILE *archi;
    TsReg reg;
    char basura[30], nombre_bin[25], estatus;

    system("clear");

    i = *(tam);
    band2 = *(band);

    validaCadOb(nombre_bin, "INGRESA EL NOMBRE DEL ARCHIVO BINARIO:\n");
    minus(nombre_bin);
    strcat(nombre_bin, ".dat");

    if (band2 == 0)
    {
        archi = fopen(nombre_bin, "rb");

        if (archi)
        {
            while(fread(&reg, sizeof(TsReg), 1, archi))
            {

                registros[i] = reg;
                i++;

                if(i == max)
                {
                    printf("NO SE PUDO AGREGAR MAS DATOS");
                    getchar();
                    return;
                }
            }
            fclose(archi);
            band2 = 1;

            printf("HAS CARGADO EL ARCHIVO\n");
            getchar();
        }
        else
        {
            printf("NO EXISTE ESTE ARCHIVO\n");
            getchar();
        }
    }
    else
    {
        if (band2 == 1)
        {
            printf("YA HAS CARGADO LOS DATOS\n");
            getchar();
        }
        else
        {
            printf("NO SE PUDIERON CARGAR MAS DATOS\n");
            getchar();
        }
    }

    *(tam) = i;
    *(band) = band2;
}

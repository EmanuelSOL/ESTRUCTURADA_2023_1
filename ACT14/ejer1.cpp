#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tatalib14.h"
#define N 2700

bool ordenado = false;
typedef struct talum{
        long matricula;
        char nombre[20];
        char ApPat[20];
        char ApMat[20];
        int edad;
        char sexo[20];
        int status;
    }talum;

typedef struct tindex{
        long matricula;
        int indice;   
    }tindex;

int msges();
void menu();
talum agregar(talum vect[],int n);
void imprimirbin(talum vect[],int n);
void editar_registro(talum vect[],int n);
void buscar(talum vect[], int n);
void imprimir_indices(tindex vect[], int n);
void cargar_indices(tindex vect[],int n);
void eliminar(tindex vect[], int n);
int leebinario(talum vect[],int n);
void generartxt(talum vect[],tindex vect_index[],int n,char nombrearchivo[]);
void generarbin(void);
void buscar_principal(talum vect[],int n);
void imprimirtxt(char nombrearchivo[]);
void edicion(talum vect[],int op,int pos,int n);
int validar_matri(int matri, talum vector[], int n);
void ordenar(tindex vect[], int n);
void burbuja(tindex vect[],int n);
void buscar(tindex vect[], int n);
void quicksort(tindex vect[], int primero, int ultimo);
void imprimir_ord(tindex vect[], int n);
void empaquetar(int n);

int main()
{
    srand(time(NULL));
    menu();
	return 0;
}

int msges()
{   
    int op,menu;
    system ("clear");
    printf ("MENU\n");
    printf("1.- AGREGAR AUTOMATICO \n");
    printf("2.- ELIMINAR \n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR \n");
    printf("5.- IMPRIMIR REGISTROS ARCHIVO ORIGINAL \n");
    printf("6.- IMPRIMIR REGISTROS ARCHIVO ORDENADO \n");
    printf("7.- GENERAR ARCHIVO TEXTO \n");
    printf("8.- EMPAQUETAR \n");
    printf("9.-IMPRIMIR VECTOR INDICES \n");
    printf("0.- SALIR  \n");
    op=validanum_int(0,9,"ELIGE UNA OPCION:","ERROR");
    return op;
}

void menu()
{
    int i,op,total,tam=0,j,k=0,l=0;
    char nom_arch[20] = "Alumnos";
    char nom_arch_bin[20] = "archi";
    char nombrearchivo[20];
    generarbin();
    bool cargado_bin = false;
    talum vect[N];
    tindex vect_index[N];
    cargar_indices(vect_index,0);
    k = leebinario(vect,k);
    do{
        op=msges();
        switch (op)
        {
            case 1:
                if(k < N-1)
                {
                    vect[i]=agregar(vect,k);
                    k++;
                    ordenado = false;
                    cargar_indices(vect_index,0);
                }
                break;
            case 2:
                eliminar(vect_index,k);
                break;
            case 3:
                buscar(vect_index,k);
                break;
            case 4:
                if(ordenado==false)
                {
                    ordenar(vect_index,k);
                    ordenado = true;
                }
                else
                {
                    printf("YA ESTA ORDENADO EL VECTOR \n");
                    getchar();
                }
                break;
            case 5:
                imprimirbin(vect,k);
                break;
            case 6:
                imprimir_ord(vect_index,k);
                break;
            case 7:
                printf("DALE UN NOMBRE AL ARCHIVO DE TEXTO: ");
                fflush(stdin);
                gets(nombrearchivo);
				generartxt(vect,vect_index,k,nombrearchivo);
				break;
            case 8:
                empaquetar(k);
                break;
            case 9:
                imprimir_indices(vect_index,k);
                break;
		}
    }while (op != 0);
    getchar();
}

talum agregar(talum vect[],int n)
{
    talum reg;
	char nombres[20][20]={"EMANUEL", "DAVID", "CARLOS", "ALEX", "MARTIN", "PABLO", "ALEXIS", "RAMON", "ANGEL", "ARMANDO", "IVAN"};
	char mujeres[20][20]={"MARIA", "LAURA", "ANA", "SOFIA", "VALERIA", "ISABELLA", "EMMA", "LUCIA", "MARTA", "ANDREA", "NATALIA"};
	char ApPat[20][20]={"ALVAREZ", "VELAZQUEZ", "RIOS", "NAVARRO", "MENDOZA", "GUERRERO", "BENITEZ", "MEDINA", "RIVAS", "DELGADO", "CERVANTES", "QUINTERO"};
	char ApMat[20][20]={"PAREDES", "GUZMAN", "ESCOBAR", "ZAMORA", "MONTOYA", "GALLEGOS", "CISNEROS", "ACOSTA", "IBARRA", "SOLIS", "URIBE", "FIGUEROA"};
    int sexo,status=1,i;
	long ri3=300000, rf3=399999, rango3,matri;
	strcpy(reg.ApPat,ApPat[rand()%12]);
	strcpy(reg.ApMat,ApMat[rand()%12]);
	sexo=(rand()%2)+1;
	if (sexo==1)
	{
	   	strcpy(reg.sexo,"HOMBRE");
	   	strcpy(reg.nombre,nombres[rand()%11]);
	}
	else
	{
	   	strcpy(reg.sexo,"MUJER");
		strcpy(reg.nombre,mujeres[rand()%11]);
	}
	reg.edad=(rand()%10)+12;
    rango3 = ( rf3 - ri3 ) + 1;
    do{
        matri = (rand()%rango3) + ri3;
    }while(validar_matri(matri,vect,n) != -1);
    reg.matricula = matri; 
    reg.status=status;
    FILE *arch;
    arch = fopen("registros1.dat","a+b");
    if(arch)
    {
        fwrite(&reg,sizeof(talum),1,arch);
        fclose(arch);
    }
	return reg;
    
}

void imprimir_indices(tindex vect[], int n)
{
	system("clear");

	int i;
	printf("   INDICE      MATRICULA\n");
	for(i=0; i<n; i++)
	{
	    printf("    %4d    %6ld \n",vect[i].indice,vect[i].matricula);
    }	
	getchar();
}


int validar_matri(int matri, talum vector[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (vector[i].matricula == matri) 
        {
            return i;
        }
    }
    return -1;
}

void imprimirbin(talum vect[],int n)
{
    system("clear");
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros1.dat","r+b");
    if(arch)
    {
        i = n;
        while(fread(&reg,sizeof(talum),1,arch))
        {
            printf("    %6d    %10s    %12s    %12s     %6d    %10s  %d \n",reg.matricula,reg.nombre,reg.ApPat,reg.ApMat,reg.edad,reg.sexo,reg.status);
        }
        fclose(arch);
    }
    getchar();
}

void cargar_indices(tindex vect[],int n)
{
    int i, index;
    long matricula;
    talum temp;
    tindex reg;
    FILE *arch;
    arch = fopen("registros1.dat","r+b");
    if(arch)
    {
        i = n;
        while(fread(&temp,sizeof(talum),1,arch))
        {
            reg.matricula = temp.matricula;
            reg.indice = i;
            vect[i] = reg;
            i++;
            
        }
        fclose(arch);
    }
}

void eliminar(tindex vect[], int n)
{
	system("clear");
	int mati,i,j,com=0,op;
    int indicebuscado;
    long desplazamiento;
	printf("ELIMINAR MATRICULA\n ");
	mati=validanum_long(300000,399999,"INGRESA LA MATRICULA QUE DESEAS ELIMINAR: ","LA MATRICULA DEBE ESTAR ENTRE 300000 Y 399999");
	for(i=0; i<=n; i++)
	{
		
		if (vect[i].matricula==mati)
		{
			printf("SE ENCONTRO LA MATRICULA EN EL INDICE %d \n",i);
			printf("   INDICE      MATRICULA\n");
			printf("    %d    %ld \n",vect[i].indice,vect[i].matricula);	
			com=1;
            FILE *arch;
            arch = fopen("registros1.dat","r+b");
            if(arch)
            {
                indicebuscado = vect[i].indice;
                desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
                fseek(arch, desplazamiento, SEEK_SET);
                talum reg;
                fread(&reg, sizeof(talum), 1, arch);
                printf("\n");
                printf("    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
                printf("   %6ld        %8s    %14s       %14s        %5d       %7s      \n",reg.matricula,reg.nombre,reg.ApPat,reg.ApMat,reg.edad,reg.sexo);	
                com=1;
                op = validanum_int(1,2,"DESEAS ELIMINARLO? [1.-SI 2.-NO]:","OPCION ENTRE 1 Y 2");
                if(op == 1)
                {
                    reg.status = 0;
                    fseek(arch, desplazamiento, SEEK_SET);
                    fwrite(&reg, sizeof(talum), 1, arch);
                    printf("\n SE ELIMINO CORRECTAMENTE \n");
                }
                fseek(arch, desplazamiento, SEEK_END);
                fclose(arch);
                
            }
                   
        }
        
    }
    if (com==0)
    {
        printf("USUARIO NO ENCONTRADO..\n");
    }
	getchar();
}

void buscar(tindex vect[], int n)
{
	system("clear");
	int mati,i,j,com=0;
    int indicebuscado;
    long desplazamiento;
	printf("BUSCAR MATRCICULA\n ");
	mati=validanum_long(300000,399999,"INGRESA LA MATRICULA QUE DESEAS BUSCAR: ","LA MATRICULA DEBE ESTAR ENTRE 300000 Y 399999");
	for(i=0; i<=n; i++)
	{
		
		if (vect[i].matricula==mati)
		{
			printf("SE ENCONTRO LA MATRICULA EN EL INDICE %d \n",i);
			printf("   INDICE      MATRICULA\n");
			printf("    %d    %ld \n",vect[i].indice,vect[i].matricula);	
			com=1;
            FILE *arch;
            arch = fopen("registros1.dat","r+b");
            if(arch)
            {
                indicebuscado = vect[i].indice;
                desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
                fseek(arch, desplazamiento, SEEK_SET);
                talum reg;
                fread(&reg, sizeof(talum), 1, arch);
                printf("\n");
                printf("    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO  STATUS\n");
                printf("   %6ld        %8s    %14s       %14s        %5d       %7s     [%d] \n",reg.matricula,reg.nombre,reg.ApPat,reg.ApMat,reg.edad,reg.sexo,reg.status);	
                com=1;
                fseek(arch, desplazamiento, SEEK_END);
                fclose(arch);
                
            }
                   
        }
        
    }
    if (com==0)
    {
        printf("USUARIO NO ENCONTRADO..\n");
    }
	getchar();
}

int leebinario(talum vect[],int n)
{
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros1.dat","r+b");
    if(arch)
    {
        i = n;
        while(fread(&reg,sizeof(talum),1,arch))
        {
            vect[i] = reg;
            i++;
            if(i == n)
            {
                return i;
            }
        }
        fclose(arch);
    }
    return i;
}

void ordenar(tindex vect[], int n) 
{
    int i, j;
    tindex burb;
    if (vect[i].matricula > vect[i+1].matricula) 
    {
        quicksort(vect,0,n);
    }
    else
    {
        burbuja(vect,n);
    }
    printf("EL VECTOR SE ORDENO POR MATRICULA \n");
    getchar();
}

void burbuja(tindex vect[], int n) 
{
    int i, j;
    tindex burb;
    for (i = 0; i<n; i++) 
    {
        for (j = i+1; j<n; j++) 
        {
            if (vect[i].matricula > vect[j].matricula) 
            {
                burb = vect[i];
                vect[i] = vect[j];
                vect[j] = burb;
            }
        }
    }
}

void quicksort(tindex vect[], int primero, int ultimo) 
{
    int i,j, pivote_n;
    tindex pivote,temp;
    if (primero < ultimo) 
    {
        pivote = vect[ultimo];
        i = primero - 1;

        for (j = primero; j <= ultimo-1; j++) 
        {
            if (vect[j].matricula < pivote.matricula) 
            {
                i++;
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
        temp = vect[i+1];
        vect[i+1] = vect[ultimo];
        vect[ultimo] = temp;
        pivote_n = i + 1;
        quicksort(vect, primero, pivote_n - 1);
        quicksort(vect, pivote_n + 1, ultimo);
    }
}

void imprimir_ord(tindex vect[], int n)
{
	system("clear");
	int mati,i,j;
    long desplazamiento;
    int indicebuscado;
	printf("IMPRIMIR ORDENADO\n ");
    FILE *arch;
    arch = fopen("registros1.dat","rb");
    if(arch)
    {
        printf("    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO  STATUS\n");
        printf("\n");
        for(i=0;i<n;i++)
        {
            indicebuscado = vect[i].indice;
            desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
            fseek(arch, desplazamiento, SEEK_SET);
            talum reg;
            fread(&reg, sizeof(talum), 1, arch);    
            printf("   %6ld        %8s    %14s       %14s        %5d       %7s     [%d] \n",reg.matricula,reg.nombre,reg.ApPat,reg.ApMat,reg.edad,reg.sexo,reg.status);	
        }
        fseek(arch, desplazamiento, SEEK_END);
        fclose(arch);   
    }     
    getchar();     
}

void generartxt(talum vect[],tindex vect_index[],int n,char nombrearchivo[])
{
    int i,op;
    long desplazamiento;
    int indicebuscado;
    char nombre_arch[24];
    strcpy(nombre_arch,nombrearchivo);
    strcat(nombre_arch,".txt");
    op = validanum_int(1,2,"DESEAS IMPRIMIRLO ORDENADO?[1.-SI 2.-NO]","LA OPCION DEBE ESTAR ENTRE 1 Y 2");
    FILE *arch;
    arch = fopen(nombre_arch,"w");
    FILE *arch_bin;
    arch_bin = fopen("registros1.dat","rb");
    
    if(arch)
    {
        talum reg;
        fprintf(arch,"----------------------------------------------------------------------------------------- \n");
        fprintf(arch,"  No | MATRICULA | NOMBRE        | APELLIDO P.    |  APELLIDO MAT.   | EDAD  | SEXO       \n");
        fprintf(arch,"----------------------------------------------------------------------------------------- \n");
        if(op == 1)
        {
            for(i=0;i<n;i++)
            {
                indicebuscado = vect_index[i].indice;
                desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
                fseek(arch_bin, desplazamiento, SEEK_SET);
                fread(&reg, sizeof(talum), 1, arch_bin);    
                fprintf(arch,"%d      %6ld     %10s    %12s      %12s      %6d   %10s \n",i,reg.matricula,reg.nombre,reg.ApPat,reg.ApMat,reg.edad,reg.sexo);
            }
            
        }
        else
        {
            i = 0;
            while(fread(&reg,sizeof(talum),1,arch_bin))
            {
                fprintf(arch,"%d      %6ld     %10s    %12s      %12s      %6d   %10s \n",i,reg.matricula,reg.nombre,reg.ApPat,reg.ApMat,reg.edad,reg.sexo);
                i++;
            }
            fclose(arch);
        }
        
        fseek(arch_bin, desplazamiento, SEEK_END);
        fclose(arch);   
    }
}

void generarbin(void)
{
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros.dat","r+b");
    FILE *copia_arch;
    copia_arch = fopen("registros1.dat","w+b");
    if(arch)
    {
        
        while(fread(&reg,sizeof(talum),1,arch))
        {
            fwrite(&reg,sizeof(talum),1,copia_arch);
        }
        fclose(arch);
        fclose(copia_arch);
    }
}

void empaquetar(int n)
{
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros.dat","wb");
    FILE *copia_arch;
    copia_arch = fopen("registros1.dat","w+b");
    if(arch)
    {
        for(i=0;i<n;i++)
        {
            
            fread(&reg,sizeof(talum),1,copia_arch);
            fwrite(&reg,sizeof(talum),1,arch);
        }
        fclose(arch);
        fclose(copia_arch);
    }
}

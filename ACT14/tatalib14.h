#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int validanum_int(int ri, int rf ,const char msg[],const char msger[]);
long validanum_long(long ri, long rf ,const char msg[],const char msger[]);
void validCadena(char*cadena, const char msge[]);
int aleatorio(int ri,int rf);

int validanum_int(int ri, int rf , const char msg[], const char msger[])
{
	char xnum[30];
	int num;
	do{
		puts(msg);
		fflush(stdin);
		gets(xnum);
		num=atoi(xnum);
		if (num<ri || num> rf)
		{
			printf("%s \n",msger);
		}	
	}while(num<ri||num>rf);
	return num;
    getchar();
	
}

long validanum_long(long ri, long rf ,const char msg[],const char msger[])
{
	char xnum[50];
	long num;
	do{
		puts(msg);
		fflush(stdin);
		gets(xnum);
		num=atol(xnum);
		if (num<ri || num> rf)
		{
			printf("%s \n",msger);
		}	
	}while(num<ri||num>rf);
	return num;
    getchar();
}

void validCadena( char*cadena,  const char msge[])
{
	int i=0,j=0,band=0,tam=0,error=0;
	while(band==0)
	{
		error=0;
		printf("%s",msge);
		gets(cadena);
		tam=strlen(cadena);
		if(cadena[0]==' ' ||  cadena[0]=='\0')
		{
			error=error+1;
		}
		else
		{
			for(i=0;cadena[i]!='\0';i++)
			{
				switch(cadena[i])
				{
					case -40:
						cadena[i]='I';
						break;
					case -45:
						cadena[i]='E';
						break;
					case -102:
						cadena[i]='U';
						break;
					case -103:
						cadena[i]='O';
						break;
					case -114:
						cadena[i]='A';
						break;
					default:
						if(cadena[i]==' ')
						{
							if(cadena[i+1]==' ')
							{
								error++;
							}
						}
						else
						{
							if(cadena[i]<'@')
							{
								if(cadena[i]>='0')
								{
									error++;
								}
								
							}
							if(cadena[i]<'-')
							{
								error++;
							}
							if(cadena[i]>'Z')
							{
								error++;
								
							}
						}
						break;
				}
			}
		}
		if(cadena[tam-1]==' ')
		{
			error=error+1;
		}
		if(error>0)
		{
			printf("ERROR, CARECTERES INVALIDOS...\n");
		}
		else
		{
			band=1;
		}
	}

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

const char *nombComunes[] = {"JOSE", "MARIA", "MA.", "MA", "J", "J."};

const char *palabrasIncon[] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO",
 "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO",
  "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA",
   "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI",
    "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO",
     "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA",
      "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO",
       "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO",
        "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

const char *nombEstados[] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR",
 "CAMPECHE", "COAHUILA", "COLIMA", "CHIAPAS", "CHIHUAHUA", "DISTRITO FEDERAL", "DURANGO",
  "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT",
   "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA",
    "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"};

const char *codEstados[] = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH",
 "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL",
  "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS"};

const char *nombMes[] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO",
 "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

const char *mesAbrev[] = {"ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"};

char * fechaStd (char dia[], char mes[], char anNacimiento[])
{
    static char fechaN[10];
    if(strlen(dia) == 1){
        fechaN[0] = '0';
        strcat(fechaN, dia);
    }
    
    else
    {
        strcpy(fechaN, dia);
    }
    
    char mesMayus[strlen(mes)];
    strcpy(mesMayus, mes);
    for(int i = 0; i < strlen(mesMayus); i ++)
    {
        mesMayus[i] = toupper(mesMayus[i]);
    }
    for(int i = 0; i < 12; i ++)
    {
        if(strcmp(mesMayus, nombMes[i]) == 0 || strcmp(mesMayus, mesAbrev[i]) == 0)
        {
            switch(i)
            {
                case 0:
                {
                char numMes[] = {"/01/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 1:
                {
                char numMes[] = {"/02/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 2:
                {
                char numMes[] = {"/03/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 3:
                {
                char numMes[] = {"/04/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 4:
                {
                char numMes[] = {"/05/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 5:
                {
                char numMes[] = {"/06/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 6:
                {
                char numMes[] = {"/07/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 7:
                {
                char numMes[] = {"/08/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 8:
                {
                char numMes[] = {"/09/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 9:
                {
                char numMes[] = {"/10/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 10:
                {
                char numMes[] = {"/11/"};
                strcat(fechaN, numMes);
                }
                break;
                
                case 11:
                {
                char numMes[] = {"/12/"};
                strcat(fechaN, numMes);
                }
                break;
            }
            break;
        }
    }

    strcat(fechaN, anNacimiento);
    return fechaN;
}

char caractEsp(char check)
{
    static char caract;
    switch(check)
    {
        case '/': case '-': case '.':
        caract = 'X';
        break;
        
        default:
        caract = check;
        break;
    }
    return caract;
}

char * nombre(char nomb[], char apellPat[], char apellMat[])
{
    static char nombCurp[4];
    int inicial = toupper(apellPat[0]);
    if(inicial == 195)
    {
        nombCurp[0] = 'X';
    }else
    {
        nombCurp[0] = caractEsp(toupper(apellPat[0]));
    }
    for (int i = 1; i < strlen(apellPat); i ++)
    {
        if(caractEsp(toupper(apellPat[i])) == 'X')
        {
            nombCurp[1] = 'X';
            break;
        }
        if (toupper(apellPat[i]) == 'A' || toupper(apellPat[i]) == 'E' || toupper(apellPat[i]) == 'I' || toupper(apellPat[i]) == 'O' || toupper(apellPat[i]) == 'U')
        {
            nombCurp[1] = toupper(apellPat[i]);
            break;
        }else{
            nombCurp[1] = 'X';
        }
    }
    
    if (strlen(apellMat) == 0)
    {
        nombCurp[2] = 'X';
    }else
    {
        inicial = toupper(apellMat[0]);
        if(inicial == 195)
        {
            nombCurp[2] = 'X';
        }else{
            nombCurp[2] = caractEsp(toupper(apellMat[0]));
        }
    }
    
    inicial = toupper(nomb[0]);
    if(inicial == 195){
        nombCurp[3] = 'X';
    }else{
        nombCurp[3] = caractEsp(toupper(nomb[0]));
    }

    for(int i = 0; i < (sizeof(palabrasIncon)/sizeof(palabrasIncon[0])); i ++){
        if (strcmp(nombCurp, palabrasIncon[i]) == 0){
            nombCurp[1] = 'X';
        }
    }
    
    return nombCurp;
}
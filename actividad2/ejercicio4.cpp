#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float calif1, calif2, calif3, prom;
      printf ("Dame la primera calificacion ");
      scanf ("%f", &calif1);
      printf ("Dame la segunda calificacion ");
      scanf ("%f", &calif2);
      printf ("Dame la tercera calificacion ");
      scanf ("%f", &calif3);
      
      prom=((calif1+calif2+calif3)/3);
      
        if(prom>30)
      {
        if (prom>=30 && prom<60)
        {
            
            printf ("EXTRAORDINARIO");
        }
        else
        {
            if (prom>=60 && prom<70)
            {
                
                printf ("SUFICIENTE");
            }
            else
            {
                if (prom>=70 && prom<80)
                {
                   printf ("REGULAR");
                }
                else 
                {
                    if (prom>=80 && prom<90)
                    
                    {
                      printf ("BIEN");   
                    }
                    else
                    {
                        if (prom>=90 && prom<96)
                        {
                             printf (" MUY BIEN");   
                        }
                        else
                        {
                            if (prom>=96 && prom<=100)
                            {
                                 printf ("EXCELENTE");   
                            }
                            else
                            {
                                if (prom>100)
                                {
                                     printf ("ERROR");   
                                }
                            }
                        }
                    }
                    
                }
                
            }
        }
      }
      else 
      {
          printf("REPITA");
      }

      return 0;
      
}
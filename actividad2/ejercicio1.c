#include <stdio.h>
#include <stdlib.h>

int main ()
{
     int num1,num2,num3;
      printf ("Dame el primer numero ");
      scanf ("%d", &num1);
      printf ("Dame el primer numero ");
      scanf ("%d", &num2);
      printf ("Dame el primer numero ");
      scanf ("%d", &num3);
      
      if(num1>num2 && num2>num3 || num1>num3 && num3>num2)
      
      {
        printf("El numero mayor es %d",num1);
      }
      else if (num2>num3 && num3>num1 || num2>num1 && num1>num3)
      {
          printf("El numero mayor es %d",num2);
      }
      else if (num3>num2 && num2>num1 || num3>num1 && num1>num2)
      
      {
         printf("El numero mayor es %d",num3);
      }
      
      return 0;
      
}

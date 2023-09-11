#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, numM;
    printf ("Dame el primer numero") ;
    scanf ("%d" , &num1) ;
    printf ("Dame el segundo numero ");
    scanf ("%d" , &num2) ;
    
    if (num1>num2)
    
    {
    (numM=num1);
    }
    
    else {
    (numM=num2);
    }
    printf ("Dame el tercer numero");
    scanf ("%d" , &num1);
    printf ("Dame el cuarto numero");
    scanf ("%d" , &num2);
    
    if (num1>num2 && num1>numM)
    {
    (numM=num1);
    }
    
    else if (numM>num1)
    {
    (numM=numM);
    }
    
    else if (num2>num1 && num2>numM)
    {
        (numM=num2);
    }
    else if (numM>num2)
    {
        (numM=numM);
    }
    
    printf ("Dame el quinto numeron");
    scanf ("%d", &num1) ;
    printf ("Dame el sexto numero ");
    scanf ("%d" , &num2) ;
    
    if (num1>num2 && num1>numM)
    {
        (numM=num1);
    }   
    else if (numM>num1)
    {
        (numM=numM);
    }
    else if (num2>num1 && num2>numM)
    {
    (numM=num2);
    }
    else if (numM>num2)
    {
    (numM=numM);
    }
    
    printf ("El valor mayor es %d",numM);
    
    return 0;
}

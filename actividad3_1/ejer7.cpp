//SOE_ACT3_2
//SOLIS OROZCO EMANUEL 00369154
//Horozcopo
//05-09-23

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main ()
{
    int dia, mes;

    printf("Dame el numero de tu mes de nacimiento:  ");
    scanf("%d", &mes);

    printf("Dame tu dia de nacimiento:  ");
    scanf("%d", &dia);

    if(mes == 1)
    {
        if (dia >= 1)
        {
            if (dia <= 19)
            {
                printf("Tu signo zodiacal es Capricornio\n");
                printf("Distráete, habla con tu gente de confianza y a diario ocupa tu mente en temas de tu interés.");
            }
            else
            {
                printf("Tu signo zodiacal es Acuario\n");
                printf("Nada más lejos de la realidad, estás en muy buen momento para el amor y tu chico está loquito por ti. Acuario.");
            }
        }
    }
    else
    {
        if (mes == 2)
        {
            if (dia >= 1)
            {
                if (dia <= 18)
                {
                    printf("Tu signo zodiacal es Acuario\n");
                    printf("Nada más lejos de la realidad, estás en muy buen momento para el amor y tu chico está loquito por ti. Acuario,");
                }
                else
                {
                    printf("Tu signo zodiacal es Piscis\n");
                    printf("Hoy libera espacio para que a diario entren las buenas energías en casa.");
                }
            }
        }
        else
        {
            if (mes == 3)
            {
                if (dia >= 1)
                {
                    if (dia <= 20)
                    {
                        printf("Tu signo zodiacal es Piscis\n");
                        printf("Hoy libera espacio para que a diario entren las buenas energías en casa.");
                    }
                    else
                    {
                        printf("Tu signo zodiacal es Aries\n");
                        printf("Hoy la suerte no estará de tu lado, así que intenta ser prudente en el terreno económico.");
                    }
                }
            }
            else
            {
                if (mes == 4)
                {
                    if (dia >= 1)
                    {
                        if (dia <= 19)
                        {
                            printf("Tu signo zodiacal es Aries\n");
                            printf("Hoy la suerte no estará de tu lado, así que intenta ser prudente en el terreno económico.");
                        }
                        else
                        {
                            printf("Tu signo zodiacal es Tauro\n");
                            printf("Riqueza: Bajo la influencia de Mercurio, sus habilidades de negociación se destacarán.");
                        }
                    }
                }
                else
                {
                    if (mes == 5)
                    {
                        if (dia >= 1)
                        {
                            if (dia <= 20)
                            {
                                printf("Tu signo zodiacal es Tauro\n");
                                printf("Riqueza: Bajo la influencia de Mercurio, sus habilidades de negociación se destacarán.");
                            }
                            else
                            {
                                printf("Tu signo zodiacal es Geminis\n");
                                printf("Has tomado por costumbre ver a diario el vaso medio vacío y esto te ha hecho alejar un poco de tus amigos y conocidos.");
                            }
                        }
                    }
                    else
                    {
                        if (mes == 6)
                        {
                            if (dia >= 1)
                            {
                                if (dia <= 20)
                                {
                                    printf("Tu signo zodiacal es Geminis\n");
                                    printf("Has tomado por costumbre ver a diario el vaso medio vacío y esto te ha hecho alejar un poco de tus amigos y conocidos.");
                                }
                                else
                                {
                                    printf("Tu signo zodiacal es Cancer\n");
                                    printf("La comunicación emocional será enriquecedora en sus relaciones: comparta sus pensamientos y sentimientos de manera sincera.");
                                }
                            }
                        }
                        else
                        {
                            if (mes == 7)
                            {
                                if (dia >= 1)
                                {
                                    if (dia <= 22)
                                    {
                                        printf("Tu signo zodiacal es Cancer\n");
                                        printf("La comunicación emocional será enriquecedora en sus relaciones: comparta sus pensamientos y sentimientos de manera sincera.");
                                    }
                                    else
                                    {
                                        printf("Tu signo zodiacal es Leo\n");
                                        printf("Para activar tu economía, empieza a moverte. No te hoy quedes pensando en que no puedes hacer esto o aquello.");
                                    }
                                }
                            }
                            else
                            {
                                if (mes == 8)
                                {
                                    if (dia >= 1)
                                    {
                                        if (dia <= 22)
                                        {
                                            printf("Tu signo zodiacal es Leo\n");
                                            printf("Para activar tu economía, empieza a moverte. No te hoy quedes pensando en que no puedes hacer esto o aquello.");
                                        }
                                        else
                                        {
                                            printf("Tu signo zodiacal es Virgo\n");
                                            printf("El trabajo hoy te servirá como medio para evadirte de tus problemas personales. Por otro lado, quizá te encuentres con alguien perteneciente a tu pasado.");
                                        }
                                    }
                                }
                                else
                                {
                                    if (mes == 9)
                                    {
                                        if (dia >= 1)
                                        {
                                            if (dia <= 22)
                                            {
                                                printf("Tu signo zodiacal es Virgo\n");
                                                printf("El trabajo hoy te servirá como medio para evadirte de tus problemas personales. Por otro lado, quizá te encuentres con alguien perteneciente a tu pasado.");
                                            }
                                            else
                                            {
                                                printf("Tu signo zodiacal es Libra\n");
                                                printf("Si estás pensando en volar del nido familiar, Libra, empieza desde hoy mismo a hablar de ello con tus padres y la gente más próxima. ");
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (mes == 10)
                                        {
                                            if (dia >= 1)
                                            {
                                                if (dia <= 22)
                                                {
                                                    printf("Tu signo zodiacal es Libra\n");
                                                    printf("Si estás pensando en volar del nido familiar, Libra, empieza desde hoy mismo a hablar de ello con tus padres y la gente más próxima. ");
                                                }
                                                else
                                                {
                                                    printf("Tu signo zodiacal es Escorpio\n");
                                                    printf("Hoy tu sensibilidad estará muy elevada; te comportarás de forma romántica con tu pareja o con la persona candidata a ese puesto. ");
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (mes == 11)
                                            {
                                                if (dia >= 1)
                                                {
                                                    if (dia <= 21)
                                                    {
                                                        printf("Tu signo zodiacal es Escorpio\n");
                                                        printf("Hoy tu sensibilidad estará muy elevada; te comportarás de forma romántica con tu pareja o con la persona candidata a ese puesto. ");
                                                    }
                                                    else
                                                    {
                                                        printf("Tu signo zodiacal es Sagitario\n");
                                                        printf("Estás ahora empezando a acomodarte en esta nueva fase recién iniciada, Sagitario. ");
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (mes == 12)
                                                {
                                                    if (dia >= 1)
                                                    {
                                                        if (dia <= 21)
                                                        {
                                                            printf("Tu signo zodiacal es Sagitario\n");
                                                            printf("Estás ahora empezando a acomodarte en esta nueva fase recién iniciada, Sagitario. ");
                                                        }
                                                        else
                                                        {
                                                            printf("Tu signo zodiacal es Capricornio\n");
                                                            printf("Distráete, habla con tu gente de confianza y a diario ocupa tu mente en temas de tu interés.");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
        return 0;
}
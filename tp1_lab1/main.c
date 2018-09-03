#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char respuesta = 's';
    int opcion = 0;
    float numeroUno=0;
    float numeroDos=0;
    char mensajeError[]= "Opcion invalida";
    int desde = 1;
    int hasta= 5;



   do
   {
       fflush(stdin);
       opcion= menu(numeroUno, numeroDos, mensajeError, desde, hasta);

       switch(opcion)
       {
        case 1:
            getFloat(&numeroUno);
            break;
        case 2:
            getFloat(&numeroDos);
            break;
        case 3:
            suma(numeroUno,numeroDos);
            resta(numeroUno, numeroDos);
            division(numeroUno,numeroDos);
            multiplicacion(numeroUno,numeroDos);
            factorial(numeroUno);
            break;
        case 4:
              printf("La suma es: %f\n",suma(numeroUno,numeroDos));
              printf("La resta es: %f\n",resta(numeroUno,numeroDos));
              printf("La division es: %f\n",division(numeroUno,numeroDos));
              printf("La multiplicacion es: %f\n",multiplicacion(numeroUno,numeroDos));
              printf("\n",mostrarFac(numeroUno));

        case 5:
            fflush(stdin);
            printf("Desea ingresar otros datos a calcular? s/n\n");
            scanf("%c",&respuesta);
            break;
       }
   }while(respuesta == 's');
   return 0;
}

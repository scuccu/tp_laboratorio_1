#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int menu(float numeroUno, float numeroDos, char mensajeError[], int desde, int hasta)
{
    int respuesta=0;
    int opcion;
    system("cls");
    printf("1- Ingresar primer operando: (A=%.2f)\n",numeroUno);
    printf("2- Ingresar segundo operando: (B=%.2f)\n",numeroDos);
    printf("3- Calcular todas las operaciones \n");
    printf("4- Mostras resultados\n");
    printf("5- Salir\n");

    scanf("%d",&opcion);

    if(opcion>=desde && opcion<=hasta)
    {
        respuesta=opcion;
    }
    else
    {
        printf("%s",mensajeError);
        getch()!='\n';
    }
    return respuesta;
}

void getFloat(float* numero)
{
    float auxilar;
    int scanfNumero;
    printf("Ingrese el operando: \n");
    scanfNumero=scanf("%f",&auxilar);

    if(scanfNumero==0)
    {
        printf("Dato invalido \n");
        getch()!='\n';
    }
    else
    {
        *numero=auxilar;
    }
}

float suma(float numeroUno, float numeroDos)
{
    float resultadoSuma;
    resultadoSuma=numeroUno + numeroDos;

    return resultadoSuma;
}

float resta(float numeroUno, float numeroDos)
{
    float resultadoResta;
    resultadoResta=numeroUno - numeroDos;

    return resultadoResta;
}
float division(float numeroUno, float numeroDos)
{
    float resultadoDivision;
    if(numeroDos==0)
    {
        resultadoDivision=-1;
        printf("No se puede realizar la operacion de division\n");
    }
    else
    {
        resultadoDivision=numeroUno/numeroDos;
    }
    return resultadoDivision;
}
float multiplicacion(float numeroUno, float numeroDos)
{
    float resultadoMultiplicacion;
    resultadoMultiplicacion=numeroUno*numeroDos;

    return resultadoMultiplicacion;
}
int factorial(float numeroUno)
{
    int resultadoFac,aux;
    aux=numeroUno;
    aux=(int)aux;

    if(numeroUno<0 || aux!=numeroUno)
    {
        resultadoFac= -1;
    }
    else
    {
        if(numeroUno==0)
        {
            resultadoFac= 1;
        }
        else
        {
            resultadoFac=numeroUno*factorial(numeroUno-1);
        }
    }

    return resultadoFac;
}
int mostrarFac(float numeroUno)
{
    int resultadoFac=factorial(numeroUno);

    if(factorial==-1)
    {
        printf("Error\n");
    }
    else
    {
        printf("El resultado de la factorizacion es: %d\n",resultadoFac);
    }

    return resultadoFac;
}


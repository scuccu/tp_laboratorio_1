#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#define E 1000
int main()
{
    char respuesta='s';

    eEmployee misEmpleados[E];
    initEmployees(misEmpleados,E);


    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int espacioLibre;

    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            espacioLibre=buscarLugarLibre(misEmpleados,E);

            if(espacioLibre != -1)
            {
                printf("Espacio libre = %d\n",espacioLibre);
                getValidString("Ingrese el nombre del empleado: \n","Dato incorrecto, ingrese nuevamente: \n",name);
                getValidString("Ingrese el nombre del empleado: \n","Dato incorrecto, ingrese nuevamente: \n",lastName);
                sector=getValidInt("Ingrese el sector del empleado(Hasta 100): \n","Dato incorrecto, ingrese nuevamente: \n",0,100);
                salary=getValidFloat("Ingrese el salario del empleado(Hasta 80000): \n","Dato incorrecto, ingrese nuevamente: \n",2000,80000);
                addEmployee(misEmpleados,E,espacioLibre,name,lastName,salary,sector);
            }
            else
            {
                printf("No se pudo realizar la operacion, revise los datos o el espacio\n");
                system("cls");
            }
            break;
        case 2:
            modifyEmployee(misEmpleados,E,espacioLibre);
            break;
        case 3:
            removeEmployee(misEmpleados,E,misEmpleados[E].id);
            break;
        case 4:
            sortEmployees(misEmpleados,E);
            break;
        case 5:
            respuesta='n';
            break;
        }

    }
    while(respuesta=='s');
}

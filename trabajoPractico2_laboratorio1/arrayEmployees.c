#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include"arrayEmployees.h"
#define FALSO -1
#define VERDADERO 0

float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }

}

void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}





int buscarLugarLibre(eEmployee* list, int len)
{
    int i;
    int retorno=FALSO;


    for(i=0; i<len ; i ++)
    {
        if(list[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

int menuDeOpciones()
{
    int opcion;

    printf("1. ALTA DE EMPLEADO\n");
    printf("2. MODIFICACION DE EMPLEADO\n");
    printf("3. BAJA DE EMPLEADO\n");
    printf("4. INFORMES DE EMPLEADO\n");
    printf("5. SALIR\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int mostrarEmpleado(eEmployee* list, int i)
{
    int retorno= FALSO;

    if(list[i].isEmpty == 0)
    {
        printf("%d\t  %s\t  %s\t  %f\t  %d \n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
        retorno=VERDADERO;
    }

    return retorno;
}
int initEmployees(eEmployee* list, int len)
{
    int i;
    int retorno=FALSO;

    for(i=0; i<len ; i ++)
    {
        list[i].isEmpty=1;
    }
    retorno = VERDADERO;

    return retorno;

}

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    eEmployee miEmpleado;
    int lugarLibre=buscarLugarLibre(list, len);
    int retorno;


    if(lugarLibre!= FALSO)
    {
        strcpy(miEmpleado.name,name);
        strcpy(miEmpleado.lastName,lastName);
        miEmpleado.salary=salary;
        miEmpleado.sector=sector;
        miEmpleado.id=idAutoIncremental();
        miEmpleado.isEmpty = 0;
        list[lugarLibre]=miEmpleado;
        retorno=VERDADERO;
    }
    else
    {
        printf("Datos incorrectos\n");
    }
    system("cls");
    return retorno;
}

int modifyEmployee(eEmployee* list,int len,  int id)
{
    char newName[40];
    char newLastName[40];
    float newSalary;
    int newSector;
    int retorno;
    int opcion;
    int index;
    char respuesta='n';

    printf("Ingrese el Id. del empleado a modificar: \n");
    scanf("%d", &id);
    index=findEmployeeById(list, len, id);

    do
    {
        printf("Id\t  Nombre\t  Apellido\t  Salario\t  Sector\n");
        mostrarEmpleado(list, index);

        printf("Seleccione la opcion que desea modificar: \n");
        printf("\n1. NOMBRE A MODIFICAR\n");
        printf("2. APELLIDO A MODIFICAR\n");
        printf("3. SALARIO A MODIFICAR\n");
        printf("4. SECTOR A MODIFICAR\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:

            getValidString("Ingrese nombre:", "Dato incorrecto, ingrese nuevamente:", newName);
            strcpy(list[index].name, newName);
            break;
        case 2:
            getValidString("Ingrese apellido:", "Dato incorrecto, ingrese nuevamente:", newLastName);
            strcpy(list[index].lastName, newLastName);
            break;

        case 3:
            newSalary=getValidFloat("Ingrese salario:\n","Error, no valido\n", 0, 1000000);
            list[index].salary=newSalary;
            break;
        case 4:
            newSector=getValidInt("Ingrese sector:\n","Error, no valido\n", 0, 200);
            list[index].sector=newSector;
            break;
        }
        printf("Desea modificar algo más? s/n: \n:");
        fflush(stdin);
        scanf("%c",&respuesta);
        system("cls");

    }
    while(respuesta == 's');

    retorno=VERDADERO;
}

int printEmployees(eEmployee* list, int len)
{
    int retorno=FALSO;
    int i;

    printf("ID\t  NOMBRE\t  APELLIDO\t  SALARIO\t  SECTOR\n");
    for( i=0; i<len ; i ++ )
    {
        if(list[i].isEmpty == 0)
        {
            mostrarEmpleado(list, i);
            retorno=VERDADERO;
        }
    }
    return retorno;
}
int idAutoIncremental()
{

    int id = 0;

    id ++;

    return id;
}

int findEmployeeById(eEmployee* list, int len, int id)
{
    int retorno;
    int i;


    for( i=0 ; i<len ; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int index;
    int i;
    int retorno=FALSO;

    printf("\n Ingrese el id del empleado a eliminar: \n");
    scanf("%d",&id);
    index=findEmployeeById(list, len, id);

    if(list[index].isEmpty==0)
    {
        printf("Id\t  Nombre\t    Apellido\t    Salario\t    Sector\n");

        mostrarEmpleado(list, index);
    }
    for( i=0; i<len; i++)
    {
        if(index >= 0)
        {
            printf("El empleado fue eliminado.\n");
            list[index].isEmpty = 1;
            break;
        }

        else
        {
            printf("No existe ese id.\n");
            break;
        }

        retorno=VERDADERO;
    }

    return retorno;
}

int sortEmployees(eEmployee* list, int len)
{

    eEmployee auxiliarEmployees;
    int i;
    int j;
    int respuesta;
    int retorno;
    printEmployees(list, len);

    printf("1- ORDENAR \n");
    printf("2- TOTAL, PROMEDIO Y SALARIO SUPERIOR\n");
    printf("Elija la opcion:  \n");
    fflush(stdin);
    scanf("%d", &respuesta);

    switch(respuesta)
    {
    case 1:
        for( i =0 ; i<len -1 ; i ++)
        {
            for(j= i+1 ; j<len; j++)
            {

                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                    auxiliarEmployees = list[i];
                    list[i] = list[j];
                    list[j] = auxiliarEmployees;
                }
                else if(strcmp(list[j].lastName,list[i].lastName)==0 && list[j].sector<list[i].sector)
                {
                    auxiliarEmployees = list[i];
                    list[i] = list[j];
                    list[j] = auxiliarEmployees;
                }
            }
        }
        break;

    case 2:
        promedioSalary(list,len);
        break;

    }
    retorno=VERDADERO;
    return retorno;
}




int promedioSalary(eEmployee* list, int len)
{
    float suma=0;
    float promedio;
    int i;
    int retorno;
    int contadorEmpleados=0;
    int contadorSuperanPromedio=0;


    for( i=0 ; i<len ; i++)
    {
        if(list[i].isEmpty == 0)
        {
            suma = suma + list[i].salary;
            contadorEmpleados ++;
            promedio= suma / contadorEmpleados;
        }
    }


    for( i=0; i<len ; i++)
    {
        if(list[i].isEmpty == 0)
        {
            if(list[i].salary> promedio)
            {
                contadorSuperanPromedio ++;
            }
        }

    }
    printf("La suma es: %.2f  El promedio es: %f  Los que superan el salario promedio son %d\n", suma, promedio, contadorSuperanPromedio);
    retorno=VERDADERO;

    return retorno;
}

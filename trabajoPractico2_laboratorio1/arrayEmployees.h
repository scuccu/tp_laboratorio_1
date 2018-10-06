#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define FALSO -1
#define VERDADERO 0
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

//////FUNCIONES GET///////
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
 float getFloat(char* mensaje);
 /**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje);
/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje);


////////FUNCIONES DE VALIDACION///////

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);
/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);



////////FUNCIONES ABM EMPLEADO////////

/** \brief Para indicar que todas las posiciones del array están vacías,
 * \param list* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si es falso, o retorna 0 si es verdadero
 *
 */
int initEmployees(eEmployee* list, int len);
/** \brief Muestra el menu de opciones
 * \return retorna la opcion que se elige
 *
 */
int menuDeOpciones();

/** \brief Muestra un unico empleado
 * \param list* eEmployee Puntero del array de empleados
 * \param posicion del array que sera mostrada
 *
 */
int mostrarEmpleado(eEmployee* list, int i);
/** \brief Indica que posicion del array es una posicion libre
 * \param list* eEmployee Puntero del array de empleados
 * \param tamaño del array
 * \return retorna -1 si es falso, o retorna un espacio libre
 *
 */
int buscarLugarLibre(eEmployee* list, int len);
/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id
 *
 * \param Puntero del array de empleados
 * \param len int tamaño del array
 * \param Id a ser registrado
 * \return si la posicion coincide con el id, devuelve la posicion
 *
 */
int findEmployeeById(eEmployee* list, int len, int id);
/** \brief se modifica el empleado que se ingresa por Id ingresado
 *
 * \param Puntero de array de empleados
 * \param  Largo del array
 * \param Id a ser modificado
 * \return devuelve -1 si es falso, o devuelve 0 si ees correcto
 *
 */
int modifyEmployee(eEmployee* list,int len, int id);
/** \brief Da de baja al empleado que se busca por Id
 *
 * \param Puntero del array de empleados
 * \param largo del array
 * \param Id a ser buscado
 * \return devuelve -1 si es falso, o devuelve 0 si es verdadero
 *
 */
int removeEmployee(eEmployee* list, int len, int id);
/** \brief ordenar el array de empleados por apellido y sector de manera ascendente o descendente , muestra promedio y empleados que superan el salario promedio
 * \param  Puntero del array de empleados
 * \param Largo del array
 * \return devuelve -1 si es falso, o devuelve 0 si es verdadero
 *
 */
int sortEmployees(eEmployee* list, int len);
/** \brief Muestra lista de empleados
 * \param Puntero del array de empleados
 * \param tamaño del array
 * \return retorna -1 si es falso, o 0 si es verdadero
 *
 */
int printEmployees(eEmployee* list, int len);

/** \brief genera un id autoincrementado
 *
 */
int idAutoIncremental();
/** \brief Busca un empleado a partir de su Id
 *
 * \param Puntero del array de empleados
 * \param tamaño del array
 * \param Id a ser ingresado
 * \return Devuelva la posicion que coincide con el Id ingresado
 *
 */
int findEmployeeById(eEmployee* list, int len, int id);
/** \brief Calcula el promedio de los salarios, la suma de los salarios y los empleados que superan el salario promedio
 *
 * \param Puntero de array de empleados
 * \param Largo del array
 * \return devuelve -1 si es falso, o devuelve 0 si es verdadero
 *
 */
int promedioSalary(eEmployee* list, int len);

#endif

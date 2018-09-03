/** \brief muestra el menu de opciones
 * \param numeroUno es el valor del primer operando que se muestra en el menu
 * \param numeroDos es el valor del primer operando que se muestra en el menu
 * \param errorTexto es el mensaje de error que se muestra
 * \param desde es el limite inferior a validar
 * \param hasta es el limite superior a validar
 * \return retoma la opcion de la seleccion del menu
 */
int menu(float, float, char[], int, int);

/**
 * \brief se le pide un numero al usuraio y se valida
 * \param numero se carga el numero ingresado
 *
 */
void getFloat(float* numero);
/** \brief toma los dos numeros ingresados y los suma
 * \param numeroUno toma el primer numero
 * \param numeroDos toma el segundo numero
 * \return resultado de la suma
 */
float suma(float numeroUno, float numeroDos);
/** \brief toma los dos numeros ingresados y los resta
 * \param numeroUno toma el primer numero
 * \param numeroDos toma el segundo numero
 * \return resultado de la resta
 */
float resta(float numeroUno, float numeroDos);
/** \brief toma los dos numeros ingresados y los divide
 * \param numeroUno toma el primer numero
 * \param numeroDos toma el segundo numero
 * \return resultado de la división
 */
float division(float numeroUno, float numeroDos);
/** \brief toma los dos numeros ingresados y los multiplica
 * \param numeroUno toma el primer numero
 * \param numeroDos toma el segundo numero
 * \return resultado de la multiplicación
 */
float multiplicacion(float numeroUno, float numeroDos);
/** \brief toma un numero y calcula su factorial
 * \param numeroUno toma el primer numero
 * \return devuelve el resultado de la operacion factorial
 */
int factorial(float numeroUno);
/** \brief toma un numero y muestra el resultado de la funcion factorial
 * \param numeroUno toma el primer numero
 */
int mostrarFac(float numeroUno);

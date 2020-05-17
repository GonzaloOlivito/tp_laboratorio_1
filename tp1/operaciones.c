#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
/** \brief La funcion que engloba las dos funciones generales
 *
 * \return retorna 0 en caso de no haber error
 *
 */
int calculadora ()
{
    int eleccion;
    float primerOperando;
    float segundoOperando;
    do{
    menu(primerOperando,segundoOperando, &eleccion);
    operaciones(&primerOperando,&segundoOperando,eleccion);
    system("cls");
    } while(eleccion != 5);

    return 0;
}
/** \brief El menu de opciones desplegado
 *
 * \param primerNumero es el primer numero ingresado
 * \param segundoNumero es el segundo numero ingreso
 * \param eleccion es la eleccion sobre el menu de opciones
 * \return retorna 0 si no hay error
 *
 */
int menu(float primerOperando, float segundoOperando,int* opcionElegida)
{
    int eleccion;
    printf("****CALCULADORA*****\n\n");
    printf("\nMENU DE OPERACIONES");
    printf("\n1-Ingrese el primer operando %.2f\n",primerOperando);
    printf("2-Ingrese el segundo operando %.2f\n",segundoOperando);
    printf("3-Calcular todas las operaciones \n");
    printf("4-Mostrar todos los resultados \n");
    printf("5-SALIR \n");
    printf("Elija la opcion deseada: ");
    scanf("%d", &eleccion);

    *opcionElegida = eleccion;

    return 0;
}
/** \brief Son las cinco opciones posibles a elegir
 *
 * \param primerNumero es el primer numero ingresado
 * \param segundoNumero es el segundo numero ingresado
 * \param eleccion es la eleccion hecha por el usuario
 * \return retorna 0 en caso de no haber error
 *
 */
int operaciones(float* primerOperando, float* segundoOperando, int eleccion)
{
    float primerNum;
    float segundoNum;
    switch(eleccion)
    {
    case 1:
        printf("Ingrese el primer operando: ");
        scanf("%f",&primerNum);
        *primerOperando=primerNum;
        break;

    case 2:
        printf("Ingrese el segundo operando: ");
        scanf("%f", &segundoNum);
        *segundoOperando=segundoNum;
        break;
    case 3:
        printf("a)Calcular la suma %.2f + %.2f\n", *primerOperando, *segundoOperando);
        printf("b)Calcular la resta %.2f - %.2f\n", *primerOperando, *segundoOperando);
        printf("c)Calcular la multiplicacion %.2f * %.2f\n", *primerOperando, *segundoOperando);
        printf("d)Calcular la division %.2f / %.2f\n", *primerOperando, *segundoOperando);
        printf("e)Calcular el factorial de %.2f y %.2f\n", *primerOperando, *segundoOperando);
         system("pause");
        break;
    case 4:
        suma(*primerOperando,*segundoOperando);
        resta(*primerOperando,*segundoOperando);
        multiplicacion(*primerOperando,*segundoOperando);
        division(*primerOperando,*segundoOperando);
        calcularFactorialPrimerNumero(*primerOperando);
        calcularFactorialSegundoNumero(*segundoOperando);
        system("pause");
        break;
    case 5:

        break;

    }
    return 0;
}
/** \brief Es la operacion de suma
 *
 * \param numeroUno es el primer numero ingresado
 * \param numeroDos es el segundo numero ingresado
 * \return retorna 0 en caso de no haber error
 *
 */
int suma(float numeroUno, float numeroDos)
{
    float resultadoSuma;

    resultadoSuma=numeroUno + numeroDos;

    printf("El resultado de la suma es: %.2f\n", resultadoSuma);

    return 0;
}
/** \brief Es la operacion de resta
 *
 * \param numeroUno es el primer numero ingresado
 * \param numeroDos es el segundo numero ingresado
 * \return retorna 0 en caso de no haber error
 *
 */
int resta(float numeroUno, float numeroDos)
{
    float resultadoRest;

    resultadoRest=numeroUno - numeroDos;

    printf("El resultado de la resta es: %.2f\n", resultadoRest);

    return 0;
}
/** \brief Es la operacion de multiplicacion
 *
 * \param numeroUno es el primer numero ingresado
 * \param numeroDos es el segundo numero ingresado
 * \return retorna 0 en caso de no haber error
 *
 */
int multiplicacion(float numeroUno, float numeroDos)
{
    float resultadoMulti;

    resultadoMulti=numeroUno*numeroDos;

    printf("El resultado de la multiplicacion es: %.2f\n", resultadoMulti);

    return 0;
}
/** \brief Es la operacion de division
 *
 * \param numeroUno es el primer numero ingresado
 * \param numeroDos es el segundo numero ingresado
 * \return retorna 0 en caso de no haber error
 *
 */
int division(float numeroUno, float numeroDos)
{
    float resultadoDivision;
    if(numeroDos==0)
        {
            printf("No es posible dividir por cero\n");
        }else
            {
            resultadoDivision=numeroUno/numeroDos;
            printf("El resultado de la division es: %.2f\n", resultadoDivision);
            }
    return 0;
}
/** \brief Es la operacion de calculo del primer factorial
 *
 * \param numeroUno es el primer numero ingresado
 * \return retorna 0 en caso de no haber error
 *
 */
int calcularFactorialPrimerNumero (float numeroUno)
{
    float factorial;
    if(numeroUno==0)
    {
        factorial = 1;
    }else
    {
        factorial=numeroUno;
    do{
        numeroUno --;
        factorial*=numeroUno;
      }while(numeroUno>1);

    }
        printf("El factorial del primer numero es %.2f \n", factorial);
        return 0;
}

/** \brief Es la operacion de calculo del segundo factorial
 *
 * \param numeroDos es el segundo numero ingresado
 * \return retorna 0 en caso de no haber error
 *
 */
float calcularFactorialSegundoNumero(float numeroDos)
{
 float factorial;
    if(numeroDos==0)
    {
        factorial = 1;
    }else
    {
        factorial=numeroDos;
        do{
            numeroDos --;
            factorial*=numeroDos;
          }while(numeroDos>1);

    }
        printf("El factorial del segundo numero es %.2f \n", factorial);
        return 0;
        }

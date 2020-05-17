#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define TAMSEC 5
#define TAM 10
#define CANTHARD 9

int main()
{
    int id=1000;
    char salir = 'n';
    eEmpleado lista[TAM];
    eSector sectores[TAMSEC] = {{1,"Informatica"},{2,"RRHH"},{3,"Compras"},{4,"Ventas"},{5,"Contable"}};

    inicializarEmpleados(lista,TAM);
    hardcodeo(lista,CANTHARD);

    id=id+CANTHARD;


    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(id,lista,TAM,sectores,TAMSEC))
            {
                id++;
            }
            break;
        case 2:
            modificarEmpleado(lista,TAM,sectores,TAMSEC);
            break;
        case 3:
         bajaEmpleado(lista,TAM,sectores,TAMSEC);
            break;
        case 4:

            operacionesInformes(lista,TAM,sectores,TAMSEC);
            break;
        case 5:
            printf("Confirma salir?s/n:");
            fflush(stdin);
            scanf("%c", &salir);
            break;
        default:
            printf("Opcion no valida, reintente.\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "datawarehouse.h"
#include "arrayEmployees.h"


int menu()
{
    system("cls");
    int opcion;
    printf("******MENU******\n\n");
    printf("1. ALTA EMPLEADO\n");
    printf("2. MODIFICAR EMPLEADO\n");
    printf("3. BAJA EMPLEADO\n");
    printf("4. INFORMES\n");
    printf("5. SALIR\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}


int buscarLibre (eEmpleado vec[], int tam)
{
    int retorno = -1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 1)
        {
            retorno = i;
        }
    }

    return retorno;
}

int altaEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int todoOk=-1;
    int libre;
    system("cls");
    printf("***ALTA EMPLEADO\n\n");
    libre=buscarLibre(vec,tam);
    if(libre == -1)
    {
        printf("No hay lugar");

    }else
    {
        getString(41,3,"Ingrese el nombre: ",vec[libre].nombre);
        getString(41,3,"Ingrese el apellido: ", vec[libre].apellido);
        getFloat(0,999999, &vec[libre].sueldo,"Ingrese sueldo: ");
        menuSectores();
        printf("Ingrese el sector: ");
        scanf("%d", &vec[libre].idSector);
        vec[libre].id=id;
        vec[libre].isEmpty=0;
        todoOk=1;
        printf("Alta exitosa\n\n");
    }

    return todoOk;
}
void menuSectores()
{
    printf("1. Sistemas\n");
    printf("2. RRHH\n");
    printf("3. Ventas\n");
    printf("4. Compras\n");
    printf("5. Contable\n");

}

int cargarDescripcionSector(int id, eSector sectores[], int tamsec, char descripcion[])
{
    int retorno=-1;
    for(int i=0;i<tamsec;i++)
    {
        if(id==sectores[i].id ){
            strcpy(descripcion,sectores[i].descripcion);
            retorno = 1;
        }
    }

return retorno;
}

void mostrarEmpleado(eEmpleado emp,eSector sectores[], int tamsec)
{
    char descripcion[20];
    cargarDescripcionSector(emp.idSector,sectores,tamsec,descripcion);
    printf("%5d  %10s    %10s    %.2f   %10s \n",emp.id,emp.nombre,emp.apellido,emp.sueldo,descripcion);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int flag=0;
    printf("LISTA DE EMPLEADOS \n\n");
    printf("  ID        NOMBRE      APELLIDO   SUELDO        SECTOR\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i],sectores,tamsec);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay empleados para listar \n");
    }
}
int buscarEmpleado(int id,eEmpleado vec[], int tam)
{
    int retorno = -1;
    for(int i =0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].id == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int eleccion;
    int esta;
    int todoOk = -1;
    system("cls");
    printf("      **MODIFICAR EMPLEADO**     ");
    mostrarEmpleados(vec,tam,sectores,tamsec);
    printf("\nSeleccione id a modificar: ");
    scanf("%d", &eleccion);
    esta = buscarEmpleado(eleccion,vec,tam);
    if(esta==-1)
    {
        printf("No se encuentra el id, reintente");
    }else
    {
        system("cls");
        printf("  ID        NOMBRE      APELLIDO   SUELDO      SECTOR\n");
        mostrarEmpleado(vec[esta],sectores,tam);
        switch(menuModificar())
        {
        case 1:
        getString(41,3,"Ingrese nuevo nombre:",vec[esta].nombre);
        break;
        case 2:
        getString(41,3,"Ingrese nuevo apellido:",vec[esta].apellido);
        break;
        case 3:
        getFloat(0,999999,&vec[esta].sueldo,"Ingrese nuevo sueldo:");
        break;
        case 4:

        menuSectores();
        printf("Ingrese nuevo sector: ");
        scanf("%d", &vec[esta].idSector);
        break;
        case 5:
        break;
        }
    todoOk=1;
    }
return todoOk;
}
int menuModificar()
{
    int eleccion;

    printf("1. Modificar nombre\n");
    printf("2. Modificar apellido\n");
    printf("3. Modificar salario\n");
    printf("4. Modificar sector\n");
    printf("5. Anular operacion\n");
    printf("Seleccione: ");
    scanf("%d", &eleccion);
    return eleccion;
}

int bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int eleccion;
    int esta;
    char confirma;
    system("cls");
    printf("*** BAJA EMPLEADO ***\n\n");
    mostrarEmpleados(vec,tam,sectores,tamsec);
    printf("\n Ingrese ID a dar de baja: ");
    scanf("%d", &eleccion);

    esta=buscarEmpleado(eleccion,vec,tam);
    if(esta==-1)
    {
        printf("No se encuentra al empleado, reintente");
    }else
    {
        system("cls");
        printf("  ID        NOMBRE      APELLIDO   SUELDO      SECTOR\n");
        mostrarEmpleado(vec[esta],sectores,tam);
        printf("Confirma baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            vec[esta].isEmpty=1;
            printf("\n Baja realizada con exito\n");
        }else
        {
            printf("Baja anulada");
        }
    }

    return 0;
}

int hardcodeo(eEmpleado vec[], int tam)
{
    int retorno = -1;
    for(int i=0;i<tam;i++)
    {
        strcpy(vec[i].apellido,apellidos[i]);
        strcpy(vec[i].nombre,nombres[i]);
        vec[i].idSector=idsSector[i];
        vec[i].id=ids[i];
        vec[i].sueldo=sueldos[i];
        vec[i].isEmpty=0;
        retorno = 1;
    }
    return retorno;
}

int miniMenuInformes()
{
    int opcion;
    system("cls");
    printf("\n** INFORMES ** \n");
    printf("1. Ordenar empleados por orden alfabetico de apellido y sector\n");
    printf("2. Total y promedio de los salarios, y empleados que superen el salario promedio\n");
    printf("Seleccione opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int operacionesInformes(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    switch(miniMenuInformes())
    {
    case 1:
    ordenamiento(vec,tam,sectores,tamsec);
    mostrarEmpleados(vec,tam,sectores,tamsec);
    break;
    case 2:
    promedioSalarios(vec,tam,sectores,tamsec);
    break;
    }
    return 0;
}

int ordenamiento(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    system("cls");
    eEmpleado aux;
    char sector[21];
    char sectorJ[21];
    int comp;
    int compSec;
    for(int i=0;i<tam;i++)
    {
        for(int j=i+1;j<tam-1;j++)
        {
            comp=strcmp(vec[i].apellido,vec[j].apellido);

            if(vec[i].isEmpty==0 && comp>0)
        {
            aux=vec[i];
            vec[i]=vec[j];
            vec[j]=aux;

        }
        else{

                cargarDescripcionSector(vec[i].id,sectores,tamsec,sector);
                cargarDescripcionSector(vec[j].id,sectores,tamsec,sectorJ);
                compSec=strcmp(sectores[j].descripcion,sectores[i].descripcion);
                if(comp == 0 && compSec>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
        }

    }


}

return 0;
}

int promedioSalarios(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    float acumulador=0;
    float promedio;
    int contador=0;
    int contadorMayorPromedio=0;

    system("cls");
    for(int i=0;i<tam;i++)
    {
        acumulador=vec[i].sueldo+acumulador;
        contador=contador+1;
    promedio=acumulador/(float)contador;
        if(vec[i].isEmpty==0 && vec[i].sueldo > promedio)
        {
            contadorMayorPromedio=contadorMayorPromedio+1;

        }
    }

    printf("\nEl total de los sueldos es: %.2f\n", acumulador);
    printf("El promedio total es: %.2f\n", promedio);
    printf("Los empleados que son mayores que el promedio son: %d\n", contadorMayorPromedio);


    return 0;
}



typedef struct{
int id;
char nombre[41];
char apellido[41];
float sueldo;
int idSector;
int isEmpty;
}eEmpleado;

typedef struct{
int id;
char descripcion[20];
}eSector;

int menuModificar();
void menuSectores();
int menu();

int hardcodeo(eEmpleado vec[], int tam);

void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre (eEmpleado vec[], int tam);
int altaEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamsec);
int bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
int miniMenuInformes();
int cargarDescripcionSector(int id, eSector sectores[], int tamsec, char descripcion[]);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
int buscarEmpleado(int id,eEmpleado vec[], int tam);
int modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
int ordenamiento(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
int operacionesInformes(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
int promedioSalarios(eEmpleado vec[], int tam, eSector sectores[], int tamsec);

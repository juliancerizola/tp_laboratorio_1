#define TEXT_SIZE 51

typedef struct
{
 int id;
 char nombre[TEXT_SIZE];
 char apellido[TEXT_SIZE];
 float salario;
 int sector;
 int isEmpty;
} eEmpleado;

int inicializarEmpleados(eEmpleado array[], int size);
int buscarEmptyEmpleado(eEmpleado array[], int size, int* posicion,int* valorIsEmptyBuscado);
int buscarIDEmpleado(eEmpleado array[], int size, int valorBuscado, int* posicion);
int buscarIntEmpleado(eEmpleado array[], int size, int valorBuscado, int* posicion);
int buscarStringEmpleado(eEmpleado array[], int size, char* valorBuscado, int* indice);
int altaEmpleado(eEmpleado array[], int size, int* contadorID);
int bajaEmpleado(eEmpleado array[], int size);
int modificarEmpleado(eEmpleado array[], int size);
int ordenarPorApellidoYSectorEmpleados(eEmpleado array[],int size);
int listarEmpleados(eEmpleado array[], int size);
int promediarSalarios(eEmpleado array[], int size);

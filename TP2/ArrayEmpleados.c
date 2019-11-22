#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmpleados.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
*/
int inicializarEmpleados(eEmpleado array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}


int buscarEmptyEmpleado(eEmpleado array[], int size, int* posicion,int* valorIsEmptyBuscado) /**Si valorIsEmptyBuscado==1 busca isEmpty==1, si valorIsEmptyBuscado==0 busca isEmpty==0 */
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {

            if(array[i].isEmpty==valorIsEmptyBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
 int altaEmpleado(eEmpleado array[], int size, int* idRecibido)
{
    int retorno=-1;
    if(array!=NULL && size>0)
    {
        if(buscarEmptyEmpleado(array,size,idRecibido,1)==-1)
        {
            printf("No hay lugares vacios\n");
        }
        else
        {
            array[*idRecibido].isEmpty=0;
            utn_getName(" Ingrese nombre: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].nombre);
            utn_getTexto(" Ingrese apellido: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].apellido);
            utn_getUnsignedInt(" Ingrese sector: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].sector);
            utn_getFloat(" Ingrese salario: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].salario);
            array[*idRecibido].id=*idRecibido+1;
            msj(1);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int buscarIDEmpleado (eEmpleado array[], int size, int id, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            } else if(array[i].id==id) {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
 int bajaEmpleado(eEmpleado array[], int size)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && size>0)
    {
        utn_getUnsignedInt(" ID a cancelar: "," ERROR\n",1,sizeof(int),1,size,1,&id);          //cambiar si no se busca por ID
        if(buscarIDEmpleado(array,size,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf(" No existe este ID\n");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].id=0;
            array[posicion].sector=0;
            array[posicion].salario=0;
            strncpy(array[posicion].nombre,"",TEXT_SIZE);
            strncpy(array[posicion].apellido,"",TEXT_SIZE);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca un elemento por ID y modifica sus campos
* \param
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int modificarEmpleado(eEmpleado array[], int size)
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && size>0)
    {
        utn_getUnsignedInt(" ID del empleado a modificar: "," ERROR\n",1,sizeof(int),1,size,1,&id);         //cambiar si no se busca por ID
        if(buscarIDEmpleado(array,size,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            msj(-5);                                                         //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n 1) Nombre: %s\n 2) Apellido: %s\n 3) Sector: %d\n 4) Salario: %f\n",
                array[posicion].nombre,array[posicion].apellido,array[posicion].sector,array[posicion].salario);
                utn_getUnsignedInt("Ingrese el numero de la variable que desea modificar: "," ERROR\n",1,2,1,9,2,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("\n Ingrese nombre nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 2:
                        utn_getTexto("\n Ingrese apellido nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].apellido);
                        break;
                    case 3:
                        utn_getUnsignedInt("\n Ingrese sector nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].sector);
                        break;
                    case 4:
                        utn_getFloat("\n Ingrese salario nuevo: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[posicion].salario);
                        break;
                    case 9:
                        break;
                    default:
                        msj(-4);
                }
            }while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=9);

            msj(1);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */


int ordenarPorApellidoYSectorEmpleados(eEmpleado array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
    float bufferFloat;
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strncpy(bufferString,array[i].nombre,TEXT_SIZE);
            bufferId=array[i].id;
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].sector;
            bufferFloat=array[i].salario;
            strncpy(bufferLongString,array[i].apellido,TEXT_SIZE);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferLongString,array[j].apellido)<0 && bufferInt<array[j].sector)   //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                      //buffer < campo ascendente   buffer > campo descendente
                strncpy(array[j + 1].nombre,array[j].nombre,TEXT_SIZE);
                array[j + 1].id=array[j].id;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].sector=array[j].sector;
                array[j + 1].salario=array[j].salario;
                strncpy(array[j + 1].apellido,array[j].apellido,TEXT_SIZE);

                j--;
            }
            strncpy(array[j + 1].nombre,bufferString,TEXT_SIZE);
            array[j + 1].id=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].sector=bufferInt;
            array[j + 1].salario=bufferFloat;
            strncpy(array[j + 1].apellido,bufferLongString,TEXT_SIZE);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int listarEmpleados(eEmpleado array[], int size)
{
    int retorno=-1;
    int i;
    int columnaMostrada=0;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                if(columnaMostrada==0)
                {
                    columnaMostrada=1;
                    printf("  ID\t\tNombre\t\tApellido\t\tSector\t\tSalario\n");
                }
               // printf("  %d      %s       %s       %d      %f\n",array[i].id, array[i].nombre, array[i].apellido, array[i].sector, array[i].salario);
                printf("  %d\t\t%s\t\t%s\t\t%d\t\t%f\n",array[i].id, array[i].nombre, array[i].apellido, array[i].sector, array[i].salario);
        }
        printf("\n");
        retorno=0;
    }
    return retorno;
}


int promediarSalarios(eEmpleado array[], int size)
{
    int retorno=-1;
    float totalSalarios=0;
    float promedioSalarios=0;
    int salariosSumados=0;
    int salariosMayoresOIgualesAlPromedio=0;

    if(array!=NULL && size>=0)
    {

        for(int i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                totalSalarios+=array[i].salario;
                salariosSumados++;
            }
        }
        promedioSalarios=totalSalarios/salariosSumados;

        for(int i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(array[i].salario>=promedioSalarios)
                {
                    salariosMayoresOIgualesAlPromedio++;
                }
            }
        }
        printf(" Totalidad de los salarios: $%f\n Promedio de los %d salarios: $%f\n Total de empleados que tienen un salario MAYOR O IGUAL al promedio: %d\n\n",totalSalarios,salariosSumados,promedioSalarios,salariosMayoresOIgualesAlPromedio);
        retorno=0;

    }
    return retorno;
}

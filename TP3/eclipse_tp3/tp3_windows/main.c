//////////////////////////////////////////////////////////////
#define TITULO_PRUEBA   "Trabajo practico Nro 3"    /** Reemplazamos 'Parcial de prueba' por el nombre que le queramos dar a nuestro parcial o TP */
#define ALUMNO          "Julian Cerizola"           /** Reemplazamos 'Julian Cerizola' por el nombre del alumno que esté entregando esta prueba */
#define DIVISION        "1ro E - UTN FRA"           /** Reemplazamos '1ro E - UTN FRA' por la division del alumno en cuestión */
//////////////////////////////////////////////////////////////
#define QTY_OPCIONES    10                          /** Reemplazamos 14 por la cantidad de opciones de nuestro ABM */
#define PATH            "data.csv"
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
//////////////////////////////////////////////////////////////
/**
    Menu:
//////////////////////////////////////////////////////////////
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
//////////////////////////////////////////////////////////////
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
//////////////////////////////////////////////////////////////
     6. Listar empleados
     7. Ordenar empleados
//////////////////////////////////////////////////////////////
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
//////////////////////////////////////////////////////////////
    10. Salir
//////////////////////////////////////////////////////////////
*/
//////////////////////////////////////////////////////////////
int main()
{
    // Notar que hay un \a          y un corazón <3
    printf("\a=========================================================\n\t   Bienvenide!\n\n\t%s\n\t%s\n\t%s <3\n=========================================================\n",TITULO_PRUEBA,ALUMNO,DIVISION);
    fflush(stdin);
    int option=0;
    LinkedList* listaEmpleados = ll_newLinkedList();    // Creamos la linked list
    do
    {
        //////////////////////////////////////////////////////////////
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        fflush(stdout);
        printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n\n");
        fflush(stdout);
        //////////////////////////////////////////////////////////////
        printf(" 3. Alta de empleado\n");
        fflush(stdout);
        printf(" 4. Modificar datos de empleado\n");
        fflush(stdout);
        printf(" 5. Baja de empleado\n\n");
        fflush(stdout);
        //////////////////////////////////////////////////////////////
        printf(" 6. Listar empleados\n");
        fflush(stdout);
        printf(" 7. Ordenar empleados\n\n");
        fflush(stdout);
        //////////////////////////////////////////////////////////////
        printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        fflush(stdout);
        printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n\n");
        fflush(stdout);
        //////////////////////////////////////////////////////////////
        printf(" 10. Salir\n\n");
        fflush(stdout);
        //////////////////////////////////////////////////////////////6
        utn_getUnsignedInt("-Ingrese el numero de la accion que desea realizar: ","\n ERROR - Opcion invalida (entre 1 y 10)\n=========================================================\n",0,QTY_OPCIONES,1,100,2,&option);
        fflush(stdout);
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
        switch(option)
        {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 1:    // 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
                if((controller_loadFromText(PATH,listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-1);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 2:     // 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
                if((controller_loadFromBinary(PATH,listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-1);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 3:     // 3. Alta de empleado
                if((controller_addEmployee(listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 4:     // 4. Modificar datos de empleado
                if((controller_editEmployee(listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 5:     // 5. Baja de empleado
                if((controller_removeEmployee(listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 6:     // 6. Listar empleados
                if((controller_listEmployee(listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-2);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 7:     // 7. Ordenar empleados
                if((controller_sortEmployee(listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 8:     // 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
                if((controller_saveAsText(PATH,listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case 9:     // 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
                if((controller_saveAsBinary(PATH,listaEmpleados))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
                break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case QTY_OPCIONES:      // 10. Salir
                msj(2);
                return 0;
                break;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////s
    } while(option!=QTY_OPCIONES);
//////////////////////////////////////////////////////////////
    return 0;
}

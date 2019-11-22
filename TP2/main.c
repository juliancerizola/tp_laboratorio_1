#include <stdio.h>
#include <string.h>

#include "utn.h"

#include "ArrayEmpleados.h"


#define QTY_EMPLEADOS 1000      // La agenda no soportará más de 1000 empleados

int mostrarMenu(eEmpleado* agenda[QTY_EMPLEADOS],int* contadorId);


int main()
{
    printf("\tBienvenide!\n\n   Trabajo practico numero 2\n       Julian Cerizola\n      1ro E - UTN FRA <3\n\n");
    eEmpleado agenda[QTY_EMPLEADOS];    //Creamos agenda de 1000 empleados
    inicializarEmpleados(agenda,QTY_EMPLEADOS); //Colocamos la variable isEmpty de cada empleado en 1
    mostrarMenu(agenda,1);

    return 0;
}

int mostrarMenu(eEmpleado* agenda[QTY_EMPLEADOS],int* contadorId) /** IMPORTANTE - Estas variables son parametros porque los valores no deben volver a 0 cada vez que se llama a mostrarMenu cosa que sucede si definimos las variables dentro de la funcion */
{
    int accion; //Es la accion del AMB que el usuario ingresará

    do
    {
        utn_getUnsignedInt("  1) Alta\n  2) Modificar\n  3) Baja\n  4) Informes\n  5) Salir\n Ingrese el numero de la accion que desea realizar: ",
                            "",1,TEXT_SIZE,1,5,0,&accion);    /**  El mensaje de error está vacío porque el switch ya arroja un msj de este estilo en el default (msj(-2);) */
        switch(accion)
        {
            case 1: //  Alta
                printf("\n");
                altaEmpleado(agenda,QTY_EMPLEADOS,&contadorId);
                break;
            case 2: //  Modificar
                if((buscarEmptyEmpleado(agenda,QTY_EMPLEADOS,&contadorId,0))==0)
                {
                    printf("\n");
                    if((modificarEmpleado(agenda,QTY_EMPLEADOS))==0)
                    {
                        continue;
                    }
                    else
                    {
                        msj(0);
                    }
                } else {
                    msj(-1);
                }
                break;
            case 3: //  Baja
                if((buscarEmptyEmpleado(agenda,QTY_EMPLEADOS,&contadorId,0))==0)
                {
                    printf("\n");
                    if((bajaEmpleado(agenda,QTY_EMPLEADOS))==0)
                    {
                        continue;
                    }
                    else
                    {
                        msj(0);
                    }
                }
                else
                {
                    msj(-1);

                }
                break;
            case 4://Listar
                if((buscarEmptyEmpleado(agenda,QTY_EMPLEADOS,&contadorId,0))==0)
                {
                    printf("\n");
                    accion=0;
                    do
                    {
                        utn_getUnsignedInt(" 1) Listado de los empleados ordenados alfabeticamente por apellido y sector.\n 2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n Ingrese el numero del informe que desea ver: ","",1,TEXT_SIZE,1,6,0,&accion);
                        switch(accion)
                        {
                            case 1:
                                printf("\n");
                                    if((ordenarPorApellidoYSectorEmpleados(agenda,QTY_EMPLEADOS))==0)
                                    {
                                        if((listarEmpleados(agenda,QTY_EMPLEADOS))==0)
                                        {
                                        continue;
                                        }
                                        else
                                        {
                                            msj(0);
                                        }
                                    }
                                printf("\n");
                                msj(1);
                                break;
                            case 2:
                                if((promediarSalarios(agenda,QTY_EMPLEADOS))==0)
                                {
                                    continue;
                                }
                                else
                                {
                                    msj(0);
                                }
                                break;
                            default:
                                msj(-3);
                        }
                    }
                    while(accion<1||accion>2);
                }
                else
                {
                    msj(-1);
                }
                break;
            case 5://Salir
                msj(2);
                break;
            default:    //Si ingresa otra opcion
                msj(-2);
        }
    }
    while(accion<1||accion>5);
    if(accion!=5)
    {
        mostrarMenu(agenda,contadorId);
    }
    return 0;
}


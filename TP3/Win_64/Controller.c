//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////
#include "LinkedList.h"
#include "Employee.h"
//////////////////////////////////////////////////////////////

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE *pArchivo;
    if((pArchivo=fopen(path,"r+b"))!=NULL)
    {
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno=0;
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE *pArchivo;
    if((pArchivo=fopen(path,"rb"))!=NULL)
    {
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        retorno=0;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        // HARDCODEO DE DATOS - EL ID DEBE SER AUTOMATICO
        char auxId[128]="";
        int ultIdMasUno=controller_getLastId(pArrayListEmployee)+1;
        itoa(ultIdMasUno,auxId,10);

        printf("auxId: %s\n",auxId);

        char auxNombre[128]="";
        char auxHorasTrabajadas[128]="";
        char auxSueldo[128]="";

        utn_getName("-Ingrese nombre: "," ERROR - Nombre invalido\n",1,128,2,&auxNombre);
        utn_getTexto("-Ingrese horas trabajadas: "," ERROR - Nombre invalido\n",1,128,2,&auxHorasTrabajadas);
        utn_getTexto("-Ingrese sueldo: "," ERROR - Nombre invalido\n",1,128,2,&auxSueldo);

        Employee* emp = employee_newParametros(&auxId,&auxNombre,&auxHorasTrabajadas,&auxSueldo);

        ll_add(pArrayListEmployee,emp);

        /*printf(" ID: %d\n Nombre: %s\n Horas trabajadas: %d\n Sueldo: %d\n\n",
               emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);*/

        retorno=0;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        // HARDCODEO DE DATOS - MODIFICAR PARA PERMITIRLE AL USUARIO INGRESAR DATOS, EL ID DEBE SER AUTOMATICO

        int auxId;
        char auxNombre[128];
        int auxHorasTrabajadas;
        int auxSueldo;

        Employee* emp;

        utn_getUnsignedInt("-Ingrese el ID del empleado a modificar: "," ERROR - ID invalido\n",0,1000,1,128,2,&auxId);

        printf("\n");
        if(controller_printEmployee(pArrayListEmployee,auxId-1)==0)
        {
            int option;
            utn_getUnsignedInt("-Ingrese el numero de la variable que desea modificar: ", " ERROR - Opcion incorrecta\n",1,3,1,3,2,&option);
            emp = ll_get(pArrayListEmployee,auxId-1);
            switch(option)
            {
                case 1:
                    utn_getName("-Ingrese nombre nuevo: "," ERROR - Nombre incorrecto\n",1,128,2,&auxNombre);
                    employee_setNombre(emp,auxNombre);
                    break;
                case 2:
                    utn_getUnsignedInt("-Ingrese horas trabajadas nuevas: "," ERROR - Dato incorrecto\n",1,128,1,999999,2,&auxHorasTrabajadas);
                    employee_setHorasTrabajadas(emp,auxHorasTrabajadas);
                    break;
                case 3:
                    utn_getUnsignedInt("-Ingrese sueldo nuevo: ","ERROR - Dato incorrecto\n",1,128,1,999999,2,&auxSueldo);
                    employee_setSueldo(emp,auxSueldo);
                    break;
                default:
                    printf(" ERROR - Opcion incorrecta\n");
                    break;
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        int id;
        utn_getUnsignedInt("-Ingrese el ID del empleado a dar de baja: "," ERROR - ID invalido\n",1,99999,1,19,2,&id);
        ll_remove(pArrayListEmployee,id-1); //id-1 porque la posicion siempre es 1 menos que el ID
        retorno=0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_listEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            controller_printEmployee(pArrayListEmployee,i);
        }
        retorno=0;
    }
    return retorno;
}


/** \brief Imprimir un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param i int
 * \return int
 *
 */
int controller_printEmployee(LinkedList* pArrayListEmployee, int i)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        Employee* auxEmp = employee_new();
        auxEmp = ll_get(pArrayListEmployee,i);

        int auxId;
        char auxNombre[128];
        int auxHorasTrabajadas;
        int auxSueldo;

        employee_getId(auxEmp,&auxId);
        employee_getNombre(auxEmp,&auxNombre);
        employee_getHorasTrabajadas(auxEmp,&auxHorasTrabajadas);
        employee_getSueldo(auxEmp,&auxSueldo);

        printf("    ID: %d\n 1) Nombre: %s\n 2) Horas trabajadas: %d\n 3) Sueldo: %d\n\n",
                auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        retorno=0;
    }
    return retorno;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,funcionCriterio,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        FILE* pFile;
        Employee* auxEmp;

        int auxId;
        int auxHoras;
        int auxSueldo;
        char auxNombre[120];

        pFile=fopen(path,"w");
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmp=(Employee*)ll_get(pArrayListEmployee,i);

            employee_getId(auxEmp,&auxId);
            employee_getNombre(auxEmp,auxNombre);
            employee_getHorasTrabajadas(auxEmp,&auxHoras);
            employee_getSueldo(auxEmp,&auxSueldo);

            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
        retorno=0;
        fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee!=NULL && path!="")
    {
        Employee* auxEmp;
        FILE *pArchivo;
        int r;
        if((pArchivo=fopen(path,"wb"))!=NULL)
        {
            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                auxEmp=ll_get(pArrayListEmployee,i);
                r = fwrite(auxEmp,sizeof(Employee),1,pArchivo);
            }
        }
        retorno=0;
        fclose(pArchivo);
    }
    return retorno;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int controller_getLastId(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        Employee* auxEmp = employee_new();
        int auxId;
        int idMasAlta;
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmp=ll_get(pArrayListEmployee,i);
            employee_getId(auxEmp,&auxId);

            if(idMasAlta<auxId)
            {
                idMasAlta=auxId;
            }
        }
        retorno=idMasAlta;
    }
    return retorno; //Si devuelve -1 es un error, si devuelve un numero positivo es una ID valida
}

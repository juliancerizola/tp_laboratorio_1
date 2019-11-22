//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////
#include "LinkedList.h"
#include "../testing/inc/Employee.h"
//////////////////////////////////////////////////////////////

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;

    int retorno=-1;
    int r;

    char auxId[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        auxEmp=employee_newParametros(&auxId,&auxNombre,&auxHorasTrabajadas,&auxSueldo);
        if(r==4)
        {
            if(auxEmp!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmp);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    int retorno=-1;
    while(!feof(pFile))
    {
        Employee* auxEmp = employee_new();
        r = fread(auxEmp,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee,auxEmp);
        retorno=0;
    }
    return retorno;
}

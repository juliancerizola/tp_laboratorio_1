#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}


Employee* employee_new()
{
    Employee* emp=(Employee*)malloc(sizeof(Employee));
    // No lo inicializo a través de los setters porque no necesito validar nada
    emp->id=0;
    strncpy(emp->nombre,"",128);
    emp->horasTrabajadas=0;
    emp->sueldo=0;

    return emp;
}
//////////////////////////////////////////////////////////////
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* emp=employee_new();

    int auxId=atoi(idStr);
    //char auxNombre[128];
    int auxHorasTrabajadas=atoi(horasTrabajadasStr);
    int auxSueldo=atoi(sueldoStr);

    employee_setId(emp,auxId);
    employee_setNombre(emp,nombreStr);
    employee_setHorasTrabajadas(emp,auxHorasTrabajadas);
    employee_setSueldo(emp,auxSueldo);

    /*printf(" ID: %d\n Nombre: %s\n Horas trabajadas: %d\n Sueldo: %d\n\n",
            auxId, nombreStr, auxHorasTrabajadas, auxSueldo);*/
    //fflush(stdout);

    return emp;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL&&id>=0)
    {
       this->id=id;
       retorno=0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////////
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL&&strlen(nombre)>3)
    {
        strncpy(this->nombre,nombre,128);
        retorno=0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////////
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL&&nombre!=NULL)
    {
        strncpy(nombre,this->nombre,128);
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL&&horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////////
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL&&horasTrabajadas>=0)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL&&sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////////
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL&&sueldo>=0)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int funcionCriterio(void* arg1, void* arg2)
{
    int retorno=0;     //Si no pasa la validación retorno -1

    if(arg1!=NULL&&arg2!=NULL)
    {
        Employee* pE1 = (Employee*)arg1;
        Employee* pE2 = (Employee*)arg2;

        int auxHorasTrabajadas1;
        int auxHorasTrabajadas2;

        employee_getHorasTrabajadas(pE1,&auxHorasTrabajadas1);
        employee_getHorasTrabajadas(pE2,&auxHorasTrabajadas2);

        //Si es numerico
        if(auxHorasTrabajadas1>auxHorasTrabajadas2)
        {
            retorno=1;       //Si es mayor pE1 retorno 1
        }
        else if(auxHorasTrabajadas1<auxHorasTrabajadas2)
        {
            retorno=-1;      //Si es mayor pE2 retorno 2
        }
        else
        {
            retorno=0;       //Si son iguales retorno 0
        }

        /*Si es texto
        retorno = strncmp(pE1->nombre,pE2->nombre);*/
    }
    return retorno;
}

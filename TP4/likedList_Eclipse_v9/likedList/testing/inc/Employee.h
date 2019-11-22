/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{

	//Dejo ambas variables porque unas pertenecen al tester y las otras fueron creadas por mí en el TP3
	int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    //int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    int isEmpty;

}typedef Employee;
#endif // __EMPLOYEE

int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(Employee* p);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
//////////////////////////////////////////////////////////////
void employee_delete();
//////////////////////////////////////////////////////////////
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
//////////////////////////////////////////////////////////////
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
//////////////////////////////////////////////////////////////
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
//////////////////////////////////////////////////////////////
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
//////////////////////////////////////////////////////////////
int funcionCriterio(void* arg1, void* arg2);

Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector);



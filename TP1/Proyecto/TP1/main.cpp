#include <iostream>
#include <stdio.h>
#include "aritmetica.h"
//TP Entregado
using namespace std;

void mostrarMenu(int , int );
int mostrarMenuOperaciones(int , int );
void mostrarMenuInformes(int , int );

int main()
{
    printf("    Bienvenide!\n\n");

    int num1=15;
    int num2=3;

    mostrarMenu(num1,num2);

    return 0;
}

void mostrarMenu(int a, int b)
{
    int accion;
    do{
    accion=0;
    printf(" 1- Ingresar numero 1 (Actualmente vale: %d)\n 2- Ingresar numero 2 (Actualmente vale: %d)\n 3- Realizar operaciones\n 4- Informar resultados\n 5- Salir\n\nPor favor ingrese el numero de la accion que desea realizar: ",a,b);
    scanf("%d",&accion);

    switch(accion)
    {
    case 1: //Pedir numero 1
        printf("Ingrese numero 1 (Actualmente vale: %d): ",a);
        scanf("%d",&a);
        printf("Hecho!\n\n");
        break;
    case 2: //Pedir numero 2
        printf("Ingrese numero 2 (Actualmente vale: %d): ",b);
        scanf("%d",&b);
        printf("Hecho!\n\n");
        break;
    case 3: //Realizar operaciones
        mostrarMenuOperaciones(a,b);
        break;
    case 4: //Informar resultados
        mostrarMenuInformes(a,b);

        break;
    case 5: //Salir

        break;
    default:
        printf("Algo salio mal!\n\n");
    }
    mostrarMenu(a,b);
    } while(accion<1 || accion>5);

}

int mostrarMenuOperaciones(int a, int b)
{
    char accion;
    printf("  a) Sumar %d + %d\n  b) Restar %d - %d\n  c) Multiplicar %d * %d\n  d) Dividir %d / %d\n\nPor favor ingrese la letra de la accion que desea realizar: ",a,b,a,b,a,b,a,b);
    scanf(" %c",&accion);

    if(accion=='a'){ //Suma
        printf("%d + %d = %d\n",a,b,sumar(a,b));
        printf("Hecho!\n\n");
    } else if (accion=='b'){ //Resta
        printf("%d + %d = %d\n",a,b,restar(a,b));
        printf("Hecho!\n\n");
    } else if (accion=='c'){ //Multiplicacion
        printf("%d + %d = %d\n",a,b,multiplicar(a,b));
        printf("Hecho!\n\n");
    } else if (accion=='d'){ //Division
        printf("%d + %d = %d\n",a,b,dividir(a,b));
        printf("Hecho!\n\n");
    } else {
        printf("Algo salio mal!\n\n");
    }
}

void mostrarMenuInformes(int a, int b)
{
    printf(" Resultados:\n  a) %d + %d = %d\n  b) %d - %d = %d\n  c) %d * %d = %d\n  d) %d / %d = %d\n Hecho!\n\n",a,b,sumar(a,b),a,b,restar(a,b),a,b,multiplicar(a,b),a,b,dividir(a,b));
}

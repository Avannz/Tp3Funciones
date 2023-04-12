#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila(Pila *pila);
void pasarPila(Pila *pila1, Pila *pila2);
void pasarOrdenada(Pila *pila1, Pila *pila2);
void ordenarSele(Pila *pila1);
void insertarValor(Pila *pila1, Pila *pila2);
void ordenarIns(Pila *pila1);
int pilaValidos(Pila *pila1);
int sumarPrimeros(Pila *pila1);
int buscarMenor(Pila *pila1);
int convertirPila(Pila *pila1);
float sumarElementos(Pila *pila1);
float dividirElementos(Pila *pila1);
float calcularPromedio(Pila *pila1);

int main()
{
    int menor, val1;
    float val2;
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    cargarPila(&dada);
    mostrar(&dada);
    val1 = convertirPila(&dada);
    printf("\nDADA: %d \n", val1);


}

void cargarPila(Pila *pila)
{
    char opc;
    do
    {
        leer(pila);
        printf("\ningrese 's' para seguir cargando valores...\n");
        fflush(stdin);
        scanf("%c", &opc);
    }
    while(opc == 's');
}

void pasarPila(Pila *pila1, Pila *pila2)
{
    while(!pilavacia(pila1))
    {
        apilar(pila2, desapilar(pila1));
    }
}

void pasarOrdenada(Pila *pila1, Pila *pila2)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pila1))
    {
        apilar(&aux, desapilar(pila1));
    }
    while(!pilavacia(&aux))
    {
        apilar(pila2, desapilar(&aux));
    }
}

int buscarMenor(Pila *pila1)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor, desapilar(pila1));
    while(!pilavacia(pila1))
    {
        if(tope(pila1) < tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(pila1));
        }
        else
        {
            apilar(&aux, desapilar(pila1));
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(pila1, desapilar(&aux));
    }

    return tope(&menor);

}

void ordenarSele(Pila *pila1)
{
    Pila aux, menor, ordenada;
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);

    do
    {
        if(!pilavacia(pila1))
        {
            apilar(&menor, desapilar(pila1));
        }
        while(!pilavacia(pila1))
        {
            if(tope(pila1) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(pila1));
            }
            else
            {
                apilar(&aux, desapilar(pila1));
            }
        }
        apilar(&ordenada, desapilar(&menor));
        if(!pilavacia(&aux))
        {
            while(!pilavacia(&aux))
            {
                apilar(pila1, desapilar(&aux));
            }
        }
    }
    while(!pilavacia(pila1));

    while(!pilavacia(&ordenada))
    {
        apilar(pila1, desapilar(&ordenada));
    }
}

void insertarValor(Pila *pila1, Pila *pila2)
{
    Pila aux;
    int flag = 0;
    inicpila(&aux);

    while(!pilavacia(pila1))
    {
        if(tope(pila1) < tope(pila2) && flag == 0)
        {
            apilar(&aux, desapilar(pila2));
            apilar(&aux, desapilar(pila1));
            flag = 1;
        }
        else
        {
            apilar(&aux, desapilar(pila1));
        }
    }

    if(flag == 0 && !pilavacia(pila2))
    {
        apilar(&aux, desapilar(pila2));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila1, desapilar(&aux));
    }
}

void ordenarIns(Pila *pila1)
{
    Pila aux1, aux2;
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&aux1, desapilar(pila1));
    while(!pilavacia(pila1))
    {
        apilar(&aux2, desapilar(pila1));
        insertarValor(&aux1, &aux2);

    }

    while(!pilavacia(&aux1))
    {
        apilar(pila1, desapilar(&aux1));
    }
}

int sumarPrimeros(Pila *pila1)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    apilar(&aux, desapilar(pila1));
    suma = tope(&aux) + tope(pila1);

    apilar(pila1, desapilar(&aux));

    return suma;
}

/** Saber cuántos elementos tiene Pila*/
int pilaValidos(Pila *pila1)
{
    Pila aux;
    inicpila(&aux);
    int i = 0;
    while(!pilavacia(pila1))
    {
        apilar(&aux, desapilar(pila1));
        i++;
    }

    return i;
}

float sumarElementos(Pila *pila1)
{
    Pila aux;
    inicpila(&aux);
    int suma=0;

    while(!pilavacia(pila1))
    {
        suma = tope(pila1)+suma;
        apilar(&aux, desapilar(pila1));
    }
    while(!pilavacia(&aux))
    {
        apilar(pila1, desapilar(&aux));
    }

    return suma;
}

float dividirElementos(Pila *pila1)
{
    float division = 0;
    division = sumarElementos(pila1) / pilaValidos(pila1);

    return division;
}

float calcularPromedio(Pila *pila1)
{
    float promedio = 0;
    promedio = dividirElementos(pila1);

    return promedio;
}

int convertirPila(Pila *pila1)
{
    Pila aux;
    inicpila(&aux);
    int res = 0;
    int mult = 0;
    int num = 0;
    int i=1;
    while(!pilavacia(pila1))
    {
        apilar(&aux, desapilar(pila1));
    }
    while(!pilavacia(&aux))
    {
        mult = tope(&aux) * i;
        num = num + mult;
        i = i * 10;
        mult = 0;
        apilar(pila1, desapilar(&aux));
    }

    return num;
}


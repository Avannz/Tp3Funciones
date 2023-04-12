#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila(Pila *pila);
void pasarPila(Pila *pila1, Pila *pila2);
void pasarOrdenada(Pila *pila1, Pila *pila2);
void ordenarSele(Pila *pila1);
void insertarValor(Pila *pila1, Pila *pila2);
void ordenarIns(Pila *pila1);
int buscarMenor(Pila *pila1);

int main()
{
    int menor, val1;
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    cargarPila(&dada);
    mostrar(&dada);
    ordenarIns(&dada);
    mostrar(&dada);

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

    while(!pilavacia(&aux1)){
        apilar(pila1, desapilar(&aux1));
    }
}


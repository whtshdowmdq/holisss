#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#include <conio.h>

void cargaUsuario (Pila *p, int dias);
void cargarRandom (Pila *p, int dias);
int separarPrecipitaciones (Pila *p, Pila *o, int A [], int validos);
float promedioPrecipitaciones (int A[], int validos);
float portcentajePrecipitaciones (Pila *o);
void invocacionFunciones (float promedio, float porcentaje);
int busquedaValorMaximo (int A[], int validos );

int main()
{

    srand(time(NULL));
    int arregloA [30];
    int validos = 0;
    Pila precipitaciones;
    Pila aux;
    inicpila(&precipitaciones);
    inicpila(&aux);
    int parametro, busquedaMayor;
    float promedioPrep, porcentajePrep;

    printf("ingrese la cantidad de dias a cargar\n");
    scanf("%d", &parametro);
    //cargaUsuario(&precipitaciones, parametro);
    //mostrar(&precipitaciones);
    cargarRandom (&precipitaciones, parametro);
    mostrar(&precipitaciones);

    validos = separarPrecipitaciones(&precipitaciones,&aux,arregloA,30);
    promedioPrep = promedioPrecipitaciones(arregloA, validos);
    porcentajePrep = portcentajePrecipitaciones(&aux);
    invocacionFunciones(promedioPrep, porcentajePrep);

    busquedaMayor = busquedaValorMaximo(arregloA, validos);
    printf("La busqueda del mayor es: %d\n", busquedaMayor);

    return 0;
}

void cargaUsuario (Pila *p, int dias)
{
    int i, datos;
    for (i = 0; i < dias; i++)
    {
        printf("Ingrese el dato");
        scanf("%d", &datos);
        apilar(p, datos);
    }
}

void cargarRandom (Pila *p, int dias)
{
    int i, datos;
    for (i = 0; i < dias; i++)
    {
        apilar(p, rand()%181);
    }
}

int separarPrecipitaciones (Pila *p, Pila *o, int A [], int validos)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    int i =0, j = 0;
    while (!pilavacia(p)&& i < validos)
    {
        if (tope(p) <= 60 )
        {
            apilar(o, desapilar(p));

        }
        else
        {
            A[i] = tope(p);
            i++;
            apilar (&aux2, desapilar(p));
        }

    }
    for (j ; j< i; j++)
    {
        printf("%d - ",A[j]);
    }
    return j;
}
float promedioPrecipitaciones (int A[], int validos)
{
    int i;
    float promedio = 0;
    float suma = 0;

    for (i = 0; i < validos; i++)
    {
        suma = A[i] + suma;
    }
    promedio = suma / validos;
    return promedio;
}

float portcentajePrecipitaciones (Pila *o)
{
    int menor =0, i = 0;
    float porcentaje, parametroPorcentaje;
    Pila aux;
    inicpila(&aux);
    printf("\n ingrese el parametro a calcular:\n");
    scanf("%f", &parametroPorcentaje);
    while (!pilavacia(o))
    {
        if (tope(o)< parametroPorcentaje)
        {
            menor++;
        }
        apilar(&aux, desapilar(o));
        i++;
    }
    porcentaje = (menor * 100)/i;
    return porcentaje;
}
void invocacionFunciones (float promedio, float porcentaje)
{
   printf("El promedio es: %.2f\n", promedio);
   printf("El porcentaje es: %.2f\n", porcentaje);
}
int busquedaValorMaximo (int A[], int validos )
{
    int i,mayor;
    mayor = A[0];
    for (i =0; i< validos; i++)
    {
        if (mayor < A[i])
        {
            mayor = A[i];
        }
    }
    return mayor;
}
int busquedaValorMenor (pila *p)
{
    int aux;

    apilar(aux, desapilar(p));
    while (!pilavacia(p))
    {
        if (tope(p))
    }
}

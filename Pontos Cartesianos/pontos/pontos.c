#include "pontos.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos_{
    double x;
    double y;
};

PONTOS* criar(double x, double y)
{
    PONTOS *pontos = (PONTOS*)calloc(1,sizeof(PONTOS));
    if(pontos == NULL)
    {
        printf("Erro de alocação de memória!");
        return NULL;
    }

    pontos->x = x;
    pontos->y = y;

    return pontos;
}

double* distancia(PONTOS* ponto_inicial, PONTOS* ponto_final, double* resultado_anterior)
{
    double *resultado = (double*)calloc(1,sizeof(double));

   // d = sqrt((Xf - Xi)² + (Yf - Yi)² ) 
    *resultado = sqrt(pow((ponto_final->x - ponto_inicial->x), 2) + pow((ponto_final->y - ponto_inicial->y), 2));
    *resultado += *resultado_anterior;

    free(resultado_anterior);

    return resultado;
}

void imprimir(double* resultado)
{
    printf("%.2lf\n", *resultado);
}

void apagar_pontos(PONTOS* ponto)
{
    free(ponto);
}

void apagar_resultado(double* resultado)
{
    free(resultado);
}
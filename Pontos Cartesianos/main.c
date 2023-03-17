#include "pontos/pontos.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Inicializando as variáveis
    int* quantidade_de_pontos = (int*)calloc(1, sizeof(int));
    double* ponto_x = (double*)calloc(1,sizeof(double));
    double* ponto_y = (double*)calloc(1,sizeof(double));
    double *resultado = (double*)calloc(1, sizeof(double));
    PONTOS *ponto_inicial;
    PONTOS *ponto_final;

    scanf("%d", quantidade_de_pontos);

    if(quantidade_de_pontos > 0)
    {
        scanf("%lf %lf", ponto_x, ponto_y);
        ponto_inicial = criar(*ponto_x, *ponto_y);

        for(int i = 0; i < *quantidade_de_pontos - 1; i++)
        {
            scanf("%lf %lf", ponto_x, ponto_y);
            apagar_pontos(ponto_final);
            ponto_final = criar(*ponto_x, *ponto_y);

            resultado = distancia(ponto_inicial, ponto_final, resultado);

            apagar_pontos(ponto_inicial);
            ponto_inicial = criar(*ponto_x, *ponto_y);
        }
    }

    imprimir(resultado);

    free(ponto_x);
    free(ponto_y);
    apagar_pontos(ponto_inicial);
    apagar_pontos(ponto_final);
    apagar_resultado(resultado);
    free(quantidade_de_pontos);

    return 0;
}
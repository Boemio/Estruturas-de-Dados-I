#ifndef PONTOS_H
#define PONTOS_H

typedef struct pontos_ PONTOS;

PONTOS* criar(double x, double y);
double* distancia(PONTOS* ponto_a, PONTOS* ponto_b, double* resultado_anterior);
void imprimir(double* resultado);
void apagar_pontos(PONTOS* ponto);
void apagar_resultado(double *resultado);


#endif //PONTOS_H

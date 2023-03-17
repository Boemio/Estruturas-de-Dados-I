#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void boolean_print(boolean boleano)
{
    if(boleano == TRUE)
    {
        printf("TRUE\n");
    }
    else if(boleano == FALSE)
    {
        printf("FALSE\n");
    }
    else
    {
        printf("ERRO\n");
    }
}

int chartoint(char *simbolo)
{
    int numero;

    if(strcmp(simbolo, "1") == 0)
    {
        numero = 1;
    }
    else if(strcmp(simbolo, "2") == 0)
    {
        numero = 2;
    }
    else if(strcmp(simbolo, "3") == 0)
    {
        numero = 3;
    }
    else if(strcmp(simbolo, "4") == 0)
    {
        numero = 4;
    }
    else if(strcmp(simbolo, "5") == 0)
    {
        numero = 5;
    }
    else if(strcmp(simbolo, "6") == 0)
    {
        numero = 6;
    }
    else if(strcmp(simbolo, "7") == 0)
    {
        numero = 7;
    }
    else if(strcmp(simbolo, "8") == 0)
    {
        numero = 8;
    }
    else if(strcmp(simbolo, "9") == 0)
    {
        numero = 9;
    }
    else if(strcmp(simbolo, "10") == 0)
    {
        numero = 10;
    }
    
    return numero;
}
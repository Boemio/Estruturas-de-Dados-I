#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void boolean_print(boolean bool)
{
    if(bool == TRUE)
    {
        printf("TRUE\n");
    }
    else if(bool == FALSE)
    {
        printf("FALSE\n");
    }
    else
    {
        printf("ERRO\n");
    }
}

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF) && (currentInput != ' '));
    string[index - 1] = '\0';
    return string;
}

int chartoint(char simbolo)
{
    int numero;

    if(simbolo == '1')
    {
        numero = 1;
    }
    else if(simbolo == '2')
    {
        numero = 2;
    }
    else if(simbolo == '3')
    {
        numero = 3;
    }
    else if(simbolo == '4')
    {
        numero = 4;
    }
    else if(simbolo == '5')
    {
        numero = 5;
    }
    else if(simbolo == '6')
    {
        numero = 6;
    }
    else if(simbolo == '7')
    {
        numero = 7;
    }
    else if(simbolo == '8')
    {
        numero = 8;
    }
    else if(simbolo == '9')
    {
        numero = 9;
    }
    else if(simbolo == '0')
    {
        numero = 0;
    }
    
    return numero;
}
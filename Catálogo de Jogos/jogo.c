#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogo_st
{
    char nome_jogo[30];
    char nome_produtora[30];
    int ano;
};

JOGO *jogo_criar(char *nome_jogo, char *nome_produtora, int ano)
{
    JOGO *jogo;

    jogo = (JOGO*)calloc(1,sizeof(JOGO));

    if(jogo != NULL)
    {
        strcpy(jogo->nome_jogo, nome_jogo);
        strcpy(jogo->nome_produtora, nome_produtora);
        jogo->ano = ano;

        return jogo;
    }

    return NULL;
}

JOGO *jogo_ler_std_in()
{
    char *nome;
    char *empresa;
    int ano;
    
    nome = readLine();
    if(strcmp(nome, "F") == 0)
    {
        return NULL;
    }
    empresa = readLine();
    scanf ("%d", &ano);
    while(getchar() != '\n');

    return jogo_criar(nome, empresa, ano);
}

boolean jogo_apagar(JOGO **jogo)
{
    if(*jogo != NULL)
    {
        strcpy((*jogo)->nome_jogo, "ERRO");
        free(*jogo);
        *jogo = NULL;

        return TRUE;
    }

    return FALSE;
}

void jogo_imprimir(JOGO* jogo)
{
    if(jogo != NULL)
    {
        printf("%s\n", jogo->nome_jogo);
    }
}

int jogo_get_ano(JOGO *jogo)
{
    if(jogo != NULL)
    {
        return jogo->ano;
    }
    return ERRO;
}

char* jogo_get_produtora(JOGO *jogo)
{
    if(jogo != NULL)
    {
        return jogo->nome_produtora;
    }
    return NULL;
}

char* jogo_get_nome(JOGO *jogo)
{
    if(jogo != NULL)
    {
        return jogo->nome_jogo;
    }
    return NULL;
}
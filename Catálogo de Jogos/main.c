#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void funcaoCatalogo();

int main()
{
    funcaoCatalogo();
}

void funcaoCatalogo()
{
    boolean trueorfalse;
    LISTA *lista;
    lista = lista_criar();
    JOGO *jogo = NULL;

    do
    {
        jogo = jogo_ler_std_in();      
        if(jogo != NULL)
        {
            trueorfalse = lista_inserir(lista, jogo);
            if(trueorfalse == FALSE)
            {
                printf("Erro ao inserir o jogo na lista!\n");
                exit(1);
            }
        } 
    }while(jogo != NULL);

    do
    {
        trueorfalse = lista_busca_sequencial(lista);
    } while(trueorfalse == TRUE);

    free(jogo);
    lista_apagar(&lista);
}
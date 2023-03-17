#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

struct item_st
{
    int chave;
    int numero;
};

ITEM *item_criar (int chave, const int numero)
{
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL)
    {
        item->chave = chave;
        item->numero = numero;
        return item;
    }
    return NULL;
}

boolean item_apagar(ITEM **item)
{
    if (*item != NULL)
    {
        (*item)->chave = ERRO; /*apaga o item simbolicamente*/
        free (*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

int item_get_chave(const ITEM *item)
{
    if (item != NULL)
    {
        return item->chave;
    }
    return ERRO;
}

int item_get_numero(const ITEM *item)
{
    if (item != NULL)
    {
        return item->numero;
    }
    return ERRO;
}


boolean item_set_chave(ITEM *item, int chave)
{
    if (item != NULL){
        item->chave = chave;
        return TRUE;
    }
    return FALSE;
}


void item_imprimir(const ITEM *item)
{
    if (item != NULL)
    {
        printf("%d", item->numero);
    }
}
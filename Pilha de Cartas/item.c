#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

struct item_st
{
    int simbolo;
};

ITEM *item_criar (int simbolo)
{
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL)
    {
        item->simbolo = simbolo;
        return item;
    }
    return NULL;
}

boolean item_apagar(ITEM **item)
{
    if (*item != NULL)
    {
        (*item)->simbolo = ERRO; /*apaga o item simbolicamente*/
        free (*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

int item_get_simbolo(const ITEM *item)
{
    if (item != NULL)
    {
        return item->simbolo;
    }
    return ERRO;
}


boolean item_set_simbolo(ITEM *item, int simbolo)
{
    if (item != NULL){
        item->simbolo = simbolo;
        return TRUE;
    }
    return FALSE;
}


void item_imprimir(const ITEM *item)
{
    if (item != NULL)
    {
        printf("%d\n", item->simbolo);
    }
}

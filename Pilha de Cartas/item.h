#ifndef ITEM_H
#define ITEM_H

#include "util.h"

#define ERRO (-32000)

typedef struct item_st ITEM;

ITEM *item_criar (int simbolo);
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_simbolo(const ITEM *item);
boolean item_set_simbolo(ITEM *item, int simbolo);

#endif //ITEM_H

#ifndef ITEM_H
#define ITEM_H

#include "util.h"

#define ERRO (-32000)

typedef struct item_st ITEM;

ITEM *item_criar (int chave, const int numero);
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_chave(const ITEM *item);
int item_get_numero(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);

#endif //ITEM_H;

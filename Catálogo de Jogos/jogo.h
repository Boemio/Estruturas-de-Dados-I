#ifndef JOGO_H
#define JOGO_H

#include "util.h"

#define ERRO (-32000)

typedef struct jogo_st JOGO;

JOGO *jogo_criar(char *nome_jogo, char *nome_produtora, int ano);
JOGO *jogo_ler_std_in();
boolean jogo_apagar(JOGO **jogo);
void jogo_imprimir(JOGO *jogo);
int jogo_get_ano(JOGO *jogo);
char* jogo_get_produtora(JOGO *jogo);
char* jogo_get_nome(JOGO *jogo);

#endif //JOGO_H
#ifndef LISTA_H
#define LISTA_H

#include "util.h"
#include "jogo.h"

#define TAM_MAX 100
#define INICIO 0
#define ERRO (-32000)

typedef struct lista LISTA;

LISTA* lista_criar();
int lista_inserir(LISTA *lista, JOGO* jogo);
boolean lista_inserir_posicao(LISTA *lista, int posicao, JOGO *jogo);
boolean lista_apagar(LISTA **lista);
boolean lista_remover(LISTA* lista);
int lista_tamanho(LISTA *lista);
boolean lista_vazia(LISTA *lista);
boolean lista_cheia(LISTA *lista);
void lista_imprimir(LISTA *Lista);
boolean lista_busca_sequencial(LISTA *lista);
void lista_busca_sequencial_ano(LISTA *lista, int ano);
void lista_busca_sequencial_produtora(LISTA *lista, char *produtora);

#endif //LISTA_H
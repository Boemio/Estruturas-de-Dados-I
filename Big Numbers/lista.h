#ifndef LISTA_H
#define LISTA_H

#include "util.h"
#include "item.h"

#define ERRO (-32000)

typedef struct lista LISTA;
typedef struct node_st NODE;


LISTA* lista_criar(); 
int lista_inserir(LISTA *lista, ITEM* item); 
boolean lista_remover_item(LISTA* lista, int chave); 
boolean lista_apagar(LISTA** lista, int n);
int lista_tamanho(const LISTA *lista); 
boolean lista_vazia(const LISTA* lista); 
ITEM* lista_busca_sequencial(const LISTA *lista, int chave); 
void big_numbers(int n);
LISTA* big_number_to_int(char* big_number);
void imprimir_big_number(const LISTA* lista);
void big_number_operacoes(const LISTA* primeiro_big_number, const LISTA* segundo_big_number, const char* operacao);

#endif //LISTA_H


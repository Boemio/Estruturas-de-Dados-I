#ifndef TADGENERICO_ARVOREBINARIA_H
#define TADGENERICO_ARVOREBINARIA_H

#include "item.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

#define COUNT 8
typedef struct node_st NODE;
typedef struct arvore_binaria ARVORE_BINARIA;

ARVORE_BINARIA *arvore_binaria_criar();
NODE* cria_no(ITEM *item);
void pre_ordem_recursao(NODE *raiz);
void em_ordem_recursao(NODE *raiz);
void pos_ordem_recursao(NODE *raiz);
void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria);
NODE *ab_inserir_no(NODE *raiz, ITEM *item, int lado, long long int chave);
boolean arvore_binaria_inserir(ARVORE_BINARIA *T, ITEM *item, int lado, long long int chave);
int ab_profundidade(NODE *no);
void apagar_arvore(NODE **raiz);
void ab_apagar_arvore(ARVORE_BINARIA **T);
NODE *abb_inserir_no(NODE *raiz, ITEM *item);
boolean ehMenor(const NODE *raiz, const ITEM *item);
boolean ehMaior(const NODE *raiz, const ITEM *item);
boolean abb_inserir (ARVORE_BINARIA *T, ITEM *item);
ITEM *abb_busca_no(NODE *raiz, long long int chave);
ITEM *abb_busca(ARVORE_BINARIA *T, long long int chave);
boolean abb_remover_aux (NODE **raiz, long long int chave);
boolean arvore_binaria_remover(ARVORE_BINARIA *T, long long int chave);
void troca_min_dir(NODE *troca, NODE *raiz, NODE *ant);
void print2DUtil(NODE *root, int space);
void arvore_binaria_imprimir(ARVORE_BINARIA *root);
void inserir_items(ARVORE_BINARIA *arvoreBinaria, int qtd);
void operacoes_bancarias();

#endif //TADGENERICO_ARVOREBINARIA_H

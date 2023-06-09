#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE *anterior;
};

struct pilha {
    NODE *topo;
    int tamanho;
};

static void pilha_remove_tudo(PILHA *const *pilha);

static void pilha_remove_topo(PILHA *const *pilha);

PILHA *pilha_criar()
{
    PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));
    if(pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

boolean pilha_vazia(const PILHA *pilha)
{
    if(pilha != NULL)
    {
        return pilha->tamanho == 0;
    }
    return ERRO_PILHA;
}

boolean pilha_cheia(const PILHA *pilha) {
    if(pilha != NULL)
    {
        return FALSE;
    }
    return ERRO_PILHA;
}

int pilha_tamanho(const PILHA *pilha) {
    if(pilha != NULL)
    {
        return pilha->tamanho;
    }
    return ERRO_PILHA;
}

int pilha_empilhar(PILHA *pilha, ITEM *item)
{
    if (pilha!=NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if(novoNode != NULL)
        {
            novoNode->item = item;
            novoNode->anterior = pilha->topo;
            pilha->topo = novoNode;
            pilha->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

ITEM *pilha_topo(const PILHA *pilha) {
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        return pilha->topo->item;
    }
    return NULL;
}

ITEM *pilha_desempilhar(PILHA *pilha) {
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        NODE *desempilhado = pilha->topo;
        ITEM *item = pilha->topo->item;
        pilha->topo = pilha->topo->anterior;
        desempilhado->anterior = NULL;
        free(desempilhado);
        desempilhado = NULL;
        pilha->tamanho--;
        return item;
    }
    return NULL;
}

boolean pilha_apagar(PILHA **pilha)
{
    if ((*pilha != NULL) && (!pilha_vazia(*pilha)))
    {
        pilha_remove_tudo(pilha);
        free(*pilha);
        *pilha = NULL;
        return TRUE;
    }
    return FALSE;
}

static void pilha_remove_tudo(PILHA *const *pilha) {
    while((*pilha)->topo != NULL)
    {
        pilha_remove_topo(pilha);
    }
}

static void pilha_remove_topo(PILHA *const *pilha) {
    NODE *temporaryNode;
    temporaryNode = (*pilha)->topo;
    (*pilha)->topo = (*pilha)->topo->anterior;
    item_apagar(&temporaryNode->item);
    temporaryNode->anterior = NULL;
    free(temporaryNode);
    temporaryNode = NULL;
}

void blackjack()
{
    PILHA *pilha;
    ITEM *item;
    char naipe[30];
    char simbolo[3];
    int contador = 0;

    pilha = pilha_criar();

    for(int i = 0; i < 52; i++) // Empilha as 52 cartas
    {
        scanf("%s %s", naipe, simbolo);
        while(getchar() != '\n');

        if(strcmp(simbolo, "V") == 0 || strcmp(simbolo, "D") == 0 || strcmp(simbolo, "R") == 0)
        {
            item = item_criar(10);
        }
        else
        {
            item = item_criar(chartoint(simbolo));
        }

        pilha_empilhar(pilha, item);
    }

    for(int i = 0; i < 52; i++)
    {
        contador += item_get_simbolo(pilha_topo(pilha));
        pilha_desempilhar(pilha);
        if(contador == 21)
        {
            printf("Ganhou ;)\n");
            break;
        }
        else if(contador > 21)
        {
            printf("Perdeu :(\nSoma :: %d\n", contador);
            break;
        }
    }

    pilha_apagar(&pilha);
    item_apagar(&item);
}
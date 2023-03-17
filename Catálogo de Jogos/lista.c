#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    JOGO *jogos[TAM_MAX];
    int inicio;
    int fim;
};

static boolean posicao_valida(LISTA *l, int pos);

static void move_itens_a_direita(LISTA *l, int pos);

static void lista_remove_tudo(LISTA *lista);

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*)malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->inicio = INICIO;
        lista->fim = lista->inicio;
    }

    return lista;
}

boolean lista_inserir(LISTA *lista, JOGO *jogo)
{
    if((lista != NULL) && !lista_cheia(lista))
    {
        (lista->jogos[lista->fim]) = jogo;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

boolean lista_cheia(LISTA *lista)
{
    return lista->fim >= TAM_MAX;
}

boolean lista_vazia(LISTA *lista)
{
    return lista->fim == INICIO;
}

boolean lista_inserir_posicao(LISTA *lista, int posicao, JOGO *jogo)
{
    if(!lista_cheia(lista) && posicao_valida(lista, posicao))
    {
        move_itens_a_direita(lista, posicao);
        lista->jogos[posicao] = jogo;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

boolean lista_busca_sequencial(LISTA *lista)
{
    char opt;

    scanf("%c", &opt);
    while(getchar() != '\n');

    if(opt == 'A')
    {
        int ano;

        scanf("%d", &ano);
        while(getchar() != '\n');

        lista_busca_sequencial_ano(lista, ano);
        return TRUE;
    }
    else if(opt == 'E')
    {
        char *nome_produtora;
        nome_produtora = readLine();
        lista_busca_sequencial_produtora(lista, nome_produtora);
        return TRUE;
    }
    else if(opt == 'F')
    {
        return FALSE;
    }

    return FALSE;
}

void lista_busca_sequencial_ano(LISTA *lista, int ano)
{
    int counter = 0;
    
    for(int i = 0; i < lista->fim; i++)
    {
        if(jogo_get_ano(lista->jogos[i]) == ano)
        {
            jogo_imprimir(lista->jogos[i]);
            counter++;
        }
    }

    if(counter == 0)
    {
        printf("Nada encontrado\n");
    }
}

void lista_busca_sequencial_produtora(LISTA *lista, char *produtora)
{
    int counter = 0;
    if(produtora != NULL)
    {
        for(int i = 0; i < lista->fim; i++)
        {
            if(strcmp(jogo_get_produtora(lista->jogos[i]), produtora) == 0)
            {
                jogo_imprimir(lista->jogos[i]);
                counter++;
            }
        }
    }
    if(counter == 0)
    {
        printf("Nada encontrado\n");
    }
}

static boolean posicao_valida(LISTA *l, int pos)
{
    return pos < l->fim;
}

static void move_itens_a_direita(LISTA *l, int pos)
{
    for(int i = (l->fim -1); i >= pos; i--)
    {
        l->jogos[i+1] = l->jogos[i];
    }
}

boolean lista_apagar(LISTA **lista)
{
    if((*lista != NULL) && (!lista_vazia(*lista)))
    {
        lista_remove_tudo(*lista);
        free (*lista);
        *lista = NULL;
        return TRUE;
    }
    return FALSE;
}

static void lista_remove_tudo(LISTA *lista)
{
    for(int i = 0; i < lista->fim; ++i)
    {
        jogo_apagar(&lista->jogos[i]);
        lista->jogos[i] = NULL;
    }
    lista->fim = INICIO;
}
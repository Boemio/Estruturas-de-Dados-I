#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "item.h"
#include "util.h"

struct item_st
{
    char *cpf;
    long long int cpf_int;
    char *nome;
    int idade;
    double saldo;
};

ITEM *item_criar_vazio()
{
    ITEM *item;

    item = (ITEM *) calloc(sizeof(ITEM), 1);
    return item;
}

ITEM *item_criar (char *cpf, long long int cpf_int, char *nome, int idade, double saldo)
{
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));
    item->cpf = (char*) malloc (sizeof(char)*(strlen(cpf)+1)); 
    item->nome = (char*) malloc (sizeof(char)*(strlen(nome)+1)); 

    if (item != NULL)
    {
        strcpy(item->cpf, cpf);
        item->cpf_int = cpf_int;
        strcpy(item->nome, nome);
        item->idade = idade;
        item->saldo = saldo;
        free(cpf);
        free(nome);
        return item;
    }
    return NULL;
}

ITEM *item_ler_std_in()
{
    ITEM item;

    item.cpf = readLine();
    item.cpf_int = ler_cpf(item.cpf);
    item.nome = readLine();
    scanf("%d", &(item.idade));
    getchar();
    scanf("%lf ", &(item.saldo));

    return item_criar(item.cpf, item.cpf_int, item.nome, item.idade, item.saldo);
}

boolean item_apagar(ITEM **item)
{
    if (*item != NULL)
    {
        (*item)->cpf_int = ERRO; /*apaga o item simbolicamente*/
        free((*item)->cpf);
        free((*item)->nome);
        free (*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

long long int item_get_chave(const ITEM *item)
{
    if (item != NULL)
    {
        return item->cpf_int;
    }
    return ERRO;
}


boolean item_set_chave(ITEM *item, long long int chave)
{
    if (item != NULL){
        item->cpf_int = chave;
        return TRUE;
    }
    return FALSE;
}


void item_imprimir(const ITEM *item)
{
    if (item != NULL)
    {
        printf("Conta :: %s\n", item->nome);
        printf("CPF :: %s\n", item->cpf);
        printf("Idade :: %d\n", item->idade);
        printf("Saldo atual :: R$ %.2lf\n", item->saldo);
    }
}

long long int ler_cpf(char *str)
{
    char *ptr;
    ptr = str;
    long long int number = 0;
    long long int counter = pow(10,9);

    while (*ptr) { // While there are more characters to process...
        if ( isdigit(*ptr) ) {
            // Found a number
            int val = (int)strtol(ptr,&ptr, 10); // Read number
            number += val*counter;
            if(counter == 1000)
            {
                counter /= 100;
            }
            else
            {
                counter /= 1000;
            }
        } else {
            // Otherwise, move on to the next character.
            ptr++;
        }
    }

    number /= 10;

    return number;
}
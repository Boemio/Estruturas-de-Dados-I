#ifndef TADGENERICO_ITEM_H
#define TADGENERICO_ITEM_H

#define ERRO (-32000)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct item_st ITEM;

ITEM *item_criar_vazio();
ITEM *item_criar (char *cpf, long long int cpf_int, char *nome, int idade, double saldo);
ITEM *item_ler_std_in();
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
long long int item_get_chave(const ITEM *item);
boolean item_set_chave(ITEM *item, long long int chave);
long long int ler_cpf(char *str);

#endif //TADGENERICO_ITEM_H

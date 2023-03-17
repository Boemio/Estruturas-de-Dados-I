#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista.h"
#include "item.h"

struct node_st
{
    ITEM* item;
    NODE* proximo;
};

struct lista {
    NODE* inicio;
    NODE* fim;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

boolean lista_vazia(const LISTA *lista)
{
    if(lista != NULL)
    {
        return lista->inicio == NULL;
    }
    return ERRO;
}

int lista_tamanho(const LISTA *lista) {
    if(lista != NULL)
    {
        return lista->tamanho;
    }
    return ERRO;
}

int lista_inserir(LISTA *lista, ITEM *item)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = NULL;
            if(lista_vazia(lista))
            {
                lista->inicio = novoNode;
            }
            else
            {
                lista->fim->proximo = novoNode;
            }
            lista->fim = novoNode;
            lista->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

ITEM *lista_busca_sequencial(const LISTA *lista, int chave) {
    if (lista != NULL) {
        NODE *noAtual;
        noAtual = lista->inicio;
        while(noAtual != NULL)
        {
            if(item_get_chave(noAtual->item) == chave)
            {
                return noAtual->item;
            }
            noAtual = noAtual->proximo;
        }
    }
    return NULL;
}

boolean lista_apagar(LISTA** lista, int n)
{
    if ((*lista != NULL) && (!lista_vazia(*lista)))
    {
        for(int i = 0; i < n; i++)
        {
            lista_remover_item(*lista, i);
        }
        free (*lista);
        *lista = NULL;
        return TRUE;
    }

    return FALSE;
}

boolean lista_remover_item(LISTA *lista, int chave) {
    if (lista != NULL) {
        NODE *noAtual;
        NODE *noAnterior = NULL;
        noAtual = lista->inicio;
        while(noAtual != NULL && (item_get_chave(noAtual->item) != chave))
        {
            noAnterior = noAtual;
            noAtual = noAtual->proximo;
        }
        if(noAtual != NULL)
        {
            if(noAtual == lista->inicio)
            {
                lista->inicio = noAtual->proximo;
                noAtual->proximo = NULL;
            }
            else
            {
                noAnterior->proximo = noAtual->proximo;
                noAtual->proximo = NULL;
            }
            if(lista->fim == noAtual)
            {
                lista->fim = noAnterior;
            }
            return TRUE;
        }
    }
    return FALSE;
}

void big_numbers(int n)
{
    // Declaração de variáveis
    LISTA* primeiro_numero;
    LISTA* segundo_numero;
    char* operacao;
    char* big_number;
    char* big_number2;

    for(int i = 0; i < n; i++)
    {
        primeiro_numero = lista_criar();
        segundo_numero = lista_criar();

        operacao = readLine();
        big_number = readLine();
        big_number2 = readLine();

        primeiro_numero = big_number_to_int(big_number);
        segundo_numero = big_number_to_int(big_number2);

        big_number_operacoes(primeiro_numero, segundo_numero, operacao);

        free(operacao);
        free(big_number);
        free(big_number2);
        lista_apagar(&primeiro_numero, lista_tamanho(primeiro_numero));
        lista_apagar(&segundo_numero, lista_tamanho(segundo_numero));
    }
    
}

LISTA* big_number_to_int(char* big_number)
{
    LISTA* list_big_number;
    ITEM* divided_big_number;
    int numero = 0;
    int primeiro_numero = 0;
    int check = 0;
    int chave = 0;
    int sinal = 1;

    list_big_number = lista_criar();

    for(int i = 1; i <= strlen(big_number); i++)
    {
        if((big_number[0] == '-') && (check == 0))
        {
            check = 1;
            sinal = -1;
            i++;
        }

        numero = chartoint(big_number[i-1])*sinal;
        if(numero != 0 || primeiro_numero != 0 || i == strlen(big_number))
        {
            divided_big_number = item_criar(chave, numero);
            lista_inserir(list_big_number, divided_big_number);
            chave++;
            primeiro_numero = 1;
        }
        numero = 0;
    }

    return list_big_number;
}

void imprimir_big_number(const LISTA* lista)
{
    int primeiro_numero = 0;

    for(int i = lista_tamanho(lista)-1; i >= 0; i--)
    {  
        if((item_get_numero(lista_busca_sequencial(lista, i)) != 0) || primeiro_numero != 0)
        {
            item_imprimir(lista_busca_sequencial(lista, i));
            primeiro_numero = 1;
        }
    }
    printf("\n");
}

void big_number_operacoes(const LISTA* primeiro_big_number, const LISTA* segundo_big_number, const char* operacao)
{
    int trueorfalse = TRUE;
    ITEM* total;
    LISTA* resultado;
    int total_aux = 0;
    int diferenca = 0;
    int primeiro_numero = 0;
    int segundo_numero = 0;
    int chave = 0;
    int resto = 0;
    int sinal = 0;

    resultado = lista_criar();

    // {soma, maior, menor, igual}

    if(strcmp(operacao, "igual") == 0)
    {
        if(lista_tamanho(primeiro_big_number) != lista_tamanho(segundo_big_number))
        {
            printf("Resultado :: False\n");
        }
        else
        {
            for(int i = 0; i < lista_tamanho(primeiro_big_number) && trueorfalse == TRUE; i++)
            {
                if(item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) != item_get_numero(lista_busca_sequencial(segundo_big_number, i)))
                {
                    printf("Resultado :: False\n");
                    trueorfalse = FALSE;
                }
            }

            if(trueorfalse == TRUE)
            {
                printf("Resultado :: True\n");
            }
        }
    }

    else if(strcmp(operacao, "menor") == 0)
    {
        if((lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) > 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))> 0))
        {
            printf("Resultado :: False\n");
        }
        else if((lista_tamanho(primeiro_big_number) < lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) > 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))> 0))
        {
            printf("Resultado :: True\n");
        }
        else if((lista_tamanho(primeiro_big_number) < lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) < 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))< 0))
        {
            printf("Resultado :: False\n");
        }
        else if((lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) < 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))< 0))
        {
            printf("Resultado :: True\n");
        }
        else if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) > 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))< 0))
        {
            printf("Resultado :: False\n");
        }
        else if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) < 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))> 0))
        {
            printf("Resultado :: True\n");
        }
        else
        {
            for(int i = 0; i < lista_tamanho(primeiro_big_number) && trueorfalse == TRUE; i++)
            {
                if(item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) > item_get_numero(lista_busca_sequencial(segundo_big_number, i)))
                {
                    printf("Resultado :: False\n");
                    trueorfalse = FALSE;
                }
                else if(item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) < item_get_numero(lista_busca_sequencial(segundo_big_number, i)))
                {
                    printf("Resultado :: True\n");
                    trueorfalse = FALSE;
                }
            }

            if(trueorfalse == TRUE)
            {
                printf("Resultado :: False\n");
            }
        }
    }

    else if(strcmp(operacao, "maior") == 0)
    {
        if((lista_tamanho(primeiro_big_number) < lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) > 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) > 0))
        {
            printf("Resultado :: False\n");
        }
        else if((lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) > 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) > 0))
        {
            printf("Resultado :: True\n");
        }
        else if((lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) < 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) < 0))
        {
            printf("Resultado :: False\n");
        }
        else if((lista_tamanho(primeiro_big_number) < lista_tamanho(segundo_big_number)) && 
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) < 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) < 0))
        {
            printf("Resultado :: True\n");
        }
        else if(
        (item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) > 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))< 0))
        {
            printf("Resultado :: True\n");
        }
        else if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) < 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0))> 0))
        {
            printf("Resultado :: False\n");
        }
        else
        {
            for(int i = 0; i < lista_tamanho(primeiro_big_number) && trueorfalse == TRUE; i++)
            {
                if(item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) < item_get_numero(lista_busca_sequencial(segundo_big_number, i)))
                {
                    printf("Resultado :: False\n");
                    trueorfalse = FALSE;
                }
                else if(item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) > item_get_numero(lista_busca_sequencial(segundo_big_number, i)))
                {
                    printf("Resultado :: True\n");
                    trueorfalse = FALSE;
                }
            }

            if(trueorfalse == TRUE)
            {
                printf("Resultado :: False\n");
            }
        }
    }

    else if(strcmp(operacao, "soma") == 0)
    {

        if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) >= 0) && 
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) >= 0)) // Quando os dois são positivos
        {
            if(lista_tamanho(primeiro_big_number) == lista_tamanho(segundo_big_number))
            {
                chave = 0;
                for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                {
                    primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));
                    segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));
                    total_aux = primeiro_numero+segundo_numero+resto;
                    resto = 0;
                    if(total_aux >= 10)
                    {
                        resto = 1;
                        total_aux -= 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto > 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
            }
            else if(lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number))
            {
                chave = 0;
                diferenca = lista_tamanho(primeiro_big_number)-lista_tamanho(segundo_big_number);
                for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                {
                    
                    primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = primeiro_numero+segundo_numero+resto;
                    resto = 0;
                    if(total_aux >= 10)
                    {
                        resto = 1;
                        total_aux -= 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto > 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
            }
            else if(lista_tamanho(segundo_big_number) > lista_tamanho(primeiro_big_number))
            {
                chave = 0;
                diferenca = lista_tamanho(segundo_big_number)-lista_tamanho(primeiro_big_number);
                for(int i = lista_tamanho(segundo_big_number); i > 0; i--)
                {
                    
                    primeiro_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = primeiro_numero+segundo_numero+resto;
                    resto = 0;
                    if(total_aux >= 10)
                    {
                        resto = 1;
                        total_aux -= 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto > 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
            }
            printf("Resultado :: ");
            imprimir_big_number(resultado);
        }

    else if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) <= 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) <= 0)) // Quando os dois são negativos
        {
            if(lista_tamanho(primeiro_big_number) == lista_tamanho(segundo_big_number))
            {
                chave = 0;
                for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                {
                    primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));
                    segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));
                    total_aux = (primeiro_numero*-1)+(segundo_numero*-1)+resto;
                    resto = 0;
                    if(total_aux >= 10)
                    {
                        resto = 1;
                        total_aux -= 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto > 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
            }
            else if(lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number))
            {
                chave = 0;
                diferenca = lista_tamanho(primeiro_big_number)-lista_tamanho(segundo_big_number);
                for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                {
                    
                    primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = (primeiro_numero*-1)+(segundo_numero*-1)+resto;
                    resto = 0;
                    if(total_aux >= 10)
                    {
                        resto = 1;
                        total_aux -= 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto > 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
            }
            else if(lista_tamanho(segundo_big_number) > lista_tamanho(primeiro_big_number))
            {
                chave = 0;
                diferenca = lista_tamanho(segundo_big_number)-lista_tamanho(primeiro_big_number);
                for(int i = lista_tamanho(segundo_big_number); i > 0; i--)
                {
                    
                    primeiro_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = (primeiro_numero*-1)+(segundo_numero*-1)+resto;
                    resto = 0;
                    if(total_aux >= 10)
                    {
                        resto = 1;
                        total_aux -= 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto > 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
            }

            printf("Resultado :: -");
            imprimir_big_number(resultado);
        }

        else if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) >= 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) <= 0)) // Quando o primeiro é maior que zero e o segundo é menor que zero
        {

            if(lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number)) // Se o positivo tiver mais digitos
            {
                chave = 0;
                diferenca = lista_tamanho(primeiro_big_number)-lista_tamanho(segundo_big_number);
                for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                {
                    primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = (primeiro_numero)+(segundo_numero)+resto;
                    resto = 0;
                    if(total_aux < 0)
                    {
                        resto = -1;
                        total_aux += 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto < 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
                printf("Resultado :: ");
                imprimir_big_number(resultado);
            }

            else if(lista_tamanho(segundo_big_number) > lista_tamanho(primeiro_big_number)) // Se o negativo tiver mais digitos
            {
                chave = 0;
                diferenca = lista_tamanho(segundo_big_number)-lista_tamanho(primeiro_big_number);
                for(int i = lista_tamanho(segundo_big_number); i > 0; i--)
                {
                    primeiro_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = (primeiro_numero*-1)+(segundo_numero*-1)+resto;
                    resto = 0;
                    if(total_aux < 0)
                    {
                        resto = -1;
                        total_aux += 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto < 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
                printf("Resultado :: -");
                imprimir_big_number(resultado);
            }

            else if(lista_tamanho(primeiro_big_number) == lista_tamanho(segundo_big_number)) // Se ambos possuem a mesma quantidade de digitos
            {
                chave = 0;
                for(int i = 0; i < lista_tamanho(primeiro_big_number); i++)
                {
                    if((trueorfalse != FALSE) &&
                        (item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) > abs(item_get_numero(lista_busca_sequencial(segundo_big_number, i)))))
                    {
                        sinal = 1;
                        trueorfalse = FALSE;
                    }
                    else if((trueorfalse != FALSE) &&
                        (item_get_numero(lista_busca_sequencial(primeiro_big_number, i)) < abs(item_get_numero(lista_busca_sequencial(segundo_big_number, i)))))
                    {
                        sinal = -1;
                        trueorfalse = FALSE;
                    }
                }

                if(sinal == 1)
                {
                    for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                    {
                        primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                        total_aux = (primeiro_numero)+(segundo_numero)+resto;
                        resto = 0;
                        if(total_aux < 0)
                        {
                            resto = -1;
                            total_aux += 10;
                        }
                        total = item_criar(chave, total_aux);
                        lista_inserir(resultado, total);
                        chave++;
                        if(resto < 0 && i == 1)
                        {
                            total = item_criar(chave, resto);
                            lista_inserir(resultado, total);
                        }
                    }

                    printf("Resultado :: ");
                    imprimir_big_number(resultado);
                }
                else if(sinal == -1)
                {
                    for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                    {
                        primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                        total_aux = (primeiro_numero*(-1))+(segundo_numero*(-1))+resto;
                        resto = 0;
                        if(total_aux < 0)
                        {
                            resto = -1;
                            total_aux += 10;
                        }
                        total = item_criar(chave, total_aux);
                        lista_inserir(resultado, total);
                        chave++;
                        if(resto < 0 && i == 1)
                        {
                            total = item_criar(chave, resto);
                            lista_inserir(resultado, total);
                        }
                    }

                    printf("Resultado :: -");
                    imprimir_big_number(resultado);
                }
                else if(sinal == 0)
                {
                    printf("Resultado :: 0\n");
                }
            }
        }
    
        else if((item_get_numero(lista_busca_sequencial(primeiro_big_number, 0)) <= 0) &&
        (item_get_numero(lista_busca_sequencial(segundo_big_number, 0)) >= 0)) // Quando o primeiro é menor que zero e o segundo é maior que zero
        {
            if(lista_tamanho(primeiro_big_number) > lista_tamanho(segundo_big_number)) // Se o negativo tiver mais digitos
            {
                chave = 0;
                diferenca = lista_tamanho(primeiro_big_number)-lista_tamanho(segundo_big_number);
                for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                {
                    primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = (primeiro_numero*-1)+(segundo_numero*-1)+resto;
                    resto = 0;
                    if(total_aux < 0)
                    {
                        resto = -1;
                        total_aux += 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto < 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
                printf("Resultado :: -");
                imprimir_big_number(resultado);
            }

            else if(lista_tamanho(segundo_big_number) > lista_tamanho(primeiro_big_number)) // Se o positivo tiver mais digitos
            {
                chave = 0;
                diferenca = lista_tamanho(segundo_big_number)-lista_tamanho(primeiro_big_number);
                for(int i = lista_tamanho(segundo_big_number); i > 0; i--)
                {
                    primeiro_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                    if((i-1-diferenca) >= 0)
                        segundo_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-diferenca-1));
                    else
                        segundo_numero = 0;

                    total_aux = (primeiro_numero)+(segundo_numero)+resto;
                    resto = 0;
                    if(total_aux < 0)
                    {
                        resto = -1;
                        total_aux += 10;
                    }
                    total = item_criar(chave, total_aux);
                    lista_inserir(resultado, total);
                    chave++;
                    if(resto < 0 && i == 1)
                    {
                        total = item_criar(chave, resto);
                        lista_inserir(resultado, total);
                    }
                }
                printf("Resultado :: ");
                imprimir_big_number(resultado);
            }

            else if(lista_tamanho(primeiro_big_number) == lista_tamanho(segundo_big_number)) // Se ambos possuem a mesma quantidade de digitos
            {
                chave = 0;
                for(int i = 0; i < lista_tamanho(primeiro_big_number); i++)
                {
                    if((trueorfalse != FALSE) &&
                        (abs(item_get_numero(lista_busca_sequencial(primeiro_big_number, i))) > abs(item_get_numero(lista_busca_sequencial(segundo_big_number, i)))))
                    {
                        sinal = -1;
                        trueorfalse = FALSE;
                    }
                    else if((trueorfalse != FALSE) &&
                        (abs(item_get_numero(lista_busca_sequencial(primeiro_big_number, i))) < abs(item_get_numero(lista_busca_sequencial(segundo_big_number, i)))))
                    {
                        sinal = 1;
                        trueorfalse = FALSE;
                    }
                }

                if(sinal == 1)
                {
                    for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                    {
                        primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                        total_aux = (primeiro_numero)+(segundo_numero)+resto;
                        resto = 0;
                        if(total_aux < 0)
                        {
                            resto = -1;
                            total_aux += 10;
                        }
                        total = item_criar(chave, total_aux);
                        lista_inserir(resultado, total);
                        chave++;
                        if(resto < 0 && i == 1)
                        {
                            total = item_criar(chave, resto);
                            lista_inserir(resultado, total);
                        }
                    }

                    printf("Resultado :: ");
                    imprimir_big_number(resultado);
                }
                else if(sinal == -1)
                {
                    for(int i = lista_tamanho(primeiro_big_number); i > 0; i--)
                    {
                        primeiro_numero = item_get_numero(lista_busca_sequencial(primeiro_big_number, i-1));
                        segundo_numero = item_get_numero(lista_busca_sequencial(segundo_big_number, i-1));

                        total_aux = (primeiro_numero*(-1))+(segundo_numero*(-1))+resto;
                        resto = 0;
                        if(total_aux < 0)
                        {
                            resto = -1;
                            total_aux += 10;
                        }
                        total = item_criar(chave, total_aux);
                        lista_inserir(resultado, total);
                        chave++;
                        if(resto < 0 && i == 1)
                        {
                            total = item_criar(chave, resto);
                            lista_inserir(resultado, total);
                        }
                    }

                    printf("Resultado :: -");
                    imprimir_big_number(resultado);
                }
                else if(sinal == 0)
                {
                    printf("Resultado :: 0\n");
                }
            }
        }
    }

    lista_apagar(&(resultado), lista_tamanho(resultado));
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaC.h"

struct PilhaC
{
    char item[TAM_MAX];
    int topo;
};

// Criar uma pilha vazia
PilhaC *criar_pilha()
{
    PilhaC *p = (PilhaC *)malloc(sizeof(PilhaC));

    p->topo = -1;

    return p;
}

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(PilhaC *p)
{
    // Uma solução simples
    // Antes de verificar o topo da pilha, primeiro devemos verificar se
    // a pilha é nula
    // return (p != NULL) && p->topo == (TAM_MAX - 1);

    // outra alternativa para implementação dessa função para retornar
    //-1: se a pilha for nula
    //  0: se a pilha não estiver cheia
    //  1: se a pilha estiver cheia
    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

// Verificar se a pilha está vazia (stack overflow)
int pilha_vazia(PilhaC *p)
{
    // Uma solução simples
    // Pilha nula ou com o topo igual a -1 é uma pilha vazia
    // return (p == NULL) || (p->topo == -1);

    // outra alternativa para implementação dessa função para retornar
    //-1: se a pilha for nula
    //  0: se a pilha não estiver vazia
    //  1: se a pilha estiver vazia
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

// Inserir um novo item na pilha, caso houver espaço
int empilhar(PilhaC *p, char item)
{
    // Se a pilha for nula, reservar um espaço na memória para ela
    if (p == NULL)
        p = criar_pilha();

    // Se a pilha não estiver cheia, empilhar um item
    // ! => operação lógica de negação
    // Exemplos:
    // !0 = 1
    // !(número diferente de 0) = 0
    // Caso a pilha seja nula, antes de entrar no comando if, ela é criada
    // ou seja, não precisa fazer "if (pilha_cheia(p) == 0)"
    if (!pilha_cheia(p))
    {
        p->topo++; // a pilha aumenta

        p->item[p->topo] = item; // um novo item é empilhado

        return 1; // operação bem sucedida
    }

    return 0; // opera
}

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
char desempilhar(PilhaC *p)
{
    char item;

    // Verificar se a pilha é vazia (1) ou nula (-1)
    // A única condição para "entrar" no comando if é a função abaixo
    // retornar 0, cuja negação é 1
    // Para qualquer retorno diferente de 0, a negação será 0
    if (!pilha_vazia(p))
    {
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

// Imprimir conteúdo da pilha
void imprimir_pilha(PilhaC *p)
{
    // Uma cópia da pilha deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela operação desempilhar, ou seja,
    // se usarmos a pilha original (p), perderíamos os seus dados
    PilhaC aux = *p;
    char item;

    // Como a variável aux não é ponteiro, para utilizamos o seu
    // endereço como parâmetro para chamarmos a função pilha_vazia
    while (!pilha_vazia(&aux))
    {
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

// Liberar a pilha
void liberar_pilha(PilhaC *p)
{
    if (p != NULL)
        free(p);
}

// Obter a posição da pilha em que está o topo
int obter_posicao_topo(PilhaC *p)
{
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

int operar(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
}

int resolver_pos_fix(char str[])
{
    int i, a, b, aux;
    PilhaC *p = criar_pilha;

    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= '0') && str[i] <= '9')
        {
            empilhar(p, str[i]);
        }
        else if ((str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-'))
        {
            a = desempilhar(p) - 48;
            b = desempilhar(p) - 48;

            aux = operar(b, a, str[i]);
            empilharp(p, aux);
        }
    }
    aux = desempilhar(p);
    liberar_pilha(p);
}

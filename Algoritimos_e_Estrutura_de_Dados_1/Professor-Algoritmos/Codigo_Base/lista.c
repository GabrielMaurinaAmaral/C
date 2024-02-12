#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Estrutura para uma lista estática
struct Lista
{
    int item[MAX_SIZE]; // A lista pode ser de qualquer tipo. Nesse caso, é uma lista de int, mas também pode ser de float, char, string, etc.
    int tam;            // tamanho da lista
};

// Função para criar uma lista estática
Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    // Ao iniciar a lista, a mesma estará "vazia"
    l->tam = 0;

    return l;
}

// Retorna 1 se a lista está vazia ou 0, caso contrário
int lista_vazia(Lista *l)
{
    return (l == NULL) || (l->tam == 0);
}

// Retorna 1 se a lista está cheia ou 0, caso contrário
int lista_cheia(Lista *l)
{
    return (l != NULL) && (l->tam == MAX_SIZE);
}

// Procura a posição de um item com a chave e retorna a sua respectiva posição
// Caso o item não seja encontrado, é retornado -1
int buscar(Lista *l, int chave)
{
    int i;

    if (!lista_vazia(l))
    {
        // Procurar na parte "não vazia" da lista
        for (i = 0; i < l->tam; i++)
        {
            if (l->item[i] == chave)
            {
                return i;
            }
        }
    }

    // Se chegou aqui é porque a lista está vazia ou o item não foi encontrado
    return -1;
}

// Um item é inserido no final da lista caso ela não estiver cheia.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int inserir(Lista *l, int chave)
{
    if (!lista_cheia(l))
    {
        // O item é adicionado no final da lista
        l->item[l->tam] = chave;

        // Se foi adicionado um elemento, então a lista cresceu
        l->tam++; // l->tam = l->tam + 1; ou l->tam += 1;

        // A inserção foi bem-sucedida
        return 1;
    }

    // Se chegou aqui é porque a lista estava cheia (ou nula)
    return 0;
}

// O item procurado e removido da lista caso ela. Para isso, a lista não deve estar vazia e o item
// deve existir.
// A função retorna 1 se a operação for bem sucedida ou 0, caso contrário
int remover(Lista *l, int chave)
{
    int i, p = buscar(l, chave);

    // A chave foi encontrada
    if (p > -1)
    {
        for (i = p; i < l->tam - 1; i++)
            // Deslocamento de itens da lista para ocupar o espaço do item removido
            // Se o item a ser removido for o último, o comando abaixo não é executado
            l->item[i] = l->item[i + 1];

        // Se foi removido um elemento, então a lista diminuiu
        l->tam--; // l->tam = l->tam - 1; ou l->tam -= 1;

        // Remoção bem-sucedida
        return 1;
    }

    return 0;
}

// Imprime o conteúdo da lista
void imprimir_lista(Lista *l)
{
    int i;

    if (!lista_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

// Libera a lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_lista(Lista *l)
{
    if (l != NULL)
    {
        free(l);

        return 1;
    }

    return 0;
}

int existe_substr(char str[], char substr[])
{
    int i, j, aux;

    if (strlen(substr) > strlen(str))
    {
        return 0;
    }
    else
    {
        for (i = 0; i < (strlen(str) - strlen(substr) + 1); i++)
        {
            aux = 0;

            for (j = i; ((j < (i + strlen(substr))) && (substr[j - i] == str[j])); j++)
            {
                aux++;
            }
            if (aux == strlen(substr))
            {
                return 1;
            }
        }

        return 0;
    }
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
};

Node *criar(int item)
{
    Node *tree = (Node *)malloc(sizeof(Node));

    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node *pesquisar(int item, Node *tree)
{
    if (tree != NULL)
    {
        if (item == tree->item)
            return tree;
        else if (item < tree->item)
            return pesquisar(item, tree->left);
        else
            return pesquisar(item, tree->right);
    }
    else
        return NULL;
}

int min(Node *tree)
{
    Node *aux = tree;

    if (aux != NULL)
    {
        while (aux->left != NULL)
            aux = aux->left;

        return aux->item;
    }

    return INT_MIN;
}

int max(Node *tree)
{
    Node *aux = tree;

    if (aux != NULL)
    {
        while (aux->right != NULL)
            aux = aux->right;

        return aux->item;
    }

    return INT_MAX;
}

Node *inserir(int item, Node *tree)
{
    if (tree == NULL)
        tree = criar(item);
    else if (item < tree->item)
        tree->left = inserir(item, tree->left);
    else if (item > tree->item)
        tree->right = inserir(item, tree->right);

    return tree;
}

Node *remover(int item, Node *tree)
{
    Node *aux, *auxP, *auxF;

    if (tree != NULL)
    {
        if (item < tree->item)
            tree->left = remover(item, tree->left);
        else if (item > tree->item)
            tree->right = remover(item, tree->right);

        else
        {
            aux = tree;

            if (aux->left == NULL)
                tree = tree->right;
            else if (aux->right == NULL)
                tree = tree->left;
            else
            {
                auxP = aux->right;
                auxF = auxP;

                while (auxF->left != NULL)
                {
                    auxP = auxF;
                    auxF = auxF->left;
                }

                if (auxP != auxF)
                {
                    auxP->left = auxF->right;
                    auxF->left = aux->left;
                }

                auxF->right = aux->right;

                tree = auxF;
            }

            free(aux);
        }
    }

    return tree;
}

void imprimirInfix(Node *tree)
{
    if (tree != NULL)
    {
        imprimirInfix(tree->left);
        printf("%i ", tree->item);
        imprimirInfix(tree->right);
    }
}

void imprimirPrefix(Node *tree)
{
    if (tree != NULL)
    {
        printf("%i ", tree->item);
        imprimirPrefix(tree->left);
        imprimirPrefix(tree->right);
    }
}

void imprimirPosfix(Node *tree)
{
    if (tree != NULL)
    {
        imprimirPosfix(tree->left);
        imprimirPosfix(tree->right);
        printf("%i ", tree->item);
    }
}

void liberar_arvore(Node *tree)
{
    if (tree != NULL)
    {
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree);
    }
}

int conta_no(Node *arvore)
{
    if (arvore == NULL)
        return 0;
    else
        return 1 + conta_no(arvore->left) + conta_no(arvore->right);
}

int altura(Node *arvore)
{
    if (arvore == NULL)
        return -1;
    else
    {
        int l = altura(arvore->left);
        int r = altura(arvore->right);

        return ((l > r) ? l : r) + 1;
    }
}

int nos_faltando(Node *arvore)
{
    return ((int)pow(2, altura(arvore) + 1) - 1) - (int)conta_no(arvore);
}

int main()
{
    int n, i, item;
    Node *arvore = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &item);
        arvore = inserir(item, arvore);
    }

    printf("%d", nos_faltando(arvore));

    liberar_arvore(arvore);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;

struct Cell
{
    int item;
    int col;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

struct Spa_Mat
{
    int n_lin;
    int n_col;
    ListaE **lin;
};

Spa_Mat *criar(int l, int c)
{
    Spa_Mat *mat = (Spa_Mat *)malloc(sizeof(Spa_Mat));
    int i;

    mat->n_col = c;
    mat->n_lin = l;
    mat->lin = (ListaE **)malloc(sizeof(ListaE *) * l);

    for (i = 0; i < l; i++)
    {
        mat->lin[i] = (ListaE *)malloc(sizeof(ListaE));
        mat->lin[i]->head = NULL;
    }

    return mat;
}

Cell *criar_celula(int item, int col)
{
    Cell *nova = (Cell *)malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}

static int procurar_lista(int item, ListaE *l)
{
    Cell *aux;

    if (l != NULL)
    {
        aux = l->head;

        while ((aux != NULL) && (aux->item != item))
            aux = aux->next;
    }

    if ((aux != NULL) && (aux->item == item))
        return 1;
    else
        return 0;
}

int buscar(int item, Spa_Mat *mat)
{
    int i;
    int aux = 0;

    for (i = 0; (i < mat->n_lin) && (aux == 0); i++)
        aux = procurar_lista(item, mat->lin[i]);

    return aux;
}

static int validar_pos_matriz(int lin, int col, Spa_Mat *mat)
{
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}

static void trocar_inserir_na_lista(int item, int col, ListaE *l)
{
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col))
    {
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
    }
    else if (col == l->head->col)
    {
        l->head->item = item;
    }
    else
    {
        auxA = l->head;
        auxP = auxA;

        while ((auxP != NULL) && (auxP->col < col))
        {
            auxA = auxP;
            auxP = auxP->next;
        }

        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
        else
        {
            novo = criar_celula(item, col);
            novo->next = auxA->next; // auxP
            auxA->next = novo;
        }
    }
}

static void remover_na_lista(int col, ListaE *l)
{
    Cell *auxA, *auxP = NULL;

    if (l->head != NULL)
    {
        if (col == l->head->col)
        {
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }
        else
        {
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->col < col))
            {
                auxA = auxP;
                auxP = auxP->next;
            }

            if ((auxP != NULL) && (col == auxP->col))
            {
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}

void trocar(int item, int l, int c, Spa_Mat *mat)
{
    if (validar_pos_matriz(l, c, mat))
    {
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}

void imprimir(Spa_Mat *mat)
{
    int i, j;
    Cell *aux;

    for (i = 0; i < mat->n_lin; i++)
    {
        aux = mat->lin[i]->head;
        j = 0;
        printf("%d: ", i);

        while (aux != NULL)
        {
            while (j < aux->col)
            {
                j++;
            }

            printf("-> %d,%d ", j, aux->item);
            j++;
            aux = aux->next;
        }

        if (j == 0)
            printf("->");

        printf("\n");
    }
}

Spa_Mat *converter_esparca(int **mat, int l, int c)
{
    Spa_Mat *spa_mat = criar(l, c);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            trocar(mat[i][j], i, j, spa_mat);
        }
    }

    return spa_mat;
}
int main()
{
    int l, c;
    scanf("%d %d", &l, &c);
    int **mat = (int **)malloc(l * sizeof(int *));

    Spa_Mat *spa_mat = criar(l, c);

    for (int i = 0; i < l; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int *));

        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    spa_mat = converter_esparca(mat, l, c);
    imprimir(spa_mat);

    return 0;
}
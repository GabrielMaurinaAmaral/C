/*Passagem de par�metro por refer�ncia: usa-se o operador "*" na frente do nome do
par�metro durante a declara��o da fun��o.*/

#include <stdio.h>

void somaMaisUm(int *x);

int main(void)
{
    int num;

    printf("Digite um valor para a variavel num: ");
    scanf("%d", &num);

    printf("\nVariavel num antes de passar pela funcao: %d\n", num);

    somaMaisUm(&num);//chamada da fun��o com um ponteiro como par�metro

    printf("Variavel num depois de passar pela funcao: %d\n", num);

    return 0;
}

void somaMaisUm(int *x) //x = o que est� dentro do endere�o de x
{
    *x = *x + 1;
    printf("Variavel num dentro da funcao: %d\n", *x);
}

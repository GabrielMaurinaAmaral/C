/*Quest�o 3 (3,3 pontos) � Fazer um programa que l� n n�meros inteiros e informa se os n�meros lidos est�o ou n�o em ordem crescente. n � informado pelo usu�rio e � um valor positivo e maior que 0. Caso a sequ�ncia n�o esteja ordenada, o programa dever� interromper o processo de repeti��o no momento em que a sequ�ncia deixar de ser ordenada. Al�m disso, o programa dever� encontrar o maior e o menor elemento da sequ�ncia e imprimi-los na tela.*/

#include <stdio.h>

int main(void)
{
    int i, n, atual, anterior, ordenado=1, maior, menor;

    do //valida��o de n
    {
        printf("Digite o valor de n: ");
        scanf("%d", &n);

        if(n < 0)
        {
            printf("Valor invalido\n");
        }
    }while(n < 0);

    printf("\nInforme o valor 1: "); //solicita o primeiro valor da sequ�ncia
    scanf("%d", &anterior);

    maior = anterior; //inicializa a vari�vel maior com o primeiro valor da sequ�ncia
    menor = anterior; //inicializa a vari�vel menor com o primeiro valor da sequ�ncia

    i = 2; //inicializa i com 2 pois o primeiro valor da sequ�ncia j� foi solicitado
    ordenado = 1; //considera que a sequ�ncia est� ordenada

    while(i <= n)
    {
        printf("Informe o valor %d: ", i); //solicita o pr�ximo valore grava em atual
        scanf("%d", &atual);

        if(atual > maior) //se atual for maior que maior, maior armazena atual
        {
            maior = atual;
        }
        else if(atual < menor) //se atual for menor que menor, menor armazena atual
        {
            menor = atual;
        }

        if(atual < anterior) //significa que a sequ�ncia n�o est� ordenada
        {
           ordenado = 0;
           break; //sai da estrutura de repeti��o
        }

        anterior = atual; //atualiza o valor de anterior
        i++;
    }
    if(ordenado == 1)
    {
        printf("Sequencia ordenada!\n");
    }
    else
    {
        printf("Sequencia nao ordenada!\n");
    }

    printf("\nMaior valor da sequencia: %d\n", maior);
    printf("Menor valor da sequencia: %d\n", menor);

    return 0;
}

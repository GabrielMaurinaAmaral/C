#include <stdio.h>

int quadrado(int a)
{
    return a*a;
}

int main(void)
{
    /*Fun��o: conjunto de comandos que recebe um nome e pode ser chamada
    em qualquer parte de um programa, quantas vezes forem necess�rias.
    Vantagens: estrutura��o do programa e reutiliza��o de c�digos.

    Forma geral de uma fun��o
    tipo nome_da_fun��o(par�metros)
    {
        conjunto de declara��es e comandos;
    }*/

    int num, i;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Quadrado do numero: %d\n", quadrado(num));

    printf("\nNUMERO\tQUADRADO\n");
    for(i=1; i<=15; i++)
    {
        printf("%d\t%d\n", i, quadrado(i));
    }

    return 0;
}

/*1) Ler dois n�meros float e apresentar, sem utilizar fun��es matem�ticas prontas:
a) A divis�o do primeiro n�mero pelo segundo, armazenando somente a parte inteira do n�mero.
b) A soma dos dois n�meros com o resultado arredondado para o pr�ximo n�mero inteiro.
Obs.: As vari�veis de resultados devem ser do tipo int.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
    float x, y;
    int a;

    printf("Informe o valor de x em float:");
    scanf("%f",&x);
    printf("Informe o valor de y em float:");
    scanf("%f",&y);

    a=x/y;
    printf("%f/%f=%i\n",x, y, a);

    a=ceil(x)+y;
    printf("%f+%f=%i",x,y,a);

    return 0;
}

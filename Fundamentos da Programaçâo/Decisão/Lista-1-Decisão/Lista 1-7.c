/*7) Elaborar um programa que l� dois valores, verifica se o primeiro � m�ltiplo do segundo e escreve a mensagem "S�o m�ltiplos" ou "N�o s�o m�ltiplos" dependendo da condi��o. Verificar para que n�o seja realizada uma divis�o por zero. Nesse caso, informar que n�o � poss�vel realizar uma divis�o por zero.*/

#include<stdio.h>

int main(void)
{
    int x, y, z;
    printf("Informe o primeiro numero:");
    scanf("%d",&x);
    printf("Informe o segundo numero:");
    scanf("%d",&y);

    z=x%y;

    if(z==0)
    {
       printf("Sao multiplos");
    }
    else if(z!=0)
    {
       printf("nao sao multiplos");
    }

 return 0;
}

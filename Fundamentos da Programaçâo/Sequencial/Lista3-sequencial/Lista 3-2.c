/*2) Considerando que para um cons�rcio sabe-se o n�mero total de presta��es, a quantidade de presta��es pagas e o valor de cada presta��o (que � fixo). Escreva um programa que determine o valor total j� pago pelo consorciado e o saldo devedor8*/

#include<stdio.h>

int main (void)
{
    int x,y,z,a,b;
    printf("Informe a quantidade total de prestacoes: ");
    scanf("%d",&x);
    printf("Informe a quantidade de presta��es pagas: ");
    scanf("%d",&y);
    printf("Inforeme o valor(fixo) da prestacao: ");
    scanf("%d",&z);

    a=y*z;
    printf("Valor total ja pago: R$%d\n",a);

    b=(x-y)*z;
    printf("Saldo devedor: R$%d",b);

    return 0;
}

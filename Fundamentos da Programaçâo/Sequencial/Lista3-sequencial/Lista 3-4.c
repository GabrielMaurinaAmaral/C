/*4) Fazer um programa que leia um n�mero inteiro de at� tr�s d�gitos (considere que ser� fornecido um n�mero de at� 3 d�gitos), calcule e imprima a soma dos seus d�gitos.*/

#include<stdio.h>

int main (void)
{
    int x,a,b,c,d;
    printf("Informe um numero inteiro com ate tres digitos: ");
    scanf("%d",&x);

    a=x/100;
    b=(x%100)/10;
    c=x%10;
    d=a+b+c;
    printf("%d = %d + %d + %d = %d",x,a,b,c,d);

}

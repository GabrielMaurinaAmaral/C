/*2) O custo ao consumidor de um carro novo � a soma do custo de f�brica com a percentagem do distribuidor e a percentagem dos impostos (ambas aplicadas sobre o custo de f�brica). Escrever um programa para, a partir do custo de f�brica do carro, calcular e mostrar o custo ao consumidor.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
    int x, a;
    float y, z;

    printf("Informe o valor do custo de fabrica��o do carro: R$");
    scanf("%d",&x);
    printf("Informe a porcentagem do distribuidor(100 a 0): ");
    scanf("%f",&y);
    printf("Informe a porcentagem de impostos");
    scanf("%f",&z);

    a=x+(x*(y/100))+(x*(z/100));

    printf("O custo do carro ao consumidor eh:%d",a);

    return 0;
}


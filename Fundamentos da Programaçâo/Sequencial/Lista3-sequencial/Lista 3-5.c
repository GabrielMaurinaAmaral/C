/*5) Fa�a um programa para calcular a quantidade de fita necess�ria, em cent�metros, para amarrar um pacote com duas voltas, sendo uma pela largura e outra pelo comprimento do pacote. Ser�o fornecidas a largura, a altura e o comprimento do pacote. Para amarrar as pontas da fita s�o necess�rios 15 cm de fita em cada ponta. A figura a seguir ilustra a maneira como a fita � passada pelo pacote.*/

#include<stdio.h>
int main (void)
{
    int x,y,z,a;
    printf("Informe a largura:");
    scanf("%d",&x);
    printf("Informe o comprimento:");
    scanf("%d",&y);
    printf("Informe altura:");
    scanf("%d",&z);

    a=(x*2)+(y*2)+(z*4)+30;
    printf("Serao necessarios %d cm de fitas",a);

    return 0;
}

/*4) Escreva um programa que, dados a quantidade de litros de combust�vel utilizada, os quil�metros percorridos por um autom�vel e o valor do litro de combust�vel, calcule quantos quil�metros o ve�culo percorreu por litro de combust�vel e o valor gasto em reais por km.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
    float x, y, z, a, b;

    printf("Informe os Km percorrido:");
    scanf("%f",&x);
    printf("Combustivel consumido(em L):");
    scanf("%f",&y);
    printf("Valor do livro de combustivel:");
    scanf("%f",&z);

    a=x/y;
    b=a/z;

    printf("o carro fez

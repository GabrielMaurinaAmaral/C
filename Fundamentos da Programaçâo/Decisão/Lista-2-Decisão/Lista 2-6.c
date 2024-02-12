/*6) Ler tr�s valores inteiros que representam os lados de um tri�ngulo e determinar se esses valores podem formar um tri�ngulo (obs.: para ser um tri�ngulo cada lado deve ser menor que a soma dos outros dois lados). Se for um tri�ngulo, determinar o seu tipo: equil�tero (todos os lados iguais), is�sceles (dois lados iguais) e escaleno (todos os lados diferentes).*/

#include<stdio.h>

int main (void)
{
    int x,y,z;
    printf("Informe o primeiro lado:");
    scanf("%d",&x);
    printf("Informe o segundo lado:");
    scanf("%d",&y);
    printf("Informe o terceiro lado:");
    scanf("%d",&z);

    if(x+y<z || x+z<y || y+z<x)
    {
        printf("Nao pode ser um trigangulo");
    }
    else
    {
        if(x==y==z)
        {
            printf("eh um triangulo equilatero");
        }
        else if(x==y || y==z || z==x)
        {
             printf("eh um triangulo esiceles");
        }
        else
        {
            printf("eh um triangulo escaleno");
        }

    }
 return 0;
}

/*8) Fa�a um programa que leia tr�s notas de um aluno e calcule a m�dia ponderada, com os pesos 1, 3 e 4,
respectivamente, e:
a) Se a m�dia obtida est� entre 6 a 10 informar que o aluno est� aprovado;
b) Se a m�dia obtida est� entre 4 e 5,9 informar que o aluno est� em recupera��o. Nesse caso, ler a nota de
recupera��o e calcular a m�dia final (que � a m�dia entre a m�dia anual e a nota de recupera��o);
b.1) Se a m�dia final � menor que 5 informar que o aluno est� reprovado ap�s recupera��o;
b.2) Se � igual ou maior que 5 informar que o aluno est� aprovado ap�s recupera��o;
c) Se a m�dia obtida � menor que 4 informar que o aluno est� reprovado antes da recupera��o.*/

#include<stdio.h>

int main(void)
{
    int x, y, z, w;
    float a, b;
    printf("Primeira nota: ");
    scanf("%d",&x);
    printf("Segunda nota: ");
    scanf("%d",&y);
    printf("Terceira nota: ");
    scanf("%d",&z);

    a=(float)(x+(y*3)+(z*4))/8;

    if(a>=6 && a<=10)
    {
        printf("Aluno aprovado");
    }
    if(a>=4 && a<6)
    {
        printf("Aluno esta de recuperacao\n");
        printf("Nota da Recuperacao: ");
        scanf("%d", &w);

        b=(w+a)/2;

        if(b<5)
        {
            printf("Aluno reprovado");
        }
        else if(b>=5)
        {
            printf("Aluno aprovado");
        }
    }
    if(a<4)
    {
         printf("Aluno reprovado");
    }



 return 0;
}

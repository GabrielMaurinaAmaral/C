/*Um hotel deseja fazer uma promo��o especial de final de semana, concedendo um desconto de 25% na
di�ria. Sendo informados o n�mero de apartamentos do hotel e o valor da di�ria por apartamento para o final
de semana completo. Elaborar um programa para calcular:
a) Valor promocional da di�ria;
b) Valor total caso a ocupa��o no final de semana atinja 100%;
c) Valor total a ser arrecadado caso a ocupa��o no final de semana atinja 70%;
d) Valor que o hotel deixar� de arrecadar em virtude da promo��o, caso a ocupa��o atinja 100%.*/

#include<stdio.h>
#include<math.h>

int main(void)
{
      float num1, num2, a, b, c, d;

      printf("Informe o valor da diaria:");
      scanf("%f",&num1);
      printf("Informe a quantidade de quartos:");
      scanf("%f",&num2);

      a=num1*0.75;
      b=2*(a*num2);
      c=2*(a*(num2*0.70));
      d=2*((num1*0.25)*num2);

      printf(" \nValor da diaria promocional:R$ %.2f",a);
      printf(" \nTotal arrecadado com 100 porcento de ocupa��o:R$ %.2f",b);
      printf(" \nTotal arrecadado com 70 porcento de ocupa��o:R$ %.2f",c);
      printf(" \nvalor que deixara de arrecadar aoaplicar o desconto:R$ %.2f",d);

      return 0;
}

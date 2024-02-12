/*10) Fa�a um programa que solicite ao usu�rio o valor do sal�rio de um funcion�rio e apresente o menu a seguir e permita ao usu�rio escolher a op��o desejada e mostre o resultado. Verifique a possibilidade de op��o inv�lida e n�o se preocupe com restri��es, como sal�rio negativo. Use switch - case, if e if - else para a solu��o.*/

#include<stdio.h>

int main(void)
{
    int num;
    float salario;
    printf("Menu de opcoes \n");
    printf("1 = Imposto \n");
    printf("2 = Novo salario \n");
    printf("3 = Classificacao \n");
    printf ("Escolha uma nas opcoes: ");
    scanf("%d", &num);
    printf("Informe seu salario: ");
    scanf("%f", &salario);

    switch(num)
    {
          case 1:
          {
              if(salario>1000)
              {
                  printf("Imposto sobre o salario:%0.2f", (salario*1.05)-salario);
              }
              else if(salario>=1000 && salario<=1500)
              {
                  printf("Imposto sobre o salario:%0.2f", (salario*1.1)-salario);
              }
              else
              {
                  printf("Imposto sobre o salario:%0.2f", (salario*1.15)-salario);
              }
              break;
          }

          case 2:
          {
              if(salario>1000)
              {
                  printf("Valor sobre o novo salario eh %0.2f", salario+75);
              }
              else if(salario>=1000 && salario<=1500)
              {
                  printf("Valor sobre o novo salario eh %0.2f", salario+100);
              }
              else
              {
                  printf("Valor sobre o novo salario eh %0.2f", salario+150);
              }
              break;
          }

          case 3:
          {
              if(salario<=1000)
              {
                  printf("Categoria A");
              }
              else
              {
                  printf("categoria B");
              }
              break;
          }
          default:
          {
              printf("opcao incorreta");
          }

    }
 return 0;
}

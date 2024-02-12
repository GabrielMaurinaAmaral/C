#include <stdio.h>
#include "D:\funcoes.h"

int potencia(void);

int num, num1;

int main(void)
{
    int i, opcao;
    char repete;

    do
    {
        printf("1 - Quadrado de um numero\n");
        printf("2 - Verifica se um numero eh ou nao primo\n");
        printf("3 - Quadrado dos numeros de 1 a 10\n");
        printf("4 - Primos no intervalo de 1 a 10\n");
        printf("5 - Media de duas notas\n");
        printf("6 - Multiplica dois numeros\n");
        printf("7 - Soma dois numeros\n");
        printf("8 - Calcula e mostra o fatorial de um numero\n");
        printf("9 - Fatorial dos numeros de 1 a 10\n");
        printf("10 - Potencia de um numero\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Informe um numero: ");
                scanf("%d", &num);//armazena em vari�vel global

                printf("Quadrado do numero: %d\n", quadrado(num));//chama a fun��o e passa o par�metro num
                break;
            case 2:
                printf("Informe um numero: ");
                scanf("%d", &num); //armazena em vari�vel global

                if(primo(num) == 2) //chama a fun��o e passa o par�metro num
                {
                    printf("%d eh primo\n", num);
                }
                else
                {
                    printf("%d nao eh primo\n", num);
                }
                break;
            case 3:
                printf("\nNUMERO\tQUADRADO\n");
                for(i=1; i<=10; i++)
                {
                    printf("%d\t%d\n", i, quadrado(i)); //chama a fun��o e passa o par�metro i
                }
                break;
            case 4:
                printf("\nPRIMOS\n");
                for(i=1; i<=10; i++)
                {
                    if(primo(i) == 2) //chama a fun��o e passa o par�metro i
                    {
                        printf("%d   ", i);
                    }
                }
                break;
            case 5:
                printf("\nMedia de duas notas: %.2f\n", media());//chama a fun��o e n�o passa nenhum par�metro num
                break;
            case 6:
                printf("\nInforme um numero: ");
                scanf("%d", &num);//armazena em vari�vel global
                printf("Informe outro numero: ");
                scanf("%d", &num1);//armazena em vari�vel global
                multiplica(num, num1);//chama a fun��o e passa os par�metro num e num1
                break;
            case 7:
                soma();
                break;
            case 8:
                printf("\nInforme um numero: ");
                scanf("%d", &num);//armazena em vari�vel global

                mostraFatorial(num, calculaFatorial(num)); //chama a fun��o e como par�metro passa num e a fun��o calculaFatorial(num)
                break;
            case 9:
                for(i=1; i<=10; i++)
                {
                    mostraFatorial(i, calculaFatorial(i));//chama a fun��o e como par�metro passa i e a fun��o calculaFatorial(i)
                }
                break;
            case 10:
                printf("Potencia: %d\n", potencia()); //chama a fun��o e n�o passa nenhum par�metro
                break;
            default:
                printf("Opcao invalida\n");
        }

        printf("\nDeseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &repete);
    }while(repete == 'S' || repete == 's');

    return 0;
}

//Exemplo do uso de vari�vel global
int potencia(void)//fun��o com retorno e sem par�metros
{
    int i, resultado=1;

    printf("Informe a base: ");
    scanf("%d", &num);//armazena em vari�vel global
    printf("Informe o expoente: ");//armazena em vari�vel global
    scanf("%d", &num1);

    for(i=1; i<=num1; i++)
    {
        resultado = resultado * num;
    }
    return(resultado);
}


/*Quest�o 2 (3,4 pontos) - Ler caracteres. Parar a leitura quando informado o caractere �0�, que n�o deve ser considerado no processamento.
a) Se o caractere estiver entre '1' e '9', mostrar o processo de c�lculo do fatorial do valor decimal ASCII do caractere. N�o precisa calcular o fatorial, apenas apresentar o processo de c�lculo.
b) Se o caractere estiver entre 'a' e 'z' ou entre 'A' e 'Z', mostrar todos os n�meros primos, sendo 6 n�meros por linha, no intervalo de 1 at� o valor decimal ASCII do caractere e somar todos os n�meros primos desse intervalo.
c) Contar os caracteres que s�o letras min�sculas e a quantidade total de caracteres informados e calcular e mostrar o percentual de letras min�sculas em rela��o ao total de caracteres v�lidos informados. Validar para que n�o seja poss�vel ocorrer uma divis�o por 0.
d) Implementar a repeti��o de programa. */

#include <stdio.h>

int main(void)
{
    int num, i, j, contMinusculas, contTodos, contDiv, contPrimos, somaPrimos;
    float percentual;
    char opcao, ch;

    do //repeti��o de programa
    {
        contMinusculas=0; //inicializa o contador de letras min�sculas
        contTodos=0; //inicializa o contador de todos os caracteres

        do //repeti��o dos caracteres
        {
            printf("Informe um caractere: ");
            setbuf(stdin, NULL);
            scanf("%c", &ch);

            if(ch != '0')
            {
                contTodos++; //conta todos os caracteres

                if(ch >= '1' && ch <= '9') //verifica se o caractere digitado est� entre '1' a '9'
                {
                    for(i=ch; i>=2; i--) //mostra o processo do fatorial
                    {
                        printf("%d * ", i);
                    }

                    printf("1\n");
                }
                else if(ch >= 'a' && ch <= 'z'|| ch >= 'A' && ch <= 'Z') //verifica se o caractere digitado est� entre 'a' a 'z' ou entre 'A' a 'Z'
                {
                    contPrimos=0; //inicializa o contador de primos
                    somaPrimos=0; //inicializa o somat�rio de primos

                    for(i=1; i<=ch; i++) //verifica se os n�meros de 1 at� o valor decimal de ch s�o primos
                    {
                        contDiv = 0; //inicializa o contador de divisores
                        for(j=1; j<=i; j++)//verifica se cada elemento do for anterior � primo
                        {
                            if(i%j == 0)
                            {
                                contDiv++;
                            }
                        }
                        if(contDiv == 2) //se for primo
                        {
                            printf("%d\t", i); //imprime o n�mero primo
                            contPrimos++; //conta os primos
                            somaPrimos = somaPrimos + i; //soma os primos

                            if(contPrimos % 6 == 0) //se a quantidade de primos for m�liplo de 6, quebra linha
                            {
                                printf("\n");
                            }
                        }
                    }
                    printf("\nSoma dos primos: %d\n", somaPrimos);

                    if(ch >= 'a' && ch <= 'z')
                    {
                        contMinusculas++; //conta as letras min�sculas do alfabeto
                    }
                }
            }
        }while(ch != '0');

        if(contMinusculas > 0)
        {
            percentual = contMinusculas * 100 / (float)contTodos;
            printf("\nPercentual de minusculas: %.2f%%\n", percentual);
        }
        else
        {
            printf("Nao foi digitado nenhuma letra minuscula\n");
        }

        printf("\nDeseja continuar no programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c",&opcao);

    }while(opcao == 'S' || opcao == 's');

    return 0;
}

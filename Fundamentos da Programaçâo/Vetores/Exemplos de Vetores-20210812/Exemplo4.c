#include <stdio.h>

int main(void)
{
    int i;

	//declara��o dos vetores
    int vetA[10], vetB[10];

	//atribui��o por entrada de dados
	 for(i=0; i<10; i++)
     {
         printf("Informe um valor para a posicao %d do vetor: ", i);
         scanf("%d", &vetA[i]);
     }

	//atribui��o por opera��o de valor de outro vetor
	for(i=0; i<10; i++)
    {
        vetB[i] = vetA[i] * 2;
    }

	//sa�da de dados
	for(i=0; i<10; i++)
    {
        printf("%d\t", vetB[i]);
    }

	return 0;
}

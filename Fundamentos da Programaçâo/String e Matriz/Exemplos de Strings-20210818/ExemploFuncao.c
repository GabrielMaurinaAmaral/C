/*Fazer uma fun��o para contar a quantidade de caracteres de uma string, incluindo espa�os, e outra fun��o n�o incluindo espa�os. */

#include <stdio.h>

int contarCaracteres(char texto[]);
int contarCaracteresSemEspaco(char texto[]);

int main(void)
{
    char opcao, texto[150];
    int i;

    do
    {
        printf("Informe um texto com ate 150 caracteres: ");
        setbuf(stdin, NULL);
        gets(texto);

        printf("\nNumero de caracteres com espaco: %d", contarCaracteres(texto)); //chama a fun��o e imprime o seu retorno
        printf("\nNumero de caracteres sem espaco: %d", contarCaracteresSemEspaco(texto));//chama a fun��o e imprime o seu retorno

        printf("\n\nDeseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c",&opcao);

    }while(opcao =='S' || opcao =='s');

    return 0;
}

int contarCaracteres(char texto[])
{
    int i=0;

    while(texto[i] != '\0')//enquanto n�o � final de string
    {
        i++; //conta os caracteres
    }
    return(i);
}

int contarCaracteresSemEspaco(char texto[])
{
    int i=0, cont=0;

    while(texto[i] != '\0')//enquanto n�o � final de string
    {
        if(texto[i] != ' ') //se caracter for diferente de espa�o em branco
        {
            cont++;
        }
        i++;
    }
    return(cont);
}

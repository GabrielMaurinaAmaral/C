#include <stdio.h>

int main(void)
{
   char string1[20] = "Linguagem C";
   char string2[20];
   int i=0, j=0;

   //printf("Tamamho da string: %d", strlen(string1));

    while(string1[i] != '\0') //percorre a string at� chegar no final de string
    {
        i++; //conta o tamanho da string
    }

   printf("Tamanho da String: %d\n", i);
   i = i-1;//o i vai estar na posi��o que est� o '\0', ao voltar uma posi��o, fica no �ltimo caractere
   printf("Tamanho da String: %d\n", i);

   for(i; i>=0; i--)
   {
      // printf("%c", string1[i]); // imprime a string invertida
       string2[j] = string1[i];
       //printf("String invertida: %c\n", string2[j]);
       j++;
   }
   string2[j] = '\0';
   printf("String invertida: %s\n", string2);

   return 0;
}

/*Uma pessoa resolveu fazer uma aplica��o em uma poupan�a programada1. Para calcular seu rendimento,
ela dever� fornecer o valor constante da aplica��o mensal, a taxa de juros (%) e o prazo da aplica��o (em
meses). Sabendose que a f�rmula usada para este c�lculo �:*/

#include<stdio.h>
#include<math.h>

int main (void)
{

    int n;
    float i, vm, va;

    printf("Informe o valor da aplica��o mensal:");
    scanf("%f",&vm);
    printf("Infome a taxa de juros(entre 1 a 0):");
    scanf("%f",&i);
    printf("quantas mensalidades:");
    scanf("%i",&n);

    va=(vm*(pow(1+i,n)-1))/i;

    printf("Valor final eh R$%.2f",va);

    return 0;

}

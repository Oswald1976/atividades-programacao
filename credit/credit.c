#include <stdio.h>
#include <cs50.h>

// iniciando variaveis

char numerocartao{20};
int tamanho, i;

// Prototype the functions
// long function1(long n);
// long function2(long n);
//long cardNumValidation(long n)

int main(void)
{
    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf( "%li", &numerocartao);
    if (numerocartao < 1)
    {
        printf("Digite apenas Numeros Positivos");
    }
    else if ((isdigit(numerocartao)))
    {
            {
        printf("Digite apenas Numeros");
    }
    else
    printf("Deu Certo\n" );
    }

    /*
    do
    {
    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf( "%li", &numerocartao);
    }
    while (numerocartao < 1);
    */


}
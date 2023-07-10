#include <stdio.h>
#include <cs50.h>

long numerocartao;
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
        printf("Numero Negativo");
    }
    else if (numerocartao)
    /*
    do
    {
    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf( "%li", &numerocartao);
    }
    while (numerocartao < 1);
    */

printf("Deu Certo\n" );
}
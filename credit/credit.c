#include <stdio.h>
#include <cs50.h>



// Prototype the functions
// long function1(long n);
// long function2(long n);
//long cardNumValidation(long n)

int main(void)
{

    //iniciando variaveis
    int numerocartao[20];
    int digito;
    int tamanho = 0, i = 0;


    printf("Digite o Numero do Cartão de Credito .. : ");

    for (i=0; i < 20; i++)
    {
        numerocartao[i]=scanf( "%d", &digito);
    }
/*
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

    */


}
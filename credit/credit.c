#include <stdio.h>
#include <cs50.h>



int main(void)
{

    //iniciando variaveis
    char nrcartao[20];
    int inrcartao[20];
    int i;


    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf(" %s", nrcartao);

    for (i=0; i < 20; i++)
    {
        numerocartao[i]=scanf( "%d", &digito);
    }
    //Efetua a conversao de array de char para um array de int.
    for(i=0;i<11;i++)
    {
    inrcartao[i]=nrcartao[i]-48;
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
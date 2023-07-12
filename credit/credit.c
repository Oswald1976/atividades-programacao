#include <stdio.h>
#include <cs50.h>
#include <cstring.h>



int main(void)
{

    //iniciando variaveis
    char nrcartao[20];
    int inrcartao[20];
    int qtd=0;
    int i=0;


    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf(" %s", nrcartao);
    while(nrcartao[i] != "\0")
    {
        qtd++
        i++

    }
    //Efetua a conversao de array de char para um array de int.
    for(i=0; i < strlenqtd  ;i++)

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
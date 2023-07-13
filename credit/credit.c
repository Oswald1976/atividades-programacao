#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main(void)
{

    //iniciando variaveis
    char nrcartao[20];
    int inrcartao[20];
    int qtd=0;
    int i=0;


    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf(" %s", nrcartao);

    for(i = 1; strlen(nrcartao); i++)
    {
        if(input[i-1] != '0' && input[i-1] != '1' &&
        input[i-1] != '2' && input[i-1] != '3' &&
        input[i-1] != '4' && input[i-1] != '5' &&
        input[i-1] != '6' && input[i-1] != '7' &&
        input[i-1] != '8' && input[i-1] != '9' &&
        input[i-1] != '\0'){
            return 0;
        }
    }

    //Efetua a conversao de array de char para um array de int.
    for(i=0; i <= strlen(nrcartao) ;i++) // strlen = retorna a quantidade de elemento no array
    {
    inrcartao[i]=nrcartao[i]-48; // pq -48 ?
    qtd++; // Acumula  quantidade de elementos do array
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
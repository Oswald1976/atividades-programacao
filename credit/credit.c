#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{

    char nrcartao[20];
    int inrcartao[20];
    int inrmulti = 0;
    int inrnorma = 0;
    int soma = 0;
    int len=0;
    int i;

    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf(" %s", nrcartao);
    len=strlen(nrcartao); // strlen = retorna a quantidade de elemento no array

    for(i = 0; i <= len ; i++) // confere se foram digitados apenas numeros
    {
        if(nrcartao[i] != '0' && nrcartao[i] != '1' &&
        nrcartao[i] != '2' && nrcartao[i] != '3' &&
        nrcartao[i] != '4' && nrcartao[i] != '5' &&
        nrcartao[i] != '6' && nrcartao[i] != '7' &&
        nrcartao[i] != '8' && nrcartao[i] != '9' &&
        nrcartao[i] != '\0')
        {
            printf("INVALID\n");
            printf("\n");
            printf("ERRO !!!, Lembre de digitar apenas numeros \n");
            printf("\n");
            printf("TENTE NOVAMENTE.... \n");
            printf("\n");
        }
    }

    if (len < 13 || len  > 16) // confere se a quantidade numeros esta na faixa aceitavel
    {
        Printf("INVALID");
        return 0;
    }



    for(i=0; i < len  ;i++) //
    {
        inrcartao[i]=nrcartao[i]-48; // pq -48 ?  Efetua a conversao de array de char para um array de int.
    }

// testa os codigos para saber qual bandeira pertence o cartão
        if(nrcartao[0] == '3' && nrcartao[1] == '4')
        {
           printf("\n");
           printf("Amex \n");
        }
        if(nrcartao[0] == '3' && nrcartao[1] == '7')
        {
           printf("\n");
           printf("Amex \n");
        }
        if(nrcartao[0] == '5' && nrcartao[1] == '1')
        {
           printf("\n");
           printf("MasterCard \n");
        }
        if(nrcartao[0] == '5' && nrcartao[1] == '2')
        {
           printf("\n");
           printf("MasterCard \n");
        }
        if(nrcartao[0] == '5' && nrcartao[1] == '3')
        {
           printf("\n");
           printf("MasterCard \n");
        }
        else if(nrcartao[0] == '5' && nrcartao[1] == '4')
        {
           printf("\n");
           printf("MasterCard \n");
        }
        else if(nrcartao[0] == '5' && inrcartao[1] == '5')
        {
           printf("\n");
           printf("MasterCard \n");
        }
        else if(nrcartao[0] == '4' )
        {
           printf("\n");
           printf("Visa \n");
        }
        else
        {
           printf("\n");
           printf("INVALID\n");
          // return 0;
        }


 // int validarCartaoCredito(const char* numeroCartao) { PODE VIRAR UMA FUNÇAO POSTERIORMENTE

    for (i = qtd - 2; i >= 0; i -= 2) // Inicia a partir do penúltimo para o primeiro
    {

        if ((inrcartao[i] * 2) > 9) // Multiplica por 2 e verifica se o resultado é maior que 9

        {
            inrmulti += (inrcartao[i] * 2) - 9;
        }
        else
        {
            inrmulti += inrcartao[i] * 2;
        }
    }


    for (i = qtd - 1; i >= 0; i -= 2) // Soma os dígitos que nao foram ultilizados na operação anterior
    {
        inrnorma += inrcartao[i];

    }

    soma = inrmulti + inrnorma;


    if (soma % 10 == 0) // Verifica se o número é válido
    {
        printf("Numero de Cartão Valido !!!"); // Válido
    } else {
        printf("Numero de Cartão Invalido !!!"); // Inválido
        return 0;
    }

}
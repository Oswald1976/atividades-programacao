#include <stdio.h>
#include <cs50.h>
#include <string.h>




int main(void)
{



    char nrcartao[20];
    int inrcartao[20];
    int inrmulti[8];
    int inrnorma[8];
    int qtd=0;
    int i=0;

    do
      {

    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf(" %s", nrcartao);
      }
    while(strlen(nrcartao) < 13 || strlen(nrcartao) > 16);

    for(i = 0; i <= strlen(nrcartao); i++)
    {
        if(nrcartao[i] != '0' && nrcartao[i] != '1' &&
        nrcartao[i] != '2' && nrcartao[i] != '3' &&
        nrcartao[i] != '4' && nrcartao[i] != '5' &&
        nrcartao[i] != '6' && nrcartao[i] != '7' &&
        nrcartao[i] != '8' && nrcartao[i] != '9' &&
        nrcartao[i] != '\0')
        {

            printf("\n");
            printf("ERRO !!!, Lembre de digitar apenas numeros \n");
            printf("\n");
            printf("TENTE NOVAMENTE.... \n");
            printf("\n");

        }

    }

        //Efetua a conversao de array de char para um array de int.
        for(i=0; i < strlen(nrcartao) ;i++) // strlen = retorna a quantidade de elemento no array
        {
            inrcartao[i]=nrcartao[i]-48; // pq -48 ?
            qtd++; // Acumula  quantidade de elementos do array
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
            }

     for(n=strlen(nrcartao)-1 ; n <= 0 ; n=n-2)
     {
      inrcartao[n]*2

     }


     for(n=strlen(nrcartao)-2 ; n <= 0 ; n=n-2)
     {
      inrcartao[n]*2

     }

}
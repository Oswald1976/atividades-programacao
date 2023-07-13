#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main(void)
{



    char nrcartao[20];
    int inrcartao[20];
    int qtd=0;
    int i=0;




    printf("Digite o Numero do Cartão de Credito .. : ");
    scanf(" %s", nrcartao);

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
           // return 0;


        }




        //Efetua a conversao de array de char para um array de int.
        for(i=0; i < strlen(nrcartao) ;i++) // strlen = retorna a quantidade de elemento no array
        {
            inrcartao[i]=nrcartao[i]-48; // pq -48 ?
            qtd++; // Acumula  quantidade de elementos do array
        }

        for(i=0; i < strlen(nrcartao) ;i++) // strlen = retorna a quantidade de elemento no array
        {
            printf("%i\n", inrcartao[i]); //Imprimir na tela os numeros depois de passar para o array de inteiro
        }
    }

}
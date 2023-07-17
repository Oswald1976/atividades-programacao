#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{

    char nrcartao[20];
    int inrcartao[20];
    int tnrmulti = 0;
    int tnrnorma = 0;
    int qtd=0;
    int i=0;

    do
    {
        printf("Digite o Numero do Cartão de Credito .. : ");
        scanf(" %s", nrcartao);
    }
    while(strlen(nrcartao) < 13 || strlen(nrcartao) > 16);

    int len = strlen(nrcartao);

    for(i = 0; i <= len ; i++)
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
        for(i=0; i < len  ;i++) // strlen = retorna a quantidade de elemento no array
        {
            inrcartao[i]=nrcartao[i]-48; // pq -48 ?
        }



 // int validarCartaoCredito(const char* numeroCartao) {

    int soma = 0;
    int digitoDuplo = 0;

    // Inicia a partir do penúltimo dígito e percorre o número de trás para frente
    for (int i = len - 2; i >= 0; i -= 2) {
       // int digito = numeroCartao[i] - '0'; // Converte o caractere para inteiro

        // Multiplica por 2 e verifica se o resultado é maior que 9
        if ((inrcartao[i]digito * 2) > 9)
        {
            inrmulti += (digito * 2) - 9;
        }
        else
        {
            digitoDuplo += digito * 2;
        }
    }

    // Soma os dígitos que não foram duplicados
    for (int i = len - 1; i >= 0; i -= 2) {
        int digito = numeroCartao[i] - '0'; // Converte o caractere para inteiro
        soma += digito;
    }

    int somaTotal = soma + digitoDuplo;

    // Verifica se o número é válido
    if (somaTotal % 10 == 0) {
        return 1; // Válido
    } else {
        return 0; // Inválido
    }
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

    /*
     for(int i = 0; i < qtd; i++)
        {
            long b = pow(10,i);
            fracoes = number/b;
            c = fracoes%10;

             if(i%2 != 0) // retorna os digitos na sequência do penúltimo
            {
                int tempDigit = c*2;

                //Cálculos da soma do algoritmo de Luhn
                if(tempDigit > 9)
                {
                    somaDigit1 += tempDigit%10+1;
                }
                else
                {
                    somaDigit1 += tempDigit;
                }

            }
            else
            {
                if(c > 9)
                {
                    somaDigit2 += c % 10+1;
                }
                else
                {
                    somaDigit2 += c;
                }
            }
        }
   */
}
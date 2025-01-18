#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Prototype Functions
int keyCheckFunc(char x[]);

string txt;
char txtcif[100];
int key;
int main(int argc, char *argv[])
{
    int len=0;
    if(argc == 2)  // check two arrays !?!?!?
    {

        if(keyCheckFunc(argv[1]) == 1) // check argv[1,i] = int
        {
            key=atoi(argv[1]); // atoi converte char para int

            txt = get_string("plaintext: ");

            len=strlen(txt);
            for(int i = 0 ; i < len ; i++)
            {

                if(isupper(txt[i])) // se for alfabeto, ai testa pra ver se é maiusculo
                {
                    txtcif[i]=((txt[i] - 65 + key) % 26) + 65;                             // se for maiuscula.. faz isso
                }
                else if(islower(txt[i]))  // se for alfabeto, ai testa pra ver se é minusculo
                {
                    txtcif[i]=((txt[i] - 97 + key) % 26) + 97;                             // se for minusculo.. faz isso
                }
                else
                {
                    txtcif[i]=txt[i];                            //se nao for alfabeto faz isso
                }

            }
        printf("ciphertext: %s", txtcif);
        printf("\n");
        }

        else
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }

    }
    else
    {
      printf("Usage: ./caesar key \n");
      return 1;
    }


}

// Functions

int keyCheckFunc(char x[])
{
    int stop = 1;
    for (int i = 0, n = strlen(x); i < n && stop == 1; i++)
    {

        if (!isdigit(x[i]))
        {
            stop = 0;
        }
    }
    return stop;
}
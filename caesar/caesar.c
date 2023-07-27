#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototype Functions
int keyCheckFunc(char x[]);

char txt[100];
string txtcif;
int key[2];

int main(int argc, char *argv[])
{

    if(argc == 2)  // check two arrays !?!?!?
    {

        if(keyCheckFunc(argv[1]) == 1) // check argv[1,i] = int
        {
            for(i=n,len=strlen(argv); i<len; i++)
            {
                key[0] = argv[1,0];
            }
            printf("plaintext: ");
            scanf("%s", txt);
            for(i = 0 , len=strlen(txt) ; i < len ; i++)
            {
                if(isalpha(txt[i])) // testa o caractere para ver se é alfabeto
                {
                    if(islower(txt[i])) // se for alfabeto, ai testa pra ver se é minusculo
                    {
                                                        // se for minusculo.. faz isso
                    }
                    else
                    {
                                                        // se for maiusculo
                    }
                }
                                                    //se nao for alfabeto faz isso
            }



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
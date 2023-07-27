#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Prototype Functions
int keyCheckFunc(char x[]);

string txt;
int txtcifint[];
int key,i,len;

int main(int argc, char *argv[])
{

    if(argc == 2)  // check two arrays !?!?!?
    {

        if(keyCheckFunc(argv[1]) == 1) // check argv[1,i] = int
        {


                key=atoi(argv[1]); // atoi converte char para int

            printf("plaintext: ");
            scanf("%s", txt);
            for(i = 0 , len=strlen(txt) ; i < len ; i++)
            {

                    if(isupper(txt[i])) // se for alfabeto, ai testa pra ver se é maiusculo
                    {
                         txtcifint[1]=((txt[i]) - 65 + key) % 26) + 65;                             // se for minusculo.. faz isso
                    }
                    else
                    {
                                                        // se for maiusculo
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
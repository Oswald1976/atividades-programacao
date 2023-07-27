#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototype Functions
int keyCheckFunc(char x[]);

string txt;
string txtcif;
int key;

int main(int argc, char *argv[])
{

    if(argc == 2)  // check two arrays !?!?!?
    {

        if(keyCheckFunc(argv[1]) == 1) // check argv[1,i] = int
        {
            for(i=n,len=strlen(argv); i<len; i++)
            {
                key=atoi(argv[1]); // atoi converte char para int
            }
            printf("plaintext: ");
            scanf("%s", txt);
            for(i = 0 , len=strlen(txt) ; i < len ; i++)
            {

                    if(isupper(txt[i])) // se for alfabeto, ai testa pra ver se é maiusculo
                    {
                         txtcif[1]=int(txt[i]) + key                               // se for minusculo.. faz isso
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
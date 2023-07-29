#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int keycheck(char x[]);  // prototype functions



int main(int argc, char *argv[])
{
    int len=0;
    if(argc == 2 ) // check two arrays ?
    {
        if(keycheck(argv[1]) == 1) // check arvg1 is true
        {

        }
        else
        {
           printf("key must contain 26 characters. \n");
           return 1;

        }
    }
    else
    {
       printf("Usage: ./substitution KEY \n");
       return 1;
    }
}

// functions

int keycheck(char x[])
{
    int stop = 1;
    int len=strlen(x);
    if(len == 27) // check 26 char is true
    {
        for(int i = 0; i < len && stop == 1; i++ )
        {
            if(!isalpha(x[i])) // checa se algum dos caracteres do segundo argumento é numerico
            {
                printf("key must only contain alphabetic characters. \n");
                stop = 0;
            }
            for (int j = 0; j < i; j ++)
            {
                if (x[i] == x[j])
                {
                    printf("A chave não deve conter caracteres repetidos\n");
                    stop= 1;
                }
            }
        }
    }
    else
    {
        printf("key must contain 26 characters. \n");
        stop = 0;
    }
    return stop;

}
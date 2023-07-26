#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main(int argc, char *argv[])
{
    char argvc[2];

    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
    }

    for(int i=0, len=strlen(argv[1]); i < len; i++)
        {
            argvc[i] = argv{1,i};
        }

    if(isdigit(argvc[1]))
    {
        printf("Esta certo vc digitou um numero decimal \n");
    }
    else
    {
      printf("Usage: ./caesar key \n");
    }
}
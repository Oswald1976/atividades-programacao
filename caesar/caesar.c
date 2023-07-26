#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototype Functions
int keyCheckFunc(char x[])

int main(int argc, char *argv[])
{

    if(argc == 2)
    {

       if(isdigit(argv[1]))
            {
                printf("Esta certo vc digitou um numero decimal \n");
            }
    }
    else
    {
      printf("Usage: ./caesar key \n");
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
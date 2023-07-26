#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototype Functions
int keyCheckFunc(char x[]);

int main(int argc, char *argv[])
{

    if(argc == 2)  // check two arrays !?!?!?
    {

        if(keyCheckFunc(argv[1]) == 1) // check argv[1,i] = int
        {
            string txt = get_string("plaintext: ");

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
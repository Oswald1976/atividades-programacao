#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int keycheck(char x[]);  // prototype functions



int main(int argc, char *argv[])
{
    int len=0
    if(argc == 2 ) // check two arrays ?
    {
        if(keycheck(argv[1]) == 1) // check arvg1 is true
        {

        }
    }
    else
    {
       printf("Usage: ./substitutioan KEY \n");
    }
}

// functions

int keycheck(char x[])
{
    int stop = 1;
    int len=strlen(x);
    if(len == 26)
    {
        for(int i = 0; i < len ; i++ )
        {
            if
        }
    }
    else
    {
        stop = 0;
    }
    return stop;

}
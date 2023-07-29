#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int keycheck(char x[]);  // prototype functions

int main(int argc, char *argv[])
{
    int len=0;
    if(argc != 2 ) // check two arrays ?
    {
        printf("Usage: ./substitution KEY \n");
        return 1;
    }
    if(strlen(argv[1]) !== 26) // check 26 char is true
    {
        printf("key must contain 26 characters. \n");
        return 1;
    }






/*
    if(keycheck(argv[1]) == 1) // check arvg1 is true
    {
        printf("DEU CERTO. \n");
        return 0;
    }
    else
    {
        printf("key must contain 26 characters. \n");
        return 1;
    } */

}

// functions

int keycheck(char x[])
{
    int stop = 1;
    int len=strlen(x);
    if(len == 27) // check 26 char is true
    {

    }
    else

    return stop;

}
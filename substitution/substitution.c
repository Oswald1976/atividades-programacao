#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>



int main(int argc, string argv[])
{
    char argteste[26];
    int len = strlen(argv[1]);
    if(argc != 2 ) // check two arrays ?
    {
        printf("Usage: ./substitution KEY \n");
        return 1;
    }
    if(len != 26) // check 26 char is true
    {
        printf("key must contain 26 characters. \n");
        return 1;
    }
    for(int i = 0; i <= len ; i++ )
    {
        argteste[i]=argv[1][i];
    }

    for(int i = 0; i < len ; i++ )
        {
            if(!isalpha(argv[1][i])) // checa se algum dos caracteres do segundo argumento é numerico
            {
                printf("key must only contain alphabetic characters. \n");
                return 0;
            }
            for (int j = 0; j < i; j ++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("A chave não deve conter caracteres repetidos\n");
                    return 0;
                }
            }
      
}
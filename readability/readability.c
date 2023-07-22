#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char texto[];
int i, len , letras = 0 , palav = 0, frase = 0;
int main(void)
{
    printf("Texto");
    scanf("%s", texto);
    for(i = 0, len = strlen(texto); i < len ; i++)
        if(texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto[i] <= 'Z')
        {
            letras++;
        }

    printf("%i", letras);
}
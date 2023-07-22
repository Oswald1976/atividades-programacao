#include <stdio.h>
#include <string.h>
#include <ctype.h>

char texto[];
int i, len, letras, palav, frase;
int main(void)
{
    printf("Texto");
    scanf(%s, texto);
    for(i = 0, len = strlen(texto); i < len ; i++)
        if(texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto[i] <= 'Z')
        {
            letras++;
        }

    printf(%i, letras);
}
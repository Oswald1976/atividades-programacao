#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string texto;
int letras = 0 , palav = 0, frase = 0;
int main(void)
{
    printf("Texto");
    scanf("%s", texto);
    int i, len;


    for(i = 0, len = strlen(texto) ;i < len ; len++)
    {

        if (isalpha(texto[i]) || texto[i] == '\0')  // se o caracter for letra adiciona 1 no contador de letras
        {
            letras++;
        }
        if (isblank(texto[i]) || texto[i] == '\0') // se o caracter for espaço em branco  adiciona 1 no contador de palav
        {
            palav++;
        }
        if (texto[i] == '!' || texto[i] == '.' || texto[i] == '?') // se o caracter for ! ou . ou ? adiciona 1 no contador de frase
        {
            frase++;
        }
    }while( i < len );

    printf("%i", letras);
}
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main(void)
{


    string texto = get_string("Digite o texto: ");

    int letras = 0 , palav = 0, frase = 0;
    int i;
    int len=strlen(texto);


    for(i = 0 ; i < len ; i++)
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

    INDICE = 0,0588 * L - 0,296 * S - 15,8



    printf("%i", letras);
    printf("\n");
    printf("%i", palav);
    printf("\n");
    printf("%i", frase);
    printf("\n");
}
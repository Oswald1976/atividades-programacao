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

    float L = letras / (float) palav * 100;
    float S = frase / (float) palav * 100;

    float ppart = 0.0588 * L;
    float spart = 0.296 * S - 15.8;


    float INDIC = ppart - spart;

    printf("%f", INDIC);




}
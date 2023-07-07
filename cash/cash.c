#include <cs50.h>
#include <stdio.h>

float cent;
int m25 = 0, m10 = 0, 
float c = 0.10;
float d = 0.05;
float e = 0.01;

int main(void)
{
    do
        cent = get_float("Digite o Valor que terá que dar de troco em moedas (aceitavel entre 0,01 e 0,99)");
    while ((float) cent < 0, 01 || (float) cent > 0, 99);
    {

    }
}
#include <stdio.h>
#include <cs50.h>

int a;
int main(void)
{   do
    a = get_flot("Digite o Valor que terá que dar de troco em moedas (aceitavel entre 0,01 e 0,99)");
    while (a < 0,01 || a > 0,99)

    
}